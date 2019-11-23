#ifndef MALLUI
#define MALLUI

#include"Mall.h"

using namespace std;

class MallUI
{
    private:
        //��ǰ���̵�
        Mall* _mall;
        //----------����Ϊ�Զ���function----------
        //�˿�ѡ�����
        int menuCustomerSelect(int min, int max);
        //�̵�ѡ�����
        int menuShopSelect(int min, int max);
        //�̵��ڲ�������
        int menuShopActionSelect(int min, int max);
        //�����������
        string checkInputString();
        //�۸��������
        double checkInputPrice();
		//�·�id�������
		int checkInputClothId();
		//�·������������
		int checkInputClothCount();
        //�ָ��ı�
        vector<string> split(string str, char key);
        //�ж��Ƿ�Ϊ�Ϸ�������
        bool isDouble(const string& str);
        //�̵����ѡ����UI��
        void menuShopUI(Shop* nowShop, Customer* nowCustomer);
        //�����·���UI��
        void addClothToShopUI(Shop* nowShop);
        //�鿴�����·���UI��
        void showAllClothsFormShopUI(Shop* nowShop);
        //�����¶�����UI��
        void createNewOrder(Shop* nowShop, Customer* nowCustomer);
        //�����·���UI��
        void addClothToOrder(Shop* nowShop, Customer* nowCustomer);
        //����������UI��
        void placeAnOrder(Shop* nowShop, Customer* nowCustomer);
        //�鿴ʣ�������UI��
        void showPoints(Customer* customer);
        //�鿴��ʷ�վݣ�UI��
        void showHistoryOrders(Customer* customer);
    public:
        //���캯��
        MallUI(Mall* mall);
        //��ʼ����
        void start();
};
#endif