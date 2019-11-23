#ifndef COMMON
#define COMMON

#include<string>
#include<sstream>
#include<vector>
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"

//分割文本
vector<string> split(string str, char key);
//判断是否为合法浮点数
bool isDouble(const string& str);
//获取Cloth.txt中的衣服信息（name description price）
vector<string> getClothContent(string line);
//获取Cloth.txt中的店铺名信息（Shop H&M:）
string getShopContent(string line);

#endif