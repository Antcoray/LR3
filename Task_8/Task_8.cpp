#include <cmath>
#include <iostream>
#include <string>

int integerpart () {

}

void intro() {
  std::cout << "=== Задание 8. Выполнил Колесников Антон Сергеевич ==="
            << std::endl;
  std::cout << "Эта программа считает выражение a0 - 2 * a1 + 4 * a2 - 8 * a3 "
               "+ ... + 2^(n-1) * (-1)^(n-1) * an-1 без использования "
               "вещественной арифметики"

            << std::endl;
  std::cout << "*Введите 0 чтобы выйти в любой момент выполнения программы*\n"
            << std::endl;
}

std::string correctInputn() {
  std::cout << "Введите число n" << std::endl;
  std::string x = "";
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
  } while (incorrectInput);
  return x;
}

int main() {
  intro();
  while (true) {
    std::string n = correctInputn();
    if (n == "0") {
      break;
    }
  }
  return 0;
}