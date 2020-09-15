/*
 *  Actividad 5
 *  Programación avanzada
 * 
 *  Daniel Roa
 *  A01021960
 */ 
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void manual();

int main(int argc, char * const *argv){
    
    char * numberVal = NULL;
    int dat, updateValue = 0, man = 0;
    pid_t pid;

    while ((dat = getopt(argc, argv, "n:m")) != -1)
    {
        switch (dat)
        {
        case 'n':
            numberVal = optarg;

            if(isdigit(*numberVal) > 0){
                updateValue = atoi(numberVal);

                printf("Se van a crear %d procesos\n\n", updateValue);
            }else{
                printf("Inserte un valor numerico valido.\n");
            }

            break;
        
        case 'm':
            man = 1;
            break;

        case '?':
            if (optopt == 'n'){
                fprintf(stderr, "Inserte un argumento a la opción -%c\n", optopt);
            }
            else if (isprint(optopt)){
                fprintf(stderr, "La opción -%c no es válida.\n", optopt);
            }else{
                fprintf(stderr, "Opción desconocida '\\x%x'.", optopt);
            }

            break;

        default:
            abort();
        }   
    }
    
    if(man == 1){
        manual();
    }else

    return 0;
}

void manual(){
    printf("Usage: ./a.out <options> <numeric value>\n");
    printf("The possible options are:\n");
    printf("-n\t\tAllows user to input a number in the numeric value field\n-m\t\tAllows the user to view this manual.\n");
}