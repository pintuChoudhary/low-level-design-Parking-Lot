#define VEHICLE_H

#include<string>
#include"owner.h"

enum VehicleType{
    BIKE,
    CAR,
    BUS
};

class VehicleInfo{
    private:
    int vehicleNumber;
    Owner *owner;
    VehicleType type;
    
    public:
    VehicleInfo(std::string name,std::string phone,int amount,int vehicleNumber,VehicleType type);
    ~VehicleInfo();

    std::string getOwnerName();
    std::string getOwnerNumber();
    VehicleType getVehicleType();
    int toPay(int amount);

    int getVehicleNumber();
    std::string toString();
};