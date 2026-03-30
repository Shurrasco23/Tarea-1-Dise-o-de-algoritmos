#include "../includes/tarea.h"

void CreaCsv(){
    FILE *archivo;

    archivo = fopen("db/deportistas.csv", "w");

    fprintf(archivo,"ID,Nombre,Equipo,Puntaje,CantidadCompetencias\n");

    fclose(archivo);
}

void OrdenaCsv(){
    
}

void BuscarPorID(){

}

void Ranking(){

}