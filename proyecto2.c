/*

*** ENCABEZADO DEL DOCUMENTO ***

Estudiantes:
Yoel Moya Carmona - B75262
Manuel Zapata Zamora - B47801
Luis Diego Nuñez Mora - B75473

*** ESTRUCTURA GENERAL DEL CODIGO ***

Se dio la creación independiente de un algoritmo que acomoda los valores
de mayor a menor en una lista. Este se logro iterando sobre dicha lista
iniciando por el valor en la posición 'n' y comparando este con n-1. Si
n-1 es mayor, cambia ambos numeros de lugar y reinicia el contador. El
'for loop' utilizado termina una vez que no se realice ningun cambio a}
la lista.

La segunda función creada se dio para imprimir la lista, la cual recibe un
contador con la cantidad de valores que fueron leidos e ingresados a la lista
y los imprime uno por uno iniciando por el mayor en la posicion cero.

En el 'main' se da un manejo de exepciones para la cantidad de argumentos con
'if statements', y para los numeros no validos del archivo, se aprovechó la
respuesta de la funcion atof() cuando no logra convertir un 'string' a float,
la cual automaticamente es cero, y cada vez que aparece un cero, se compara el
string antes de ser convertido con un string de ceros. En dado caso que esta
comparacion no sea valida, se puede saber que no es un numero valido y se
levanta una exepcion. No se continua el proceso de ejecución.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


// Algoritmo que acomoda los numeros de mayor a menor:
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

// funcion que imprime todos los valores ya acomodados de la lista
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
                    "%.3Lf\n",
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

    // Manejo de exepciones para cantidad de argumentos proveidos:
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

            // Asignación del numero a posicion de lista:
            numeros_float[place_counter] = atof(lista);

            // Manejo de exepciones de los numeros del archivo:
            char *purity_test = lista;
            char *purity_test2 ="0";
            char *purity_test3 ="0.0";
            char *purity_test4 ="0.00";
            char *purity_test5 ="0.000";

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

            // Contador de posiciones en la lista:
            place_counter++;
        }

        sort_float(numeros_float, place_counter);

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