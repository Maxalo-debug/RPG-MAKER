#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef unsigned short hptype;
typedef uint8_t stattype;

typedef struct{
    hptype shieldHP;
    hptype currentHP;
    hptype maxHP;    

}Hp;


bool setMaxHP(hptype, Hp*);
void takeDamage(hptype, int8_t, Hp*);
void heal(hptype, Hp*);
int damage_reduced_after_armor(int8_t armor, hptype damage_received);