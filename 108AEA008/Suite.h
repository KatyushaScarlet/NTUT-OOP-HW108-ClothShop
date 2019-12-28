#ifndef SUITE
#define SUITE

#include<string>
#include<vector>
#include"Cloth.h"

class Suite : public Cloth
{
    protected:
        vector<Cloth*> _clothes;
    public:
        //���캯��
        Suite(string name, string description, double price, int id, vector<Cloth*> clothes) : Cloth(name, description, price, id), _clothes(clothes) {}
        //��װ����·�
        void add(Cloth* cloth);
        //��װ��ȡ�۸�
        double getPrice();
};

#endif