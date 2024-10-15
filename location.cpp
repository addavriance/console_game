#include "location.h"
#include "utils.h"
#include <iostream>
#include <iterator>
#include <random>

Location::Location(int w, int h) : width(w), height(h) {
    tiles.resize(width, std::vector<Tile>(height));

    char textures[][1][3] = {
        {{'/', ',', '/'}},
        {{'_', '.', '.'}}
    };

    std::random_device rd;
    std::mt19937 g(rd());

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int textures_size = std::end(textures) - std::begin(textures);
            int randomIndex = randint(0, textures_size-1);
            char (*texture)[3] = textures[randomIndex];

            std::shuffle(&texture[0][0], &texture[0][3], g);

            tiles[y][x].setTexture(textures[randomIndex]);
        }
    }
}

void Location::draw(int screenWidth, int screenHeight, const Player& player) const {
    for (int y = 0; y < screenHeight; y++) {
        for (int x = 1; x < screenWidth; x+=std::vector<Tile>::value_type::WIDTH) {
            if (x-1 <= player.getX() && player.getX() <= x+1 && y == player.getY()) {
                tiles[x][y].draw(player.getX(), player.getY(), player);
            } else {
                tiles[x][y].draw(0, 0, std::nullopt);
            }
        }
        std::cout << std::endl;
    }


    std::cout << "\033[" << player.getY() << ";" << player.getX()-2 << "H";
    std::cout << "[ " << player.getName() << " ]";
    std::cout << "\033[" << 24/2 << ";" << 81 << "H";
    std::cout.flush();

}
