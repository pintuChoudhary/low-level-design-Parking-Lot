#include<iostream>
#include "parkinglot.h"

#ifndef GLOBAL_INCLUDES_H
#include"globalIncludes.h"
#endif

void printParkingLotStatus(ParkingLot *parkinglot){
    std::cout<<"System Info at time "<<current_time<<std::endl;
    std::cout<<parkinglot->toString()<<std::endl;
    std::cout<<"======================================="<<std::endl;
}

int main(){
    
    std::cout<<"Parking Lot Application is online"<<std::endl;
    VehicleInfo *v1 = new VehicleInfo("User1","123456781",100,1212,VehicleType::CAR);
    VehicleInfo *v2 = new VehicleInfo("User2","123456782",100,1222,VehicleType::BIKE);
    VehicleInfo *v3 = new VehicleInfo("User3","123456783",100,1232,VehicleType::BUS);
    VehicleInfo *v4 = new VehicleInfo("User4","123456784",100,1242,VehicleType::BIKE);
    VehicleInfo *v5 = new VehicleInfo("User5","123456785",100,1252,VehicleType::CAR);

    ParkingLot *parkinglot = new ParkingLot(1,6,4,2);
    printParkingLotStatus(parkinglot);
    Ticket *t1 = parkinglot->issueTicket(v1);

    current_time += 1;
    printParkingLotStatus(parkinglot);
    Ticket *t2 =parkinglot->issueTicket(v2);
    Ticket *t3 =parkinglot->issueTicket(v3);

    current_time += 2;
    parkinglot->submitTicket(t1);
    printParkingLotStatus(parkinglot);
    
    current_time += 2;
    Ticket *t4 =parkinglot->issueTicket(v4);
    parkinglot->submitTicket(t3);
    printParkingLotStatus(parkinglot);

    current_time += 2;
    parkinglot->submitTicket(t4);
    printParkingLotStatus(parkinglot);

    current_time += 4;
    Ticket *t5 =parkinglot->issueTicket(v5);
    parkinglot->submitTicket(t2);
    printParkingLotStatus(parkinglot);

    current_time += 2;
    parkinglot->submitTicket(t5);
    printParkingLotStatus(parkinglot);

    return 0;
}