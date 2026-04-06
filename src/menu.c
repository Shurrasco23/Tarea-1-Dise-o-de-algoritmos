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

        while (scanf("%d", &eleccion)!=1){
            printf ("\033[0;31mNo se admiten letras solo numeros: \033[0m");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }

        switch (eleccion){

            case 1:
                
                printf("Ingrese la cantidad de deportistas a generar: ");
                scanf("%d", &itemsPorCrear);
                printf("\033[0;33mGenerando CSV con %d deportistas...\033[0m\n", itemsPorCrear);
                
                CreaCsv(itemsPorCrear);
                break;

            case 2:
                ListarCsvDisponibles();

                while (csvElegido != -1){

                    printf("Ingrese el tamaño de CSV que desea utilizar (-1 para salir): ");
                    scanf(" %d", &csvElegido);
                    snprintf(path, sizeof(path), "db/deportistas%d.csv", csvElegido);
                    
                    if (access(path, F_OK) == 0) {
                        LeerCsvDeportistas(path); 
                        break;  
                    } else {
                        printf("%d no es un tamaño válido\n", csvElegido);
                    }
                }

                csvElegido = 0; // Reiniciar variable
                break;

            case 3:
                OrdenaCsv();
                break;
                
            case 4:
                BuscarPorID();
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