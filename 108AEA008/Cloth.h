#ifndef CLOTH
#define CLOTH

#include<string>
#include<vector>

using namespace std;

class Cloth
{
    private:
        //衣服id
        int _id;
        //衣服名称
        string _name;
        //衣服描述
        string _description;
        //衣服价格
        double _price;
    public:
        //构造函数
        Cloth(string name, string description, double price, int id);
        //获取衣服名称
        string getName();
        //获取衣服描述
        string getDescription();
        //获取衣服信息
        string getInformation();
        //获取衣服价格
        double getPrice();
        //获取衣服id
        int getId();
};
#endif