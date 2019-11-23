#include<iostream>
#include<sstream>
#include<fstream>
#include"common.h"
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"

using namespace std;

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