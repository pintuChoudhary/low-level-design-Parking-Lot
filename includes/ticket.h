#define TICKET_H

#ifndef VEHICLE_H
#include"vehicleInfo.h"
#endif

#ifndef PRICING_H
#include"pricing.h"
#endif

#ifndef PARKINGSPOT_H
#include"parkingspot.h"
#endif

#ifndef GLOBAL_INCLUDES_H
#include"globalIncludes.h"
#endif


class Ticket{
    private:
    int id;
    VehicleInfo * vehicleInfo;
    ParkingSpot * parkingSpot;
    Pricing *price;
    int currentTime;

    public:
    Ticket();
    Ticket(VehicleInfo *vInfo, ParkingSpot *ps);
    int submitTicket();
    int getId();
    void copy(Ticket *ticket);
    
    std::string toString();
};