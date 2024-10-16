#include "mob.h"

Mob::Mob(int startX, int startY, char mobSymbol, bool isHostile)
    : x(startX), y(startY), symbol(mobSymbol), hostile(isHostile) {}

void Mob::move(int dx, int dy) {
    x += dx;
    y += dy;
}

bool Mob::isHostile() const {
    return hostile;
}

char Mob::getSymbol() const {
    return symbol;
}
