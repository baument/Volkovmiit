#pragma once

#include <initializer_list>
#include <iostream>
#include <list>
#include <string>

class Stack
{
private:
    int* data;
    size_t count;

    void ERROR(const std::string& text);

public:
    Stack();

    Stack(std::initializer_list<int> other);

    Stack(std::list<int>& other);

    Stack(const Stack& other);

    Stack(Stack&& other) noexcept;

    ~Stack();

    Stack& operator=(const Stack& other);

    Stack& operator=(Stack&& other) noexcept;

    bool operator==(const Stack& other) const;

    bool operator!=(const Stack& other) const;

    int& operator[](size_t index);

    const int& operator[](size_t index) const;

    void push(const int& object);

    void pop();

    int peek() const;

    bool isEmpty() const;

    size_t getSize() const;

    int* getData() const;

    std::ostream& printSize(std::ostream& os) const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Stack& other);

    friend std::istream& operator>>(std::istream& is, Stack& other);
};
