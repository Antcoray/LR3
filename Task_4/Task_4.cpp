#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

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
      std::cout << "Некорректный ввод. Введите число n " << std::endl;
      incorrect = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout << "Некорректный ввод. Введите число n " << std::endl;
      incorrect = true;
      error = true;
    }
    if ((n < 0 || (n > 0 && n < 1)) && error == false) {
      std::cout << "Некорректный ввод. Введите число n " << std::endl;
      incorrect = true;
    }
  } while (incorrect);
  return (int)n;
}

int correctInputNofx() {
  std::cout
      << "Введите количество чисел, от которых вы хотите посчитать функцию"
      << std::endl;
  bool incorrect = false;
  bool error = false;
  double Nofx = 0;
  do {
    incorrect = false;
    std::string str = "";
    std::cin >> str;
    try {
      Nofx = std::stod(str);
    } catch (std::invalid_argument) {
      std::cout << "Некорректный ввод. Введите количество чисел, от которых вы "
                   "хотите посчитать функцию "
                << std::endl;
      incorrect = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout << "Некорректный ввод. Введите количество чисел, от которых вы "
                   "хотите посчитать функцию "
                << std::endl;
      incorrect = true;
      error = true;
    }
    if ((Nofx < 0 || (Nofx > 0 && Nofx < 1)) && error == false) {
      std::cout << "Некорректный ввод. Введите количество чисел, от которых вы "
                   "хотите посчитать функцию"
                << std::endl;

      incorrect = true;
    }
  } while (incorrect);
  return (int)Nofx;
}

double correctInputx() {
  bool incorrect = false;
  bool error = false;
  double x = 0;
  do {
    incorrect = false;
    std::string str = "";
    std::cin >> str;
    try {
      x = std::stod(str);
    } catch (std::invalid_argument) {
      std::cout << "Некорректный ввод. Введите x " << std::endl;
      incorrect = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout << "Некорректный ввод. Введите x " << std::endl;
      incorrect = true;
      error = true;
    }
    if (((x < 0.1 && x != 0) || x > 1) && error == false) {
      std::cout << "Некорректный ввод. Введите x " << std::endl;
      incorrect = true;
    }
  } while (incorrect);
  return x;
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