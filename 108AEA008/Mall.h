#ifndef MALL
#define MALL

#include<string>
#include<vector>
#include"Cloth.h"
#include"Shop.h"

using std::string;
using std::vector;

class Mall
{
    private:
        //当前选中的商店
        int _shopIndex;
        //所有商店
        vector<Shop*> _shops;
    public:
        //构造函数
        Mall();
        //添加衣服
        void createNewCloth(string name, string description, double price);
        //选择商店
        void selectShop(int shopIndex);
        //获取所有衣服
        vector<Cloth*>* getClothes();
        //获取所有商店
        vector<Shop*>* getShops();
};
#endif