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
        //当前订单
        Order* _order;
        //历史订单
        vector<Order*> _historyOrders;
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
        //----------以下为自定义function----------
        //将订单添加至历史订单
        void addToHistoryOrders(Order* order);
        //获取当前店铺下的订单
        vector<Order*> getHistoryOrders(Shop* shop);
};

#endif // ! CUSTOMER
