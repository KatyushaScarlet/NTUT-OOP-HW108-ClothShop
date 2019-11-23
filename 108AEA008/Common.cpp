#include<iostream>
#include<sstream>
#include<fstream>
#include"common.h"
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"

using namespace std;

//分割文本
vector<string> split(string input, char pattern)
{
    //转换为字符流
    istringstream inputStream(input);
    string word;
    vector<string> output;

    //逐个读入
    while (getline(inputStream, word, pattern))
    {
        //加入容器
        output.push_back(word);
    }

    return output;
}

//判断是否为合法浮点数
bool isDouble(const string& str)
{
    //小数点的数量
    int dotCount = 0;
    //副号的数量
    int negativeCount = 0;
    //参数转换为char指针
    const char* item = str.c_str();

    while (*item != '\0')
    {
        //逐个判断字符是否为数字
        if (*item < '0' || *item > '9')
        {
            //若不是数字，判断是否为小数点或副号
            if (*item == '.')
            {
                //记录小数点的个数
                dotCount++;
            }
            else if (*item == '-')
            {
                //记录副号的个数
                negativeCount++;
            }
            else
            {
                //若非数字非小数点非副号
                return false;
            }
        }

        item++;
    }

    //如果小数点或副号超过一个
    if (dotCount > 1 || negativeCount > 1)
    {
        return false;
    }

    //是合法的浮点数
    return true;
}

//获取Cloth.txt中的衣服信息（name description price）
vector<string> getClothContent(string line)
{
    //创建容器
    vector<string> output;
    output.push_back("");
    output.push_back("");
    output.push_back("");
    //寻找第一个和最后一个分隔符的位置
    int first = line.find_first_of(",");
    int last = line.find_last_of(",");
    ////转换为char
    //const char* item = line.c_str();

    //第一个字符到第一个分隔符为止中间的部分
    for (int i = 0; i < first; i++)
    {
        output[0] = output[0] + line[i];
    }

    //第一个分隔符到最后一个分隔符为止中间的部分
    for (int i = first + 1; i < last; i++)
    {
        output[1] = output[1] + line[i];
    }

    //最后一个分隔符到最后一个字符
    for (int i = last + 1; i < line.length(); i++)
    {
        output[2] = output[2] + line[i];
    }

    return output;
}

//获取Cloth.txt中的店铺名信息（Shop H&M:）
string getShopContent(string line)
{
    //寻找第一个和最后一个分隔符的位置
    int first = line.find_first_of(" ");
    int last = line.find_last_of(":");
    //输出变量
    string output;

    //取第一个分隔符到最后一个分隔符为止中间的部分
    for (int i = first + 1; i < last; i++)
    {
        output = output + line[i];
    }

    return output;
}