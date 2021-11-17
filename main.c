#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"

void imprimirMenu(int opcion);
void imprimirOperandos(float a, float b);
void hacerPausa();
void setColor(int background, int text);
void printChar(char c, int a);
float ingresarOperando(char mensaje[]);

int main()
{
    int opcion = 0;
    float a = 0, b = 0, resultado = 0;
    imprimirMenu(opcion);
    imprimirOperandos(a, b);

    do
    {
        opcion = getch();
        switch(opcion) {
            case 49: opcion = 1; break;
            case 50: opcion = 2; break;
            case 51: opcion = 3; break;
            case 52: opcion = 4; break;
            case 53: opcion = 5; break;
            case 54: opcion = 6; break;
            case 55: opcion = 7; break;
            case 56: opcion = 8; break;
            case 57: opcion = 9; break;
            default: opcion = 0; break;
        }
        system("cls");
        imprimirMenu(opcion);
        imprimirOperandos(a, b);

        switch(opcion) {
            case 1:
                a = ingresarOperando("Ingresar 1er operando: ");
                break;
            case 2:
                b = ingresarOperando("Ingresar 2do operando: ");
                break;
            case 3:
                resultado = suma(a, b);
                printf("\nLa suma de los operandos es: %.2f\n", resultado);
				hacerPausa();
                break;
            case 4:
                resultado = resta(a, b);
                printf("\nLa diferencia entre los operandos es: %.2f\n", resultado);
				hacerPausa();
                break;
            case 5:
                resultado = division(a, b);
                printf("\nLa division entre los operandos es: %.2f\n", resultado);
				hacerPausa();
                break;
            case 6:
                resultado = multiplicacion(a, b);
                printf("\nLa multiplicacion entre los operandos es: %.2f\n", resultado);
				hacerPausa();
                break;
            case 7:
                resultado = factorial(a);
                printf("\nEl factorial de A es: %.2f\n", resultado);
				hacerPausa();
                break;
            case 8:
                resultado = suma(a, b);
                printf("\nLa suma de los operandos es: %.2f", resultado);
                resultado = resta(a, b);
                printf("\nLa diferencia entre los operandos es: %.2f", resultado);
                resultado = division(a, b);
                printf("\nLa division entre los operandos es: %.2f", resultado);
                resultado = multiplicacion(a, b);
                printf("\nLa multiplicacion entre los operandos es: %.2f", resultado);
                resultado = factorial(a);
                printf("\nEl factorial de A es: %.2f\n", resultado);
				hacerPausa();
                break;
        }
        system("cls");
        imprimirMenu(0);
        imprimirOperandos(a, b);

    } while(opcion != 9);

    return 0;
}

float ingresarOperando(char mensaje[]) {
    float operando = 0;
    printf (mensaje);
    scanf ("%f", &operando);
    return operando;
}

void imprimirOperandos(float a, float b) {
    setColor(1, 15);
    printf(" A=%10.2f", a);
    printChar(32, 12);
    printf("B=%10.2f   \n", b);
    printChar(32, 40);
    printf("\n");
    setColor(0, 15);
}

void imprimirMenu(int opcion) {
    char menu[9][40] = {
        " 1- Ingresar 1er operando (A=x)      ",
        " 2- Ingresar 2do operando (B=y)      ",
        " 3- Calcular la suma (A+B)           ",
        " 4- Calcular la resta (A-B)          ",
        " 5- Calcular la division (A/B)       ",
        " 6- Calcular la multiplicacion (A*B) ",
        " 7- Calcular el factorial (A!)       ",
        " 8- Calcular todas las operaciones   ",
        " 9- Salir                            "
    };

    setColor(1, 15);
    printf("%c",218);
    printChar(196, 37);
    printf("%c \n",191);

    for(int i = 1; i <= 9; i++) {
        printf("%c", 179);
        if(opcion == i) {
            setColor(2, 15);
        }
        printf(menu[i-1]);
        if(opcion == i) {
            setColor(1, 15);
        }
        printf("%c \n", 179);
    }

    printf("%c",192);
    printChar(196, 37);
    printf("%c \n",217);

    setColor(0, 15);
}

void printChar(char c, int a) {
    for(int i=0;i<a;i++) {
        printf("%c", c);
    }
}

void hacerPausa() {
    printf("\nPresiona una techa para continuar");
    getch();
}

void setColor(int background, int text){
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 int ncolor = text + (background * 16);
 SetConsoleTextAttribute(console, ncolor);
}
