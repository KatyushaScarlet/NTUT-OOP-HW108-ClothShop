#include"Cloth.h"
#include"Shop.h"

//��ʼ�·�id
int Shop::_clothesId = 1;

//���캯��
Shop::Shop(string name)
{
    _name = name;
}

//Ѱ���·�
Cloth* Shop::findCloth(int id)
{
    for (size_t i = 0; i < _clothes.size(); i++)
    {
        //Ѱ��id��ͬ���·�
        if (_clothes[i]->getId() == id)
        {
            return _clothes[i];
        }
    }

    return new Cloth("", "", 0, 0);
}

//����·�
void Shop::createNewCloth(string name, string description, double price)
{
    _clothes.push_back(new Cloth(name, description, price, _clothesId));
    //ÿ���һ���·���id����1
    _clothesId++;
}

//��ȡ�̵�����
string Shop::getName()
{
    return _name;
}

//��ȡ�����·�
vector<Cloth*>* Shop::getClothes()
{
    return &_clothes;
}