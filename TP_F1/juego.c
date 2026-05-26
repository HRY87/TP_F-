#include "juego.h"
#include "piloto.h"

static void inicializarSistema();
static int mostrarMenu();

void iniciarJuego()
{
    int opcion;

    inicializarSistema();

    opcion = mostrarMenu();


    while (opcion != 0)
    {
        system("cls");
        switch (opcion)
        {
        case 1:
            listarPilotos(RUTA_PILOTO_BIN);
            break;
        case 2:
           // registrarCarrera();
        default:
            printf("[!] Opcion invalida.\n\n");
            break;
        }
        opcion = mostrarMenu();
    }


    printf("Hasta luego.\n");
}

static void inicializarSistema()
{
    printf("--- Inicializando sistema ---\n");

    FILE *f_bin = fopen(RUTA_PILOTO_BIN, "rb");

    if (f_bin == NULL)
    {
        printf("[!] Archivo no encontrado, generando carga inicial.\n");
        cargarArchivoPilotos(RUTA_PILOTO_TXT, RUTA_PILOTO_BIN);
    }
    else
    {
        fclose(f_bin);
    }

    printf("----------------------------\n\n");
}

static int mostrarMenu()
{
    int opcion;

    printf("+==================================+\n");
    printf("|   GESTION TEMPORADA F1 2026      |\n");
    printf("|==================================|\n");
    printf("|  1. Listar pilotos y sus puntos.  |\n");
    printf("|  2. Registrar una carrera (ingreso de posiciones)  |\n");
    printf("|  0. Salir.                        |\n");
    printf("+==================================+\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
