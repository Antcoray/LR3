#include <cmath>
#include <iostream>

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
  std::cout << "Введите 1 чтобы найти сумму ряда с точностью ε=10^-3, общий "
               "член которого dn = 1/2^n + 1/3^n"
            << std::endl;
  std::cout << "Введите 0 чтобы выйти" << std::endl;
}

/*int correctInput() {
  bool incorrect = false;
  bool error = false;
  int s;
  do {
    incorrect = false;
    std::string str = "";
    std::cin >> str;
    try {
      s = std::stoi(str);
    } catch (std::invalid_argument) {
      std::cout
          << "=== Некорректный ввод. Введите 1 чтобы найти сумму ряда или 0 "
             "чтобы выйти ==="
          << std::endl;
      incorrect = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout
          << "=== Некорректный ввод. Введите 1 чтобы найти сумму ряда или 0 "
             "чтобы выйти ==="
          << std::endl;
      incorrect = true;
      error = true;
    }
    if (s != 1 && s != 0 && error == false) {
      std::cout
          << "=== Некорректный ввод. Введите 1 чтобы найти сумму ряда или 0 "
             "чтобы выйти ==="
          << std::endl;

      incorrect = true;
    }
  } while (incorrect);
  return s;
}
*/

int correctInput() {
  int x = 0;
  bool error = false;
  bool incorrectInput = false;
  do {
    error = false;
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "=== Некорректный ввод. Введите 1 чтобы вычислить N или 0 "
                   "чтобы выйти ==="
                << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if (x != 1 && x != 0 && error == false) {
      std::cout << "=== Некорректный ввод. Введите 1 чтобы вычислить N или 0 "
                   "чтобы выйти ==="
                << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int main() {
  intro();
  while (true) {
    int s = correctInput();
    if (s == 1) {
      std::cout << "N = " << countN() << std::endl;
    }
    if (s == 0) {
      break;
    }
  }
  return 0;
}