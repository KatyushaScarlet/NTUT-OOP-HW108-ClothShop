#ifndef MALLUI
#define MALLUI

#include"Mall.h"

class MallUI
{
    private:
        //��ǰ���̵�
        Mall* _mall;
    public:
        //���캯��
        MallUI(Mall* mall);
        //��ʼ����
        void start();
};
#endif