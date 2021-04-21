#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool is_int(string str) {
    return str.find_first_not_of("-0123456789") == string::npos;
}

int get_rand() {
    return rand() % 101 - 50;
}

bool is_file_exist(string filename) {
    if (FILE *file = fopen(filename.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

void show_array_and_sum(vector<int> arr) {
    if (arr.size() > 0) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            cout << "[" << i << "]: " << arr[i] << "  ";
            sum += arr[i];
            if ((i + 1) % 4 == 0) { 
                cout << endl;
            }
        }
        cout << endl << "Сумма элементов: " << sum << endl;
    } else {
        cout << "Невозможно вывести результат, массив пуст" << endl;
    }
}

void save_to_file(vector<int> arr, string filename) {
    if (is_file_exist(filename)) {
        rename(filename.c_str(), (filename + ".old").c_str());
    }

    ofstream file(filename);

    for(int i = 0; i < arr.size(); i++) {
        file << arr[i] << endl;
    }

    file.close();
    cout << "Сохранено в файл " << filename << endl;

}

vector<int> load_from_file(string filename) {
    if(is_file_exist(filename)) {
        fstream file(filename);
        vector<int> loaded_data;

        if(file.is_open()) {
            int cur_num;
            while (file >> cur_num) {
                loaded_data.push_back(cur_num);
            }
            cout << "Загружено из фйла " << filename << endl;
            file.close();
            return loaded_data;
        } else {
            cout << "Не удалось открыть файл " << filename << endl;
            exit(1);
        }
    } else {
        cout << "Файла " << filename << " не существует." << endl;
        exit(1);
    }
}

int main(void) {
    srand((unsigned int) time(NULL));

    string N; 
    int size;

    cout << "Введите размер массива (не более 100): ";
    cin >> N;

    if (!is_int(N)) {
        cout << "Введено не целое число" << endl;
        exit(1);
    } else {
        size = stoi(N);
        if ((size < 1) || (size > 100)) {
            cout << "Введено число больше 100 или меньше 1" << endl;
            exit(1);
        } 
    }

    vector<int> arr;

    for(int i = 0; i < size; i++) {
        arr.push_back(get_rand());
    } 

    string filename;
    cout << "Введите название файла для сохранения: ";
    cin >> filename;
    cout << endl;
    save_to_file(arr, filename);

    cout << "Введите название файла для загрузки: ";
    cin >> filename;
    cout << endl;

    vector<int> arr2 = load_from_file(filename);
    show_array_and_sum(arr2);

    return 0;
}