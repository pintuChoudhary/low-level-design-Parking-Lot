#include"vehicleInfo.h"
#include<iostream>
#include<string>
#include<sstream>

VehicleInfo::VehicleInfo(std::string name,std::string phone,int amount,int vehicleNumber,VehicleType type){
    this->owner = new Owner(name,phone,amount);
    this->vehicleNumber = vehicleNumber;
    this->type = type;
}

std::string VehicleInfo::getOwnerName(){
    return this->owner->getName();
}

std::string VehicleInfo::getOwnerNumber(){
    return this->owner->getPhone();
}

int VehicleInfo::getVehicleNumber(){
    return this->vehicleNumber;
}

int VehicleInfo::toPay(int amount){
    return this->owner->toPay(amount);
}

VehicleType VehicleInfo::getVehicleType(){
    return this->type;
}

std::string VehicleInfo::toString(){
    std::stringstream ss;
    ss<<this->owner->toString();
    ss<<"Vehicle Number = "<<this->vehicleNumber<<"\n";
    std::string vehicletype;
    if(this->type == VehicleType::BIKE){
        vehicletype = "BIKE";
    } else if(this->type == VehicleType::CAR){
        vehicletype = "CAR";
    } else {
        vehicletype = "BUS";
    }
    ss<<"Vehicle Type = "<<vehicletype<<std::endl;
    return ss.str();
}

VehicleInfo::~VehicleInfo(){
    delete this->owner;
}