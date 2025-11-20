#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "game.h"
#include "menu.h"
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 4096

void run_game(){
    char buffer[BUFFER_SIZE];
    int numero = 0;
    enum jogo_estado estado = PLAY;

    show_text_menu();
    
    while(estado == PLAY)
    {
        menu_user_process(&numero, buffer, &estado);
    }
        
}

void menu_user_process(int* numero, char buffer[], enum jogo_estado* estado){
        
        printf(">");
        fgets(buffer, BUFFER_SIZE, stdin);

        int value = parse_int(buffer, numero);
        
        if(value == false){
            printf("Só número, por favor.\n");
            return;
        }

        switch(*numero){
            case 1: start(); break;
            case 2: load();  break;
            case 3: *estado = QUIT; break;
            default: printf("Só numeros entre 1 a 3, por favor.\n");
        }        

    }

void process_user_input(int* estado){    
    

}


bool parse_int(char* string, int* interger){
    int i = 0;
    int length = strlen(string);

    while(isspace(string[i])){i++;}

    if(length == i ){ return false;}
    char buffer[BUFFER_SIZE]; 

    if(string[i] == '-'){return false;}
    int integer_chars = 0;

    if(isdigit(string[i])){
        *interger = atoi(string);
        i++;
    }else{
        return false;
    }
    
    return true;

}