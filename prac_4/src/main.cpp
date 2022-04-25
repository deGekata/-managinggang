#include "bank_dep.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

// #include <map>
#include <set>
#include <unordered_set>
int main() {
    std::ifstream myfile ("example.txt");
    size_t cnt;
    myfile >> cnt;

    std::vector<Bank_dep> deps;
    // deps[5] = deps[4];
    std::set<Bank_dep> abc;
    std::unordered_set<Bank_dep> un_abc;
    for (size_t it = 0; it < cnt; ++it) {
        std::string name;
        double sum, procent;
        size_t currency;
        myfile >> name >> sum >> procent >> currency;
        deps.push_back(Bank_dep (name, sum, procent, (CURRENCY_TYPE) currency));
        abc.insert(Bank_dep (name, sum, procent, (CURRENCY_TYPE) currency));
        un_abc.insert(Bank_dep (name, sum, procent, (CURRENCY_TYPE) currency));
    }

    std::cout << "readed deps:\n";
    for (auto &v: deps) {
        std::cout << v << "\n";
    }    

    std::cout << "test1\n";
    std::vector<Bank_dep> save(deps.size());
    std::copy(deps.begin(), deps.end(), save.begin());
    std::cout << "test\n";

    std::sort(deps.begin(), deps.end());
    std::cout << "\n\n\n\n";

    std::cout << "sort deps:\n";
    for (auto &v: deps) {
        std::cout << v << "\n";
    }    
    std::cout << "\n\n\n\n";

    std::cout << "saved deps(vector save):\n";
    for (auto &v: save) {
        std::cout << v << "\n";
    }
    std::cout << "\n\n\n\n";


    std::cout << "set of deps: sorted:\n";
    for (auto v = abc.begin(); v != abc.end(); ++v) {
        const Bank_dep& dep  = *v;
        std::cout << dep << " " << dep.getId() << "\n";
        // std::cout << ((Bank_dep&)(*v)) << "\n";
    }

    std::cout << "\n\n\n\n";

    std::cout << "unordered_set of deps:\n";
    for (auto v = un_abc.begin(); v != un_abc.end(); ++v) {
        const Bank_dep& dep  = *v;
        std::cout << dep << " " << dep.getId() << "\n";
        // std::cout << ((Bank_dep&)(*v)) << "\n";
    }

    return 0;
}