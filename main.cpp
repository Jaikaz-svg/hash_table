// Лабораторная работа №3 "Хэш-таблицы"
#include <iostream>
#include <cmath>
#include <cstring>
#include "my_hash_table.h"
#include "hash_functions.h"

using namespace std;

int main() {
    const char* str[] = {"hashfunc", "hashmap", "lab3", "Zabrodin"};
    int size = 1433;
    int n = 1000;
    My_Hash_Map h(hash_func3, size);

    for (int i = 0; i < n; i++) {
        h.add_item("key" + std::to_string(i), "value" + std::to_string(i));
    }

    int cnt_fylly_cells = 0;

    for (auto& list : h.pole) {
        if (list.is_head_null()) cnt_fylly_cells++;
    }

    cout << (double)cnt_fylly_cells / size << endl;
    // try {
    //     for (int i = 0; i < 100; i++) {
    //         std::cout << h.get_item("key" + std::to_string(i)) << std::endl;
    //     }
    // }
    // catch (char const*) { cout << "KeyError" << endl; }


    cout << "Collisions = " << (double)h.get_collisions() / n * 100 << endl;

    
    // HashMap h(10);
    // const char* keys[4] = {"hashfunc", "hashmap", "lab3", "Zabrodin"};
    // for (int i = 0; i < 4; ++i) {
    //     h = h.insert(h, keys[i], i + 1);
    // }
    // for (int i = 0; i < 4; ++i) {
    //     std::cout << keys[i] << " = " << h.get(keys[i]) << std::endl;
    // }
    
    // h.delete_key("lab3");
    // std::cout << h.get("lab3");
    // for (int i = 0; i < 4; ++i) {
    //     int res = h.get(keys[i]);
    //     if (res != 0) std::cout << keys[i] << "=" << res << std::endl;
    // }

    return 0;
}