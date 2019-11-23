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
        //��ǰѡ�еĹ˿�
        int _customerIndex;
        //��ǰѡ�е��̵�
        int _shopIndex;
        //���й˿�
        vector<Customer*>_customers;
        //�����̵�
        vector<Shop*> _shops;
        //----------����Ϊ�Զ���function----------
        //�Զ���Shop�ıȽϹ���
        bool compareShop(Shop* shop1, Shop* shop2);
        //��vector<Shop*>��������
        void sortShopVector(vector<Shop*>* shops);
        //��ӹ˿���Ϣ
        void addCustomer(Customer* customer);
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
        //�����¶���
        void makeNewOrder();
        //�򶩵�����·�
        void addOrderToCloth(int id);
        //ѡ��˿����̵�
        void selectCustomerAndShop(int custimerIndex, int shopIndex);
        //�жϵ����Ƿ��㹻
        bool isPointEnough();
        //�Ӷ�����ȡ����
        void reducePointFromOrder();
        //ȡ������
        void cancelOrder();
        //��ȡ��ǰ�Ķ���
        Order* getCurrentOrder();
        //��ȡ�����·�
        vector<Cloth*>* getClothes();
        //��ȡ�����̵�
        vector<Shop*>* getShops();
        //��ȡ���й˿�
        vector<Customer*>* getCustomers();
        //----------����Ϊ�Զ���function----------
        //��ȡ��ǰѡ�е��̵�
        Shop* getSelectShop();
        //��ȡ��ǰѡ�еĹ˿�
        Customer* getSelectCustomer();
};
#endif