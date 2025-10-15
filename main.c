#include <stdio.h>



int main(void){

    float damageMultplier = (0.06 * 60) / (1 + 0.06 * (-1 * 60));

    printf("%f", damageMultplier);





    return 0;
}