#ifndef ORDER
#define ORDER

#include<vector>
#include"Cloth.h"
#include"Shop.h"

using namespace std;

class Order
{
    private:
        //�����е������·�
        vector<Cloth*> _orderedClothes;
        //������Ӧ���̵�
        Shop* _shop;
        //������Ӧ���û�����
        string _owner;
    public:
        //���캯��
        Order(Shop* shop) : _shop(shop) {}
        //��ȡ��ǰ�̵�
        Shop* getShop();
        //��������·�
        void addCloth(Cloth* clothToAdd);
        //��ȡ�����ܼ�
        double getTotalPrice();
        //----------����Ϊ�Զ���function----------
        //��ȡ�������·��嵥
        vector<Cloth*>getOrderClothes();
};
#endif // !ORDER