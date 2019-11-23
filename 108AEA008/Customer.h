#ifndef CUSTOMER
#define CUSTOMER

#include<vector>
#include<string>
#include"Cloth.h"
#include"Shop.h"
#include"Order.h"

class Customer
{
    private:
        //����
        string _name;
        //����
        double _point;
        //����
        Order* _order;
    public:
        //���캯��
        Customer(string name);
        //��ȡ����
        string getName();
        //��ȡ����
        double getCash();
        //�����¶���
        void makeNewOrder(Shop* shop);
        //����·�������
        void addClothToOrder(Cloth* cloth);
        //��ȡ�����ܼ�
        double getOrderTotalPrice();
        //�����Ƿ��㹻
        bool isPointEnough();
        //�Ӷ�����ȡ����
        void reducePointFromOrder();
        //ȡ������
        void cancelOrder();
        //��ȡ�ͻ�����
        Order* getCurrentOrder();
};

#endif // ! CUSTOMER
