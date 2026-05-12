#include "../include/ClassStack.h"

#include <iostream>

using namespace std;

int getElement();

int main()
{
    system("chcp 1251");
    system("cls");

    Stack first;

    cin >> first;

    system("cls");

    cout << "Исходный стек:" << endl;
    cout << first << endl;

    first.printSize(cout);

    cout << endl;

    cout << "Верхний элемент: " << first.peek() << endl;

    cout << endl;

    cout << "Удаляем верхний элемент..." << endl;

    first.pop();

    cout << first << endl;

    cout << endl;

    cout << "Введите элемент для добавления: ";

    int value = getElement();

    first.push(value);

    cout << endl;

    cout << "Стек после добавления элемента:" << endl;

    cout << first << endl;

    cout << endl;

    cout << "Верхний элемент: " << first.peek() << endl;

    return 0;
}

int getElement()
{
    int value;

    cin >> value;

    if (cin.fail())
    {
        cerr << "Ошибка ввода";
        exit(1);
    }

    return value;
}
