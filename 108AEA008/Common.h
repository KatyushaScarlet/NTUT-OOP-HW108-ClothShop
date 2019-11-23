#ifndef COMMON
#define COMMON

#include<string>
#include<sstream>
#include<vector>
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"

using std::string;
using std::istringstream;
using std::vector;

//分割文本
vector<string> split(string str, char key);
//判断是否为合法浮点数
bool isDouble(const string& str);
//获取Cloth.txt中的衣服信息（name description price）
vector<string> getClothContent(string line);
//获取Cloth.txt中的店铺名信息（Shop H&M:）
string getShopContent(string line);
//自定义Shop的比较规则
bool compareShop(Shop* shop1, Shop* shop2);
//对vector<Shop*>进行排序
void sortShopVector(vector<Shop*>* shops);
//写入店铺信息
void addShops(vector<string> fileContent, vector<Shop*>* _shops);
//读取文件内容
vector<string> readFile(string fileName);
//商店选单防呆
int menuShopSelect(int min, int max);
//商店内操作选单防呆
int menuShopActionSelect(int min, int max);
//文字输入防呆
string checkInputString();
//价格输入防呆
double checkInputPrice();
#endif