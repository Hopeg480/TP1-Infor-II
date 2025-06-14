#include <stdio.h>
#ifndef _MY_LIB_H
#define _MY_LIB_H 

#define CANT_ARTICULOS 60


typedef struct {
    char descripcion[90];
    int cantidad_sucursal_1;
    int cantidad_sucursal_2;
    int cantidad_sucursal_3;
    int total;
} articulos_t;

#endif 