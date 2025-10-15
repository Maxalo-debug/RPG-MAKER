// Proposito: Facilitar certas transformações

#include "hp.h"



bool setMaxHP(hptype new_max_hp, Hp* characther_hp){

    if (new_max_hp < 1)
    {
        return false;
    }

    characther_hp->maxHP = new_max_hp;

    if (characther_hp->currentHP > characther_hp->maxHP)
        characther_hp->currentHP = characther_hp->maxHP;
}


// Essa função vai pegar o dano de ataque recebido, fazer uma redução de acordo com a armadura
// e diminuir da vida o dano recebido. Em termos simples, a cada 16.6 de armadura dobra sua vida.
// mecanica encontrada no dota 2. 

void takeDamage(hptype damage_received,int8_t armor, Hp* person){
        
    float trueDamage = damage_reduced_after_armor(armor, damage_received);
    if(trueDamage > person->currentHP) {
        person->currentHP = 0;
        return;
    }

    person->currentHP -= trueDamage;   

}

void heal(hptype healing, Hp* person){
    
    if(healing > (person->maxHP - person->currentHP)){
        person->currentHP = person->maxHP;
        return;
    }
    person->currentHP += healing;

}

float damage_reduced_after_armor(int8_t armor, hptype damage_received){

    float damageMultplier = 1 - ((0.06 * armor) / (1 + 0.06 * armor));
    
    float new_damage_received = (float)damage_received * damageMultplier; 

    return new_damage_received;
}



