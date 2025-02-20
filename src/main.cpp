#include "AllHeaders.h"

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");
    // system("color 0a");  //设置终端文字颜色为绿色
    cout << "欢迎来到剑与魔法的世界！" << endl << endl;
    string user_name;
    user_name = inputName("冒险者", "你的名字");
    cout << "你好，" << user_name << "！" << endl;

    Menu(user_name);
    system("pause");


    return 0;

}