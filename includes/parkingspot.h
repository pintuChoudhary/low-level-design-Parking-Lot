#define PARKINGSPOT_H
#include<string>

enum SpotType{
    SPOT_REGULAR,
    SPOT_SPECIAL,
    SPOT_LARGE
};

class ParkingSpot{
    private:
    bool available;
    int floor;
    int spot;
    SpotType type;

    public:
    ParkingSpot(int floor,int spot,SpotType type);
    void occupy();
    void vaccat();

    bool isAvailable();
    std::string toString();
};