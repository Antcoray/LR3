#include <cmath>
#include <iostream>
#include <string>
#include <vector>

const int Q = 1000000;

struct bubble {
  int whole;
  int fraction;

  bubble(double value = 0) {
    whole = (int)value;
    fraction = (int)(round((value - whole) * Q));
  }

  bubble operator+(const bubble& other) const {
    bubble result(0);
    result.whole = whole + other.whole;
    result.fraction = fraction + other.fraction;

    if (abs(result.fraction) >= Q) {
      result.whole += result.fraction / Q;
      result.fraction %= Q;
    }
    return result;
  }

  bubble operator-(const bubble& other) const {
    bubble result(0);
    result.whole = whole - other.whole;
    result.fraction = fraction - other.fraction;

    if (result.fraction < 0) {
      result.whole -= 1;
      result.fraction += Q;
    } else if (result.fraction >= Q) {
      result.whole += 1;
      result.fraction -= Q;
    }
    return result;
  }

  bubble operator*(int multiplier) const {
    bubble result(0);
    result.whole = whole * multiplier;
    result.fraction = fraction * multiplier;

    result.whole += result.fraction / Q;
    result.fraction %= Q;
    return result;
  }

  void print() const {
    std::cout << whole << "." << abs(fraction) << std::endl;
  }
};

bubble divideNumber(const std::string& input) {
  double value = std::stod(input);
  return bubble(value);
}

void intro() {
  std::cout << "=== Задание 8. Выполнил Колесников Антон Сергеевич ==="
            << std::endl;
  std::cout << "Эта программа считает выражение a0 - 2 * a1 + 4 * a2 - 8 * a3 "
               "+ ... + 2^(n-1) * (-1)^(n-1) * an-1 без использования "
               "вещественной арифметики"
            << std::endl;
  std::cout << "*Введите  n = 0 чтобы выйти*\n" << std::endl;
}

int correctInputn() {
  std::cout << "Введите число n" << std::endl;
  double x = 0;
  bool error = false;
  bool incorrectInput = false;
  do {
    error = false;
    incorrectInput = false;
    std::cin >> x;
    int y = x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число n" << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if ((x >= 1 || x == 0) && error == false && x == (double)y) {
      incorrectInput = false;
    } else {
      std::cout << "Некорректный ввод. Введите число n" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

std::string correctInputa(int index) {
  std::cout << "Введите число a" << index << std::endl;
  std::string x = "";
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число a" << index << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    try {
      double i = std::stod(x);
    } catch (std::invalid_argument) {
      std::cout << "Некорректный ввод. Введите число a" << index << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int main() {
  intro();
  while (true) {
    int n = correctInputn();
    if (n == 0) {
      break;
    }
    std::vector<bubble> a;
    for (int i = 0; i < n; ++i) {
      std::string aStr = correctInputa(i);
      /*if (aStr == "0") {
        return 0;
      }*/
      a.push_back(divideNumber(aStr));
    }
    bubble result(0);
    int power_of_two = 1;
    for (int i = 0; i < n; ++i) {
      int sign = (i % 2 == 0) ? 1 : -1;
      result = result + a[i] * (sign * power_of_two);
      power_of_two *= 2;
    }
    std::cout << "Результат: ";
    result.print();
  }
  return 0;
}