#include "AllHeaders.h"

using namespace std;

void Menu(const string& user_name){
    do{
        cout << "请选择模式：" << endl << endl;
        cout << "1. 模拟战斗" << endl;
        cout << "Else or 0. 退出世界" << endl;
        int mode;
        mode = inputInt(0, 1, 0, "模式");

        switch(mode){
            case 1:
                cout << endl;
                SimulateBattle();
                continue;
            case 0:
                cout << "欢迎下次再来！" << endl;
                return ;
        }
    }while(true);
}

void SimulateBattle(){
    cout << "欢迎来到模拟战斗！" << endl << endl;
    int n;
    string nInput;
    Summoner A("A");
    cout << "请输入A的队伍：" << endl;
    cout << "输入A的队伍人数：" << endl;
    n = inputInt(1, 5, 3, "队伍人数");
    Cteam Ateam = inputTeam(n);
    A.summon(Ateam);
    A.show_info();

    Summoner B("B");
    cout << "请输入B的队伍：" << endl;
    cout << "输入B的队伍人数：" << endl;
    n = inputInt(1, 5, 3, "队伍人数");
    Cteam Bteam = inputTeam(n);
    B.summon(Bteam);
    B.show_info();
    system("pause");

    cout << "3 秒后开始战斗" << endl << endl;
    sleep(1);
    cout << "3" << endl << endl;
    sleep(1);
    cout << "2" << endl << endl;
    sleep(1);
    cout << "1" << endl << endl;
    sleep(1);

    battle(A,B);

    cout << endl << "感谢您的试玩 !!!" << endl << endl;

    system("pause");
}