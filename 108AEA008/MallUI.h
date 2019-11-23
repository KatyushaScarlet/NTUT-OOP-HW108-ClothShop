#ifndef MALLUI
#define MALLUI

#include"Mall.h"

using namespace std;

class MallUI
{
    private:
        //当前的商店
        Mall* _mall;
		//商店选择防呆
        int menuShopSelect(int min, int max);
		//商店内操作防呆
        int menuShopActionSelect(int min, int max);
        //文字输入防呆
        string checkInputString();
        //价格输入防呆
        double checkInputPrice();
        //分割文本
        vector<string> split(string str, char key);
        //判断是否为合法浮点数
        bool isDouble(const string& str);

    public:
        //构造函数
        MallUI(Mall* mall);
        //开始运行
        void start();
};
#endif