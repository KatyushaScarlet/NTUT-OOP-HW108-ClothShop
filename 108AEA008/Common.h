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

//�ָ��ı�
vector<string> split(string str, char key);
//�ж��Ƿ�Ϊ�Ϸ�������
bool isDouble(const string& str);
//��ȡCloth.txt�е��·���Ϣ��name description price��
vector<string> getClothContent(string line);
//��ȡCloth.txt�еĵ�������Ϣ��Shop H&M:��
string getShopContent(string line);
//�Զ���Shop�ıȽϹ���
bool compareShop(Shop* shop1, Shop* shop2);
//��vector<Shop*>��������
void sortShopVector(vector<Shop*>* shops);
//д�������Ϣ
void addShops(vector<string> fileContent, vector<Shop*>* _shops);
//��ȡ�ļ�����
vector<string> readFile(string fileName);
//�̵�ѡ������
int menuShopSelect(int min, int max);
//�̵��ڲ���ѡ������
int menuShopActionSelect(int min, int max);
//�����������
string checkInputString();
//�۸��������
double checkInputPrice();
#endif