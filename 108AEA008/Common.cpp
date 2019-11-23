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

//自定义Shop的比较规则
bool compareShop(Shop* shop1, Shop* shop2)
{
    //先根据店内衣服数量升序
    //再根据名称首字母升序
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

//对vector<Shop*>进行排序
void sortShopVector(vector<Shop*>* shops)
{
    //采用冒泡排序
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

//写入店铺信息
void addShops(vector<string> fileContent, vector<Shop*>* _shops)
{
    //创建店铺指针
    Shop* newShop = new Shop("");

    //写入店铺信息
    for (size_t i = 0; i < fileContent.size(); i++)
    {
        //如果内容是店铺名
        if (fileContent[i].find("Shop") != fileContent[i].npos)
        {
            if (i != 0)
            {
                //将上次创建的店铺加入列表中
                _shops->push_back(newShop);
            }

            //创建新的店铺
            newShop = new Shop(getShopContent(fileContent[i]));
        }
        else if (fileContent[i] != "")
        {
            //如果内容不为空
            vector<string>newCloth = getClothContent(fileContent[i]);
            //将当前店铺添加新的衣服
            newShop->createNewCloth(newCloth[0], newCloth[1], atof(newCloth[2].c_str()));
        }
    }

    //将最后一次创建的店铺加入列表中
    _shops->push_back(newShop);
}

//读取文件内容
vector<string> readFile(string fileName)
{
    //读取文件
    ifstream file(fileName);
    //文件每行
    string fileLine;
    //文件内容
    vector<string> fileContent;

    //逐行读取文件
    while (getline(file, fileLine))
    {
        fileContent.push_back(fileLine);
    }

    //关闭文件
    file.close();
    //返回结果
    return fileContent;
}

//商店选单防呆
int menuShopSelect(int min, int max)
{
    //读取输入
    int inputNumber;
    cout << "Select Shop:";
    cin >> inputNumber;

    //如果输入的数据类型不正确，或超出范围
    while (cin.fail() || (inputNumber < min || inputNumber > max))
    {
        //错误提示
        cout << "請選擇畫面上的店家" << endl;
        //清空cin的错误状态
        cin.clear();
        cin.ignore(1024, '\n');
        //重新读取输入
        cout << "Select Shop:";
        cin >> inputNumber;
    }

    return inputNumber;
}

//商店内操作选单防呆
int menuShopActionSelect(int min, int max)
{
    //读取输入
    int inputNumber;
    cin >> inputNumber;

    //如果输入的数据类型不正确，或超出范围
    while (cin.fail() || (inputNumber < min || inputNumber > max))
    {
        //错误提示
        cout << "請輸入正確選項：";
        //清空cin的错误状态
        cin.clear();
        cin.ignore(1024, '\n');
        //重新读取输入
        cin >> inputNumber;
    }

    return inputNumber;
}

//文字输入防呆
string checkInputString()
{
    string inputString;
    getline(cin, inputString);

    //如果输入格式错误或长度为空
    while (cin.fail() || inputString == "")
    {
        //错误提示
        cout << "輸入錯誤，請重新輸入：";
        //清空cin的错误状态
        cin.clear();
        cin.ignore(1024, '\n');
        getline(cin, inputString);
    }

    return inputString;
}

//价格输入防呆
double checkInputPrice()
{
    double price;
    string inputString;
    cin >> inputString;
    //尝试转换为浮点类
    price = atof(inputString.c_str());

    //如果输入格式错误或范围错误
    while (cin.fail() || !isDouble(inputString) || price <= 0)
    {
        //错误提示
        cout << "價格不能小於等於零，請重新輸入" << endl;
        cout << "請輸入價格：";
        //清空cin的错误状态
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> inputString;
        //尝试转换为浮点类
        price = atof(inputString.c_str());
    }

    return price;
}
