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
        //获取所有顾客
        vector<Customer*> customers = *(_mall->getCustomers());

        //输出顾客选单
        for (size_t i = 0; i < customers.size(); i++)
        {
            cout << (i + 1) << "." << customers[i]->getName() << endl;
        }

        //添加离开的选项
        cout << (customers.size() + 1) << ".離開" << endl;
        //顾客选择防呆
        int selectCustomer = menuCustomerSelect(1, customers.size() + 1);

        //选择离开时直接结束
        if (selectCustomer == customers.size() + 1)
        {
            exit(0);
        }

        //获取当前选中的客户
        Customer* nowCustomer = customers[selectCustomer - 1];
        //获取所有商店
        vector<Shop*> shops = *(_mall->getShops());

        //输出商店选单
        for (size_t i = 0; i < shops.size(); i++)
        {
            cout << (i + 1) << "." << shops[i]->getName() << endl;
        }

        //商店选择防呆
        int selectShop = menuShopSelect(1, shops.size());
        //获取当前选中的商店
        Shop* nowShop = shops[selectShop - 1];
        //选择商店和客户
        _mall->selectCustomerAndShop(selectCustomer, selectShop);
        //商店操作选单
        menuShopUI(nowShop, nowCustomer);
    }
}

//商店操作选单（UI）
void MallUI::menuShopUI(Shop* nowShop, Customer* nowCustomer)
{
    while (true)
    {
        //输出欢迎信息
        cout << "親愛的顧客：" << nowCustomer->getName() << "，您好！" << endl;
        //输出商店操作选单
        cout << "(" << nowShop->getName() << ")" << "1.新增衣服" << endl;
        cout << "(" << nowShop->getName() << ")" << "2.查看所有衣服" << endl;
        cout << "(" << nowShop->getName() << ")" << "3.建立新訂單" << endl;
		cout << "(" << nowShop->getName() << ")" << "4.購買衣服" << endl;
		cout << "(" << nowShop->getName() << ")" << "5.結束訂單" << endl;
		cout << "(" << nowShop->getName() << ")" << "6.查看剩餘點數" << endl;
		cout << "(" << nowShop->getName() << ")" << "7.查看歷史收據" << endl;
		cout << "(" << nowShop->getName() << ")" << "8.離開" << endl;
        cout << "請輸入選擇：";
        //商店内操作防呆
        int inputNumber = menuShopActionSelect(1, 8);

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
			//建立新订单
			createNewOrder(nowShop, nowCustomer);
        }
		else if (inputNumber == 4)
		{
			//购买衣服
			addClothToOrder(nowShop, nowCustomer);
		}
		else if (inputNumber == 5)
		{
			//结束订单
			placeAnOrder(nowShop, nowCustomer);
		}
		else if (inputNumber == 6)
		{
			//查看剩余点数
			showPoints(nowCustomer);
		}
		else if (inputNumber == 7)
		{
			//查看历史收据
			showHistoryOrders(nowCustomer);
		}
		else if (inputNumber == 8)
		{
			//返回商城
			break;
		}
    }
}

//新增衣服（UI）
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

//建立新订单（UI）
void MallUI::createNewOrder(Shop* nowShop, Customer* nowCustomer)
{
	cout << "TODO createNewOrder" << endl;
}
//购买衣服（UI）
void MallUI::addClothToOrder(Shop* nowShop, Customer* nowCustomer)
{
	cout << "TODO addClothToOrder" << endl;
}
//结束订单（UI）
void MallUI::placeAnOrder(Shop* nowShop, Customer* nowCustomer)
{
	cout << "TODO addClothToOrder" << endl;
}

//查看剩余点数（UI）
void MallUI::showPoints(Customer* customer) 
{
	cout << "您剩餘的點數剩下：" << customer->getCash() << endl;
}

//查看历史收据（UI）
void MallUI::showHistoryOrders(Customer* customer)
{
	cout << "本功能尚未完成實作" << endl;
}

//顾客选择防呆
int MallUI::menuCustomerSelect(int min, int max)
{
    //读取输入
    int inputNumber;
    cout << "Select Customer:";
    cin >> inputNumber;

    //如果输入的数据类型不正确，或超出范围
    while (cin.fail() || (inputNumber < min || inputNumber > max))
    {
        //错误提示
        cout << "請選擇畫面上的顾客" << endl;
        //清空cin的错误状态
        cin.clear();
        cin.ignore(1024, '\n');
        //重新读取输入
        cout << "Select Customer:";
        cin >> inputNumber;
    }

    return inputNumber;
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