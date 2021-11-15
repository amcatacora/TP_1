#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"

void imprimirMenu();
void hacerPausa();
void setColor(int background, int text);
void printChar(char c, int a);
float ingresarOperando(char mensaje[]);

int main()
{
    char seguir='s';
    int opcion=0;
    float a=0,b=0,resultado=0;

    while(seguir=='s')
    {
        imprimirMenu(0);

        printf("\nA=%.2f B=%.2f\n\n", a, b);

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        system("cls");
        imprimirMenu(opcion);

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
