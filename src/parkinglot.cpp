#include"parkinglot.h"
#include<iostream>
#include<sstream>

ParkingLot::ParkingLot(int level,int regular,int special,int large){
    for(int lvl = 0; lvl < level; lvl++){
        for(int rg = 0; rg < regular; rg++){
            ParkingSpot *ps = new ParkingSpot(lvl+1,rg+1,SpotType::SPOT_REGULAR);
            this->regularSpots.push_back(ps);
        }

        for(int sp = 0; sp < special; sp++){
            ParkingSpot *ps = new ParkingSpot(lvl+1,sp+1,SpotType::SPOT_SPECIAL);
            this->specialSpots.push_back(ps);
        }

        for(int lg = 0; lg < large; lg++){
            ParkingSpot *ps = new ParkingSpot(lvl+1,lg+1,SpotType::SPOT_LARGE);
            this->largeSpots.push_back(ps);
        }
    }
    this->money=0;
}

Ticket * ParkingLot::issueTicket(VehicleInfo* vInfo){
    ParkingSpot *ps = nullptr;
    if(VehicleType::BIKE == vInfo->getVehicleType()){
        for(ParkingSpot *parkingSpot: this->specialSpots){
            if(parkingSpot->isAvailable()){
                ps = parkingSpot;
                break;
            }
        }
    } else if(VehicleType::CAR == vInfo->getVehicleType()){
        for(ParkingSpot *parkingSpot: this->regularSpots){
            if(parkingSpot->isAvailable()){
                ps = parkingSpot;
                break;
            }
        }
    } else if(VehicleType::BUS == vInfo->getVehicleType()){
        for(ParkingSpot *parkingSpot: this->largeSpots){
            if(parkingSpot->isAvailable()){
                ps = parkingSpot;
                break;
            }
        }
    } else {
        std::cout<<"Unknown Vehicle Type. Cannot issue ticket"<<std::endl;
        return nullptr;
    }

    return new Ticket(vInfo,ps);
}

void ParkingLot::submitTicket(Ticket *ticket){
    int amount = ticket->submitTicket();
    this->money += amount;
    
    Ticket tkt;
    tkt.copy(ticket);

    this->ticketHistory[ticket->getId()] = tkt;
    delete ticket;
}

void  ParkingLot::totalMoney(){
    std::cout<<"Money = Rs."<<money<<std::endl;
}

std::string ParkingLot::toString(){
    std::stringstream ss;
    int sspot = 0, rspot = 0, lspot = 0;
    for(ParkingSpot *parkingSpot: this->specialSpots){
        if(parkingSpot->isAvailable()){
            sspot++;
        }
    }
    for(ParkingSpot *parkingSpot: this->regularSpots){
        if(parkingSpot->isAvailable()){
            rspot++;
        }
    }
    for(ParkingSpot *parkingSpot: this->largeSpots){
        if(parkingSpot->isAvailable()){
            lspot++;
        }
    }

    ss<<"Availabe Spot for Regular = "<<rspot<<" Special = "<<sspot<<" Large = "<<lspot<<std::endl;
    ss<<"Ticket Count = "<<this->ticketHistory.size()<<std::endl;
    ss<<"Profit Rs."<<this->money<<std::endl;

    return ss.str();
}