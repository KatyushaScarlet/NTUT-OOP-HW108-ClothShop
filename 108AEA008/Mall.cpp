#include<fstream>
#include<string>
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
}

//����·�
void Mall::createNewCloth(string name, string description, double price)
{
    _shops[_shopIndex]->createNewCloth(name, description, price);
}

//ѡ���̵�
void Mall::selectShop(int shopIndex)
{
    _shopIndex = shopIndex;
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

//д�������Ϣ
void Mall::addShops(vector<string> fileContent, vector<Shop*>* _shops)
{
    //��������ָ��
    Shop* newShop = new Shop("");

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
            }

            //�����µĵ���
            newShop = new Shop(getShopContent(fileContent[i]));
        }
        else if (fileContent[i] != "")
        {
            //������ݲ�Ϊ��
            vector<string>newCloth = getClothContent(fileContent[i]);
            //����ǰ��������µ��·�
            newShop->createNewCloth(newCloth[0], newCloth[1], atof(newCloth[2].c_str()));
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

//��ȡCloth.txt�е��·���Ϣ��name description price��
vector<string> Mall::getClothContent(string line)
{
    //��������
    vector<string> output;
    output.push_back("");
    output.push_back("");
    output.push_back("");
    //Ѱ�ҵ�һ�������һ���ָ�����λ��
    int first = line.find_first_of(",");
    int last = line.find_last_of(",");
    ////ת��Ϊchar
    //const char* item = line.c_str();

    //��һ���ַ�����һ���ָ���Ϊֹ�м�Ĳ���
    for (int i = 0; i < first; i++)
    {
        output[0] = output[0] + line[i];
    }

    //��һ���ָ��������һ���ָ���Ϊֹ�м�Ĳ���
    for (int i = first + 1; i < last; i++)
    {
        output[1] = output[1] + line[i];
    }

    //���һ���ָ��������һ���ַ�
    for (int i = last + 1; i < line.length(); i++)
    {
        output[2] = output[2] + line[i];
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