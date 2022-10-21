#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

//交戦形態
int engagement_form_func(){
	int numbers_list[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4};
	int r, form;
	srand((unsigned int)time(NULL));
	r = rand() % 19 + 0;
	
	return numbers_list[r];
}

//キャップ前補正
float correction_before_cap_func(int engagement_form, int attack_formation, int damaged_condition, int attack_mode){
	float engagement_form_correction;
    if (engagement_form == 1){
        engagement_form_correction = 1.0;
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
        attack_formation_firepower = 0.8;
        attack_formation_torpedo = 0.8;
    }else if (attack_formation == 3){
        attack_formation_firepower = 0.7;
        attack_formation_torpedo = 0.7;
    }else if (attack_formation == 4){
        attack_formation_firepower = 0.6;
        attack_formation_torpedo = 0.6;
    }else if (attack_formation == 5){
        attack_formation_firepower = 0.6;
        attack_formation_torpedo = 0.6;
    }
	
	float damaged_condition_correction;
    if (damaged_condition == 1){
        damaged_condition_correction = 1.0;
    }else if (damaged_condition == 2){
        damaged_condition_correction = 0.7;
    }else if (damaged_condition == 3){
        damaged_condition_correction = 0.4;
    }

	float correction;
    if (attack_mode == 1){
        correction = engagement_form_correction * attack_formation_firepower * damaged_condition_correction;
    }else if (attack_mode == 2){
        correction = engagement_form_correction * attack_formation_torpedo * damaged_condition_correction;
    }

    return correction;
}

//基本攻撃力
float basic_attackpower_func(int firepower){
    return float(firepower) + 5.0;
}

//キャップ前攻撃力
float attackpower_before_cap_func(float basic_attackpower, float correction_before_cap){
    return basic_attackpower * correction_before_cap;
}

//キャップ後攻撃力
float attackpower_after_cap_func(float attackpower_before_cap, int attack_mode){
	float attackpower_after_cap;
	if (attack_mode == 1){
		if (attackpower_before_cap >= 220){
			attackpower_after_cap = 220 + sqrt(attackpower_before_cap - 220);
		}else if (attackpower_before_cap < 220){
			attackpower_after_cap = attackpower_before_cap;
		}
	}else if (attack_mode == 2){
		if (attackpower_before_cap >= 180){
			attackpower_after_cap = 180 + sqrt(attackpower_before_cap - 180);
		}else if (attackpower_before_cap < 180){
			attackpower_after_cap = attackpower_before_cap;
		}
	}
	
	return attackpower_after_cap;
	
}

//最終攻撃力
float final_attackpower_func(float attackpower_after_cap){
	return floor(attackpower_after_cap);
}

//防御力
float vitality_func(int armor){
	return 0.7 * armor + 0.6 * (rand() % (armor-1) + 0);
}

//ダメージ
int damage_func(float final_attackpower, float vitality, float correction_amount_of_ammo){
	int damage;
	damage = floor((final_attackpower - vitality) * correction_amount_of_ammo);
	return damage;
}

//割合ダメージ(カスダメ)
float percentage_damage_func(int now_hp){
	int percentage_damage;
	percentage_damage = floor(now_hp * 0.06 + (rand() % (now_hp-1) + 0) * 0.08);
	return percentage_damage;
}