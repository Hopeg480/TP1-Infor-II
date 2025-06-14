#include <stdio.h>
#include "mylib.h"
#include "my_string.h"
#include "funciones.h"

void Carga(articulos_t * articulos){
    int i, a=1, b, cantidad;
    char articulo[90];
    
    do
    {
        printf("Ingrese la descripcion del archivo:\n");
        scanf("%s", articulo);
        fflush(stdin);
        i=0;
        while (i < CANT_ARTICULOS && articulos[i].descripcion[0] && mi_strcmp(articulo, articulos[i].descripcion)) i++;
        mi_strcpy(articulos[i].descripcion, articulo);
        printf("Ingrese la sucursal deseada (1, 2, 3):\n");
        scanf("%d", &b);
        fflush(stdin);
        printf("Ingrese la cantidad del producto:\n");
        scanf("%d", &cantidad);
        fflush(stdin);
        if (b==1)
        {
            articulos[i].cantidad_sucursal_1 = cantidad;
        }
        else if (b==2)
        {
            articulos[i].cantidad_sucursal_2 = cantidad;
        }
        else
        {
            articulos[i].cantidad_sucursal_3 = cantidad;
        }
        printf("Desea cargar otro producto? 1_si 2_no:\n"); 
        scanf("%d", &a);
        fflush(stdin);
    } while (a==1);
    return;
}

void muestra(articulos_t *articulos)
{
    int i;
    i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulos[i].descripcion[0]){
        printf("%s\t%d\t%d\t%d\t%d\n", articulos[i].descripcion, articulos[i].cantidad_sucursal_1 , articulos[i].cantidad_sucursal_2, articulos[i].cantidad_sucursal_3,articulos[i].total);
        i++;
    }
    return;
}

    void ordenamiento(articulos_t *articulos){
        int articulo_index, opc, i;
        char articulo[90];
    for ( opc = 1; opc < CANT_ARTICULOS; opc++)
    {
        for ( i = 0; i < CANT_ARTICULOS-1; i++)
        {
            if(articulos[i].total<articulos[i+1].total){
                mi_strcpy (articulo,articulos[i].descripcion);
                mi_strcpy(articulos[i].descripcion,articulos[i+1].descripcion);
                mi_strcpy(articulos[i+1].descripcion, articulo);

                articulo_index = articulos[i].cantidad_sucursal_1;
                articulos[i].cantidad_sucursal_1 = articulos[i+1].cantidad_sucursal_1;
                articulos[i+1].cantidad_sucursal_1 = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal_2;
                articulos[i].cantidad_sucursal_2 = articulos[i + 1].cantidad_sucursal_2;
                articulos[i + 1].cantidad_sucursal_2 = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal_3;
                articulos[i].cantidad_sucursal_3 = articulos[i + 1].cantidad_sucursal_3;
                articulos[i + 1].cantidad_sucursal_3 = articulo_index;

                articulo_index = articulos[i].total;
                articulos[i].total = articulos[i + 1].total;
                articulos[i + 1].total = articulo_index;
            }
            
        }
        
    }   
}