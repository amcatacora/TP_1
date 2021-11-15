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
float suma(float a, float b){
    float resultado = a + b;
    return resultado;
}
/*
    Calcular la resta (A+B)
*/
float resta(float a, float b){
  float resultado = a - b;
  return resultado;
}
/*
    Calcular la division (A+B)
*/
float division(float a, float b){
  float resultado = a / b;
  return resultado;
}
/*
    Calcular la division (A+B)
*/
float multiplicacion(float a, float b){
  float resultado = a * b;
  return resultado;
}
