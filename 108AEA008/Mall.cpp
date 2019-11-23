#include"Mall.h"
#include"common.h"
#include<fstream>
using std::ifstream;

//���캯��
Mall::Mall()
{
    //��ȡ�ļ�
    vector<string> fileContent = readFile("Cloth.txt");
    //ʹ�ö�ȡ����������ӵ���
    addShops(fileContent, &_shops);
    //���ݹ����������
    sortShopVector(&_shops);
}

//����·�
void Mall::createNewCloth(string name, string description, double price)
{
    _shops[_shopIndex]->createNewCloth(name, description, price);
}

//ѡ���̵�
void Mall::selectShop(int shopIndex)
{
    _shopIndex = shopIndex;
}

//��ȡ�����·�
vector<Cloth*>* Mall::getClothes()
{
    return _shops[_shopIndex]->getClothes();
}

//��ȡ�����̵�
vector<Shop*>* Mall::getShops()
{
    return &_shops;
}