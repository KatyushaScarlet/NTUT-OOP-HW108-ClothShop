#include<vector>
#include<string>
#include"Cloth.h"
#include"Shop.h"
#include"Order.h"
#include"Customer.h"

using namespace std;

//���캯��
Customer::Customer(string name)
{
    _name = name;
}
//��ȡ����
string Customer::getName()
{
    return _name;
}
//��ȡ����
double Customer::getCash()
{
    return _point;
}
//�����¶���
void Customer::makeNewOrder(Shop* shop)
{
    _order = new Order(shop);
}
//����·�������
void Customer::addClothToOrder(Cloth* cloth)
{
    _order->addCloth(cloth);
}
//��ȡ�����ܼ�
double Customer::getOrderTotalPrice()
{
    return _order->getTotalPrice();
}
//�����Ƿ��㹻
bool Customer::isPointEnough()
{
    //�жϵ����Ƿ���ڵ��ڶ����ܼ�
    return (_point >= _order->getTotalPrice());
}
//�Ӷ�����ȡ����
void Customer::reducePointFromOrder()
{
    //��ǰ������ȥ�����ܼ�
    _point -= _order->getTotalPrice();
}
//ȡ������
void Customer::cancelOrder()
{
    _order = (Order*)NULL;
}
//��ȡ�ͻ�����
Order* Customer::getCurrentOrder()
{
    return _order;
}