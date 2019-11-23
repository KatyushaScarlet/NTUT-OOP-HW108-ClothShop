#ifndef MALLUI
#define MALLUI

#include"Mall.h"

class MallUI
{
    private:
        //当前的商店
        Mall* _mall;
		//商店选单防呆
		int menuShopSelect(int min, int max);
		//商店内操作选单防呆
		int menuShopActionSelect(int min, int max);
		//文字输入防呆
		string checkInputString();
		//价格输入防呆
		double checkInputPrice();
    public:
        //构造函数
        MallUI(Mall* mall);
        //开始运行
        void start();
};
#endif