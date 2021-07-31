import random, math

###交戦形態#################################################################################################
def engagement_form_func(): #used
    random_number = list(range(1, 5))
    w = [9, 6, 3, 2]
    formation = random.choices(random_number, weights = w)
    for i in formation:
        form = i
    return form

###キャップ前補正############################################################################################
def correction_before_cap_func(engagement_form, attack_formation, damaged_condition, attack_mode):
    if engagement_form == 1: #used
        engagement_form_correction = 1
    elif engagement_form == 2:
        engagement_form_correction = 0.8
    elif engagement_form == 3:
        engagement_form_correction = 1.2
    elif engagement_form == 4:
        engagement_form_correction = 0.6
    
    if attack_formation == "1":
        attack_formation_fire = 1
        attack_formation_torpedo = 1
    elif attack_formation == "2":
        attack_formation_fire = 0.8
        attack_formation_torpedo = 0.8
    elif attack_formation == "3":
        attack_formation_fire = 0.7
        attack_formation_torpedo = 0.7
    elif attack_formation == "4":
        attack_formation_fire = 0.6
        attack_formation_torpedo = 0.6
    elif attack_formation == "5":
        attack_formation_fire = 0.6
        attack_formation_torpedo = 0.6
        
    if damaged_condition == "1":
        damaged_condition_correction = 1
    elif damaged_condition == "2":
        damaged_condition_correction = 0.7
    elif damaged_condition == "3":
        damaged_condition_correction = 0.4
        
    if attack_mode == "1":
        correction = engagement_form_correction * attack_formation_fire * damaged_condition_correction
    elif attack_mode == "2":
        correction = engagement_form_correction * attack_formation_torpedo * damaged_condition_correction
    return correction

###基本攻撃力###############################################################################################
def basic_attackpower_func(firepower):
    return int(firepower) + 5

###キャップ前攻撃力#########################################################################################
def attackpower_before_cap_func(basic_attackpower, correction_before_cap):
    return basic_attackpower * correction_before_cap

###キャップ後攻撃力#########################################################################################
def attackpower_after_cap_func(attackpower_before_cap, attack_mode):
    if attack_mode == "1":
        if attackpower_before_cap >= 220:
            attackpower_after_cap = 220 + math.sqrt(attackpower_before_cap - 220)
        elif attackpower_before_cap <= 220:
            attackpower_after_cap = attackpower_before_cap
    elif attack_mode == "2":
        if attackpower_before_cap >= 180:
            attackpower_after_cap = 180 + math.sqrt(attackpower_before_cap - 180)
        elif attackpower_before_cap <= 180:
            attackpower_after_cap = attackpower_before_cap
    return attackpower_after_cap

###最終攻撃力##############################################################################################
def final_attackpower_func(attackpower_after_cap):
    return math.floor(attackpower_after_cap)

###防御力##################################################################################################
def vitality_func(armor):
    armor = int(armor)
    vital = 0.7 * armor + 0.6 * random.randint(0, armor)
    return vital

###ダメージ################################################################################################
def damage_func(final_attackpower, vital, correction_amount_of_ammo):
    return math.floor((final_attackpower - vital) * correction_amount_of_ammo)

###割合ダメージ(カスダメ)###################################################################################
def percentage_damage_func(now_hp):
    return math.floor(now_hp * 0.06 + random.randint(0, now_hp) * 0.08)

###弾薬量補正##############################################################################################
def ammo_func(now_ammo, max_ammo):
    left_ammo_ratio = now_ammo / max_ammo * 100
    return left_ammo_ratio / 50
