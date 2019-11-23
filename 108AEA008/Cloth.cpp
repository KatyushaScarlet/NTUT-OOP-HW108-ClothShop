#include"Cloth.h"

//构造函数
Cloth::Cloth(string name, string description, double price, int id)
{
    _name = name;
    _description = description;
    _price = price;
    _id = id;
}

//获取衣服名称
string Cloth::getName()
{
    return _name;
}

//获取衣服描述
string Cloth::getDescription()
{
    return _description;
}

//获取衣服价格
double Cloth::getPrice()
{
    return _price;
}

//获取衣服id
int Cloth::getId()
{
    return _id;
}