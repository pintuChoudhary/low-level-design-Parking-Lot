#include"ticket.h"
#include<sstream>

#ifndef IMP_PRICING_H
#include"ImpPricing.h"
#endif

int current_time = 0;
int ticketId = 1;

Ticket::Ticket(){}

Ticket::Ticket(VehicleInfo *vInfo,ParkingSpot *ps){
    this->id = ticketId++;
    this->vehicleInfo = vInfo;
    this->parkingSpot = ps;
    this->parkingSpot->occupy();
    this->currentTime = current_time;
    this->price = new ImpPricing();
}

int Ticket::getId(){
    return id;
}

int Ticket::submitTicket(){
    int timeDiff = current_time - this->currentTime;
    int amount =  timeDiff * this->price->getRate();
    this->vehicleInfo->toPay(amount);
    this->parkingSpot->vaccat();
    return amount;
}


void Ticket::copy(Ticket *ticket){
    this->id=ticket->id;
    this->parkingSpot = ticket->parkingSpot;
    this->vehicleInfo = ticket->vehicleInfo;
}

std::string Ticket::toString(){
    std::stringstream ss;
    ss<<"Id = "<<id<<"\n";
    ss<<this->vehicleInfo->toString();
    ss<<this->parkingSpot->toString();
    ss<<"Ticket Time = "<<this->currentTime<<std::endl;
    return ss.str();
}