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
    if (x < 154 && error == false) {
      std::cout << "Некорректный ввод. Введите число x " << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}
long long int countDigits(long long int y) {
  long long int numOfDigits = 1;
  long long int NewNum = y;
  for (long long int i = 1; NewNum >= 1; ++i) {
    NewNum = NewNum / 10;
    numOfDigits = i;
  }
  return numOfDigits;
}

bool checkIfArmstrong(long long int x) {
  long long int sum = 0;
  long long int numOfDigits = countDigits(x);
  std::string strX = std::to_string(x);
  for (char digit : strX) {
    std::cout << digit << "\n";
  }
  return true;
}
int findNum(double x) {
  for (long long int num = 153; num > x; ++num) {
    
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
    findNum(x);
  }
  return 0;
}