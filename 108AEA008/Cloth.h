#ifndef CLOTH
#define CLOTH

#include<string>
#include<vector>

using namespace std;

class Cloth
{
    private:
        //�·�id
        int _id;
        //�·�����
        string _name;
        //�·�����
        string _description;
        //�·��۸�
        double _price;
    public:
        //���캯��
        Cloth(string name, string description, double price, int id);
        //��ȡ�·�����
        string getName();
        //��ȡ�·�����
        string getDescription();
        //��ȡ�·���Ϣ
        string getInformation();
        //��ȡ�·��۸�
        double getPrice();
        //��ȡ�·�id
        int getId();
};
#endif