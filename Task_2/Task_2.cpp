#include <iostream>
#include <cmath>

double countN() {
    double N = 0;
    double dn = 0;
    int n = 1;
    do {
        dn = 1 / pow(2, n) + 1 / pow(3, n);
        N = N + dn;
        ++n;
    } while (dn >= 0.001);
    return N;
}

void intro() {
    std::cout << "Задание 2. Выполнил Колесников Антон Сергеевич" << std::endl;
    std::cout << "Введите 1 чтобы найти сумму ряда с точностью ε=10^-3, общий член которого dn = 1/2^n + 1/3^n" << std::endl;
    std::cout << "Введите 0 чтобы выйти" << std::endl;
}

int main() {
    int s = 0;
    intro();
    while(true) {
        std::cin >> s; 
    if (s == 1) {
        std::cout << "N = " << countN() << std::endl;
    }
    if (s == 0) {
        break;
    }
    }
    return 0;
}