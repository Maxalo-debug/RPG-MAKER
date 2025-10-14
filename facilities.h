// Proposito: Facilitar certas transformações
#pragma once
#include "hp.h"
typedef unsigned short hptype;

bool setMaxHP(hptype new_max_hp, Hp* characther_hp){

    if (new_max_hp < 1)
    {
        return false;
    }

    characther_hp->maxHP = new_max_hp;

    if (characther_hp->currentHP > characther_hp->maxHP)
        characther_hp->currentHP = characther_hp->maxHP;
}

void shield();


void takeDamage(hptype damage_received, Hp* person){
    if(damage_received > person->currentHP) {
        person->currentHP = 0;
        return;
    }

    person->currentHP -= damage_received;   

}

void heal(hptype healing, Hp* person){
    
    if(healing > (person->maxHP - person->currentHP)){
        person->currentHP = person->maxHP;
        return;
    }
    person->currentHP += healing;

}

