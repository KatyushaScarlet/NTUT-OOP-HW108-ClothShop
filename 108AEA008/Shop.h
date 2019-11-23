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
        //商店中所有衣服
        vector<Cloth*> _clothes;
        //商店名称
        string _name;
        //每添加一件衣服，id增加1
        static int _clothesId;
    public:
        //构造函数
        Shop(string name);
        //寻找衣服
        Cloth* findCloth(int id);
        //添加衣服
        void createNewCloth(string name, string description, double price);
        //获取商店名称
        string getName();
        //获取所有衣服
        vector<Cloth*>* getClothes();
};
#endif