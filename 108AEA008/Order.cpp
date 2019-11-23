#include <vector>
#include "Cloth.h"
#include "Shop.h"
#include"Order.h"

using namespace std;

//构造函数
Order::Order(Shop* shop)
{
    //设置当前商店
    _shop = shop;
}

//获取当前商店
Shop* Order::getShop()
{
    //返回当前商店
    return _shop;
}

//订单添加衣服
void Order::addCloth(Cloth* clothToAdd)
{
    //新的Cloth加入Vector中
    _orderedClothes.push_back(clothToAdd);
}

//获取订单总价
double Order::getTotalPrice()
{
    //总价
    double sum = 0;
    //数量
    int count = _orderedClothes.size();

    for (int i = 0; i < count; i++)
    {
        //价格累加
        sum += _orderedClothes[i]->getPrice();
    }

    return sum;
}