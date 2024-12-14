#include "application.h"
#include <limits>

void Application::run() {
    int command = 0;
    while (command != 6) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Ввести полином\n";
        std::cout << "2. Изменить коэффициент an\n";
        std::cout << "3. Изменить корень\n";
        std::cout << "4. Вычислить значение полинома\n";
        std::cout << "5. Вывести полином\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите команду: ";

        while (!(std::cin >> command)) {
            std::cout << "Некорректный ввод. Попробуйте снова: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (command) {
        case 1: {
            Complex an;
            size_t degree;
            std::cout << "Введите коэффициент an:\n";
            while (!(std::cin >> an)) {
                std::cout << "Некорректный ввод. Попробуйте снова:\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Введите степень полинома (количество корней): ";
            while (!(std::cin >> degree) || degree == 0) {
                std::cout << "Некорректный ввод. Пожалуйста, введите положительное число:\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            Array roots(degree);
            std::cout << "Введите корни:\n";
            std::cin >> roots;
            polynom = Polynom(an, roots);  // Инициализация полинома
            std::cout << "Полином успешно введён!\n";
            break;
        }
        case 2: {
            Complex newAn;
            std::cout << "Введите новый коэффициент an:\n";
            while (!(std::cin >> newAn)) {
                std::cout << "Некорректный ввод. Попробуйте снова:\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            polynom.setAn(newAn);
            std::cout << "Коэффициент an успешно изменён!\n";
            break;
        }
        case 3: {
            if (polynom.getDegree() == 0) {
                std::cout << "Полином не задан. Сначала введите полином.\n";
                break;
            }

            size_t index;
            Complex newRoot;
            std::cout << "Введите индекс корня для изменения (0 - " << (polynom.getDegree() - 1) << "):\n";
            std::cin >> index;

            if (index >= polynom.getDegree()) {
                std::cout << "Некорректный индекс корня.\n";
                break;
            }
            std::cout << "Введите новое значение корня:\n";
            std::cin >> newRoot;
            polynom.setRoot(index, newRoot);
            std::cout << "Корень успешно изменён!\n";
            break;
        }
        case 4: {
            Complex x;
            std::cout << "Введите значение x для вычисления полинома:\n";
            std::cin >> x;
            Complex result = polynom.calculateAt(x);
            std::cout << "Значение полинома при x = " << x << " равно " << result << "\n";
            break;
        }
        case 5: {
            if (polynom.getDegree() == 0) {
                std::cout << "Полином не задан. Сначала введите полином.\n";
                break;
            }

            int form;
            std::cout << "Выберите форму вывода (1 или 2): ";
            std::cin >> form;
            polynom.print(form == 1);
            break;
        }
        case 6:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректная команда.\n";
            break;
        }
    }
}
