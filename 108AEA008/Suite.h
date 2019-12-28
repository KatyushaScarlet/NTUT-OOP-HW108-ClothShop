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
        //构造函数
        Suite(string name, string description, double price, int id, vector<Cloth*> clothes) : Cloth(name, description, price, id), _clothes(clothes) {}
        //套装添加衣服
        void add(Cloth* cloth);
        //套装获取价格
        double getPrice();
};

#endif