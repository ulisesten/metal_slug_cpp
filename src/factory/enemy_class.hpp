#pragma once

#include <iostream>
#include "soldier_class.hpp"

class Enemy {
    protected:
        std::string _name;

    public:
        Enemy(const std::string name): _name(name){}

};

class GunEnemy: Enemy {
    public:
       GunEnemy(const std::string name):Enemy(name){}
};