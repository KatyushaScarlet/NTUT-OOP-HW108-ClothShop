#ifndef COMMON
#define COMMON

#include<string>
#include<sstream>
#include<vector>
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"

//�ָ��ı�
vector<string> split(string str, char key);
//�ж��Ƿ�Ϊ�Ϸ�������
bool isDouble(const string& str);
//��ȡCloth.txt�е��·���Ϣ��name description price��
vector<string> getClothContent(string line);
//��ȡCloth.txt�еĵ�������Ϣ��Shop H&M:��
string getShopContent(string line);

#endif