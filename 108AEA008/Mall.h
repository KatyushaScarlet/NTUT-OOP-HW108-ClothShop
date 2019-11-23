#ifndef MALL
#define MALL

#include<string>
#include<vector>
#include"Cloth.h"
#include"Shop.h"
#include"Customer.h"

using namespace std;

class Mall
{
    private:
        //当前选中的顾客
        int _customerIndex;
        //当前选中的商店
        int _shopIndex;
        //所有顾客
        vector<Customer*>_customers;
        //所有商店
        vector<Shop*> _shops;
        //----------以下为自定义function----------
        //自定义Shop的比较规则
        bool compareShop(Shop* shop1, Shop* shop2);
        //对vector<Shop*>进行排序
        void sortShopVector(vector<Shop*>* shops);
        //添加顾客信息
        void addCustomer(Customer* customer);
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
        //创建新订单
        void makeNewOrder();
        //向订单添加衣服
        void addOrderToCloth(int id);
        //选择顾客与商店
        void selectCustomerAndShop(int custimerIndex, int shopIndex);
        //判断点数是否足够
        bool isPointEnough();
        //从订单扣取点数
        void reducePointFromOrder();
        //取消订单
        void cancelOrder();
        //获取当前的订单
        Order* getCurrentOrder();
        //获取所有衣服
        vector<Cloth*>* getClothes();
        //获取所有商店
        vector<Shop*>* getShops();
        //获取所有顾客
        vector<Customer*>* getCustomers();
        //----------以下为自定义function----------
        //获取当前选中的商店
        Shop* getSelectShop();
        //获取当前选中的顾客
        Customer* getSelectCustomer();
};
#endif