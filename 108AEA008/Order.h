#ifndef ORDER
#define ORDER

#include<vector>
#include"Cloth.h"
#include"Shop.h"

using namespace std;

class Order
{
    private:
        //订单中的所有衣服
        vector<Cloth*> _orderedClothes;
        //订单对应的商店
        Shop* _shop;
        //订单对应的用户名称
        string _owner;
    public:
        //构造函数
        Order(Shop* shop) : _shop(shop) {}
        //获取当前商店
        Shop* getShop();
        //订单添加衣服
        void addCloth(Cloth* clothToAdd);
        //获取订单总价
        double getTotalPrice();
        //----------以下为自定义function----------
        //获取订单内衣服清单
        vector<Cloth*>getOrderClothes();
};
#endif // !ORDER