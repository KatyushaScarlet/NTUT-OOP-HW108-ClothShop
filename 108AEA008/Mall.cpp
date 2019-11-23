#include<fstream>
#include<string>
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
}

//添加衣服
void Mall::createNewCloth(string name, string description, double price)
{
    _shops[_shopIndex]->createNewCloth(name, description, price);
}

//选择商店
void Mall::selectShop(int shopIndex)
{
    _shopIndex = shopIndex;
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
    for (size_t i = 1; i < (shops->size() - 1); i++)
    {
        for (size_t j = i + 1; j < shops->size(); j++)
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

//写入店铺信息
void Mall::addShops(vector<string> fileContent, vector<Shop*>* _shops)
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

//获取Cloth.txt中的衣服信息（name description price）
vector<string> Mall::getClothContent(string line)
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