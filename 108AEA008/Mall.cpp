#include"Mall.h"
#include"common.h"
#include<fstream>
using std::ifstream;

//构造函数
Mall::Mall()
{
    //读取文件
    vector<string> fileContent = readFile("Cloth.txt");
    //使用读取到的内容添加店铺
    addShops(fileContent, &_shops);
    //根据规则排序店铺
    sortShopVector(&_shops);
}

//添加衣服
void Mall::createNewCloth(string name, string description, double price)
{
    _shops[_shopIndex]->createNewCloth(name, description, price);
}

//选择商店
void Mall::selectShop(int shopIndex)
{
    _shopIndex = shopIndex;
}

//获取所有衣服
vector<Cloth*>* Mall::getClothes()
{
    return _shops[_shopIndex]->getClothes();
}

//获取所有商店
vector<Shop*>* Mall::getShops()
{
    return &_shops;
}