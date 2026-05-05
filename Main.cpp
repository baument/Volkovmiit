#include <iostream>
#include <stdexcept>
#include "Class Square.h"

using namespace std;

int main() {
    float Ax, Ay, Bx, By, Cx, Cy;

    try {
        cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

        if (cin.fail()) {
            throw invalid_argument("Error: incorrect input");
        }

        Square square(Ax, Ay, Bx, By, Cx, Cy);

        cout << "Perimeter: " << square.perimeter() << endl;
        cout << "Area: " << square.area() << endl;
    }
    catch (const invalid_argument& error) {
        cout << error.what() << endl;
    }

    return 0;
}
