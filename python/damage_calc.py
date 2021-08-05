import Kancolle_damage_func as kd

attack_formation = input('''>>陣形選択
#1:単縦陣
#2:複縦陣
#3:輪形陣
#4:梯形陣
#5:単横陣
:''')
damaged_condition = input('''\n>>艦状態
#1:小破以下
#2:中破
#3:大破
:''')
attack_mode = input('''\n>>砲撃か雷撃
#1:砲撃
#2:雷撃
:''')

firepower = input("\n>>火力値(雷装値):")
enemy_armor = input("\n>>敵の装甲値:")
now_hp = input("\n>>現在の敵HP:")

loopnumber = input("\n>>繰り返す回数:")

##################################################################

correction_before_cap = []
basic_attackpower = []
attackpower_before_cap = []
attackpower_after_cap = []
final_attackpower = []
vitality = []
results_list = []
prob_hit = 0
prob_through_the_armor = 0
prob_percentage_damage = 0
prob_miss = 0
miss_counter = 0

for i in range(0, int(loopnumber)):
    engagement_form = kd.engagement_form_func()

    correction_before_cap.append(kd.correction_before_cap_func(engagement_form, attack_formation, damaged_condition, attack_mode))
    #print(f"\n>>キャップ前補正:{correction_before_cap[i]}")

    basic_attackpower.append(kd.basic_attackpower_func(firepower))
    #print(f">>基本攻撃力:{basic_attackpower[i]}")

    attackpower_before_cap.append(kd.attackpower_before_cap_func(basic_attackpower[i], correction_before_cap[i]))
    #print(f">>キャップ前攻撃力:{attackpower_before_cap[i]}")

    attackpower_after_cap.append(kd.attackpower_after_cap_func(attackpower_before_cap[i], attack_mode))
    #print(f">>キャップ後攻撃力:{attackpower_after_cap}")

    final_attackpower.append(kd.final_attackpower_func(attackpower_after_cap[i]))
    #print(f">>最終攻撃力:{final_attackpower}")

    vitality.append(kd.vitality_func(enemy_armor))
    #print(f">>敵の防御力:{vitality}")

    damage = kd.damage_func(final_attackpower[i], vitality[i], 1)
    if damage <= 0:
        percentage_damage = kd.percentage_damage_func(int(now_hp))
        if percentage_damage <= 0:
            results_list.append("miss")
            prob_miss += 100
            miss_counter += 1
            #print("\n>>結果:miss")
        else:
            results_list.append(str(percentage_damage) + "(カスダメ)")
            prob_percentage_damage += 100
            prob_hit += 100
            #print("\n>>カスダメ")
            #print(f">>結果:{percentage_damage}")
    else:
        results_list.append(damage)
        prob_through_the_armor += 100
        prob_hit += 100
        #print(f"\n>>結果:{damage}")
    
############################################################################
    
    print(f"\n>>{i+1}回目のキャップ前補正:{correction_before_cap[i]}")
    print(f">>{i+1}回目の基本攻撃力:{basic_attackpower[i]}")
    print(f">>{i+1}回目のキャップ前攻撃力:{attackpower_before_cap[i]}")
    print(f">>{i+1}回目のキャップ後攻撃力:{attackpower_after_cap[i]}")
    print(f">>{i+1}回目の最終攻撃力:{final_attackpower[i]}")
    print(f">>{i+1}回目の敵の防御力:{vitality[i]}")
    print(f">>{i+1}回目の結果:{results_list[i]}")

    
