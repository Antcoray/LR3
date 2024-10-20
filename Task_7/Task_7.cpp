#include <cmath>
#include <iostream>
#include <string>

void intro() {
  std::cout
      << "=== Задание 7. Выполнил Колесников Антон Сергеевич. Вариант 12 ==="
      << std::endl;
  std::cout << "Эта программа выводит все числа Армстронга, меньше введённого "
               "числа x, при этом минимальное значение x --- 154"
            << std::endl;
  std::cout << "*Введите 0 чтобы выйти в любой момент выполнения программы*\n"
            << std::endl;
}

int correctInputx() {
  std::cout << "Введите число x " << std::endl;
  double x = 0;
  bool error = false;
  bool incorrectInput = false;
  do {
    error = false;
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число x" << std::endl;
      std::cin.ignore(1000000, '\n');
      error = true;
      incorrectInput = true;
    }
    if (x < 154 && x != 0 && error == false) {
      std::cout << "Некорректный ввод. Введите число x " << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int countDigits(int y) {
  int numOfDigits = 1;
  int NewNum = y;
  for (int i = 1; NewNum >= 1; ++i) {
    NewNum = NewNum / 10;
    numOfDigits = i;
  }
  return numOfDigits;
}

bool checkIfArmstrong(int x) {
  int sum = 0;
  int numOfDigits = countDigits(x);
  std::string strX = std::to_string(x);
  int d = 0;
  for (char digit : strX) {
    d = digit - '0';
    sum += pow(d, numOfDigits);
  }
  return sum == x;
}
int findNum(double x) {
  for (int num = 153; num < x; ++num) {
    if (checkIfArmstrong(num)) {
      std::cout << num << '\n';
    }
  }
  return 0;
}
int main() {
  intro();
  while (true) {
    double x = correctInputx();
    if (x == 0) {
      break;
    }
    findNum(x);
  }
  return 0;
}