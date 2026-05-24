#include <stdio.h>
#include <stdlib.h>
#include "piloto.h"

static void inicializarSistema();
static int archivoExiste(const char *ruta);
static int mostrarMenu();

int main()
{
    int opcion;

    inicializarSistema();

    opcion = mostrarMenu();

    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            listarPilotos(RUTA_PILOTO_BIN);
            break;
        default:
            printf("[!] Opcion invalida.\n\n");
            break;
        }
        opcion = mostrarMenu();
    }

    printf("Hasta luego.\n");
    return 0;
}

static int archivoExiste(const char *ruta)
{
    FILE *f = fopen(ruta, "r");

    if (f == NULL)
    {
        return 0;
    }
    fclose(f);
    return 1;
}

static void inicializarSistema()
{
    printf("--- Inicializando sistema ---\n");

    if (!archivoExiste(RUTA_PILOTO_TXT))
    {
        generarArchivoTxt(RUTA_PILOTO_TXT);
    }
    else
    {
        printf("[OK] '%s' ya existe, se omite generacion.\n",
               RUTA_PILOTO_TXT);
    }

    if (!archivoExiste(RUTA_PILOTO_BIN))
    {
        cargarArchivoPilotos(RUTA_PILOTO_TXT, RUTA_PILOTO_BIN);
    }
    else
    {
        printf("[OK] '%s' ya existe, se omite carga.\n",
               RUTA_PILOTO_BIN);
    }

    printf("----------------------------\n\n");
}

static int mostrarMenu()
{
    int opcion;

    printf("+==================================+\n");
    printf("|   GESTION TEMPORADA F1 2026      |\n");
    printf("|==================================|\n");
    printf("|  1. Listar pilotos y sus puntos  |\n");
    printf("|  0. Salir                        |\n");
    printf("+==================================+\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
