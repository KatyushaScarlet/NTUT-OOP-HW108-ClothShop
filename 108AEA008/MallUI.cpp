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

//���캯��
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
}

//��ʼ����
void MallUI::start()
{
    while (true)
    {
        //��ȡ���е��̵�
        vector<Shop*> shops = *(_mall->getShops());

        //����̵�ѡ��
        for (size_t i = 0; i < shops.size(); i++)
        {
            cout << (i + 1) << "." << shops[i]->getName() << endl;
        }

        //�̵�ѡ������
        int inputNumber = menuShopSelect(1, shops.size());
        //ѡ���̵�
        _mall->selectShop(inputNumber);
        //��ȡ��ǰѡ�е��̵�
        Shop* nowShop = shops[inputNumber - 1];

        while (true)
        {
            //����̵����ѡ��
            cout << "(" << nowShop->getName() << ")" << "1.�����·�" << endl;
            cout << "(" << nowShop->getName() << ")" << "2.�鿴�����·�" << endl;
            cout << "(" << nowShop->getName() << ")" << "3.�����̈�" << endl;
            cout << "Ոݔ���x��";
            //�̵��ڲ���ѡ������
            int inputNumber = menuShopActionSelect(1, 3);

            //��������
            if (inputNumber == 1)
            {
                //�����·�
                try
                {
                    //����ϴε�����
                    cin.clear();
                    cin.ignore(1024, '\n');
                    //��ʼ��������
                    string clothName;
                    string clothDescription;
                    double clothPrice;
                    cout << "Ոݔ���·����Q��";
                    //�����������
                    clothName = checkInputString();
                    cout << "Ոݔ���·�������";
                    //�����������
                    clothDescription = checkInputString();
                    cout << "Ոݔ��r��";
                    //�۸��������
                    clothPrice = checkInputPrice();
                    nowShop->createNewCloth(clothName, clothDescription, clothPrice);
                    cout << "����ꮅ��" << endl;
                }
                catch (const std::exception&)
                {
                    //�����쳣��ʾ
                    cout << "�l��������Ո����ݔ��" << endl;
                    //���cin�Ĵ���״̬
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
            }
            else if (inputNumber == 2)
            {
                //�鿴�����·�
                cout << std::left << setw(6) << "No." << std::left << setw(50) << "�·����Q" << std::left << setw(10) << "�r��" << std::left << setw(50) << "����" << endl;
                //��ȡ�����·�
                vector<Cloth*> cloths = *(nowShop->getClothes());

                //�������
                for (int i = 0; i < cloths.size(); i++)
                {
                    cout << std::left << setw(6) << cloths[i]->getId() << std::left << setw(50) << cloths[i]->getName() << std::left << setw(10) << setiosflags(ios::fixed) << setprecision(2) << cloths[i]->getPrice() << std::left << setw(50) << cloths[i]->getDescription() << endl;
                }

                //�����Ϻ��������
                cloths.clear();
            }
            else if (inputNumber == 3)
            {
                //�����̳�
                break;
            }
        }
    }
}