#include <iostream>
#include <string>

#include "Creature.h"
#include "Summoner.h"
#include "Event.h"
#include "Tools.h"

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
    // system("color 0a");  //设置文字颜色为绿色

    auto m0 = make_shared<Mage>(10);
    auto w3 = make_shared<Warrior>(10);
    Cteam Ateam = {w3,m0};
    Summoner summonerA("A");
    summonerA.summon(Ateam);

    Cteam Bteam = new_team();
    Summoner summonerB("B");
    summonerB.summon(Bteam);

    battle(summonerA,summonerB);

    return 0;
}


