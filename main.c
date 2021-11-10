#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

void hacerPausa();

int main()
{
    char seguir='s';
    int opcion=0;
    float a=0,b=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\nA=%.2f B=%.2f\n\n", a, b);

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf ("\nIngresar 1er operando: ");
                scanf ("%f", &a);
                break;
            case 2:
                printf ("\nIngresar 2do operando: ");
                scanf ("%f", &b);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }
        if(opcion != 9) {
            hacerPausa();
        }
    }

    return 0;
}

void hacerPausa() {
    printf("\nPresiona una techa para continuar");
    getch(); //pausa
    system("cls"); //limpia la consola
}
