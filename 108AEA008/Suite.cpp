#include"Cloth.h"
#include"Suite.h"

using namespace std;

//套装添加衣服
void Suite::add(Cloth* cloth)
{
    _clothes.push_back(cloth);
}

//套装获取价格
double Suite::getPrice()
{
    return _price;
}