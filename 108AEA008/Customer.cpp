#include<vector>
#include<string>
#include"Cloth.h"
#include"Shop.h"
#include"Order.h"
#include"Customer.h"

using namespace std;

//构造函数
Customer::Customer(string name)
{
    //输入姓名
    _name = name;
    //预设点数为2000
    _point = 1000000;
}

//获取姓名
string Customer::getName()
{
    return _name;
}

//获取点数
double Customer::getCash()
{
    return _point;
}

//创建新订单
void Customer::makeNewOrder(Shop* shop)
{
    _order = new Order(shop);
}

//添加衣服到订单
void Customer::addClothToOrder(Cloth* cloth)
{
    _order->addCloth(cloth);
}

//获取订单总价
double Customer::getOrderTotalPrice()
{
    return _order->getTotalPrice();
}

//判断点数是否足够
bool Customer::isPointEnough()
{
    //判断点数是否大于等于订单总价
    return (_point >= _order->getTotalPrice());
}

//从订单扣取点数
void Customer::reducePointFromOrder()
{
    //当前点数减去订单总价
    _point -= _order->getTotalPrice();
}

//取消订单
void Customer::cancelOrder()
{
    _order = NULL;
}

//获取客户订单
Order* Customer::getCurrentOrder()
{
    return _order;
}

//将订单添加至历史订单
void Customer::addToHistoryOrders(Order* order)
{
    _historyOrders.push_back(order);
}

//获取当前店铺下的订单
vector<Order*> Customer::getHistoryOrders(Shop* shop)
{
    vector<Order*> result;

    for (int i = 0; i < _historyOrders.size(); i++)
    {
        string temp1 = _historyOrders[i]->getShop()->getName();
        string temp2 = shop->getName();

        if (temp1 == temp2 )
        {
            result.push_back(_historyOrders[i]);
        }
    }

    return result;
}