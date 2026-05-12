#include "../include/ClassStack.h"

#include <cstdlib>

using namespace std;

void Stack::ERROR(const string& text)
{
    cerr << text << endl;
    exit(1);
}

Stack::Stack() : data(nullptr), count(0)
{
}

Stack::Stack(initializer_list<int> other)
    : data(nullptr), count(other.size())
{
    data = new int[count];

    size_t i = 0;

    for (const auto& value : other)
    {
        data[i++] = value;
    }
}

Stack::Stack(list<int>& other)
    : data(nullptr), count(other.size())
{
    data = new int[count];

    size_t i = 0;

    for (const auto& value : other)
    {
        data[i++] = value;
    }
}

Stack::Stack(const Stack& other)
    : data(nullptr), count(other.count)
{
    data = new int[count];

    for (size_t i = 0; i < count; i++)
    {
        data[i] = other.data[i];
    }
}

Stack::Stack(Stack&& other) noexcept
    : data(other.data), count(other.count)
{
    other.data = nullptr;
    other.count = 0;
}

Stack::~Stack()
{
    delete[] data;
}

Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        delete[] data;

        count = other.count;

        data = new int[count];

        for (size_t i = 0; i < count; i++)
        {
            data[i] = other.data[i];
        }
    }

    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;

        data = other.data;
        count = other.count;

        other.data = nullptr;
        other.count = 0;
    }

    return *this;
}

bool Stack::operator==(const Stack& other) const
{
    if (count != other.count)
    {
        return false;
    }

    for (size_t i = 0; i < count; i++)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }

    return true;
}

bool Stack::operator!=(const Stack& other) const
{
    return !(*this == other);
}

int& Stack::operator[](size_t index)
{
    if (index >= count)
    {
        ERROR("Выход за границы стека");
    }

    return data[index];
}

const int& Stack::operator[](size_t index) const
{
    if (index >= count)
    {
        ERROR("Выход за границы стека");
    }

    return data[index];
}

void Stack::push(const int& object)
{
    int* newData = new int[count + 1];

    for (size_t i = 0; i < count; i++)
    {
        newData[i] = data[i];
    }

    newData[count] = object;

    delete[] data;

    data = newData;

    count++;
}

void Stack::pop()
{
    if (count == 0)
    {
        cout << "Стек пуст" << endl;
        return;
    }

    size_t newSize = count - 1;

    int* newData = nullptr;

    if (newSize > 0)
    {
        newData = new int[newSize];

        for (size_t i = 0; i < newSize; i++)
        {
            newData[i] = data[i];
        }
    }

    delete[] data;

    data = newData;

    count = newSize;
}

int Stack::peek() const
{
    if (count == 0)
    {
        ERROR("Стек пуст");
    }

    return data[count - 1];
}

bool Stack::isEmpty() const
{
    return count == 0;
}

size_t Stack::getSize() const
{
    return count;
}

int* Stack::getData() const
{
    return data;
}

ostream& Stack::printSize(ostream& os) const
{
    os << "Размер стека: " << count << endl;

    return os;
}

string Stack::toString() const
{
    string result = "{";

    for (size_t i = 0; i < count; i++)
    {
        result += to_string(data[i]);

        if (i != count - 1)
        {
            result += ", ";
        }
    }

    result += "}";

    return result;
}

ostream& operator<<(ostream& os, const Stack& other)
{
    os << other.toString();

    return os;
}

istream& operator>>(istream& is, Stack& other)
{
    size_t size;

    cout << "Введите количество элементов: ";
    is >> size;

    if (is.fail())
    {
        other.ERROR("Ошибка ввода");
    }

    delete[] other.data;

    other.count = size;

    if (size > 0)
    {
        other.data = new int[size];

        for (size_t i = 0; i < size; i++)
        {
            cout << "Введите элемент " << i + 1 << ": ";

            is >> other.data[i];

            if (is.fail())
            {
                other.ERROR("Ошибка ввода");
            }
        }
    }
    else
    {
        other.data = nullptr;
    }

    return is;
}
