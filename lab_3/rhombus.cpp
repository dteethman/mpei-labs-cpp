#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

class Rhombus {
    private:
    float side;
    float first_diagonal;
    float second_diagonal;
    
    public:
    Rhombus(float f_d, float s_d) {
        if ((f_d > 0) && (s_d > 0)) {
            first_diagonal = f_d;
            second_diagonal = s_d;
            side = sqrt(pow(f_d, 2) + pow(s_d, 2)) / 2;
        } else {
            cout << fixed << setprecision(2) 
            << "Невозможно инициализировать ромб с диагоналями " << f_d << " и " << s_d << endl;
            exit(1);
        }
    }

    float get_side() {
        return side;
    }

    float get_perimeter() {
        return (side * 4);
    }

    float get_area() {
        return ((first_diagonal * second_diagonal) / 2 );
    }

    string get_info() {
        stringstream ss;
        ss << fixed << setprecision(2) 
        << "AC: " << first_diagonal << endl
        << "BD: " << second_diagonal << endl
        << "Сторона: " << get_side() << endl
        << "Периметр: " << get_perimeter() << endl
        << "Площадь: " << get_area() << endl;
        string text = ss.str();
        return text;
    }

};