#ifndef SUITE
#define SUITE

#include<string>
#include<vector>
#include"Cloth.h"

class Suite : public Cloth
{
    protected:
        vector<Cloth*> _clothes;
    public:
        void add(Cloth* cloth);
        double getPrice();
};

#endif