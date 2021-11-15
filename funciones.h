#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int factorial(int n);
int suma(int a, int b);
int resta(int a, int b);
int division(int a, int b);
int multiplicacion(int a, int b);

/*
    Calcular factorial de un numero
*/
int factorial(int n)
{
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
/*
    Calcular la suma (A+B)
*/
int suma(int a, int b)
{
    int resultado = a + b;
    return resultado;
}
/*
    Calcular la resta (A+B)
*/
int resta(int a, int b)
{
    int resultado = a - b;
    return resultado;
}
/*
    Calcular la division (A+B)
*/
int division(int a, int b)
{
    int resultado = a / b;
    return resultado;
}
/*
    Calcular la division (A+B)
*/
int multiplicacion(int a, int b)
{
    int resultado = a * b;
    return resultado;
}

#endif // FUNCIONES_H_INCLUDED
