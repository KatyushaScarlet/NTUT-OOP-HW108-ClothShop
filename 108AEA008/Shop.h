#ifndef SHOP
#define SHOP

#include<string>
#include<vector>
#include"Cloth.h"

using std::string;
using std::vector;

class Shop
{
    private:
        //�̵��������·�
        vector<Cloth*> _clothes;
        //�̵�����
        string _name;
        //ÿ���һ���·���id����1
        static int _clothesId;
    public:
        //���캯��
        Shop(string name);
        //Ѱ���·�
        Cloth* findCloth(int id);
        //����·�
        void createNewCloth(string name, string description, double price);
        //��ȡ�̵�����
        string getName();
        //��ȡ�����·�
        vector<Cloth*>* getClothes();
};
#endif