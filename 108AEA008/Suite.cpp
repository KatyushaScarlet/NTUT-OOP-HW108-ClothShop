#include"Cloth.h"
#include"Suite.h"

using namespace std;

//��װ����·�
void Suite::add(Cloth* cloth)
{
    _clothes.push_back(cloth);
}

//��װ��ȡ�۸�
double Suite::getPrice()
{
    return _price;
}