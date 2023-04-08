#define OWNER_H

#include<string>

class Owner{
    private:
    std::string name;
    std::string phone;
    int money;
    
    public:
    Owner(std::string name,std::string phone, int money);
    std::string getName();
    std::string getPhone();
    int toPay(int amount);

    std::string toString(); 
};