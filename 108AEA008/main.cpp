/*
作業：HW10 連續3
系所：資訊工程
班級：二資陸生一
學號：108AEA008
姓名：王翔
*/

#include<iostream>
#include"Mall.h"
#include"MallUI.h"

using namespace std;

int main()
{
    Mall mall;
    MallUI ui(&mall);
    ui.start();
    system("PAUSE");
    return 0;
}