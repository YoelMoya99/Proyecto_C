/*
*** ENCABEZADO DEL DOCUMENTO ***

Estudiantes:
Yoel Moya Carmona - B75262
Manuel Zapata Zamora - B47801
Luis Diego Nuñez Mora - B75473

*** ESTRUCTURA GENERAL DEL CODIGO ***

Se intentó crear dos funciones. Una que generara una lista
con la combinacion de pasos nesesaria para llegar a los
requeridos. Y otra funcion que permute esa lista, y que resulte
en todas las diferentes combinaciones en las cuales se pueden
dar los pasos.

En la función generadora de combinaciones, se utilizaron dos
tipos de contadores, los cuales el 'delimitador' nos da la
cantidad maxima de posiciones en la lista a imprimir, y el
'global_index' el cual segun una serie de condiciones logicas
nos dice que posicicion de la lista cambia a que valor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int conmutador(int *list_pasos){

    /* 
    Se tenia la idea de permutar las listas, sin embargo no se
    logro realizar. El codigo solo imprime las listas de los
    pasos que se tiene.
    */

}

void gen_combinaciones(int *combinaciones_pasos,
                       int escalones){

    int delimitador, suma, global_index;
    delimitador = suma = global_index = 0;
    int outer_loop = 0;

    do{
      
        // Definir el delimitador aqui:
        delimitador = suma = 0;
        do{
            suma += combinaciones_pasos[delimitador];
            delimitador++;
        } while (suma != escalones);
        

        // Hacer el print en pantalla:
        for (int j = 0; j < delimitador; ++j){
            printf("%d,",combinaciones_pasos[j]);
        }
        printf("\n");


        // determinación de cual indice de la lista debe para cambiar
        // para que valor:
        if ((delimitador - global_index) > 1){

            // Segun cada valor, cambia al siguiente:
            if (combinaciones_pasos[global_index] == 1){
                combinaciones_pasos[global_index] = 2;

                // Se determina la posicion del siguiente
                // valor a ser cambiado:
                global_index++;
            }
            else if (combinaciones_pasos[global_index] == 2){
                combinaciones_pasos[global_index] = 3;
                global_index++;
            }
            else if (combinaciones_pasos[global_index] == 3){
                combinaciones_pasos[global_index] = 4;
                global_index++;
            }
        }
        
        // En dado caso que los contadores esten a un valor
        // de distancia:
        else if (((delimitador - global_index) == 1)){

            // Condiciones de redireccion del 'global_index'
            // en dado caso que el siguiente numero de la lista no
            // pueda cambiar:

            // Esta primera termina la ejecucion ya que se alcanzo
            // una condicion de finalización:
            if ((combinaciones_pasos[global_index-1] == escalones)
            ){outer_loop = 1;}

            else {
                int while_condition = 0; int i_while = 0;
                while (while_condition != 1)
                {
                    if ((combinaciones_pasos[global_index-1] ==
                         combinaciones_pasos[i_while]) &&
                        (combinaciones_pasos[i_while] != 4)){
                        while_condition = 1;
                    }
                    i_while++;
                }
                global_index = i_while-1;

                if (combinaciones_pasos[global_index] == 1){
                    combinaciones_pasos[global_index] = 2;
                    global_index++;
                }
                else if (combinaciones_pasos[global_index] == 2){
                    combinaciones_pasos[global_index] = 3;
                    global_index++;
                }
                else if (combinaciones_pasos[global_index] == 3){
                    combinaciones_pasos[global_index] = 4;
                    global_index++;
                }

                for (int i = global_index; i < delimitador; ++i){
                combinaciones_pasos[i] = 1;
                }

            }
        }

        // En dado caso que los contadores esten a ningún valor
        // de distancia:
        else if (((delimitador - global_index) == 0)){

            // Determinación de finalización de la ejecución:
            if ((combinaciones_pasos[global_index-1] == escalones)
                ){outer_loop = 1;}

            else if ((combinaciones_pasos[global_index-1] == 4)
                ){outer_loop = 1;}

            else if ((combinaciones_pasos[global_index-2] == 4)
            ){outer_loop = 1;}

            // Si el codigo no se finaliza, determinacion de la posicion
            // del 'global_index' para realizar el siguente cambio de
            // numero:
             else {
                    int while_condition = 0; int i_while = 0;
                    while (while_condition != 1)
                    {
                        if ((combinaciones_pasos[global_index-2] ==
                             combinaciones_pasos[i_while]) &&
                            (combinaciones_pasos[i_while] != 4)){
                            while_condition = 1;
                        }
                        i_while++;
                    }
                    global_index = i_while-1;

                    if (combinaciones_pasos[global_index] == 1){
                        combinaciones_pasos[global_index] = 2;
                        global_index++;
                    }
                    else if (combinaciones_pasos[global_index] == 2){
                        combinaciones_pasos[global_index] = 3;
                        global_index++;
                    }
                    else if (combinaciones_pasos[global_index] == 3){
                        combinaciones_pasos[global_index] = 4;
                        global_index++;
                    }

                    for (int i = global_index; i < delimitador; ++i){
                    combinaciones_pasos[i] = 1;
                    }
                }
        }
        
    } while (outer_loop != 1);

}

int main(int argc, char *argv[]){

    // Con la variable argc se da el manejo de la cantidad de
    // Argumentos nesesarios:
    if (argc < 2){
        printf(
            "Hay menos argumentos de los nesesarios.\n"
            "Solo se ocupa uno.\n"
        );
        exit(0);
    }

    else if (argc > 2){
        printf(
            "Hay mas argumentos de los nesesarios.\n"
            "Solo se ocupa uno.\n"
        );
        exit(0);

    }
    else {

        int combinaciones_pasos[150];
        int lista_pasos[150];
        int escalones;
        escalones = atoi(argv[1]); 

        // con este if se da el manejo de la cantidad de pasos
        if (escalones == 0){
            printf(
                "No se permiten cero escalones.\n"
                "Solo se permiten numeros enteros positivos.\n"
            );
            exit(0);
        }
        else if (escalones < 0){
            printf(
                "No se permiten escalones negativos.\n"
                "Solo se permiten numeros enteros positivos.\n"
            );
            exit(0);
        }
        else if (atoi(argv[1]) != atof(argv[1])){
            printf(
                "No se permiten numeros flotantes.\n"
                "Solo se permiten numeros enteros positivos.\n"
            );
            exit(0);
        }
        else {
            for (int indice1 = 0; indice1 < escalones; indice1++){
            combinaciones_pasos[indice1] = 1;
            }

            gen_combinaciones(combinaciones_pasos,
                        escalones);

            return 0;
        }
    }
}