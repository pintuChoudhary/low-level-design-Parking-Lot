#define IMP_PRICING_H

#ifndef PRICING_H
#include "pricing.h"
#endif

class ImpPricing: public Pricing{
    public:
    ImpPricing();
    int getRate();
};
