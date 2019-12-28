#ifndef SHOP
#define SHOP

#include<string>
#include<vector>
#include"Cloth.h"

using namespace std;

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
        void addNewCloth(string name, string description, double price);
        //�����װ
        void addNewSuite(string name, string description, double price, vector<Cloth*> cloths);
        //��ȡ�̵�����
        string getName();
        //��ȡ�����·�
        vector<Cloth*>* getClothes();
};
#endif