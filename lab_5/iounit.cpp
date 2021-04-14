#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

RhombusC set_rhombus() {
    cout << "Введите две диагонали ромба" << endl;

    float fd, sd;
    string c;
    cout << "Введите первую диагональ: ";
    cin >> fd;
    cout << "Введите вторую диагональ: ";
    cin >> sd;
    cout << "Введите цвет: ";
    cin >> c;

    RhombusC a(fd, sd, c);
    return a; 
}

vector<int> get_max_col(vector<RhombusC> arr) {
    vector<int> max_col(6, 0);
    vector<int> tmp_col(6, 0);

    for (int i = 0; i < arr.size(); i++) {
        tmp_col = arr[i].get_col_widths();
        max_col[0] = max(max_col[0], tmp_col[0]);
        max_col[1] = max(max_col[1], tmp_col[1]);
        max_col[2] = max(max_col[2], tmp_col[2]);
        max_col[3] = max(max_col[3], tmp_col[3]);
        max_col[4] = max(max_col[4], tmp_col[4]);
        max_col[5] = max(max_col[5], tmp_col[5]);
    }

    return max_col;
}

void show_rhombuses_table(vector<RhombusC> arr) {
    vector<int> widths = get_max_col(arr);

    cout << "--Ромбы--" << endl;
    cout << arr[0].get_t_header(widths) << endl;

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].get_info_t(widths) << endl;
    }

    cout << endl;
}

void show_rhombuses_table(vector<RhombusC> arr, string color) {
    vector<RhombusC> filtred_arr;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].get_color() == color) {
            filtred_arr.push_back(arr[i]);
        }
    }

    if (filtred_arr.size() > 0) {
        vector<int> widths = get_max_col(filtred_arr);

        cout << "--Ромбы цвета "<< color << "--" << endl;
        cout << filtred_arr[0].get_t_header(widths, false) << endl;

        for (int i = 0; i < filtred_arr.size(); i++) {
            cout << filtred_arr[i].get_info_t(widths, false) << endl;
        }

        cout << endl;
    } else {
        cout << "Нет ромбов цвета " << color << endl;
    }

    
}

