#include"owner.h"
#include<iostream>
#include<sstream>

Owner::Owner(std::string name,std::string phone, int money){
    this->name = name;
    this->phone = phone;
    this->money = money;
}
std::string Owner::getName(){
    return this->name;
}

std::string Owner::getPhone(){
    return this->phone;
}

int Owner::toPay(int amount){
    std::cout<<name<<" paid Rs."<<amount<<std::endl;
    return amount;
}

std::string Owner::toString(){
    std::stringstream ss;
    ss<<"Name = "<<name<<"\n";
    ss<<"Phone = "<<phone<<"\n";
    ss<<"Money = "<<money<<std::endl;
    return ss.str();
} 