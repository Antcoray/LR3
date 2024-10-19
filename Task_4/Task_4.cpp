#include <cmath>
#include <iomanip>
#include <iostream>

int factorial(int value) {
  long long int f = 1;
  if (value > 32) {
    value = 32;
  }
  for (int i = 2; i <= value; ++i) {
    f *= i;
  }
  return f;
}

long double countS(int n, double x) {
  long double S = 0;
  if (n > 16) {
    n = 16;
  }
  for (int i = 1; i <= n; ++i) {
    S += pow(-1, i) * pow(2 * x, 2 * i) / factorial(2 * i);
  }
  return S;
}

void intro() {
  std::cout << "=== Задание 4. Выполнил Колесников Антон Сергеевич ==="
            << std::endl;
  std::cout << "Эта программа раскладывает функцию Y(x) в ряд S(x)"
            << std::endl;
  std::cout << "*Введите 0 чтобы выйти в любой момент выполнения программы*\n"
            << std::endl;
}

int correctInputn() {
  std::cout << "Введите количество членов ряда (n)" << std::endl;
  int n = 0;
  bool error = false;
  bool incorrectInput = false;
  do {
    error = false;
    incorrectInput = false;
    std::cin >> n;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число n " << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if (n < 0 && error == false) {
      std::cout << "Некорректный ввод. число n " << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return n;
}

double correctInputx() {
  double x = 0;
  bool error = false;
  bool incorrectInput = false;
  do {
    error = false;
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите x " << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if (((x < 0.1 && x != 0) || x > 1) && error == false) {
      std::cout << "Некорректный ввод. Введите x " << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int correctInputNofx() {
  std::cout
      << "Введите количество чисел, от которых вы хотите посчитать функцию"
      << std::endl;
  int Nofx = 0;
  bool error = false;
  bool incorrectInput = false;
  do {
    error = false;
    incorrectInput = false;
    std::cin >> Nofx;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите количество чисел, от которых вы "
                   "хотите посчитать функцию "
                << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if (Nofx < 0 && error == false) {
      std::cout << "Некорректный ввод. Введите количество чисел, от которых вы "
                   "хотите посчитать функцию "
                << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return Nofx;
}

int main() {
  intro();
  while (true) {
    int n = correctInputn();
    if (n == 0) {
      break;
    }
    int Nofx = correctInputNofx();
    if (Nofx == 0) {
      break;
    }
    std::cout << "Введите по одному числу (x от 0.1 до 1)" << std::endl;
    for (int i = 1; i <= Nofx; ++i) {
      double x = correctInputx();
      if (x == 0) {
        return 0;
      }
      std::cout << "\n S(" << x << ") = " << std::setprecision(15)
                << countS(n, x) << "\n Y(" << x
                << ") = " << 2 * (pow(cos(x), 2) - 1) << std::endl;
    }
    std::cout << "\n*Повторное выполнение программы*\n" << std::endl;
  }
  return 0;
}