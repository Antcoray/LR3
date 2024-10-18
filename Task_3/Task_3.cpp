#include <cmath>
#include <iostream>

double countN() {
  int A = 0;
  double B = M_PI / 2;
  int M = 20;
  double y = 0;
  double H = (B - A) / M;
  for (int i = 0; y <= 0.99; ++i) {
    double xi = A + i * H;
    y = sin(xi) - cos(xi);
    std::cout << "y = " << y << std::endl;
  }
  return 0;
}

void intro() {
  std::cout << "Задание 3. Выполнил Колесников Антон Сергеевич" << std::endl;
  std::cout << "Введите 1 чтобы найти значения функции y = sin(x) - cos(x) на "
               "отрезке [A, B] в точках Xi = A + i ∗ H, где H = (B - A) / M, M "
               "= 20, A = 0, B = π / 2"
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
      std::cout << "=== Некорректный ввод. Введите 1 чтобы найти значения "
                   "функции y = sin(x) - cos(x) или 0 "
                   "чтобы выйти ==="
                << std::endl;
      incorrect = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout << "=== Некорректный ввод. Введите 1 чтобы найти значения "
                   "функции y = sin(x) - cos(x) или 0 "
                   "чтобы выйти ==="
                << std::endl;
      incorrect = true;
      error = true;
    }
    if (s != 1 && s != 0 && error == false) {
      std::cout << "=== Некорректный ввод. Введите 1 чтобы найти значения
функции y = sin(x) - cos(x) или 0 " "чтобы выйти ==="
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
      std::cout << "=== Некорректный ввод. Введите 1 чтобы найти значения "
                   "функции y = sin(x) - cos(x) или 0 "
                   "чтобы выйти ==="
                << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if (x != 1 && x != 0 && error == false) {
      std::cout << "=== Некорректный ввод. Введите 1 чтобы найти значения "
                   "функции y = sin(x) - cos(x) или 0 "
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
      countN();
    }
    if (s == 0) {
      break;
    }
  }
  return 0;
}