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
