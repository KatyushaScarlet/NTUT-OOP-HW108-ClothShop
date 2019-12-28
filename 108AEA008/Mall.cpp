#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<map>
#include"Mall.h"

using namespace std;

//构造函数
Mall::Mall()
{
    //读取文件
    vector<string> fileContent = readFile("Cloth.txt");
    //使用读取到的内容添加店铺
    addShops(fileContent, &_shops);
    //根据规则排序店铺
    sortShopVector(&_shops);
    //添加默认顾客
    addCustomer(new Customer("Amber"));
    addCustomer(new Customer("Tim"));
    addCustomer(new Customer("Marry"));
}

//添加衣服
void Mall::createNewCloth(string name, string description, double price)
{
    _shops[_shopIndex]->addNewCloth(name, description, price);
}

//获取所有衣服
vector<Cloth*>* Mall::getClothes()
{
    return _shops[_shopIndex]->getClothes();
}

//获取所有商店
vector<Shop*>* Mall::getShops()
{
    return &_shops;
}

//获取所有顾客
vector<Customer*>* Mall::getCustomers()
{
    return &_customers;
}

//创建新订单
void Mall::makeNewOrder()
{
    _customers[_customerIndex]->makeNewOrder(_shops[_shopIndex]);
}

//向订单添加衣服
void Mall::addOrderToCloth(int id)
{
    Cloth* selectCloth = _shops[_shopIndex]->findCloth(id);
    _customers[_customerIndex]->addClothToOrder(selectCloth);
}

//选择顾客与商店
void Mall::selectCustomerAndShop(int custimerIndex, int shopIndex)
{
    _customerIndex = custimerIndex;
    _shopIndex = shopIndex;
}

//判断点数是否足够
bool Mall::isPointEnough()
{
    return _customers[_customerIndex]->isPointEnough();
}

//从订单扣取点数
void Mall::reducePointFromOrder()
{
    _customers[_customerIndex]->reducePointFromOrder();
}

//取消订单
void Mall::cancelOrder()
{
    _customers[_customerIndex]->cancelOrder();
}

//获取当前的订单
Order* Mall::getCurrentOrder()
{
    return _customers[_customerIndex]->getCurrentOrder();
}

//自定义Shop的比较规则
bool Mall::compareShop(Shop* shop1, Shop* shop2)
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
void Mall::sortShopVector(vector<Shop*>* shops)
{
    //采用冒泡排序
    for (int i = 1; i < (shops->size() - 1); i++)
    {
        for (int j = i + 1; j < shops->size(); j++)
        {
            //采用自定规则比较大小
            if (compareShop((*shops)[i + 1], (*shops)[i]))
            {
                Shop* temp = (*shops)[i + 1];
                (*shops)[i + 1] = (*shops)[i];
                (*shops)[i] = temp;
            }
        }
    }
}

//添加顾客信息
void Mall::addCustomer(Customer* customer)
{
    _customers.push_back(customer);
}

//写入店铺信息
void Mall::addShops(vector<string> fileContent, vector<Shop*>* _shops)
{
    //创建店铺指针
    Shop* newShop = new Shop("");
    //当前店铺的衣服<index,cloth>
    map<int, shared_ptr<vector<string>>> clothMap;

    //写入店铺信息
    for (int i = 0; i < fileContent.size(); i++)
    {
        //如果内容是店铺名
        if (fileContent[i].find("Shop") != fileContent[i].npos)
        {
            if (i != 0)
            {
                //将上次创建的店铺加入列表中
                _shops->push_back(newShop);
                //清空衣服清单
                clothMap.erase(clothMap.begin(), clothMap.end());
            }

            //创建新的店铺
            newShop = new Shop(getShopContent(fileContent[i]));
        }
        else if (fileContent[i] != "")
        {
            //如果内容不为空
            vector<string>newItem = split(fileContent[i], ',');

            if (newItem[3] != "Suite")
            {
                //添加衣服
                newShop->addNewCloth(newItem[1], newItem[2], atof(newItem[3].c_str()));
                //将衣服信息添加到map中
                clothMap.insert(make_pair(atoi(newItem[0].c_str()), make_unique<vector<string>>(newItem)));
            }
            else
            {
                //添加套装
                //获取套装中的衣服清单
                //int suiteList[10];
                vector<Cloth*> suiteList;
                double totalPrice = 0.0;
                //前4个元素为基础信息，跳过
                int suiteSize = newItem.size() - 4;

                for (int i = 0; i < suiteSize; i++)
                {
                    //获取衣服index
                    int index = atoi(newItem[i + 4].c_str());
                    //根据index获取要添加的衣服信息
                    shared_ptr<vector<string>> ptr = clothMap[index];
                    //获取单价
                    double clothPrice = atoi((*ptr)[3].c_str());
                    //加入套装清单
                    suiteList.push_back(new Cloth((*ptr)[1], (*ptr)[2], clothPrice, -1));
                    //加入总价格
                    totalPrice += clothPrice;
                }

                //总价打九折
                totalPrice *= 0.9;
                //添加套装
                newShop->addNewSuite(newItem[1], newItem[2], totalPrice, suiteList);
            }
        }
    }

    //将最后一次创建的店铺加入列表中
    _shops->push_back(newShop);
}

//读取文件内容
vector<string> Mall::readFile(string fileName)
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

//去除首位空格
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

//分割文本
vector<string> Mall::split(string input, char pattern)
{
    //转换为字符流
    istringstream inputStream(input);
    string word;
    vector<string> output;

    //逐个读入
    while (getline(inputStream, word, pattern))
    {
        //去除首位空格
        word = clearHeadTailSpace(word);
        //加入容器
        output.push_back(word);
    }

    return output;
}

//获取Cloth.txt中的店铺名信息（Shop H&M:）
string Mall::getShopContent(string line)
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

//获取当前选中的商店
Shop* Mall::getSelectShop()
{
    return _shops[_shopIndex];
}

//获取当前选中的顾客
Customer* Mall::getSelectCustomer()
{
    return _customers[_customerIndex];
}