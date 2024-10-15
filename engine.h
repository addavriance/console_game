#ifndef ENGINE_H
#define ENGINE_H

#pragma once
#include <vector>
#include <thread>
#include <atomic>
#include "location.h"
#include "player.h"

class Engine {
    Player player;
    std::vector<Location> locations;
    int currentLocationIndex;
    int screenWidth;
    int screenHeight;

    std::thread renderThread;
    std::atomic<bool> isRunning;

    void renderLoop();

public:
    Engine(int width, int height);
    ~Engine();

    void run();
    void handleInput();
    void loadLocations();
    void switchLocation(int newLocationIndex);
};

#endif //ENGINE_H
