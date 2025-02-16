#include <iostream>
#include <string>

#include "Creature.h"
#include "Summoner.h"
#include "Event.h"
#include "Tools.h"
#include "UserIO.h"

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

    int n;
    string nInput;
    Summoner A("A");
    cout << "请输入A的队伍：" << endl;
    Cteam Ateam = inputTeam(3);
    A.summon(Ateam);
    A.show_info();

    Summoner B("B");
    cout << "请输入B的队伍：" << endl;
    Cteam Bteam = inputTeam(3);
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
    return 0;

}


