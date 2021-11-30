///Librerias que se utilizaron
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"

///definicion de colores
#define COLOR_NEGRO 0
#define COLOR_AZUL 1
#define COLOR_VERDE 2
#define COLOR_CELESTE 3
#define COLOR_ROJO 4
#define COLOR_BLANCO 15

///declaracion de funciones
void imprimirMenu(int opcion);
void imprimirOperandos(float a, float b);
void hacerPausa();
void setColor(int background, int text);
void printChar(char c, int a);
float ingresarOperando(char mensaje[], int *error);
int calculadoraVirtual();

void imprimirCalculadoraVirtual(int primerOperando, float operando1, float operando2, int operador);
float addDigitToNumber(float n, float a);
void setPressNumber(int primerOperando, float *operando1, float *operando2, float n);

int main()
{
    int opcion = 0;
    int error = 0;
    float a = 0, b = 0, resultado = 0;
    imprimirMenu(opcion);
    imprimirOperandos(a, b);

    do
    {
        if(error == 0) {
            opcion = getch(); ///getch es una funcion que usamos para hacer una pausa esperando al usuario, y la funcion
                             /// devuelve la tecla que se toco, en codigo ascii
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
                case 9: opcion = 10; break;
                default: opcion = 0; break;
            }
        } else {
            error = 0;
        }
        system("cls"); ///limpia la pantalla
        imprimirMenu(opcion);
        imprimirOperandos(a, b);

        switch(opcion) {
            case 1:
                a = ingresarOperando("\nIngresar 1er operando: ", &error);
                break;
            case 2:
                b = ingresarOperando("\nIngresar 2do operando: ", &error);
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
                if(b == 0) {
                    printf("\nEl divisor B no puede ser cero.\n");
                } else {
                    resultado = division(a, b);
                    printf("\nLa division entre los operandos es: %.2f\n", resultado);
                }
				hacerPausa();
                break;
            case 6:
                resultado = multiplicacion(a, b);
                printf("\nLa multiplicacion entre los operandos es: %.2f\n", resultado);
				hacerPausa();
                break;
            case 7:
                resultado = factorial(a);
                printf("\nEl factorial de A, primer numero es: %.2f\n", resultado);
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
            case 10:
                calculadoraVirtual();
                break;
        }
        system("cls");
        imprimirMenu(0);
        imprimirOperandos(a, b);

    } while(opcion != 9);

    return 0;
}

float ingresarOperando(char mensaje[], int *error) {
    float operando = 0;
    printf (mensaje);
    if(scanf ("%f", &operando) == 0) {
        for( int c = getchar(); c != EOF && c != ' ' && c != '\n' ; c = getchar());
        printf("\nSe ingreso un valor incorrecto!\n");
        hacerPausa();
        *error = 1;
    } else {
        *error = 0;
    }
    return operando;
}

void imprimirOperandos(float a, float b) {
    setColor(1, COLOR_BLANCO);
    printf("    A=%10.2f", a);
    printChar(32, 18);
    printf("B=%10.2f     \n", b);
    printChar(32, 51);
    printf("\n");
    setColor(COLOR_NEGRO, COLOR_BLANCO);
}

void imprimirMenu(int opcion) {
    char menu[9][50] = {
        "    1) Ingresar 1er operando (A=x)         ",
        "    2) Ingresar 2do operando (B=y)         ",
        "    3) Calcular la suma (A+B)              ",
        "    4) Calcular la resta (A-B)             ",
        "    5) Calcular la division (A/B)          ",
        "    6) Calcular la multiplicacion (A*B)    ",
        "    7) Calcular el factorial (A!)          ",
        "    8) Calcular todas las operaciones      ",
        "    9) Salir                               "
    };

    setColor(COLOR_AZUL, COLOR_BLANCO);

    printChar(32, 51);
    printf("\n");

    printf("   %c",218);
    printChar(196, 43);
    printf("%c   \n",191);

    //titulo
    printf("   %c", 179);
    printf("                CALCULADORA                ");
    printf("%c   \n", 179);

    printf("   %c",195);
    printChar(196, 43);
    printf("%c   \n",180);

    printf("   %c",179);
    printChar(32, 43);
    printf("%c   \n",179);

    for(int i = 1; i <= 9; i++) {
        printf("   %c", 179);
        if(opcion == i) {
            setColor(COLOR_VERDE, COLOR_BLANCO);
        }
        printf(menu[i-1]);
        if(opcion == i) {
            setColor(COLOR_AZUL, 15);
        }
        printf("%c   \n", 179);

    }

    printf("   %c",179);
    printChar(32, 43);
    printf("%c   \n",179);

    printf("   %c",192);
    printChar(196, 43);
    printf("%c   \n",217);

    setColor(COLOR_NEGRO, COLOR_BLANCO);
}

