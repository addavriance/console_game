#include "tile.h"
#include <iostream>

Tile::Tile() : walkable(true) {
    texture[0][0] = '.';
    texture[0][1] = '.';
    texture[0][2] = '.';
}

void Tile::setTexture(char t[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            texture[i][j] = t[i][j];
        }
    }
}

char Tile::getTexture(int x_index, int y_index) const {
    return texture[y_index][x_index];
}

bool Tile::isWalkable() const {
    return walkable;
}

void Tile::draw(int x, int y, std::optional<Player> p) const {
    int player_index = p ? abs(x) % WIDTH : 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (p && player_index == j) {
                std::cout << p->getSymbol();
            } else {
                std::cout << texture[i][j];
            }
        }
    }

}

