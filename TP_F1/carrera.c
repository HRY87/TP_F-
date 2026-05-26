#include <stdio.h>
#include "utilidades.h"
#include "carrera.h"
#include "piloto.h"

int registrarCarrera(const char* rutaCarrera, const char* rutaPilotos)
{
    int i = 0;
    Carrera carrera;

    /**1 - Abrir el archivo**/
    FILE* fCarrera = fopen(rutaCarrera, "ab+");

    if(!fCarrera)
        return ERR_ARCH;


    /**2 - Asignar ID**/
    carrera.id = generarIdCarrera(fCarrera);
    carrera.estado = ESTADO_CARRERA_ACTIVA;

    /** 3 - Ingreso de datos de la carrera (manual?)**/
    printf("\nNombre del circuito: ");
    //Buscar manera que lea espacio
    scanf("%19[^\n]", carrera.circuito);

    printf("\nFecha (AAAAMMDD): ");
    scanf("%llu", &carrera.fecha);

    /**4 - Obtener cantidad de pilotos activos**/
    carrera.cant_resultados = obtenerCantidadDePilotosActivos(RUTA_PILOTO_BIN);

    if(carrera.cant_resultados == 0)
    {
        fclose(fCarrera);
        return ERR_ARCH;
    }

    /**5 - Ingreso de resultados**/
    for(i=0; i<carrera.cant_resultados; i++){

    }

    /**6 - Escribir en carreras.dat**/
    fseek(fCarrera, 0, SEEK_END);
    fwrite(&carrera, sizeof(Carrera), 1, fCarrera);
    fclose(fCarrera);

    return TODO_OK;
}

static int generarIdCarrera(FILE* f)
{
    Carrera ultima;

    fseek(f, 0, SEEK_END);

    /**Si esta vacio sera la primera**/
    if(ftell(f) < (long)sizeof(Carrera))
        return 1;

    /**Me posicion en la ultima carrera ingresada, para obtener el id**/
    fseek(f, -(long)sizeof(Carrera), SEEK_END);
    fread(&ultima, sizeof(Carrera), 1, f);

    return (ultima.id + 1);
}

