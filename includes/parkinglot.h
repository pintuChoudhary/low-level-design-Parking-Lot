#define PARKINGLOT_H

#include<vector>
#include<unordered_map>

#ifndef PARKINGSPOT_H
#include"parkingspot.h"
#endif

#ifndef TICKET_H
#include"ticket.h"
#endif



class ParkingLot{
    private:
    int money;
    std::vector<ParkingSpot*> regularSpots;
    std::vector<ParkingSpot*> specialSpots;
    std::vector<ParkingSpot*> largeSpots;
    std::unordered_map<int,Ticket> ticketHistory;

    public:
    ParkingLot(int levels,int regularSpot,int specialSpot,int largeSpot);
    Ticket *issueTicket(VehicleInfo *vInfo);
    void submitTicket(Ticket* ticket);
    void totalMoney();
    std::string toString();
};