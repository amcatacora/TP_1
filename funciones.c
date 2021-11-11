/*
    Calcular factorial de un numero
*/
float factorial(float n) {
    if(n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}
