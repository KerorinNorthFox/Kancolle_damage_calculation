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

engagement_form = kd.engagement_form_func()

correction_before_cap = kd.correction_before_cap_func(engagement_form, attack_formation, damaged_condition, attack_mode)
print(f"\n>>キャップ前補正:{correction_before_cap}")

basic_attackpower = kd.basic_attackpower_func(firepower)
print(f">>基本攻撃力:{basic_attackpower}")

attackpower_before_cap = kd.attackpower_before_cap_func(basic_attackpower, correction_before_cap)
print(f">>キャップ前攻撃力:{attackpower_before_cap}")

attackpower_after_cap = kd.attackpower_after_cap_func(attackpower_before_cap, attack_mode)
print(f">>キャップ後攻撃力:{attackpower_after_cap}")

final_attackpower = kd.final_attackpower_func(attackpower_after_cap)
print(f">>最終攻撃力:{final_attackpower}")

vitality = kd.vitality_func(enemy_armor)
print(f">>敵の装甲値:{vitality}")

damage = kd.damage_func(final_attackpower, vitality, 1)
if damage <= 0:
    percentage_damage = kd.percentage_damage_func(int(now_hp))
    if percentage_damage <= 0:
        print("\n>>結果:miss")
    else:
        print("\n>>カスダメ")
        print(f">>結果:{percentage_damage}")
else:
    print(f"\n>>結果:{damage}")
