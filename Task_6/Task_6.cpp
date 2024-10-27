#include <cmath>
#include <iostream>
#define pi 3.1415926535897932384626433832
#define twopi 6.2831853071795864769252867665
#define stepForLn 2.302585093
#define rad 57.295779513
#define lg2pi 0.798179868

long long int factorial(int value) {
  long long int f = 1;
  if (value > 32) {
    value = 32;
  }
  for (int i = 1; i <= value; ++i) {
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

long long int myfloor(double x) {
  long long int intPart = (long long int)x;
  if (intPart > x && x > 0) {
    intPart -= 1;
  }
  if (intPart < x && x < 0) {
    intPart += 1;
  }
  return intPart;
}
double rangeReduction(double x) {
  double reducedX = 0;
  if (x > 1e16) {
    int n = 0;
    double x1 = x;
    for (int i = 1; x1 >= 10; ++i) {
      x1 = x1 / 10;
      n = i;
    }
    double ostatok = twopi * (n - lg2pi * myfloor(n / lg2pi));
    return ostatok;
  } else {
    long long int k = myfloor(x / twopi);
    reducedX = x - k * twopi;
  }
  return reducedX;
}

double sinTaylor(double y) {
  double x = rangeReduction(y);
  double sinx = 0;
  for (int i = 0; i <= 10; ++i) {
    sinx += stepen(-1, i) * stepen(x, 2 * i + 1) / factorial(2 * i + 1);
  }
  return sinx;
}

double cosTaylor(double y) {
  double x = rangeReduction(y);
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
  for (int i = 1; inaccurate; ++i) {
    previous = lnx;
    lnx += stepen(-1, i + 1) * stepen(x - 1, i) / i;
    estimating = lnx;
    abc = myabs(previous - estimating);
    if (abc <= 1e-4) {
      inaccurate = false;
    }
  }
  if (xMt1) {
    lnx = -1 * lnx;
  }
  return lnx;
}

double bigLn(double x) {
  double Ln = 0;
  int n = 0;
  if (x < 0) {
    x *= -1;
  }
  if (x >= 1e4) {
    for (int i = 0; x >= 10; ++i) {
      x = x / 10;
      n = i;
    }
    for (int i = 0; i <= n; ++i) {
      Ln += stepForLn;
    }
  } else {
    for (int i = 0; x <= 0.99; ++i) {
      x = x * 10;
      n = i;
    }
    for (int i = 0; i <= n; ++i) {
      Ln -= stepForLn;
    }
  }

  return Ln;
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
  double x = 0;

  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число x " << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int main() {
  double c = 0;
  bool xBigNumber = false;
  intro();
  while (true) {
    double x = correctInputx();
    if (x == 0) {
      break;
    }
    if (myabs(x) >= 1e4 || myabs(x) <= 1e-4) {
      xBigNumber = true;
    }
    double a = sinTaylor(x);
    double b = cosTaylor(x);
    if (xBigNumber) {
      c = bigLn(x);
    } else {
      c = lnx(x);
    }
    /*if (a < b && a < c) {
      std::cout << "a = " << a << std::endl;
    }
    if (b < a && b < c) {
      std::cout << "b = " << b << std::endl;
    }
    if (c < b && c < a) {
      std::cout << "с = " << c << std::endl;
    }*/
    std::cout << "mysinx = " << a << std::endl;
    std::cout << "cmath sinx = " << sin(x) << std::endl;
    std::cout << "mycosx = " << b << std::endl;
    std::cout << "cmath cosx = " << cos(x) << std::endl;
    std::cout << "mylogx = " << c << std::endl;
    std::cout << "cmath logx = " << log(myabs(x)) << std::endl;
  }
  return 0;
}
