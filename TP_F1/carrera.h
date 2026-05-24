#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED

#define ESTADO_CARRERA_INACTIVA     0
#define ESTADO_CARRERA_ACTIVA       1
#define TAM_NOMBRE_CIRCUITO         20
#define MAX_PILOTOS_CARRERA         20

typedef struct
{
    int id;
    char circuito[TAM_NOMBRE_CIRCUITO];
    unsigned long long fecha;
    int estado;
    int cant_resultados;
    int resultado[MAX_PILOTOS_CARRERA][2]; /**Aun no definido**/
}Carrera;

int registrarCarrera(const char* rutaCarrera, const char* rutaPilotos);
static int generarIdCarrera(FILE* f);

#endif // CARRERA_H_INCLUDED
