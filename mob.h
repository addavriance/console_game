#ifndef MOB_H
#define MOB_H

#pragma once
#include <string>

class Mob {
private:
    int x, y;
    char symbol;
    bool hostile;

public:
    Mob(int startX, int startY, char mobSymbol, bool isHostile);
    void move(int dx, int dy);
    bool isHostile() const;
    char getSymbol() const;
};

#endif //MOB_H
