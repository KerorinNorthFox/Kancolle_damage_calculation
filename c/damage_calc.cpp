#include <stdio.h>
#include "damage_func.cpp"

int main(void)
{
	int attack_formation, damaged_condition, attack_mode, firepower, enemy_armor, now_hp;
	printf(">>陣形選択/n#1:単縦陣\n#2:複縦陣\n#3:輪形陣\n#4:梯形陣\n#5:単横陣\n:");
	scanf("%d", &attack_formation);
	printf("\n>>艦状態\n#1:小破以下\n#2:中破\n#3:大破\n:");
	scanf("%d", &damaged_condition);
	printf("\n>>砲撃か雷撃\n#1:砲撃\n#2:雷撃\n:");
	scanf("%d", &attack_mode);
	printf("\n>>火力値(雷装値):");
	scanf("%d", &firepower);
	printf("\n>>敵の装甲値:");
	scanf("%d", &enemy_armor);
	printf("\n>>現在の敵HP:");
	scanf("%d", &now_hp);
	
	int engagement_form;
	engagement_form = engagement_form_func();
	printf("%d", engagement_form);
	
	float correction_before_cap;
	correction_before_cap = correction_before_cap_func(engagement_form, attack_formation, damaged_condition, attack_mode);
	printf("\n>>キャップ前補正:%f", correction_before_cap);
	/*
	int basic_attackpower;
	basic_attackpower = basic_attackpower(firepower);
	printf("\n>>基本攻撃力:%d", basic_attackpower);
	
	float attackpower_before_cap;
	attackpower_before_cap = attackpower_before_cap_func(basic_attackpower, correction_before_cap);
	printf("\n>>キャップ前攻撃力:%f", attackpower_before_cap);
	*/
}
