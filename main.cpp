#include <iostream>
#include <iomanip>
#include "rhombus.cpp"

using namespace std;

Rhombus set_rhombus() {
    cout << "Введите диагонали ромба" << endl;
    
    float fd, sd;
    cout << "Первая диагональ: ";
    cin >> fd;
    cout << "Вторая диагональ: ";
    cin >> sd;

    Rhombus a(fd, sd);
    return a;
}

void compare_rhobuses(Rhombus a, Rhombus b) {
    if (a.get_perimeter() > b.get_perimeter()) {
        cout << "Периметр первого ромба больше" << endl;
    } else if (a.get_perimeter() < b.get_perimeter()) {
        cout << "Периметр второго ромба больше" << endl;
    } else {
        cout << "Периметры ромбов равны" << endl;
    }

    if (a.get_area() > b.get_area()) {
        cout << "Площадь первого ромба больше" << endl;
    } else if (a.get_area() < b.get_area()) {
        cout << "Площадь второго ромба больше" << endl;
    } else {
        cout << "Площади ромбов равны" << endl;
    }

    return;
}

int main(void) {
    Rhombus r1 = set_rhombus();
    cout << r1.get_info() << endl;

    cout << "Введите два ромба для сравнения" << endl;
    Rhombus r2 = set_rhombus();
    cout << r2.get_info() << endl;

    Rhombus r3 = set_rhombus();
    cout << r3.get_info() << endl;

    compare_rhobuses(r2, r3);

    return 0;
}