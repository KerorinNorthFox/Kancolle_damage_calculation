#include <stdio.h>
#include "damage_func.cpp"

int main(void)
{
	int attack_formation, damaged_condition, attack_mode, firepower, enemy_armor, now_hp, loopnumber;
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
	printf("\n>>繰り返す回数:");
	scanf("%d", &loopnumber);
	
	float correction_before_cap[];
	float basic_attackpower[];
	float attackpower_before_cap[];
	float attackpower_after_cap[];
	float final_attackpower[];
	float vitality[];
	float results_list[];
	int prob_hit, prob_throught_the_armor, prob_percentage_damage, prob_miss, miss_counter = 0;
	
	printf("\n######################################################");
	
	for(i=0; i<loopnumber; i++){
		int engagement_form;
		engagement_form = engagement_form_func();
		#printf("%d", engagement_form);

		correction_before_cap[i] = correction_before_cap_func(engagement_form, attack_formation, damaged_condition, attack_mode);
		#printf("\n>>キャップ前補正:%f", correction_before_cap[i]);

		basic_attackpower[i] = basic_attackpower(firepower);
		#printf("\n>>基本攻撃力:%f", basic_attackpower[i]);

		attackpower_before_cap[i] = attackpower_before_cap_func(basic_attackpower[i], correction_before_cap[i]);
		#printf("\n>>キャップ前攻撃力:%f", attackpower_before_cap[i]);
		
		attackpower_after_cap[i] = attackpower_after_cap_func(attackpower_before_cap[i]);
		#printf("\n>>キャップ後攻撃力:%f", attackpower_after_cap[i]);
		
		final_attackpower[i] = final_attackpower_func(attackpower_after_cap[i]);
		#printf("\n>>最終攻撃力:%f", final_attackpower[i]);
}
