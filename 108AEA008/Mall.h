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
        //��ǰѡ�е��̵�
        int _shopIndex;
        //�����̵�
        vector<Shop*> _shops;
		//�Զ���Shop�ıȽϹ���
		bool compareShop(Shop* shop1, Shop* shop2);
		//��vector<Shop*>��������
		void sortShopVector(vector<Shop*>* shops);
		//д�������Ϣ
		void addShops(vector<string> fileContent, vector<Shop*>* _shops);
		//��ȡ�ļ�����
		vector<string> readFile(string fileName);
    public:
        //���캯��
        Mall();
        //����·�
        void createNewCloth(string name, string description, double price);
        //ѡ���̵�
        void selectShop(int shopIndex);
        //��ȡ�����·�
        vector<Cloth*>* getClothes();
        //��ȡ�����̵�
        vector<Shop*>* getShops();
};
#endif