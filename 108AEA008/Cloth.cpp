#include"Cloth.h"

//���캯��
Cloth::Cloth(string name, string description, double price, int id)
{
    _name = name;
    _description = description;
    _price = price;
    _id = id;
}

//��ȡ�·�����
string Cloth::getName()
{
    return _name;
}

//��ȡ�·�����
string Cloth::getDescription()
{
    return _description;
}

//��ȡ�·��۸�
double Cloth::getPrice()
{
    return _price;
}

//��ȡ�·�id
int Cloth::getId()
{
    return _id;
}