#include "../includes/commons.h"

void Menu(){

    int eleccion = 0;
    int itemsPorCrear = 0;
    int numRankingMostrar = 0;
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
        printf("|6: Experimento complejidad temporal algoritmos de ordenamiento|\n");
        printf("|7: Experimento complejidad temporal algoritmos de búsqueda    |\n");
        printf("|8: Salir                                                      |\n");
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
                OpcionOrdenarCsv(); // Submenu de ordenamiento
                break;
                
            case 4:
                BuscarPorIDBinario();
                break;

            case 5:
                printf("Ingrese la cantidad de deportistas a mostrar en el ranking: ");
                while(scanf("%d", &numRankingMostrar)!=1 || numRankingMostrar <= 0 || numRankingMostrar > cantItems){
                    printf ("Ingrese un número válido, menor a %d: ", cantItems);
                    while (getchar()!='\n');
                }
                Ranking(numRankingMostrar);
                break;
            
            case 6:
                if (!HayDeportistasCargados()) break; // Validar que hay deportistas cargados para experimentar
            
                printf("\033[0;33mExperimento complejidad temporal algoritmos de ordenamiento\033[0m\n");
                
                printf("Bubble Sort\n");
                ExperimentoOrdenamiento(BubbleSort, CmpPorNombre); // Ordenamos por ID para experimentar
                printf("\nInsertion Sort\n");
                ExperimentoOrdenamiento(InsertionSort, CmpPorNombre);
                printf("\nSelection Sort\n");
                ExperimentoOrdenamiento(SelectionSort, CmpPorNombre);
                printf("\nCocktail Sort\n");
                ExperimentoOrdenamiento(CocktailSort, CmpPorNombre);


                break;
            case 7:
                printf("\033[0;33mFuncionalidad en desarrollo...\033[0m\n");
                break;

            case 8:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida, seleccione nuevamente\n");
        }

    } while (eleccion != 8);

}

void OpcionOrdenarCsv(){
    
    int seleccionCriterio = 0;
    int seleccionAlgoritmo = 0;
    Comparador cmp = NULL;

    if (!HayDeportistasCargados()) return; // No hay deportistas cargados
 
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
            BubbleSort(deportistas, cantItems, CmpPorID); 
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
                case 1: BubbleSort(deportistas, cantItems, cmp); break;
                case 2: InsertionSort(deportistas, cantItems, cmp); break;
                case 3: SelectionSort(deportistas, cantItems, cmp); break;
                case 4: CocktailSort(deportistas, cantItems, cmp); break;
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

void BuscarPorIDBinario(){

    if (!HayDeportistasCargados()) return; // Validar que hay deportistas cargados
    
    printf ("\033[0;33mBusqueda por ID: \033[0m\n");
    printf ("Ingresar -2 para salir de la busqueda por ID\n");

    int targetID;

    do {
        printf ("Ingrese el ID del deportista que desea buscar: ");
        while (scanf("%d", &targetID)!=1){
            printf ("\033[0;31mNo se admiten letras solo numeros: \033[0m");
            if (targetID == -2){
                printf ("Saliendo de busqueda por ID");
                break;
            }
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        }

        int index = BusquedaBinaria(deportistas, cantItems, targetID);

        if (index != -1) {
            printf ("\033[0;32mDeportista encontrado: [%d]\033[0m \n", targetID);
            printf("%-5s %-25s %-15s %-10s %s\n", "ID", "Nombre", "Equipo", "Puntaje", "Competencias");
            printf ("-------------------------------------------------------------\n");
            printf("%-5d %-20s %-15s %-10.2f %d\n", 
                deportistas[index].ID, 
                deportistas[index].nombre, 
                deportistas[index].equipo, 
                deportistas[index].puntaje, 
                deportistas[index].cantidadCompetencias
            );
            printf ("-------------------------------------------------------------\n");
        }

        else {
            printf ("\033[0;31mDeportista no encontrado: [%d]\033[0m\n", targetID);
        }
    } while (targetID != -2);
}

void Ranking(int numRankingMostrar){
    if (!HayDeportistasCargados()) return; // Validar que hay deportistas cargados

    printf ("\033[0;33mRanking de deportistas por puntaje: \033[0m\n");
    printf("%-5s %-25s %-15s %-10s %s\n", "ID", "Nombre", "Equipo", "Puntaje", "Competencias");
    printf ("-------------------------------------------------------------\n");

    // Crear un arreglo temporal para ordenar sin modificar el original
    Deportista* temp = malloc(cantItems * sizeof(Deportista));
    if (temp == NULL) {
        printf("Error al asignar memoria para ranking.\n");
        return;
    }
    memcpy(temp, deportistas, cantItems * sizeof(Deportista));

    // Ordenar por puntaje usando el comparador
    BubbleSort(temp, cantItems, CmpPorPuntaje);

    for (int i = 0; i < 10 && i < cantItems; i++) {
        printf("%-5d %-20s %-15s %-10.2f %d\n", 
            temp[i].ID, 
            temp[i].nombre, 
            temp[i].equipo, 
            temp[i].puntaje, 
            temp[i].cantidadCompetencias
        );
    }
    printf ("-------------------------------------------------------------\n");

    free(temp);
}

