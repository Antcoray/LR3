#include <iostream>
#include <string>

double countN()
{
    int i = 1;
    double N = 0, a = 0, b = 0;
    while (i <= 30)
    {
        if (i % 2 != 0)
        {
            a = i;
            b = i * i;
        }
        else
        {
            a = i / 2;
            b = i * i * i;
        }
        N += (a - b) * (a - b);
        ++i;
    }
    return N;
}

void intro()
{
    std::cout << "=== Задание 1. Выполнил Колесников Антон Сергеевич ===" << std::endl;
    std::cout << "                                               30          2" << std::endl;
    std::cout << "Введите 1 чтобы вычислить значение N, где N = Σ   = (a - b)" << std::endl;
    std::cout << "                                               i=1    i   i" << std::endl;
    std::cout << "Введите 0 чтобы выйти" << std::endl;
}

int correctInput()
{   bool incorrect = false;
    bool error = false;
    int s;
    do {
    incorrect = false;
    std::string str = "";
    std::cin >> str;
    try
    {
    s = std::stoi(str);
    }
    catch(std::invalid_argument)
    {
        std::cout << "=== Некорректный ввод. Введите 1 чтобы вычислить N или 0 чтобы выйти ===" << std::endl;
        incorrect = true;
        error = true;
    }
    if (s != 1 && s != 0 && error == false)
        {
            std::cout << "=== Некорректный ввод. Введите 1 чтобы вычислить N или 0 чтобы выйти ===" << std::endl;
            incorrect = true;
        }
    } while(incorrect);
    return s;
}
int main()
{
    intro();
    while (true)
    {
        int s = correctInput();

        if (s == 1)
        {
            std::cout << "N = " << countN() << std::endl;
        }
        if (s == 0)
        {
            break;
        }
    }
    return 0;
}
