#include "AllHeaders.h"

using namespace std;

Cteam new_team(){
    auto w0 = make_shared<Warrior>(10);
    auto w1 = make_shared<Warrior>(10);
    auto w2 = make_shared<Warrior>(10);
    Cteam team = {w0,w1,w2};
    return team;
}

int main(){
    system("chcp 65001");
    system("cls");
    // system("color 0a");  //设置终端文字颜色为绿色
    cout << "欢迎来到剑与魔法的世界！" << endl << endl;
    string user_name;
    user_name = inputName("冒险者", "你的名字");
    cout << "你好，" << user_name << "！" << endl;
    system("pause");

    // SimulateBattle();

    return 0;

}


