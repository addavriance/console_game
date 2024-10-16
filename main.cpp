#include "./src/game/engine.h"

int main() {
    // Инициализируем движок с размерами экрана, например 20x10 символов
    Engine engine(79, 23);

    // Запускаем игровой цикл
    engine.run();

    return 0;
}
