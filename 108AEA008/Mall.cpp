#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<map>
#include"Mall.h"

using namespace std;

//���캯��
Mall::Mall()
{
    //��ȡ�ļ�
    vector<string> fileContent = readFile("Cloth.txt");
    //ʹ�ö�ȡ����������ӵ���
    addShops(fileContent, &_shops);
    //���ݹ����������
    sortShopVector(&_shops);
    //���Ĭ�Ϲ˿�
    addCustomer(new Customer("Amber"));
    addCustomer(new Customer("Tim"));
    addCustomer(new Customer("Marry"));
}

//����·�
void Mall::createNewCloth(string name, string description, double price)
{
    _shops[_shopIndex]->addNewCloth(name, description, price);
}

//��ȡ�����·�
vector<Cloth*>* Mall::getClothes()
{
    return _shops[_shopIndex]->getClothes();
}

//��ȡ�����̵�
vector<Shop*>* Mall::getShops()
{
    return &_shops;
}

//��ȡ���й˿�
vector<Customer*>* Mall::getCustomers()
{
    return &_customers;
}

//�����¶���
void Mall::makeNewOrder()
{
    _customers[_customerIndex]->makeNewOrder(_shops[_shopIndex]);
}

//�򶩵�����·�
void Mall::addOrderToCloth(int id)
{
    Cloth* selectCloth = _shops[_shopIndex]->findCloth(id);
    _customers[_customerIndex]->addClothToOrder(selectCloth);
}

//ѡ��˿����̵�
void Mall::selectCustomerAndShop(int custimerIndex, int shopIndex)
{
    _customerIndex = custimerIndex;
    _shopIndex = shopIndex;
}

//�жϵ����Ƿ��㹻
bool Mall::isPointEnough()
{
    return _customers[_customerIndex]->isPointEnough();
}

//�Ӷ�����ȡ����
void Mall::reducePointFromOrder()
{
    _customers[_customerIndex]->reducePointFromOrder();
}

//ȡ������
void Mall::cancelOrder()
{
    _customers[_customerIndex]->cancelOrder();
}

//��ȡ��ǰ�Ķ���
Order* Mall::getCurrentOrder()
{
    return _customers[_customerIndex]->getCurrentOrder();
}

//�Զ���Shop�ıȽϹ���
bool Mall::compareShop(Shop* shop1, Shop* shop2)
{
    //�ȸ��ݵ����·���������
    //�ٸ�����������ĸ����
    if (shop1->getClothes()->size() < shop2->getClothes()->size())
    {
        return true;
    }
    else if (shop1->getName()[0] < shop2->getName()[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

//��vector<Shop*>��������
void Mall::sortShopVector(vector<Shop*>* shops)
{
    //����ð������
    for (size_t i = 1; i < (shops->size() - 1); i++)
    {
        for (size_t j = i + 1; j < shops->size(); j++)
        {
            //�����Զ�����Ƚϴ�С
            if (compareShop((*shops)[i + 1], (*shops)[i]))
            {
                Shop* temp = (*shops)[i + 1];
                (*shops)[i + 1] = (*shops)[i];
                (*shops)[i] = temp;
            }
        }
    }
}

//��ӹ˿���Ϣ
void Mall::addCustomer(Customer* customer)
{
    _customers.push_back(customer);
}

//д�������Ϣ
void Mall::addShops(vector<string> fileContent, vector<Shop*>* _shops)
{
    //��������ָ��
    Shop* newShop = new Shop("");
    //��ǰ���̵��·��嵥<index,cloth>
    map<int, unique_ptr<Cloth>> clothList;

    //д�������Ϣ
    for (size_t i = 0; i < fileContent.size(); i++)
    {
        //��������ǵ�����
        if (fileContent[i].find("Shop") != fileContent[i].npos)
        {
            if (i != 0)
            {
                //���ϴδ����ĵ��̼����б���
                _shops->push_back(newShop);
                //����·��嵥
                clothList.erase(clothList.begin(), clothList.end());
            }

            //�����µĵ���
            newShop = new Shop(getShopContent(fileContent[i]));
        }
        else if (fileContent[i] != "")
        {
            //������ݲ�Ϊ��
            vector<string>newItem = split(fileContent[i], ',');

            if (newItem[3] != "Suite")
            {
                //����·�
                newShop->addNewCloth(newItem[1], newItem[2], atof(newItem[3].c_str()));
                //���·���Ϣ��ӵ�map��
            }
            else
            {
                //�����װ
            }

            //vector<string>newCloth = getClothContent(fileContent[i]);
            ////����ǰ��������µ��·�
            //newShop->addNewCloth(newCloth[0], newCloth[1], atof(newCloth[2].c_str()));
        }
    }

    //�����һ�δ����ĵ��̼����б���
    _shops->push_back(newShop);
}

//��ȡ�ļ�����
vector<string> Mall::readFile(string fileName)
{
    //��ȡ�ļ�
    ifstream file(fileName);
    //�ļ�ÿ��
    string fileLine;
    //�ļ�����
    vector<string> fileContent;

    //���ж�ȡ�ļ�
    while (getline(file, fileLine))
    {
        fileContent.push_back(fileLine);
    }

    //�ر��ļ�
    file.close();
    //���ؽ��
    return fileContent;
}

//ȥ����λ�ո�
string& Mall::clearHeadTailSpace(string& input)
{
    if (input.empty())
    {
        return input;
    }

    input.erase(0, input.find_first_not_of(" "));
    input.erase(input.find_last_not_of(" ") + 1);
    return input;
}

////�ָ��ı�
//vector<string> Mall::split(const string& input, const string& sym)
//{
//    vector<string> output;
//
//    if (input == "")
//    {
//        return output;
//    }
//
//    //�Ƚ�Ҫ�ָ���ַ�����string����ת��Ϊchar*����
//    char* buffer;
//    char* strs = new char[input.length() + 1];
//    strcpy_s(strs, strlen(strs) + 1, input.c_str());
//    char* d = new char[sym.length() + 1];
//    strcpy_s(d, strlen(d) + 1, sym.c_str());
//    char* p = strtok_s(strs, d, &buffer);
//
//    while (p)
//    {
//        string s = p; //�ָ�õ����ַ���ת��Ϊstring����
//        output.push_back(s); //����������
//        p = strtok_s(NULL, d, &buffer);
//    }
//
//    return output;
//}

//�ָ��ı�
vector<string> Mall::split(string input, char pattern)
{
    //ת��Ϊ�ַ���
    istringstream inputStream(input);
    string word;
    vector<string> output;

    //�������
    while (getline(inputStream, word, pattern))
    {
        //ȥ����λ�ո�
        word = clearHeadTailSpace(word);
        //��������
        output.push_back(word);
    }

    return output;
}

//��ȡCloth.txt�еĵ�������Ϣ��Shop H&M:��
string Mall::getShopContent(string line)
{
    //Ѱ�ҵ�һ�������һ���ָ�����λ��
    int first = line.find_first_of(" ");
    int last = line.find_last_of(":");
    //�������
    string output;

    //ȡ��һ���ָ��������һ���ָ���Ϊֹ�м�Ĳ���
    for (int i = first + 1; i < last; i++)
    {
        output = output + line[i];
    }

    return output;
}

//��ȡ��ǰѡ�е��̵�
Shop* Mall::getSelectShop()
{
    return _shops[_shopIndex];
}

//��ȡ��ǰѡ�еĹ˿�
Customer* Mall::getSelectCustomer()
{
    return _customers[_customerIndex];
}