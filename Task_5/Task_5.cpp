#include <cmath>
#include <iostream>
#include <string>

double STEP(int parts) {
    double step = 1 / parts;
    return step;
}


void intro() {
  std::cout
      << "=== Задание 5. Выполнил Колесников Антон Сергеевич. Вариант 12 ==="
      << std::endl;
  std::cout << "Эта программа приближенно находит корень уравнения f(x) = 0 "
               "для функции sinh(x) + arccos(x) - 1.5 "
            << std::endl;
  std::cout << "*Введите 0 чтобы выйти в любой момент выполнения программы*\n"
            << std::endl;
}

int correctInputP() {
  std::cout << "Введите на сколько частей разделить область поиска корня" << std::endl;
  bool incorrect = false;
  bool error = false;
  int n = 0;
  do {
    incorrect = false;
    std::string str = "";
    std::cin >> str;
    try {
      n = std::stod(str);
    } catch (std::invalid_argument) {
      std::cout << "Некорректный ввод. Введите число частей " << std::endl;
      incorrect = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout << "Некорректный ввод. Введите число частей " << std::endl;
      incorrect = true;
      error = true;
    }
    if ((n < 0 || (n > 0 && n < 1)) && error == false) {
      std::cout << "Некорректный ввод. Введите число частей " << std::endl;
      incorrect = true;
    }
  } while (incorrect);
  return (int)n;
}

int main() {
  intro();
  while (true) {
    int parts = correctInputP();
    double step = STEP(parts);
  }
  return 0;
}