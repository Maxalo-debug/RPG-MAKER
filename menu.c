#include <stdio.h>
#include "menu.h"



void show_text_menu(){
    printf("MAIN MENU\n\n");
    printf("1 - START GAME\n");
    printf("2 - LOAD GAME\n");
    printf("3 - EXIT\n");

}

void start(){
    printf("funcionou start\n");
    char* history[100];
    struct character_details* user = malloc(sizeof(struct character_details));
    if(user == NULL){
        perror("Erro de alocar mémoria");
        exit(EXIT_FAILURE);
    }
    profileScreen(user); 
    
    
}
void load(){
    printf("funcionou load");
}

void loadScreen(){
    
}

void profileScreen(struct character_details* user){
    
    char* nome = getInput("Nome do personagem:");
    char* race = getInput("Raça:");
    strcpy(user->name, nome);
    strcpy(user->race, race);

    free(nome);
    free(race);
    
    //char* data = getCurrentDate();
    //printf("Data de criação: %s\n", data);
}
/*

struct character_details* getCharacter_profile(char* nome, char* race){
    struct character_details* temp = malloc(sizeof(struct character_details)); 

    if(temp == NULL){
        perror("Erro de alocar mémoria");
        exit(EXIT_FAILURE);
    }
    strcpy(temp->name, nome);
    strcpy(temp->race, race);
    return temp;
     
}
*/
char* getInput(char* prompt){
    char* nome = malloc(sizeof(char) * 50);
    printf("%s", prompt);
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    return nome;
}

char* getCurrentDate(){

    time_t currentDate;
    time(&currentDate);
    return ctime(&currentDate);

}

char** dateParser(int* number){

    char** dataList = malloc(sizeof(char*));

    char* token;
    char* original = getCurrentDate(), *copy;
    copy = strdup(original);
    token = strtok_r(copy, " ", &copy);    
    int i = 0;
    while(token != NULL){
        dataList[i] = strdup(token);
        i++;
        char** temp = realloc(dataList, sizeof(char*) * (i + 1));
        if(temp != NULL){
            dataList = temp;
        }else{
            printf("Não foi bem sucedido a alocação");
        }

        token = strtok_r(NULL, " ", &copy);
    }
    *number = i;

    
    return dataList;
}


void dataDisplay(char** dataList){
    char* data;
    char* lista[12] = {"Jan", "Fev", "Mar", "Apr", "May", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dec"};
    char* meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    for(int i = 0; i < 12; i++)
    {
        if(strcmp(lista[i], dataList[1]) == 0){
            data = strdup(meses[i]);
        }
    }
     
    printf("%s de %s %s",dataList[2], data, dataList[4]); 

}