#include <iostream>
#include "Fraction.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Fraction f1(3, 4);
    Fraction f2(1, 2);

    std::cout << "f1 = ";
    f1.output();

    std::cout << "f2 = ";
    f2.output();

    std::cout << "f1 + f2 = ";
    (f1 + f2).output();

    std::cout << "f1 - f2 = ";
    (f1 - f2).output();

    std::cout << "f1 * f2 = ";
    (f1 * f2).output();

    std::cout << "f1 / f2 = ";
    (f1 / f2).output();

    std::cout << "f1 > f2: " << (f1 > f2) << std::endl;
    std::cout << "f1 < f2: " << (f1 < f2) << std::endl;
    std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2: " << (f1 != f2) << std::endl;
    try {
        Fraction f3;
        std::cout << "Введите дробь: " << std::endl;
        f3.input();
        std::cout << "Введенная дробь: ";
        f3.output();
        f3.toMixed();
        Fraction f3_rec = f3.reciprocal();
        std::cout << "Обратная дробь:";
        f3_rec.output();

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
