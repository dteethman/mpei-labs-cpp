#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Rhombus set_rhombus() {
    cout << "Введите две диагонали ромба" << endl;

    float fd, sd;
    cout << "Введите первую диагональ: ";
    cin >> fd;
    cout << "Введите вторую диагональ: ";
    cin >> sd;

    Rhombus a(fd, sd);
    return a;   
}

vector<int> get_max_col(vector<Rhombus> arr) {
    vector<int> max_col(5, 0);
    vector<int> tmp_col(5, 0);

    for (int i = 0; i < arr.size(); i++) {
        tmp_col = arr[i].get_col_widths();
        max_col[0] = max(max_col[0], tmp_col[0]);
        max_col[1] = max(max_col[1], tmp_col[1]);
        max_col[2] = max(max_col[2], tmp_col[2]);
        max_col[3] = max(max_col[3], tmp_col[3]);
        max_col[4] = max(max_col[4], tmp_col[4]);
    }

    return max_col;
}

void show_rhombuses_table(vector<Rhombus> arr) {
    vector<int> widths = get_max_col(arr);

    cout << "--Ромбы--" << endl;
    cout << arr[0].get_t_header(widths) << endl;

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].get_info_t(widths) << endl;
    }

    cout << endl;
}

void save_to_file(vector<Rhombus> arr ,string filename) {
    ofstream file(filename);

    for (int i = 0; i < arr.size(); i++) {
        file << arr[i].get_fd() << ";" << arr[i].get_sd() << endl;
    }

    file.close();
    cout << "Сохранено в файл " << filename << endl << endl;
}

vector<Rhombus> load_from_file(string filename) {
    vector<Rhombus> arr;
    ifstream file;

    file.open(filename);

    string fd, sd;

    while (getline(file, fd, ';')) {
        getline(file, sd, '\n');

        Rhombus tmp_r(stof(fd), stof(sd));
        arr.push_back(tmp_r);
    }

    file.close();
    return arr;
}
