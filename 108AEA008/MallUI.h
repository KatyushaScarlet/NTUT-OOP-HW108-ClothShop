#ifndef MALLUI
#define MALLUI

#include"Mall.h"

class MallUI
{
    private:
        //当前的商店
        Mall* _mall;
    public:
        //构造函数
        MallUI(Mall* mall);
        //开始运行
        void start();
};
#endif