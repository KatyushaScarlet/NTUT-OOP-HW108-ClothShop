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
        //��ȡ���й˿�
        vector<Customer*> customers = *(_mall->getCustomers());

        //����˿�ѡ��
        for (size_t i = 0; i < customers.size(); i++)
        {
            cout << (i + 1) << "." << customers[i]->getName() << endl;
        }

        //����뿪��ѡ��
        cout << (customers.size() + 1) << ".�x�_" << endl;
        //�˿�ѡ�����
        int selectCustomer = menuCustomerSelect(1, customers.size() + 1);

        //ѡ���뿪ʱֱ�ӽ���
        if (selectCustomer == customers.size() + 1)
        {
            exit(0);
        }

        //��ȡ��ǰѡ�еĿͻ�
        Customer* nowCustomer = customers[selectCustomer - 1];
        //��ȡ�����̵�
        vector<Shop*> shops = *(_mall->getShops());

        //����̵�ѡ��
        for (size_t i = 0; i < shops.size(); i++)
        {
            cout << (i + 1) << "." << shops[i]->getName() << endl;
        }

        //�̵�ѡ�����
        int selectShop = menuShopSelect(1, shops.size());
        //��ȡ��ǰѡ�е��̵�
        Shop* nowShop = shops[selectShop - 1];
        //ѡ���̵�Ϳͻ�
        _mall->selectCustomerAndShop(selectCustomer, selectShop);
        //�̵����ѡ��
        menuShopUI(nowShop, nowCustomer);
    }
}

//�̵����ѡ����UI��
void MallUI::menuShopUI(Shop* nowShop, Customer* nowCustomer)
{
    while (true)
    {
        //�����ӭ��Ϣ
        cout << "�H�۵�ͣ�" << nowCustomer->getName() << "�����ã�" << endl;
        //����̵����ѡ��
        cout << "(" << nowShop->getName() << ")" << "1.�����·�" << endl;
        cout << "(" << nowShop->getName() << ")" << "2.�鿴�����·�" << endl;
        cout << "(" << nowShop->getName() << ")" << "3.������ӆ��" << endl;
		cout << "(" << nowShop->getName() << ")" << "4.ُ�I�·�" << endl;
		cout << "(" << nowShop->getName() << ")" << "5.�Y��ӆ��" << endl;
		cout << "(" << nowShop->getName() << ")" << "6.�鿴ʣ�N�c��" << endl;
		cout << "(" << nowShop->getName() << ")" << "7.�鿴�vʷ�Փ�" << endl;
		cout << "(" << nowShop->getName() << ")" << "8.�x�_" << endl;
        cout << "Ոݔ���x��";
        //�̵��ڲ�������
        int inputNumber = menuShopActionSelect(1, 8);

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
			//�����¶���
			createNewOrder(nowShop, nowCustomer);
        }
		else if (inputNumber == 4)
		{
			//�����·�
			addClothToOrder(nowShop, nowCustomer);
		}
		else if (inputNumber == 5)
		{
			//��������
			placeAnOrder(nowShop, nowCustomer);
		}
		else if (inputNumber == 6)
		{
			//�鿴ʣ�����
			showPoints(nowCustomer);
		}
		else if (inputNumber == 7)
		{
			//�鿴��ʷ�վ�
			showHistoryOrders(nowCustomer);
		}
		else if (inputNumber == 8)
		{
			//�����̳�
			break;
		}
    }
}

//�����·���UI��
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

//�����¶�����UI��
void MallUI::createNewOrder(Shop* nowShop, Customer* nowCustomer)
{
	cout << "TODO createNewOrder" << endl;
}
//�����·���UI��
void MallUI::addClothToOrder(Shop* nowShop, Customer* nowCustomer)
{
	cout << "TODO addClothToOrder" << endl;
}
//����������UI��
void MallUI::placeAnOrder(Shop* nowShop, Customer* nowCustomer)
{
	cout << "TODO addClothToOrder" << endl;
}

//�鿴ʣ�������UI��
void MallUI::showPoints(Customer* customer) 
{
	cout << "��ʣ�N���c��ʣ�£�" << customer->getCash() << endl;
}

//�鿴��ʷ�վݣ�UI��
void MallUI::showHistoryOrders(Customer* customer)
{
	cout << "��������δ��Ɍ���" << endl;
}

//�˿�ѡ�����
int MallUI::menuCustomerSelect(int min, int max)
{
    //��ȡ����
    int inputNumber;
    cout << "Select Customer:";
    cin >> inputNumber;

    //���������������Ͳ���ȷ���򳬳���Χ
    while (cin.fail() || (inputNumber < min || inputNumber > max))
    {
        //������ʾ
        cout << "Ո�x�����ϵĹ˿�" << endl;
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
        //���¶�ȡ����
        cout << "Select Customer:";
        cin >> inputNumber;
    }

    return inputNumber;
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