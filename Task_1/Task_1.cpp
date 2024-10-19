#include <iostream>

double countN() {
  int i = 1;
  double N = 0, a = 0, b = 0;
  while (i <= 30) {
    if (i % 2 != 0) {
      a = i;
      b = i * i;
    } else {
      a = i / 2;
      b = i * i * i;
    }
    N += (a - b) * (a - b);
    ++i;
  }
  return N;
}

void intro() {
  std::cout << "=== Задание 1. Выполнил Колесников Антон Сергеевич ==="
            << std::endl;
  std::cout << "                                               30          2"
            << std::endl;
  std::cout << "Введите 1 чтобы вычислить значение N, где N = Σ   = (a - b)"
            << std::endl;
  std::cout << "                                               i=1    i   i"
            << std::endl;
  std::cout << "Введите 0 чтобы выйти" << std::endl;
}

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
