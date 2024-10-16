#ifndef TILE_H
#define TILE_H

#pragma once
#include <string>

#include "../game/player.h"

class Tile {
public:
    Tile();
    static constexpr int WIDTH = 3;
    static constexpr int HEIGHT = 1;

    void setTexture(char t[HEIGHT][WIDTH]);
    char getTexture(int x_index, int y_index) const;
    bool isWalkable() const;
    void draw(int x, int y, std::optional<Player> p) const;

private:
    char texture[HEIGHT][WIDTH]{};
    bool walkable;
};


#endif //TILE_H
