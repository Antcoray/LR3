#include <iostream>
#include <string>
#define pi 3.1415926535897932384626433832

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

double stepen(double value, double stepen) {
  double result = 1;
  for (int i = 1; i <= stepen; ++i) {
    result *= value;
  }
  return result;
}

double sinTaylor(double x) {
  bool xlt0 = true;
  while (x > 2 * pi && xlt0) {
    x -= 2 * pi;
    if (x - 2 * pi < 0) {
      xlt0 = false;
    }
  }
  while (x < 0 && xlt0) {
    x += 2 * pi;
    if (x + 2 * pi > 2 * pi) {
      xlt0 = false;
    }
  }
  double sinx = 0;
  for (int i = 0; i <= 10; ++i) {
    sinx += stepen(-1, i) * stepen(x, 2 * i + 1) / factorial(2 * i + 1);
  }
  return sinx;
}

double cosTaylor(double x) {
  bool xlt0 = true;
  while (x > 2 * pi && xlt0) {
    x -= 2 * pi;
    if (x - 2 * pi < 0) {
      xlt0 = false;
    }
  }
  while (x < 0 && xlt0) {
    x += 2 * pi;
    if (x + 2 * pi > 2 * pi) {
      xlt0 = false;
    }
  }
  double cosx = 0;
  for (int i = 0; i <= 10; ++i) {
    cosx += stepen(-1, i) * stepen(x, 2 * i) / factorial(2 * i);
  }
  return cosx;
}

double myabs(double value) {
  if (value < 0) {
    return -value;
  }
  return value;
}

double lnx(double x) {
  if (x < 0) {
    x *= -1;
  }
  double lnx = 0;
  bool xMt1 = false;
  if (x > 1) {
    x = 1 / x;
    xMt1 = true;
  }
  double previous = 1;
  double estimating = 0;
  bool inaccurate = true;
  double abc = 0;
  for (int i = 1; inaccurate && i < 10000; ++i) {
    previous = lnx;
    lnx += stepen(-1, i + 1) * stepen(x - 1, i) / i;
    estimating = lnx;
    abc = myabs(previous - estimating);
    if (abc <= 1e-9) {
      inaccurate = false;
    }
  }
  if (xMt1) {
    lnx = -1 * lnx;
  }
  return lnx;
}

void intro() {
  std::cout << "=== Задание 6. Выполнил Колесников Антон Сергеевич ==="
            << std::endl;
  std::cout
      << "Эта программа выводит минимальноее значение из величин, определяемых "
         "выражениями a = sinx, b = cosx, c = ln|x| при заданном х"
      << std::endl;
  std::cout << "*Введите 0 чтобы выйти в любой момент выполнения программы*\n"
            << std::endl;
}

double correctInputx() {
  std::cout << "Введите x" << std::endl;
  bool incorrect = false;
  bool error = false;
  double n = 0;
  do {
    incorrect = false;
    std::string str = "";
    std::cin >> str;
    try {
      n = std::stod(str);
    } catch (std::invalid_argument) {
      std::cout << "Некорректный ввод. Введите число x " << std::endl;
      incorrect = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout << "Некорректный ввод. Введите число x " << std::endl;
      incorrect = true;
      error = true;
    }
    if ((n < 1e-10 && n > 0) && error == false) {
      std::cout << "Некорректный ввод. Введите число x " << std::endl;
      incorrect = true;
    }
  } while (incorrect);
  return n;
}

int main() {
  intro();
  while (true) {
    double x = correctInputx();
    if (x == 0) {
      break;
    }
    double a = sinTaylor(x);
    double b = cosTaylor(x);
    double c = lnx(x);

    if (a < b && a < c) {
      std::cout << "a = " << a << std::endl;
    }
    if (b < a && b < c) {
      std::cout << "b = " << b << std::endl;
    }
    if (c < b && c < a) {
      std::cout << "a = " << a << std::endl;
    }
  }
  return 0;
}