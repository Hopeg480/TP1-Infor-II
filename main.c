#include <stdio.h>
#include "mylib.h"
#include "my_string.h"
#include "funciones.h"



int main(int argc, char const *argv[]) {
    articulos_t articulos[CANT_ARTICULOS] = {0};

    Carga(articulos);     
    muestra(articulos);   
    ordenamiento(articulos);
    muestra(articulos);
    return 0;
}