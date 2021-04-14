#include <string>

using namespace std;

class Figure {
    public:
    virtual float get_side() = 0;
    virtual float get_perimeter() = 0;
    virtual float get_area() = 0;
    virtual string get_info() = 0;
};