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

static int id_counter = 0;

class Bank_dep {
    public:
        Bank_dep();
        Bank_dep(std::string name, double sum, double _percent, CURRENCY_TYPE _dep_type);
        Bank_dep(Bank_dep const& ref); //copy - constructor
        Bank_dep(Bank_dep&& ref);   //move - constructor

        void operator=(Bank_dep const& ref);
        void operator=(Bank_dep const&& ref);

        bool operator==(const Bank_dep rht) const {
            return _dep_type == rht._dep_type && 
            _percent == rht._percent && 
            _sum == rht._sum &&
            _name == rht._name;
        }

        const int getId() const { return obj_id; };
        const std::string getName() const { return this->_name; }
        bool operator<(Bank_dep const& rht) const;
        friend std::ostream& operator<<(std::ostream& out, const Bank_dep& outp);
        ~Bank_dep() = default;
    protected:

    private:
        std::string _name;
        CURRENCY_TYPE _dep_type;
        double _sum;
        double _percent;
        int obj_id;
};

namespace std
{
  template<>
    struct hash<Bank_dep>
    {
      size_t
      operator()(const Bank_dep & obj) const
      {
        return hash<std::string>()(obj.getName());
      }
    };
}