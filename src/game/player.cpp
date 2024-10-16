#include "player.h"

Player::Player() : x(0), y(0), symbol('@'), state("idle"), name("testo") {}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;

    if (dx != 0 || dy != 0) {
        state = "walking";
    }
}

void Player::setSymbol(char s) {
    symbol = s;
}

void Player::setName(const std::string& n) {
    name = n;
}

void Player::setState(const std::string& newState) {
    state = newState;
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

char Player::getSymbol() const {
    return symbol;
}

std::string Player::getName() const {
    return name;
}

