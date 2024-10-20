#include <cmath>
#include <iostream>
#include <string>
#include <vector>

const int Q = 1000000; // Точность до 6 знаков после запятой

// Структура для представления числа с целой и дробной частью
struct Number {
    int whole;   // Целая часть
    int fraction; // Числитель дробной части (делим на Q)
    
    Number(double value = 0) {
        whole = (int)value; // Выделяем целую часть
        fraction = (int)(round((value - whole) * Q)); // Выделяем дробную часть
    }

    // Сложение двух чисел
    Number operator+(const Number& other) const {
        Number result(0);
        result.whole = whole + other.whole;
        result.fraction = fraction + other.fraction;

        // Если сумма дробной части больше или равна Q, переносим в целую часть
        if (abs(result.fraction) >= Q) {
            result.whole += result.fraction / Q;
            result.fraction %= Q;
        }
        return result;
    }

    // Вычитание двух чисел
    Number operator-(const Number& other) const {
        Number result(0);
        result.whole = whole - other.whole;
        result.fraction = fraction - other.fraction;

        // Если дробная часть отрицательна или больше Q, корректируем
        if (result.fraction < 0) {
            result.whole -= 1;
            result.fraction += Q;
        } else if (result.fraction >= Q) {
            result.whole += 1;
            result.fraction -= Q;
        }
        return result;
    }

    // Умножение на целое число
    Number operator*(int multiplier) const {
        Number result(0);
        result.whole = whole * multiplier;
        result.fraction = fraction * multiplier;

        // Переносим из дробной части в целую, если дробь больше Q
        result.whole += result.fraction / Q;
        result.fraction %= Q;
        return result;
    }

    // Вывод числа
    void print() const {
        std::cout << whole << "." << abs(fraction) << std::endl;
    }
};

// Функция для разделения вещественного числа на целую и дробную части
Number divideNumber(const std::string& input) {
    double value = std::stod(input); // Преобразуем строку в вещественное число
    return Number(value);            // Возвращаем структуру Number
}

void intro() {
    std::cout << "=== Задание 8. Выполнил Колесников Антон Сергеевич ==="
              << std::endl;
    std::cout << "Эта программа считает выражение a0 - 2 * a1 + 4 * a2 - 8 * a3 "
                 "+ ... + 2^(n-1) * (-1)^(n-1) * an-1 без использования "
                 "вещественной арифметики"
              << std::endl;
    std::cout << "*Введите 0 чтобы выйти*\n"
              << std::endl;
}

int correctInputn() {
    std::cout << "Введите число n" << std::endl;
    int x = 0;
    bool error = false;
    bool incorrectInput = false;
    do {
        error = false;
        incorrectInput = false;
        std::cin >> x;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Некорректный ввод. Введите число n" << std::endl;
            std::cin.ignore(1000000, '\n');
            error = true;
            incorrectInput = true;
        }
        if ((x >= 1 || x == 0) && error == false) {
            incorrectInput = false;
        } else {
            incorrectInput = true;
        }
    } while (incorrectInput);
    return x;
}

std::string correctInputa(int index) {
    std::cout << "Введите число a" << index << std::endl;
    std::string x = "";
    bool error = false;
    bool incorrectInput = false;
    do {
        error = false;
        incorrectInput = false;
        std::cin >> x;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Некорректный ввод. Введите число a" << index << std::endl;
            std::cin.ignore(1000000, '\n');
            error = true;
            incorrectInput = true;
        }
    } while (incorrectInput);
    return x;
}

int main() {
    intro();
    
    while (true) {
        int n = correctInputn();
        if (n == 0) {
            break;
        }
        std::vector<Number> a;

        for (int i = 0; i < n; ++i) {
            std::string aStr = correctInputa(i);
            if (aStr == "0") {
                return 0;
            }
            a.push_back(divideNumber(aStr));
        }

        Number result = 0;
        int power_of_two = 1;


        for (int i = 0; i < n; ++i) {
            
            int sign = (i % 2 == 0) ? 1 : -1;

            result = result + a[i] * (sign * power_of_two);

            power_of_two *= 2;
        }

        std::cout << "Результат: ";
        result.print();
    }

    return 0;
}