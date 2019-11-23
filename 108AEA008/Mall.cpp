#include"Mall.h"
#include"common.h"
#include<fstream>
using std::ifstream;

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