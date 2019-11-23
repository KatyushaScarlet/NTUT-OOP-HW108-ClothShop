#ifndef ORDER
#define ORDER

#include <vector>
#include "Cloth.h"
#include "Shop.h"

using namespace std;

class Order
{
    private:
        //�����е������·�
        vector<Cloth*> _orderedClothes;
        //������Ӧ���̵�
        Shop* _shop;
    public:
        //���캯��
        Order(Shop* shop);
        //��ȡ��ǰ�̵�
        Shop* getShop();
        //��������·�
        void addCloth(Cloth* clothToAdd);
        //��ȡ�����ܼ�
        double getTotalPrice();
};
#endif // !ORDER