#ifndef TAREA_H
#define TAREA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NOMBRE 64

typedef struct{
    int ID;
    char nombre[MAX_NOMBRE];
    char equipo[MAX_NOMBRE];
    double puntaje;
    int CantidadCompetencias;
}Deportista;


void leer_nombres_y_apellidos();
void CreaCsv();
void menu();
void OrdenaCsv();
void BuscarPorID();
void Ranking();
#endif