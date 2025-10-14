#pragma once
#include "facilities.h"
#include <stdint.h>

typedef struct{
    hptype shieldHP;
    hptype currentHP;
    hptype maxHP;    

}Hp;


bool setMaxHP(hptype, Hp*);
void takeDamage(hptype, Hp*);
void heal();
void shield();