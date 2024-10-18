#include <cmath>
#include <iostream>

double STEP(int parts) {
  double step = 1 / (double)parts;
  return step;
}

double findx(double step) {
  double ymin = 100;
  double x = 0;
  double y = 1;
  double xmin = 0;
  for (int i = 0; i <= (1 / step); ++i) {
    y = sinh(x) + acos(x) - 1.5;
    if (y < ymin) {
      ymin = y;
      xmin = x;
    }
    x += step;
  }
  return xmin;
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
  std::cout << "Введите на сколько частей разделить область поиска корня"
            << std::endl;
  int x = 0;
  bool error = false;
  bool incorrectInput = false;
  do {
    error = false;
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число частей " << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if (x < 0 && error == false) {
      std::cout << "Некорректный ввод. Введите число частей " << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int main() {
  intro();
  while (true) {
    int parts = correctInputP();
    if (parts == 0) {
      break;
    }
    double step = STEP(parts);
    std::cout << "Корень уравнения --- " << findx(step)
              << "\n\n *Повторное выполнение программы* \n"
              << std::endl;
  }
  return 0;
}