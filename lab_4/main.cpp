#include "rhombus.cpp"
#include <iostream>
#include <vector>
#include "iounit.cpp"

using namespace std;

int main(void) {
    vector<Rhombus> A;
    int N;

    cout << "Введите количество ромбов: ";
    cin >> N;
    cout << endl;

    for (int i = 0; i < N; i++) {
        A.push_back(set_rhombus());
        cout << endl;
    }

    show_rhombuses_table(A);

    save_to_file(A, "r.csv");

    cout << "Изменение третьего ромба" << endl;

    float fd, sd;
    cout << "Введите первую диагональ: ";
    cin >> fd;
    cout << "Введите вторую диагональ: ";
    cin >> sd;

    A[2].change_rhombus(fd, sd);
    save_to_file(A, "r.csv");

    vector<Rhombus> B = load_from_file("r.csv");
    show_rhombuses_table(B);

    return 0;
}