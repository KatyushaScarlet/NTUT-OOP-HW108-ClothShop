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
    _name = name;
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
//点数是否足够
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
    _order = (Order*)NULL;
}
//获取客户订单
Order* Customer::getCurrentOrder()
{
    return _order;
}