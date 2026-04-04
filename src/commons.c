#include "../includes/commons.h"

Deportista* deportistas = NULL; // Arreglo global de deportistas
int cantItems = 0; // Contador global de deportistas

int CmpPorID(const Deportista* a, const Deportista* b) {
    return a->ID - b->ID; 
}

int CmpPorPuntaje(const Deportista* a, const Deportista* b) {
    return (a->puntaje > b->puntaje) - (a->puntaje < b->puntaje);
}

int CmpPorNombre(const Deportista* a, const Deportista* b) {
    return strcmp(a->nombre, b->nombre); 
}

int CmpPorEquipo(const Deportista* a, const Deportista* b) {
    return strcmp(a->equipo, b->equipo);
}

int CmpPorCompetencias(const Deportista* a, const Deportista* b) {
    return a->cantidadCompetencias - b->cantidadCompetencias;
}

void showFirst10Deportistas(){
    printf("\033[0;34mPrimeros 10 deportistas:\033[0m\n");
    printf("%-5s %-25s %-15s %-10s %s\n", "ID", "Nombre", "Equipo", "Puntaje", "Competencias");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < 10 && i < cantItems; i++) {
        printf("%-5d %-20s %-15s %-10.2f %d\n", 
            deportistas[i].ID, 
            deportistas[i].nombre, 
            deportistas[i].equipo, 
            deportistas[i].puntaje, 
            deportistas[i].cantidadCompetencias
        );
    }
    printf("-------------------------------------------------------------\n\n");
}