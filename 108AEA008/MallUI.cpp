#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<sstream>
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"
#include"MallUI.h"

using namespace std;

//���캯��
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
}

//��ʼ����
void MallUI::start()
{
    while (true)
    {
        //��ȡ���е��̵�
        vector<Shop*> shops = *(_mall->getShops());

        //����̵�ѡ��
        for (size_t i = 0; i < shops.size(); i++)
        {
            cout << (i + 1) << "." << shops[i]->getName() << endl;
        }

        //�̵�ѡ�����
        int inputNumber = menuShopSelect(1, shops.size());
        //ѡ���̵�
        _mall->selectShop(inputNumber);
        //��ȡ��ǰѡ�е��̵�
        Shop* nowShop = shops[inputNumber - 1];
        //�̵����ѡ��
        menuShopUI(nowShop);
    }
}

//�̵����ѡ����UI��
void MallUI::menuShopUI(Shop* nowShop)
{
    while (true)
    {
        //����̵����ѡ��
        cout << "(" << nowShop->getName() << ")" << "1.�����·�" << endl;
        cout << "(" << nowShop->getName() << ")" << "2.�鿴�����·�" << endl;
        cout << "(" << nowShop->getName() << ")" << "3.�����̈�" << endl;
        cout << "Ոݔ���x��";
        //�̵��ڲ�������
        int inputNumber = menuShopActionSelect(1, 3);

        //��������
        if (inputNumber == 1)
        {
            //�����·�
            addClothToShopUI(nowShop);
        }
        else if (inputNumber == 2)
        {
            //�鿴�����·�
            showAllClothsFormShopUI(nowShop);
        }
        else if (inputNumber == 3)
        {
            //�����̳�
            break;
        }
    }
}

//����·���UI��
void MallUI::addClothToShopUI(Shop* nowShop)
{
    try
    {
        //����ϴε�����
        cin.clear();
        cin.ignore(1024, '\n');
        //��ʼ��������
        string clothName;
        string clothDescription;
        double clothPrice;
        cout << "Ոݔ���·����Q��";
        //�����������
        clothName = checkInputString();
        cout << "Ոݔ���·�������";
        //�����������
        clothDescription = checkInputString();
        cout << "Ոݔ��r��";
        //�۸��������
        clothPrice = checkInputPrice();
        nowShop->createNewCloth(clothName, clothDescription, clothPrice);
        cout << "����ꮅ��" << endl;
    }
    catch (const std::exception&)
    {
        //�����쳣��ʾ
        cout << "�l��������Ո����ݔ��" << endl;
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
    }
}

//�鿴�����·���UI��
void MallUI::showAllClothsFormShopUI(Shop* nowShop)
{
    cout << std::left << setw(6) << "No." << std::left << setw(50) << "�·����Q" << std::left << setw(10) << "�r��" << std::left << setw(50) << "����" << endl;
    //��ȡ�����·�
    vector<Cloth*> cloths = *(nowShop->getClothes());

    //�������
    for (int i = 0; i < cloths.size(); i++)
    {
        cout << std::left << setw(6) << cloths[i]->getId() << std::left << setw(50) << cloths[i]->getName() << std::left << setw(10) << setiosflags(ios::fixed) << setprecision(2) << cloths[i]->getPrice() << std::left << setw(50) << cloths[i]->getDescription() << endl;
    }

    //�����Ϻ��������
    cloths.clear();
}

//�̵�ѡ�����
int MallUI::menuShopSelect(int min, int max)
{
    //��ȡ����
    int inputNumber;
    cout << "Select Shop:";
    cin >> inputNumber;

    //���������������Ͳ���ȷ���򳬳���Χ
    while (cin.fail() || (inputNumber < min || inputNumber > max))
    {
        //������ʾ
        cout << "Ո�x�����ϵĵ��" << endl;
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
        //���¶�ȡ����
        cout << "Select Shop:";
        cin >> inputNumber;
    }

    return inputNumber;
}

//�̵��ڲ�������
int MallUI::menuShopActionSelect(int min, int max)
{
    //��ȡ����
    int inputNumber;
    cin >> inputNumber;

    //���������������Ͳ���ȷ���򳬳���Χ
    while (cin.fail() || (inputNumber < min || inputNumber > max))
    {
        //������ʾ
        cout << "Ոݔ�����_�x헣�";
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
        //���¶�ȡ����
        cin >> inputNumber;
    }

    return inputNumber;
}

//�����������
string MallUI::checkInputString()
{
    string inputString;
    getline(cin, inputString);

    //��������ʽ����򳤶�Ϊ��
    while (cin.fail() || inputString == "")
    {
        //������ʾ
        cout << "ݔ���e�`��Ո����ݔ�룺";
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
        getline(cin, inputString);
    }

    return inputString;
}

//�۸��������
double MallUI::checkInputPrice()
{
    double price;
    string inputString;
    cin >> inputString;
    //����ת��Ϊ������
    price = atof(inputString.c_str());

    //��������ʽ�����Χ����
    while (cin.fail() || !isDouble(inputString) || price <= 0)
    {
        //������ʾ
        cout << "�r����С춵���㣬Ո����ݔ��" << endl;
        cout << "Ոݔ��r��";
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> inputString;
        //����ת��Ϊ������
        price = atof(inputString.c_str());
    }

    return price;
}

//�ָ��ı�
vector<string> MallUI::split(string input, char pattern)
{
    //ת��Ϊ�ַ���
    istringstream inputStream(input);
    string word;
    vector<string> output;

    //�������
    while (getline(inputStream, word, pattern))
    {
        //��������
        output.push_back(word);
    }

    return output;
}

//�ж��Ƿ�Ϊ�Ϸ�������
bool MallUI::isDouble(const string& str)
{
    //С���������
    int dotCount = 0;
    //���ŵ�����
    int negativeCount = 0;
    //����ת��Ϊcharָ��
    const char* item = str.c_str();

    while (*item != '\0')
    {
        //����ж��ַ��Ƿ�Ϊ����
        if (*item < '0' || *item > '9')
        {
            //���������֣��ж��Ƿ�ΪС����򸱺�
            if (*item == '.')
            {
                //��¼С����ĸ���
                dotCount++;
            }
            else if (*item == '-')
            {
                //��¼���ŵĸ���
                negativeCount++;
            }
            else
            {
                //�������ַ�С����Ǹ���
                return false;
            }
        }

        item++;
    }

    //���С����򸱺ų���һ��
    if (dotCount > 1 || negativeCount > 1)
    {
        return false;
    }

    //�ǺϷ��ĸ�����
    return true;
}