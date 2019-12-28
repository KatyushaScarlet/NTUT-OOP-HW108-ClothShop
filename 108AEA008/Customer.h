#ifndef CUSTOMER
#define CUSTOMER

#include<vector>
#include<string>
#include"Cloth.h"
#include"Shop.h"
#include"Order.h"

using namespace std;

class Customer
{
    private:
        //姓名
        string _name;
        //点数
        double _point;
        //订单
        Order* _order;
    public:
        //构造函数
        Customer(string name);
        //获取姓名
        string getName();
        //获取点数
        double getCash();
        //创建新订单
        void makeNewOrder(Shop* shop);
        //添加衣服到订单
        void addClothToOrder(Cloth* cloth);
        //获取订单总价
        double getOrderTotalPrice();
        //判断点数是否足够
        bool isPointEnough();
        //从订单扣取点数
        void reducePointFromOrder();
        //取消订单
        void cancelOrder();
        //获取当前的订单
        Order* getCurrentOrder();
        //获取在某店铺的订单历史记录
        vector<Order*>* getPurchasedHistoryFrom(Shop* shop);
};

#endif // ! CUSTOMER
