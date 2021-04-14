#include "Colored.cpp"

using namespace std;

class RhombusC : public Rhombus, public Colored {
    private:
    string color;

    int calc_col_width(string value, string argument) {
        int SPACING = 3;

        int value_size = int(value.size() + SPACING);
        int arg_size = int(argument.size() + SPACING);
        return max(value_size, arg_size);
    }

    public: 
    RhombusC(float fd, float sd, string c) : Rhombus(fd, sd) {
        color = c;
    }

    string get_color() {
        return color;
    }

    string get_info() {
        string text = Rhombus::get_info();
        text += "Цвет: ";
        text += get_color();
        text += "\n";
        return text;
    }

    vector<int> get_col_widths() {
        vector<int> w;

        w = Rhombus::get_col_widths();
        w.push_back(calc_col_width(get_color(), "Color"));

        return w;
    }

    string get_info_t(vector<int> widths, bool with_color=true) {
        string text = Rhombus::get_info_t(widths);
        if (with_color) { text += format_col(get_color(), widths[5]); }

        return text;
    }

    string get_t_header(vector<int> widths, bool with_color=true) {
        string text = Rhombus::get_t_header(widths);
        if (with_color) { text += format_col("Color", widths[5]); }

        return text;
    } 
};