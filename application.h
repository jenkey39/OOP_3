#ifndef APPLICATION_H
#define APPLICATION_H

#include "polynom.h"

class Application {
private:
    Polynom polynom;
public:
    Application() : polynom() {}  // Инициализация полинома по умолчанию
    void run();  // Запуск приложения
};

#endif // APPLICATION_H
