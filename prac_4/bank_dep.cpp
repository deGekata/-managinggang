#include "bank_dep.h"


Bank_dep::Bank_dep() {
    this->_name = "undefined";
    this->_dep_type = RUB;
    this->_percent = 0;
    this->_sum = 0;
}

Bank_dep::Bank_dep(std::string abracadabra, double _sum, double percent, CURRENCY_TYPE dep_type):
_name(abracadabra), _sum(_sum), _percent(percent), _dep_type(dep_type) {};

Bank_dep::Bank_dep(Bank_dep const& ref): 
_name(ref._name), _sum(ref._sum), _percent(ref._percent), _dep_type(ref._dep_type) {};


Bank_dep::Bank_dep(Bank_dep&& ref):
_name(std::move(ref._name)), _sum(ref._sum), _percent(ref._percent), _dep_type(ref._dep_type) {};


void Bank_dep::operator=(Bank_dep const& ref) {
    this->_name = ref._name;
    this->_sum = ref._sum;
    this->_percent = ref._percent;
    this->_dep_type = ref._dep_type;
    // Bank_dep(ref); - то же самое
}

void Bank_dep::operator=(Bank_dep const&& ref) {
    this->_name = std::move(ref._name);
    this->_sum = ref._sum;
    this->_percent = ref._percent;
    this->_dep_type = ref._dep_type;
    std::string lol = "lol";
    std::string kek = "kekdfgersgfsfddfssgfsgfffffssgfsgffsdsfsfd";
    lol = std::move(kek);

    // Bank_dep(ref); - то же самое
}


bool Bank_dep::operator<(Bank_dep const& rht) {
    return this->_sum * currency[this->_dep_type] < rht._sum * currency[rht._dep_type];
}

std::ostream& operator<<(std::ostream& out, const Bank_dep& outp) {
    out << "Name: \"" << outp._name << 
            "\", currency:" << currency_name[outp._dep_type] << ", amount and percent:" <<
            outp._sum << "|" << outp._percent * 100 << "%";
    return out;
}
 

