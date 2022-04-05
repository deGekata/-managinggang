#include <vector>
#include <string>
#include <iostream>

enum CURRENCY_TYPE {
    EUR,
    USD,
    RUB,
    CURRENCY_CNT
};

static std::vector<double> currency{80.0, 60.0, 1.0};
static std::vector<const char*> currency_name{"EUR", "USD", "RUB"};

class Bank_dep {
    public:
        Bank_dep();
        Bank_dep(std::string name, double sum, double _percent, CURRENCY_TYPE _dep_type);
        Bank_dep(Bank_dep const& ref); //copy - constructor
        Bank_dep(Bank_dep&& ref);   //move - constructor

        void operator=(Bank_dep const& ref);
        void operator=(Bank_dep const&& ref);

        bool operator<(Bank_dep const& rht);
        friend std::ostream& operator<<(std::ostream& out, const Bank_dep& outp);
        ~Bank_dep();
    protected:

    private:
        std::string _name;
        CURRENCY_TYPE _dep_type;
        double _sum;
        double _percent;

};