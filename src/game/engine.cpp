#include "engine.h"
#include <iostream>
#include <unistd.h>
#include <termios.h>

// Включение неблокирующего режима для консоли
void enableRawMode() {
    termios term{};
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Отключаем канонический режим и ввод с эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Возвращаем консоль в нормальный режим
void disableRawMode() {
    termios term{};
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // Включаем канонический режим и эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

Engine::Engine(int width, int height)
    : screenWidth(width), screenHeight(height), currentLocationIndex(0), isRunning(true) {
    loadLocations();
    enableRawMode();
}

Engine::~Engine() {
    isRunning = false;
    if (renderThread.joinable()) {
        renderThread.join();
    }
    disableRawMode();
}

void Engine::run() {
    // Запускаем поток для рендеринга
    renderThread = std::thread(&Engine::renderLoop, this);

    // Обрабатываем ввод в основном потоке
    while (isRunning) {
        handleInput();
        usleep(10000); // Небольшая задержка, чтобы снизить нагрузку на процессор
    }
}

void Engine::renderLoop() {
    while (isRunning) {
        // Логика отрисовки
        system("clear");
        locations[currentLocationIndex].draw(screenWidth, screenHeight, player);
        usleep(100000); // Перерисовываем каждые 100 мс (10 кадров в секунду)
    }
}

void Engine::handleInput() {

    char input = 0;
    if (read(STDIN_FILENO, &input, 1) == 1) {
        switch (input) {
            case 'w': player.move(0, -1); break;
            case 'a': player.move(-1, 0); break;
            case 's': player.move(0, 1); break;
            case 'd': player.move(1, 0); break;
            case 'q': isRunning = false; break; // Выход из игры
            // case 9: player. break;
            default: break;
        }
    }
}

void Engine::loadLocations() {
    locations.push_back(Location(1000, 1000));
}

void Engine::switchLocation(int newLocationIndex) {
    currentLocationIndex = newLocationIndex;
}
