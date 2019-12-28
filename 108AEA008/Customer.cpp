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
    //��������
    _name = name;
    //Ԥ�����Ϊ2000
    _point = 1000000;
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

//�жϵ����Ƿ��㹻
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
    _order = NULL;
}

//��ȡ�ͻ�����
Order* Customer::getCurrentOrder()
{
    return _order;
}

//�������������ʷ����
void Customer::addToHistoryOrders(Order* order)
{
    _historyOrders.push_back(order);
}

//��ȡ��ǰ�����µĶ���
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