#include "../includes/tarea.h"

void menu(){

    int eleccion = 0;

    do {

        printf("\n");
        printf(" --------------------------------------------------------------\n");
        printf("|Seleccione alguna de las siguientes opciones y presione enter |\n");
        printf("|                                                              |\n");
        printf("|1: Crear Csv de deportistas                                   |\n");
        printf("|2: Ordenar Csv por campo                                      |\n");
        printf("|3: Buscar deportista por ID                                   |\n");
        printf("|4: Mostrar ranking de los n mejores deportistas (n a elegir)  |\n");
        printf("|5: Salir                                                      |\n");
        printf("|                                                              |\n");
        printf(" --------------------------------------------------------------\n");

        scanf("%d", &eleccion);

        switch (eleccion){

            case 1:
                CreaCsv();
                break;

            case 2:
                OrdenaCsv();
                break;

            case 3:
                BuscarPorID();
                break;

            case 4:
                Ranking();
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida, seleccione nuevamente\n");
        }

    } while (eleccion != 5);

}