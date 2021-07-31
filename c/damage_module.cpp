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
	
}
/*
float
*/ 
