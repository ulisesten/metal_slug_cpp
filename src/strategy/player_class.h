#pragma once

#include "soldier_class.h"

class Player: public Soldier {
    public:
        Player(const std::string name): Soldier(name) {}

        void networking();
};