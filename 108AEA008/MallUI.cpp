#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include"Cloth.h"
#include"Shop.h"
#include"Mall.h"
#include"MallUI.h"
#include"common.h"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::ios;
using std::string;
using std::vector;
using std::ifstream;

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

        //商店选单防呆
        int inputNumber = menuShopSelect(1, shops.size());
        //选择商店
        _mall->selectShop(inputNumber);
        //获取当前选中的商店
        Shop* nowShop = shops[inputNumber - 1];

        while (true)
        {
            //输出商店操作选单
            cout << "(" << nowShop->getName() << ")" << "1.新增衣服" << endl;
            cout << "(" << nowShop->getName() << ")" << "2.查看所有衣服" << endl;
            cout << "(" << nowShop->getName() << ")" << "3.返回商場" << endl;
            cout << "請輸入選擇：";
            //商店内操作选单防呆
            int inputNumber = menuShopActionSelect(1, 3);

            //处理输入
            if (inputNumber == 1)
            {
                //新增衣服
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
                    continue;
                }
            }
            else if (inputNumber == 2)
            {
                //查看所有衣服
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
            else if (inputNumber == 3)
            {
                //返回商城
                break;
            }
        }
    }
}