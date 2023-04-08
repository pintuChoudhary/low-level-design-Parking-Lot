#include"parkingspot.h"
#include<sstream>

ParkingSpot::ParkingSpot(int floor,int spot,SpotType type){
    this->floor = floor;
    this->available = true;
    this->spot = spot;
    this->type = type;
}

bool ParkingSpot::isAvailable(){
    return available;
}

void ParkingSpot::occupy(){
    available = false;
}

void ParkingSpot::vaccat(){
    available = true;
}

std::string ParkingSpot::toString(){
    std::stringstream ss;
    
    std::string spottype;
    if(type == SpotType::SPOT_LARGE){
        spottype = "LARGE";
    } else if(type == SpotType::SPOT_REGULAR){
        spottype = "REGULAR";
    } else {
        spottype = "SPECIAL";
    }

    ss<<"Floor = "<<floor<<"\n";
    ss<<"Spot = "<<spot<<"\n";
    ss<<"Type = "<<spottype<<"\n";
    ss<<"available = "<<(available?"Yes":"No")<<"\n";
    return ss.str();
}