#ifndef LOCATAION_H
#define LOCATAION_H

#pragma once
#include <vector>
#include "tile.h"
#include "player.h"

class Location {
    int width, height;
    std::vector<std::vector<Tile>> tiles;

public:
    Location(int w, int h);
    void draw(int screenWidth, int screenHeight, const Player& player) const;
};


#endif //LOCATAION_H
