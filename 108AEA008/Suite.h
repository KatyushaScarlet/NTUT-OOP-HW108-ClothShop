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
        //��װ����·�
        void add(Cloth* cloth);
        //��װ��ȡ�۸�
        double getPrice();
};

#endif