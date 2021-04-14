#include "rhombus.cpp"
#include "RhombusC.cpp"
#include <iostream>
#include "iounit.cpp"
#include <vector>
#include <string>

using namespace std;

int main(void) {
    vector<RhombusC> A;
    int N;

    cout << "Введите количество ромбов: ";
    cin >> N;
    cout << endl;

    for (int i = 0; i < N; i++) {
        A.push_back(set_rhombus());
        cout << endl;
    }

    show_rhombuses_table(A);

    string color;
    cout << "Введеите цвет для поиска: ";
    cin >> color;

    show_rhombuses_table(A, color);

    return 0;
}