#include "bank_dep.h"
#include <iostream>
#include <fstream>
#include <algorithm>


int main() {
    std::ifstream myfile ("example.txt");
    size_t cnt;
    myfile >> cnt;

    std::vector<Bank_dep> deps;
    std::vector<int> my_arr;
    deps[5] = deps[4];
    my_arr.resize(10);
    my_arr.push_back(11);
     for (auto &v: my_arr) {
        std::cout << v << "\n";
    } 
    // my_arr[5] = 10;
    // deps[4] < deps[5];
    // deps[4].operator<() deps[5];
    // deps.resize(10);
    // deps[5] = 
    // [---, -----, -----, ----, ---, -----, -----, ----, ---, ---]
    for (size_t it = 0; it < cnt; ++it) {
        std::string name;
        double sum, procent;
        size_t currency;
        myfile >> name >> sum >> procent >> currency;
        deps.push_back(Bank_dep (name, sum, procent, (CURRENCY_TYPE) currency));
    }

    for (auto &v: deps) {
        std::cout << v << "\n";
    }    
    std::cout << "test1\n";
    std::vector<Bank_dep> save(deps.size());
    std::copy(deps.begin(), deps.end(), save.begin());
    std::cout << "test\n";

    std::sort(deps.begin(), deps.end());
    std::cout << "\n\n\n\n";

    for (auto &v: deps) {
        std::cout << v << "\n";
    }    

    std::cout << "\n\n\n\n";
    for (auto &v: save) {
        std::cout << v << "\n";
    }
    return 0;
}