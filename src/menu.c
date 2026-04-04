#include "../includes/commons.h"

void Menu(){

    int eleccion = 0;
    int itemsPorCrear = 0;
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
                LeerDeportistas("deportistas500.csv");
                break;

            case 3:
                 // Cargar deportistas desde un CSV específico (puede ser dinámico)
                OrdenaCsv();
                printf("Cantidad de deportistas cargados: %d\n", cantItems);
                bubbleSort(deportistas, cantItems, CmpPorPuntaje);
                printf("\033[0;32mDeportistas ordenados por Puntaje.\033[0m\n");
                showFirst10Deportistas();
                bubbleSort(deportistas, cantItems, CmpPorNombre);
                printf("\033[0;32mDeportistas ordenados por Nombre.\033[0m\n");
                showFirst10Deportistas();
                bubbleSort(deportistas, cantItems, CmpPorEquipo);
                printf("\033[0;32mDeportistas ordenados por Equipo.\033[0m\n");
                showFirst10Deportistas();
                bubbleSort(deportistas, cantItems, CmpPorCompetencias);
                printf("\033[0;32mDeportistas ordenados por Competencias.\033[0m\n");
                showFirst10Deportistas();

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