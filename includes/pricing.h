#define PRICING_H

#define PRICE 10

class Pricing{
    protected:
    int rate;
    public:
    Pricing(){rate = PRICE;}
    virtual int getRate()=0;
};