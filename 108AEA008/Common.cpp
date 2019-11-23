#include<iostream>
#include<sstream>
#include<fstream>
#include"common.h"
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

//�ָ��ı�
vector<string> split(string input, char pattern)
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
bool isDouble(const string& str)
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

//��ȡCloth.txt�е��·���Ϣ��name description price��
vector<string> getClothContent(string line)
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
string getShopContent(string line)
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

//�Զ���Shop�ıȽϹ���
bool compareShop(Shop* shop1, Shop* shop2)
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
void sortShopVector(vector<Shop*>* shops)
{
    //����ð������
    for (size_t i = 1; i < (shops->size() - 1); i++)
    {
        for (size_t j = i + 1; j < shops->size(); j++)
        {
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
void addShops(vector<string> fileContent, vector<Shop*>* _shops)
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
vector<string> readFile(string fileName)
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

//�̵�ѡ������
int menuShopSelect(int min, int max)
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

//�̵��ڲ���ѡ������
int menuShopActionSelect(int min, int max)
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
string checkInputString()
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
double checkInputPrice()
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
