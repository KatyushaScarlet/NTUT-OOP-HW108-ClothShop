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
    //ѡ��ͻ�
    //��ȡ���й˿�
    vector<Customer*> customers = *(_mall->getCustomers());

    //����˿�ѡ��
    for (int i = 0; i < customers.size(); i++)
    {
        cout << (i + 1) << "." << customers[i]->getName() << endl;
    }

    //����뿪��ѡ��
    cout << (customers.size() + 1) << ".�x�_" << endl;
    //�˿�ѡ�����
	size_t selectCustomer = menuCustomerSelect(1, customers.size() + 1);

    //ѡ���뿪ʱֱ�ӽ���
    if (selectCustomer == customers.size() + 1)
    {
        exit(0);
    }

    //��ȡ��ǰѡ�еĿͻ�
    Customer* nowCustomer = customers[selectCustomer - 1];

    //ѡ���̵�
    while (true)
    {
        //��ȡ�����̵�
        vector<Shop*> shops = *(_mall->getShops());

        //����̵�ѡ��
        for (int i = 0; i < shops.size(); i++)
        {
            cout << (i + 1) << "." << shops[i]->getName() << endl;
        }

        //�̵�ѡ�����
		size_t selectShop = menuShopSelect(1, shops.size());
        //��ȡ��ǰѡ�е��̵�
        Shop* nowShop = shops[selectShop - 1];
        //ѡ���̵�Ϳͻ�
        _mall->selectCustomerAndShop(selectCustomer - 1, selectShop - 1);
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
            addClothToShopUI();
        }
        else if (inputNumber == 2)
        {
            //�鿴�����·�
            showAllClothsFormShopUI();
        }
        else if (inputNumber == 3)
        {
            //�����¶���
            createNewOrder();
        }
        else if (inputNumber == 4)
        {
            //�����·�
            addClothToOrder();
        }
        else if (inputNumber == 5)
        {
            //��������
            placeAnOrder();
        }
        else if (inputNumber == 6)
        {
            //�鿴ʣ�����
            showPoints();
        }
        else if (inputNumber == 7)
        {
            //�鿴��ʷ�վ�
            showHistoryOrders();
        }
        else if (inputNumber == 8)
        {
            //�����̳�
            break;
        }
    }
}

//�����·���UI��
void MallUI::addClothToShopUI()
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
        _mall->createNewCloth(clothName, clothDescription, clothPrice);
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
void MallUI::showAllClothsFormShopUI()
{
    cout << std::left << setw(6) << "No." << std::left << setw(50) << "�·����Q" << std::left << setw(10) << "�r��" << std::left << setw(50) << "����" << endl;
    //��ȡ�����·�
    vector<Cloth*> cloths = *(_mall->getClothes());

    //�������
    for (int i = 0; i < cloths.size(); i++)
    {
        cout << std::left << setw(6) << cloths[i]->getId() << std::left << setw(50) << cloths[i]->getName() << std::left << setw(10) << setiosflags(ios::fixed) << setprecision(2) << cloths[i]->getPrice() << std::left << setw(50) << cloths[i]->getDescription() << endl;
    }

    //�����Ϻ��������
    cloths.clear();
}

//�����¶�����UI��
void MallUI::createNewOrder()
{
    _mall->makeNewOrder();
    cout << "�ɹ�������ӆ�Σ�����" << endl;
}

//�����·���UI��
void MallUI::addClothToOrder()
{
    if (_mall->getCurrentOrder() != NULL)
    {
        //��ʾ�����·�
        showAllClothsFormShopUI();
        cout << endl;

        while (true)
        {
            try
            {
                //����ϴε�����
                cin.clear();
                cin.ignore(1024, '\n');
                //��ʼ��������
                int clothId;
                int clothCount;
                //��ȡ�·�id
                cout << "Ոݔ���·�ID���x�_Ոݔ��-1��";
                clothId = checkInputClothId();

                if (clothId == -1)
                {
                    //����-1�����
                    return;
                }

                //�����·��Ƿ����
                Cloth* clothFind = _mall->getSelectShop()->findCloth(clothId);

                if (clothFind->getId() == 0)
                {
                    cout << "δ�ҵ�id��" << clothId << "���·���Ո��ԇ" << endl;
                    continue;
                }

                //��ȡ���·�����
                cout << "Ոݔ���·�������";
                clothCount = checkInputClothCount();

                //��cloth��ӽ�order
                for (int i = 0; i < clothCount; i++)
                {
                    _mall->addOrderToCloth(clothId);
                }
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
    }
    else
    {
        cout << "Ո������ӆ�Σ�����ُ�I�·���" << endl;
    }
}

//����������UI��
void MallUI::placeAnOrder()
{
    //�ж��Ƿ���������
    if (_mall->getCurrentOrder() != NULL)
    {
        //����������������ж�ʣ������Ƿ��㹻
        if (_mall->isPointEnough())
        {
            //��������㹻����۳�����
            _mall->reducePointFromOrder();
            //����������ȡ������
            _mall->cancelOrder();
            cout << "ӆ�νY���ɹ���" << endl;
			//����ǰ����������ʷ����
			_mall->addToHistoryOrders(_mall->getCurrentOrder());
        }
        else
        {
            cout << "ʣ�N�c�����㣬�o���M��ُ�I��" << endl;
        }
    }
    else
    {
        cout << "Ո�Ƚ�����ӆ�Σ����܉�Y��ӆ�Σ�" << endl;
    }
}

//�鿴ʣ�������UI��
void MallUI::showPoints()
{
    cout << "��ʣ�N���c��ʣ�£�" << _mall->getSelectCustomer()->getCash() << endl;
}

//�鿴��ʷ�վݣ�UI��
void MallUI::showHistoryOrders()
{
	cout << _mall->getSelectCustomer()->getName() << "�Ěvʷُ�Iӛ䛣�" << endl;
	cout << std::left << setw(6) << "���Q" << std::left << setw(50) << "����" << std::left << setw(10) << "�΃r" << std::left << setw(50) << "���r" << endl;
	//��ȡ��ʷ����
	vector<Order*>historyOrders = _mall->getHistoryOrders(_mall->getSelectShop());
	//�������
	for (size_t i = 0; i < historyOrders.size(); i++)
	{
		Order* currentOrder = historyOrders[i];


	}
}

//��������Ϣ���·�id���·�������
//map<int, int> organizeOrder(Order* order)
//{
//
//}



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


//�·�id�������
int MallUI::checkInputClothId()
{
    int inputId;
    cin >> inputId;

    //��������ʽ����
    while (cin.fail())
    {
        //������ʾ
        cout << "��ʽ�e�`��Ո����ݔ��" << endl;
        cout << "Ոݔ���·�ID���x�_Ոݔ��-1��";
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> inputId;
    }

    return inputId;
}

//�·������������
int MallUI::checkInputClothCount()
{
    int inputNumber;
    cin >> inputNumber;

    //��������ʽ���󣬻�����С�ڵ���0
    while (cin.fail() || inputNumber <= 0)
    {
        //������ʾ
        cout << "��ʽ�e�`��Ո����ݔ��" << endl;
        cout << "Ոݔ���·�������";
        //���cin�Ĵ���״̬
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> inputNumber;
    }

    return inputNumber;
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

        //��ȡ�¸��ַ�
        item++;
    }

    //���С����򸱺ų���һ��
    if (dotCount > 1 || negativeCount > 1)
    {
        //���ǺϷ��ĸ�����
        return false;
    }

    //�ǺϷ��ĸ�����
    return true;
}