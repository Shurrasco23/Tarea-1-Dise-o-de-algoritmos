#include "../includes/commons.h"

void Menu(){

    int eleccion = 0;
    int itemsPorCrear = 0;
    int csvElegido = 0;
    char path[1024];

    do {

        printf("\n");
        printf(" --------------------------------------------------------------\n");
        printf("|Seleccione alguna de las siguientes opciones y presione enter |\n");
        printf("|                                                              |\n");
        printf("|1: Crear Csv de deportistas                                   |\n");
        printf("|2: Cargar Csv de deportistas                                  |\n");
        printf("|3: Ordenar Csv por campo                                      |\n");
        printf("|4: Buscar deportista por ID                                   |\n");
        printf("|5: Mostrar ranking de los n mejores deportistas (n a elegir)  |\n");
        printf("|6: Salir                                                      |\n");
        printf("|                                                              |\n");
        printf(" --------------------------------------------------------------\n");

        // Restringir la entrada de caracteres no validos (negativos y/o letras)
        while (scanf("%d", &eleccion)!=1){
            printf ("\033[0;31mNo se admiten letras solo numeros: \033[0m");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }

        switch (eleccion){

            case 1:
                
                printf("Ingrese la cantidad de deportistas a generar: ");
                while(scanf("%d", &itemsPorCrear)!=1 || itemsPorCrear <= 0){
                    printf ("No ingresar letras o numeros negativos: ");
                    while (getchar()!='\n');
                }
                printf("\033[0;33mGenerando CSV con %d deportistas...\033[0m\n", itemsPorCrear);
                
                CreaCsv(itemsPorCrear);
                break;

            case 2:
                
                int sepuedeListar = ListarCsvDisponibles(itemsPorCrear);
                
                if (sepuedeListar == -1 || sepuedeListar == 1){
                    break;
                } // No hay csv disponibles o no se pudo abrir opciones.csv

                while (csvElegido != -1){
                    
                    printf("Ingrese el tamaño de CSV que desea utilizar (-1 para salir): ");
                    scanf(" %d", &csvElegido);
                    snprintf(path, sizeof(path), "db/deportistas%d.csv", csvElegido);
                    
                    if (access(path, F_OK) == 0) {
                        LeerCsvDeportistas(path); 
                        break;  
                    }
                    
                    else if (csvElegido == -1){
                        printf ("Saliendo de carga CSV...\n");
                        break;
                    }
                    
                    else {
                        printf("%d no es un tamaño válido\n", csvElegido);
                    }
                }

                csvElegido = 0; // Reiniciar variable
                break;

            case 3:
                OrdenaCsv(); // Submenu de ordenamiento
                break;
                
            case 4:
                BuscarPorIDBinario();
                break;

            case 5:
                Ranking();
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida, seleccione nuevamente\n");
        }

    } while (eleccion != 6);

}

void OrdenaCsv(){
    
    int seleccionCriterio = 0;
    int seleccionAlgoritmo = 0;
    Comparador cmp = NULL;

    if (!sePuedeIterar()) return; // No hay deportistas cargados
 
    while (1) { 
        printf ("\033[0;33mSub-menu de ordenamiento: \033[0m\n");
        printf(" --------------------------------------------------------------\n");
        printf("|Seleccione el campo por el cual desea ordenar:                |\n");
        printf("|1: Ordenamiento por ID                                        |\n");
        printf("|2: Ordenamiento por nombre                                    |\n");
        printf("|3: Ordenar por puntaje                                        |\n");
        printf("|4: Ordenar por cantidad de competencias                       |\n");
        printf("|5: Salir al Menu Principal                                    |\n");
        printf(" --------------------------------------------------------------\n");
    
        while (scanf("%d", &seleccionCriterio)!=1){
            printf ("\033[0;31mNo se admiten letras solo numeros: \033[0m");
            while(getchar() != '\n'); 
        }

        // Si elige 5 aquí, ordenamos por ID y salimos completamente de la función
        if (seleccionCriterio == 5) {
            printf ("Ordenando por ID antes de salir...\n"); 
            bubbleSort(deportistas, cantItems, CmpPorID); 
            printf("Saliendo del submenú de ordenamiento...\n");
            return; // Volver al menú principal
        }

        switch (seleccionCriterio){
            case 1: cmp = CmpPorID; break;
            case 2: cmp = CmpPorNombre; break;
            case 3: cmp = CmpPorPuntaje; break;
            case 4: cmp = CmpPorCompetencias; break;
            default:
                printf("Opcion invalida, seleccione nuevamente\n");
                continue;
        }

        while (1) { 
            printf ("\033[0;33mSelección de algoritmo: \033[0m\n");
            printf(" --------------------------------------------------------------\n");
            printf("|Seleccione algoritmo de ordenamiento que desea utilizar:      |\n");
            printf("|1: BubbleSort                                                 |\n");
            printf("|2: InsertionSort                                              |\n");
            printf("|3: SelectionSort                                              |\n");
            printf("|4: CocktailSort                                               |\n");
            printf("|5: Volver a elegir criterio                                   |\n");
            printf(" --------------------------------------------------------------\n"); 
            
            while (scanf("%d", &seleccionAlgoritmo)!=1){
                printf ("\033[0;31mNo se admiten letras solo numeros: \033[0m");
                while(getchar() != '\n'); 
            }
            
            // Si elige 5 aquí, rompemos el loop interno para volver al externo
            if (seleccionAlgoritmo == 5) {
                printf("Volviendo al menú de criterios...\n");
                break;
            }

            switch (seleccionAlgoritmo) {
                case 1: bubbleSort(deportistas, cantItems, cmp); break;
                case 2: insertionSort(deportistas, cantItems, cmp); break;
                case 3: selectionSort(deportistas, cantItems, cmp); break;
                case 4: cocktailSort(deportistas, cantItems, cmp); break;
                default:
                    printf("Opcion invalida, seleccione nuevamente\n");
                    continue;
            }

            
            showFirst10Deportistas(); 
            printf("\033[0;32mOrdenamiento completado exitosamente.\033[0m\n");
            return; // Volver al menú principal
        }
    } 
}