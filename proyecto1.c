#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
TAREAS:
    1. Desarrollar la idea del global index. 
    cualquier otra cosa de conmutacion hacerlo en la proxima unit test
    1.1 NOfunciona bien, tratar de acomodar diferente el global index
*/

int conmutador(int *list_pasos){



}

void gen_combinaciones(int *combinaciones_pasos,
                       int escalones){

    int delimitador, suma, global_index;
    delimitador = suma = global_index = 0;
    int outer_loop = 0;

    // for (int i = 0; i < escalones; i++){
    do
    {

        // Definir el delimitador aqui:
        delimitador = suma = 0;
        do{
            suma += combinaciones_pasos[delimitador];
            delimitador++;
        } while (suma != escalones);
        

        // Hacer el print en pantalla
        for (int j = 0; j < delimitador; j++){
            printf("%d,",combinaciones_pasos[j]);
        }
        
        printf("\n");


        // determinacion de la variable de proximo estado para cambiar posicion
        
        if ((delimitador - global_index) > 1){
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
        }
        
        else if ((delimitador - global_index == 1) &&
            (combinaciones_pasos[global_index-1] < 4)){

                // Find the match for gi-1
                int while_condition = 0; int i_while = 0;
                while (while_condition != 1)
                {
                    if (combinaciones_pasos[global_index-1] == combinaciones_pasos[i_while]){
                        while_condition = 1;
                    }
                    i_while++;
                }
                global_index = i_while - 1;

                if (combinaciones_pasos[global_index] == 1){
                    combinaciones_pasos[global_index] = 2;
                    global_index++;
                }
                else if (combinaciones_pasos[global_index] == 2){
                    combinaciones_pasos[global_index] = 3;
                    global_index++;
                }
                if (combinaciones_pasos[global_index] == 3){
                    combinaciones_pasos[global_index] = 4;
                    global_index++;
                }

                // combinaciones_pasos[global_index-1] += 1;

                for (int i = global_index; i < delimitador; i++){
                    combinaciones_pasos[i] = 1;
                }
            
        }
        // else if ((delimitador - global_index == 2) &&
        //          (combinaciones_pasos[global_index-1] < 4)){
            
        //     int while_condition = 0; int i = 0;
        //     while (while_condition != 1)
        //     {
        //         if (combinaciones_pasos[global_index-1] == combinaciones_pasos[i]){
        //             while_condition = 1;
        //         }
        //         i++;
        //     }


        // }
        
        else {
            outer_loop = 1;
        }

        // esto va adentro de los ifs
        // combinaciones_pasos[global_index] = lista_pasos[i];
        
    // }


    
        
    } while (outer_loop != 1);



    

}

int main(int argc, char *argv[]){

    int combinaciones_pasos[150];
    int lista_pasos[150];
    int escalones;
    escalones = atoi(argv[1]);


    if (escalones < 4){
        for (int i = 0; i < 4; i++){
            lista_pasos[i] = (i+1);
        }
    }
    else {
        for (int i = 0; i < escalones; i++){
            lista_pasos[i] = (i+1);
        }
        for (int i = 4; i < escalones; i++){
            lista_pasos[i] = 4;
        }

    }

    for (int indice1 = 0; indice1 < escalones; indice1++){
        combinaciones_pasos[indice1] = 1;
    }

    gen_combinaciones(combinaciones_pasos,
                      escalones);


    /*
    LO DE ABAJO ES UTILIZADO PARA VER SI FUNCIONA LA LISTA.
    */
    // for (int indice2 = 0; indice2 < delimitador; indice2++){
    //     printf(
    //         "%d,",
    //         combinaciones_pasos[indice2]
    //     );
    // }

    // printf("\n");


    return 0;
}