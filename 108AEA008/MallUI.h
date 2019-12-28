#ifndef MALLUI
#define MALLUI

#include"Mall.h"

using namespace std;

class MallUI
{
    private:
        //当前的商店
        Mall* _mall;
        //----------以下为自定义function----------
        //顾客选择防呆
        int menuCustomerSelect(int min, int max);
        //商店选择防呆
        int menuShopSelect(int min, int max);
        //商店内操作防呆
        int menuShopActionSelect(int min, int max);
        //文字输入防呆
        string checkInputString();
        //价格输入防呆
        double checkInputPrice();
        //衣服id输入防呆
        int checkInputClothId();
        //衣服数量输入防呆
        int checkInputClothCount();
        //判断是否为合法浮点数
        bool isDouble(const string& str);
		//整理订单信息（衣服id，衣服数量）
		map<int, int> organizeOrder(Order* order);
        //商店操作选单（UI）
        void menuShopUI(Shop* nowShop, Customer* nowCustomer);
        //新增衣服（UI）
        void addClothToShopUI();
        //查看所有衣服（UI）
        void showAllClothsFormShopUI();
        //建立新订单（UI）
        void createNewOrder();
        //购买衣服（UI）
        void addClothToOrder();
        //结束订单（UI）
        void placeAnOrder();
        //查看剩余点数（UI）
        void showPoints();
        //查看历史收据（UI）
        void showHistoryOrders();
    public:
        //构造函数
        MallUI(Mall* mall);
        //开始运行
        void start();
};
#endif