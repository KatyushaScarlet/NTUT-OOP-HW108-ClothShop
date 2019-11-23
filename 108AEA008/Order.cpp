#include <vector>
#include "Cloth.h"
#include "Shop.h"
#include"Order.h"

using namespace std;

//���캯��
Order::Order(Shop* shop)
{
    //���õ�ǰ�̵�
    _shop = shop;
}

//��ȡ��ǰ�̵�
Shop* Order::getShop()
{
    //���ص�ǰ�̵�
    return _shop;
}

//��������·�
void Order::addCloth(Cloth* clothToAdd)
{
    //�µ�Cloth����Vector��
    _orderedClothes.push_back(clothToAdd);
}

//��ȡ�����ܼ�
double Order::getTotalPrice()
{
    //�ܼ�
    double sum = 0;
    //����
    int count = _orderedClothes.size();

    for (int i = 0; i < count; i++)
    {
        //�۸��ۼ�
        sum += _orderedClothes[i]->getPrice();
    }

    return sum;
}