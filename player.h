#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <string>

class Player {
    int x, y; // Позиция игрока
    char symbol; // Модель игрока
    std::string name = "test"; // Ник
    std::string state; // Состояние

public:
    Player();
    void move(int dx, int dy);
    void setSymbol(char s);
    void setName(const std::string& n);
    void setState(const std::string& newState);
    int getX() const;
    int getY() const;
    char getSymbol() const;

    std::string getName() const;
};


#endif //PLAYER_H
