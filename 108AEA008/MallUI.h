#ifndef MALLUI
#define MALLUI

#include"Mall.h"

class MallUI
{
    private:
        //��ǰ���̵�
        Mall* _mall;
		//�̵�ѡ������
		int menuShopSelect(int min, int max);
		//�̵��ڲ���ѡ������
		int menuShopActionSelect(int min, int max);
		//�����������
		string checkInputString();
		//�۸��������
		double checkInputPrice();
    public:
        //���캯��
        MallUI(Mall* mall);
        //��ʼ����
        void start();
};
#endif