#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

void imprimirMenu();
void hacerPausa();
void printChar(char c, int a);
float ingresarOperando(char mensaje[]);

int main()
{
    char seguir='s';
    int opcion=0;
    float a=0,b=0,resultado=0;

    while(seguir=='s')
    {
        imprimirMenu();

        printf("\nA=%.2f B=%.2f\n\n", a, b);

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                a = ingresarOperando("\nIngresar 1er operando: ");
                break;
            case 2:
                b = ingresarOperando("\nIngresar 2do operando: ");
                break;
            case 3:
                resultado = suma(a, b);
                printf("\nLa suma de los operandos es: %.2f\n", resultado);
                break;
            case 4:
                resultado = resta(a, b);
                printf("\nLa diferencia entre los operandos es: %.2f\n", resultado);
                break;
            case 5:
                resultado = division(a, b);
                printf("\nLa division entre los operandos es: %.2f\n", resultado);
                break;
            case 6:
                resultado = multiplicacion(a, b);
                printf("\nLa multiplicacion entre los operandos es: %.2f\n", resultado);
                break;
            case 7:
                resultado = factorial(a);
                printf("\nEl factorial de A es: %.2f\n", resultado);
                break;
            case 8:
                resultado = suma(a, b);
                printf("\nLa suma de los operandos es: %.2f\n", resultado);
                resultado = resta(a, b);
                printf("\nLa diferencia entre los operandos es: %.2f\n", resultado);
                resultado = division(a, b);
                printf("\nLa division entre los operandos es: %.2f\n", resultado);
                resultado = multiplicacion(a, b);
                printf("\nLa multiplicacion entre los operandos es: %.2f\n", resultado);
                resultado = factorial(a);
                printf("\nEl factorial de A es: %.2f\n", resultado);
                break;
            case 9:
                seguir = 'n';
                break;
            break;
        }
        if(opcion != 9) {
            if(opcion > 2 && opcion < 9) {
                hacerPausa();
            }
            system("cls");
        }
    }

    return 0;
}

float ingresarOperando(char mensaje[]) {
    float operando = 0;
    printf (mensaje);
    scanf ("%f", &operando);
    return operando;
}

void imprimirMenu() {
    printf("%c",218);
    printChar(196, 37);
    printf("%c\n",191);
    printf("%c 1- Ingresar 1er operando (A=x)      %c \n", 179, 179);
    printf("%c 2- Ingresar 2do operando (B=y)      %c \n", 179, 179);
    printf("%c 3- Calcular la suma (A+B)           %c \n", 179, 179);
    printf("%c 4- Calcular la resta (A-B)          %c \n", 179, 179);
    printf("%c 5- Calcular la division (A/B)       %c \n", 179, 179);
    printf("%c 6- Calcular la multiplicacion (A*B) %c \n", 179, 179);
    printf("%c 7- Calcular el factorial (A!)       %c \n", 179, 179);
    printf("%c 8- Calcular todas las operaciones   %c \n", 179, 179);
    printf("%c 9- Salir                            %c \n", 179, 179);
    printf("%c",192);
    printChar(196, 37);
    printf("%c\n",217);
}

void printChar(char c, int a) {
    for(int i=0;i<a;i++) {
        printf("%c", c);
    }
}

void hacerPausa() {
    printf("\nPresiona una techa para continuar");
    getch(); //pausa
}
