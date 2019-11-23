#ifndef MALLUI
#define MALLUI

#include"Mall.h"

using namespace std;

class MallUI
{
    private:
        //��ǰ���̵�
        Mall* _mall;
		//�̵�ѡ�����
        int menuShopSelect(int min, int max);
		//�̵��ڲ�������
        int menuShopActionSelect(int min, int max);
        //�����������
        string checkInputString();
        //�۸��������
        double checkInputPrice();
        //�ָ��ı�
        vector<string> split(string str, char key);
        //�ж��Ƿ�Ϊ�Ϸ�������
        bool isDouble(const string& str);

    public:
        //���캯��
        MallUI(Mall* mall);
        //��ʼ����
        void start();
};
#endif