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
        //套装添加衣服
        void add(Cloth* cloth);
        //套装获取价格
        double getPrice();
};

#endif