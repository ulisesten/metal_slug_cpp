#include <iostream>

#include "personages/soldier_class.hpp"
#include "personages/player_class.hpp"

int main(){

    Player player("Marco");
    Soldier soldier("Gun Soldier");

    KnifeAttack knife;
    GunAttack gunAttack;
    
    player.setAttackBehavior(&knife);
    soldier.setAttackBehavior(&gunAttack);

    soldier.attack(&player);
    player.attack(&soldier);

    return 0;
}