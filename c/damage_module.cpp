#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int engagement_form_func(){
	int numbers_list[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4};
	int r, form;
	srand((unsigned int)time(NULL));
	r = rand() % 19 + 0;
	
	return numbers_list[r];
}

float correction_before_cap_func(int engagement_form, int attack_formation, int damaged_condition, int attack_mode);{
        float engagement_form_correction;
        if (engagement_form == 1){
            engagement_for_correction = 1.0;
        }else if (engagement_form == 2){
            engagement_form_correction = 0.8;
        }else if (engagement_form == 3){
            engagement_form_correction = 1.2;
        }else if (engagement_form == 4){
            engagement_form_correction = 0.6;
        }

        float attack_formation_firepower, attack_formation_torpedo;
        if (attack_formation == 1){
            attack_formation_firepower = 1.0;
            attack_formation_torpedo = 1.0;
        }else if (attack_formation == 2){
            attack_formation_firepower = 1;
            attack_formation_torpedo = 1;
        }else if (attack_formation == 3){
            attack_formation_correction = 1;
        }else if (attack_formation == 4){
            attack_formation_correction = 1;
        }else if (attack_formation == 5){
            attack_formation_correction = 1;
        }
}
/*
float
*/ 
