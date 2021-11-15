/*
    Calcular factorial de un numero
*/
int factorial(int n) {
    if(n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}
/*
    Calcular la suma (A+B)
*/
int suma(int a, int b){
    int resultado = a + b;
    return resultado;
}
/*
    Calcular la resta (A+B)
*/
int resta(int a, int b){
  int resultado = a - b;
  return resultado;
}
/*
    Calcular la division (A+B)
*/
int division(int a, int b){
  int resultado = a / b;
  return resultado;
}
/*
    Calcular la division (A+B)
*/
int multiplicacion(int a, int b){
  int resultado = a * b;
  return resultado;
}
