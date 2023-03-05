#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



void sort_float(long double *lista, int largo){

    long double memory1;

    for (int i = largo; i > 0; i--){

        if (lista[i-1] < lista[i]){
            memory1 = lista[i-1];
            lista[i-1] = lista[i];
            lista[i] = memory1;

            i = largo;
        }
    }
}


void mayor_a_menor(long double *numeros_float,
                   int place_counter){

    int float_index = 0;

    for (int indice = 0; indice < place_counter; indice++){

                /*
                Se utilizó la referencia (3) para modificar la cantidad
                de lugares decimales del flotante cuando se imprime en
                pantalla.
                */

                printf(
                    "Posición %d --> %.3Lf\n",
                    indice,
                    numeros_float[float_index]
                );
                float_index++;
    }
}


int main(int argc, char *argv[]){

    /*
    Se utilizo la referencia (1) para aprender a abrir archivos y
    leerlos.
    */

    FILE *fpuntero;
    char lista[80];
    long double numeros_float[80];
    int place_counter = 0;


    if (argc != 2){
        printf(
            "Numero de argumentos invalido. "
            "Solo se permite un argumento.\n"
        );
    }
    
    else {

        fpuntero = fopen(argv[1], "r");

        /*
        Se utilizo la referencia (2) y (4) para aprender a iterar sobre estos
        a travez de multiples lineas.
        */

        while ((fscanf(fpuntero, "%s", lista)) != EOF){
            fgetc(fpuntero);

            
            numeros_float[place_counter] = atof(lista);
            char *purity_test = lista;
            // char variable = *purity_test;
            char *purity_test2 ="0";
            char *purity_test3 ="0.0";
            char *purity_test4 ="0.00";
            char *purity_test5 ="0.000";
            char *purity_test6 ="\n";

            if (atof(lista) == 0){

                if ((strcmp(purity_test, purity_test2) != 0) &&
                    (strcmp(purity_test, purity_test3) != 0) &&
                    (strcmp(purity_test, purity_test4) != 0) &&
                    (strcmp(purity_test, purity_test5) != 0)){

                    printf(
                        "Existe un numero no permitido en la fila %d\n"
                        "Ejecución del programa cancelada.\n",
                        place_counter+1
                    );

                    printf(
                        "El caracter es--> %s\n",lista
                    );

                    exit(0);
                }
            }
            if (place_counter != 0){

                if (numeros_float[place_counter] ==
                numeros_float[place_counter-1]){

                    printf(
                        "Existe una linea invalida en la fila %d\n"
                        "Ejecución del programa cancelada.\n",
                        place_counter+1
                    );

                    exit(0);
                }
            }


            place_counter++;
        }

        sort_float(numeros_float, place_counter);

        printf(
            "Lista de los numeros de mayor a menor:\n"
        );

        mayor_a_menor(numeros_float, place_counter);
    }   

    fclose(fpuntero);
    return 0; 
}

/*
REFERENCIAS

(1):
https://www.programiz.com/c-programming/c-file-input-output

(2):
https://learn.microsoft.com/en-us/troubleshoot/developer/
visualstudio/cpp/libraries/fscanf-does-not-read-consecutive-line

(3):
https://linuxhint.com/setting_decimal_precision_c_-language/#:~:
text=The%20integer%20type%20variable%20is,denoted%20by%20the%20dot%20(.)

(4):
https://cplusplus.com/reference/cstdio/fscanf/

*/