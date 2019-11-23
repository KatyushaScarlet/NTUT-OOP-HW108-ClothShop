#ifndef MALL
#define MALL

#include<string>
#include<vector>
#include"Cloth.h"
#include"Shop.h"

using namespace std;

class Mall
{
    private:
        //当前选中的商店
        int _shopIndex;
        //所有商店
        vector<Shop*> _shops;
        //自定义Shop的比较规则
        bool compareShop(Shop* shop1, Shop* shop2);
        //对vector<Shop*>进行排序
        void sortShopVector(vector<Shop*>* shops);
        //写入店铺信息
        void addShops(vector<string> fileContent, vector<Shop*>* _shops);
        //读取文件内容
        vector<string> readFile(string fileName);
        //获取Cloth.txt中的衣服信息（name description price）
        vector<string> getClothContent(string line);
        //获取Cloth.txt中的店铺名信息（Shop H&M:）
        string getShopContent(string line);
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