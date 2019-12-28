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
        //�ж��Ƿ�Ϊ�Ϸ�������
        bool isDouble(const string& str);
		//��������Ϣ���·�id���·�������
		map<int, int> organizeOrder(Order* order);
        //�̵����ѡ����UI��
        void menuShopUI(Shop* nowShop, Customer* nowCustomer);
        //�����·���UI��
        void addClothToShopUI();
        //�鿴�����·���UI��
        void showAllClothsFormShopUI();
        //�����¶�����UI��
        void createNewOrder();
        //�����·���UI��
        void addClothToOrder();
        //����������UI��
        void placeAnOrder();
        //�鿴ʣ�������UI��
        void showPoints();
        //�鿴��ʷ�վݣ�UI��
        void showHistoryOrders();
    public:
        //���캯��
        MallUI(Mall* mall);
        //��ʼ����
        void start();
};
#endif