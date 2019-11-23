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

//构造函数
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
}

//开始运行
void MallUI::start()
{
    while (true)
    {
        //获取所有的商店
        vector<Shop*> shops = *(_mall->getShops());

        //输出商店选单
        for (size_t i = 0; i < shops.size(); i++)
        {
            cout << (i + 1) << "." << shops[i]->getName() << endl;
        }

        //商店选择防呆
        int inputNumber = menuShopSelect(1, shops.size());
        //选择商店
        _mall->selectShop(inputNumber);
        //获取当前选中的商店
        Shop* nowShop = shops[inputNumber - 1];
        //商店操作选单
        menuShopUI(nowShop);
    }
}

//商店操作选单（UI）
void MallUI::menuShopUI(Shop* nowShop)
{
    while (true)
    {
        //输出商店操作选单
        cout << "(" << nowShop->getName() << ")" << "1.新增衣服" << endl;
        cout << "(" << nowShop->getName() << ")" << "2.查看所有衣服" << endl;
        cout << "(" << nowShop->getName() << ")" << "3.返回商場" << endl;
        cout << "請輸入選擇：";
        //商店内操作防呆
        int inputNumber = menuShopActionSelect(1, 3);

        //处理输入
        if (inputNumber == 1)
        {
            //新增衣服
            addClothToShopUI(nowShop);
        }
        else if (inputNumber == 2)
        {
            //查看所有衣服
            showAllClothsFormShopUI(nowShop);
        }
        else if (inputNumber == 3)
        {
            //返回商城
            break;
        }
    }
}

//添加衣服（UI）
void MallUI::addClothToShopUI(Shop* nowShop)
{
    try
    {
        //清空上次的输入
        cin.clear();
        cin.ignore(1024, '\n');
        //开始处理输入
        string clothName;
        string clothDescription;
        double clothPrice;
        cout << "請輸入衣服名稱：";
        //文字输入防呆
        clothName = checkInputString();
        cout << "請輸入衣服描述：";
        //文字输入防呆
        clothDescription = checkInputString();
        cout << "請輸入價格：";
        //价格输入防呆
        clothPrice = checkInputPrice();
        nowShop->createNewCloth(clothName, clothDescription, clothPrice);
        cout << "添加完畢！" << endl;
    }
    catch (const std::exception&)
    {
        //其他异常提示
        cout << "發生異常，請重新輸入" << endl;
        //清空cin的错误状态
        cin.clear();
        cin.ignore(1024, '\n');
    }
}

//查看所有衣服（UI）
void MallUI::showAllClothsFormShopUI(Shop* nowShop)
{
    cout << std::left << setw(6) << "No." << std::left << setw(50) << "衣服名稱" << std::left << setw(10) << "價格" << std::left << setw(50) << "描述" << endl;
    //获取所有衣服
    vector<Cloth*> cloths = *(nowShop->getClothes());

    //逐行输出
    for (int i = 0; i < cloths.size(); i++)
    {
        cout << std::left << setw(6) << cloths[i]->getId() << std::left << setw(50) << cloths[i]->getName() << std::left << setw(10) << setiosflags(ios::fixed) << setprecision(2) << cloths[i]->getPrice() << std::left << setw(50) << cloths[i]->getDescription() << endl;
    }

    //输出完毕后清空容器
    cloths.clear();
}

//商店选择防呆
int MallUI::menuShopSelect(int min, int max)
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

//商店内操作防呆
int MallUI::menuShopActionSelect(int min, int max)
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
string MallUI::checkInputString()
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
double MallUI::checkInputPrice()
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

//分割文本
vector<string> MallUI::split(string input, char pattern)
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
bool MallUI::isDouble(const string& str)
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