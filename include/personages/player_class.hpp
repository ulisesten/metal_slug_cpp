#pragma once

#include "soldier_class.hpp"

class Player: public Soldier {
    public:
        Player(const std::string name): Soldier(name) {}

        void networking();
};