void printChar(char c, int a) {
    for(int i=0;i<a;i++) {
        printf("%c", c);
    }
}

void hacerPausa() {
    printf("\nPresiona una tecla para continuar");
    getch();
}

void setColor(int background, int text){
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 int ncolor = text + (background * 16);
 SetConsoleTextAttribute(console, ncolor);
}

int calculadoraVirtual()
{
    float operando1 = 0;
    float operando2 = 0;
    int primerOperando = 1;
    int operador = 0;
    int key = 0;

    do{
        system("cls");
        imprimirCalculadoraVirtual(primerOperando, operando1, operando2, operador);
        key = getch();

        switch(key) {
            //operadores
            case 8: operando1 = 0; primerOperando = 1; break;//borrar
            case 43: operador = 1; primerOperando = 0; break;//suma
            case 45: operador = 2; primerOperando = 0; break;//resta
            case 42: operador = 3; primerOperando = 0; break;//multi
            case 47: operador = 4; primerOperando = 0; break;//division
            case 33: operando1 = factorial(operando1); primerOperando = 1; operador = 0;break;//factorial
            case 13:
            case 61:
                switch(operador) {
                    case 1: operando1 = suma(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                    case 2: operando1 = resta(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                    case 3: operando1 = multiplicacion(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                    case 4: operando1 = division(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                }
                break;//igual o enter

            //numeros
            case 48: setPressNumber(primerOperando, &operando1, &operando2, 0); break;//numero 0
            case 49: setPressNumber(primerOperando, &operando1, &operando2, 1); break;//numero 1
            case 50: setPressNumber(primerOperando, &operando1, &operando2, 2); break;//numero 2
            case 51: setPressNumber(primerOperando, &operando1, &operando2, 3); break;//numero 3
            case 52: setPressNumber(primerOperando, &operando1, &operando2, 4); break;//numero 4
            case 53: setPressNumber(primerOperando, &operando1, &operando2, 5); break;//numero 5
            case 54: setPressNumber(primerOperando, &operando1, &operando2, 6); break;//numero 6
            case 55: setPressNumber(primerOperando, &operando1, &operando2, 7); break;//numero 7
            case 56: setPressNumber(primerOperando, &operando1, &operando2, 8); break;//numero 8
            case 57: setPressNumber(primerOperando, &operando1, &operando2, 9); break;//numero 9
        }
    } while(key != 27);

    return 0;
}

void setPressNumber(int primerOperando, float *operando1, float *operando2, float n) {
    if(primerOperando == 1) {
        *operando1 = addDigitToNumber(*operando1, n);
    } else {
        *operando2 = addDigitToNumber(*operando2, n);
    }
}

float addDigitToNumber(float n, float a) {
    if(n > 0) {
        char c[43] = "";
        sprintf(c, "%ld", (long)n);
        if(strlen(c) < 7) {
            return n * 10+ a;
        } else {
            return n;
        }
    } else {
        return a;
    }
}

void imprimirCalculadoraVirtual(int primerOperando, float operando1, float operando2, int operador) {

    //linea de inicio
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",218);
    printChar(196, 43);
    printf("%c\n",191);

    //linea operandos ingresados
    printf("%c", 179);
    char ing[43] = "";
    if(primerOperando == 0) {
        char op[5] = {'+','-','*','/','!'};
        sprintf(ing,"%.2f %c %.2f", operando1, op[operador-1], operando2);
    } else {
        sprintf(ing,"%.2f", operando1);
    }
    printf("%43s", ing);
    printf("%c\n", 179);

    //linea operandos
    printf("%c", 179);
    setColor(COLOR_NEGRO, COLOR_BLANCO);
    if(primerOperando == 1) {
        printf("%43.2f", operando1);
    } else {
        printf("%43.2f", operando2);
    }

    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c\n", 179);

    printf("%c",195);
    printChar(196, 43);
    printf("%c\n",180);

    //operandos  + - / * ! =

    printf("%c", 179);
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '+');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '-');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '*');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '/');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '!');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_CELESTE, COLOR_BLANCO);
    printf("  %c  ", '=');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_ROJO, COLOR_BLANCO);
    printf("  %c  ", '<');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf(" %c\n", 179);

    //linea de fin
    printf("%c",192);
    printChar(196, 43);
    printf("%c\n",217);

    setColor(COLOR_NEGRO, COLOR_BLANCO);
}
