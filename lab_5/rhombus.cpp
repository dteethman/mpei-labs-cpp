#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include "Figure.cpp"

using namespace std;

class Rhombus : public Figure {
    protected:
    float side;
    float first_diagonal;
    float second_diagonal;

    int calc_col_width(float value, string argument) {
        stringstream tmp_ss;
        string tmp_str;
        int SPACING = 3;

        tmp_ss << fixed << setprecision(2) << value;
        tmp_str = tmp_ss.str();

        int value_size = int(tmp_str.size() + SPACING);
        int arg_size = int(argument.size() + SPACING);
        return max(value_size, arg_size);
    }

    string format_col(float value, int size) {
        stringstream tmp_ss;
        string tmp_str;

        tmp_ss << fixed << setprecision(2) << value;
        tmp_str = tmp_ss.str();

        int value_size = int(tmp_str.size());

        tmp_str += string(size - value_size, ' ');

        return tmp_str;
    }

    string format_col(string argument, int size) {
        string tmp_str = argument;

        int arg_size = int(tmp_str.size());

        tmp_str += string(size - arg_size, ' ');

        return tmp_str;
    }
    
    public:
    Rhombus(float fd, float sd) {
        change_rhombus(fd, sd);
    }

    void change_rhombus(float fd, float sd) {
        if ((fd > 0) && (sd > 0)) {
            first_diagonal = fd;
            second_diagonal = sd;
            side = sqrt(pow(fd, 2) + pow(sd, 2)) / 2;
        } else {
            cout << fixed << setprecision(2) 
            << "Невозможно инициализировать ромб с диагоналями " << fd << " и " << sd << endl;
            exit(1);
        }
    }

    float get_fd() {
        return first_diagonal;
    }

    float get_sd() {
        return second_diagonal;
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

    vector<int> get_col_widths() {
        vector<int> w;

        w.push_back(calc_col_width(first_diagonal, "AC"));
        w.push_back(calc_col_width(second_diagonal, "BD"));
        w.push_back(calc_col_width(side, "AB"));
        w.push_back(calc_col_width(get_perimeter(), "P"));
        w.push_back(calc_col_width(get_area(), "A"));

        return w;
    }

    string get_info_t(vector<int> widths) {
        string text = "";

        text += format_col(first_diagonal, widths[0]);
        text += format_col(second_diagonal, widths[1]);
        text += format_col(side, widths[2]);
        text += format_col(get_perimeter(), widths[3]);
        text += format_col(get_area(), widths[4]);

        return text;
    }

    string get_t_header(vector<int> widths) {
        string text = "";

        text += format_col("AC", widths[0]);
        text += format_col("BD", widths[1]);
        text += format_col("AB", widths[2]);
        text += format_col("P", widths[3]);
        text += format_col("A", widths[4]);

        return text;
    } 

};

