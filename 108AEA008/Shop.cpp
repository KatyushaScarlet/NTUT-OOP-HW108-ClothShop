#include"Cloth.h"
#include"Suite.h"
#include"Shop.h"

using namespace std;

//初始衣服id
int Shop::_clothesId = 1;

//构造函数
Shop::Shop(string name)
{
    _name = name;
}

//寻找衣服
Cloth* Shop::findCloth(int id)
{
    for (int i = 0; i < _clothes.size(); i++)
    {
        //寻找id相同的衣服
        if (_clothes[i]->getId() == id)
        {
            return _clothes[i];
        }
    }

    return new Cloth("", "", 0, 0);
}

//添加衣服
void Shop::addNewCloth(string name, string description, double price)
{
    _clothes.push_back(new Cloth(name, description, price, _clothesId));
    //每添加一件衣服，id增加1
    _clothesId++;
}

//添加套装
void Shop::addNewSuite(string name, string description, double price, vector<Cloth*> cloths)
{
    _clothes.push_back(new Suite(name, description, price, _clothesId, cloths));
    //每添加一个套装，id增加1
    _clothesId++;
}

//获取商店名称
string Shop::getName()
{
    return _name;
}

//获取所有衣服
vector<Cloth*>* Shop::getClothes()
{
    return &_clothes;
}