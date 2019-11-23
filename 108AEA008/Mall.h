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
        //��ȡCloth.txt�е��·���Ϣ��name description price��
        vector<string> getClothContent(string line);
        //��ȡCloth.txt�еĵ�������Ϣ��Shop H&M:��
        string getShopContent(string line);
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