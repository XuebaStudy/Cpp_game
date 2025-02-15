
#include <iostream>
#include "Summoner.h"

using namespace std;

void battle(Summoner& A, Summoner& B) {
    cout << "Battle between " << A.name << " and " << B.name << endl;
    A.show_info();  // 显示 A 的队伍信息
    B.show_info();  // 显示 B 的队伍信息
    for (int R = 1; R < 100; R++) {
        cout << "---------------------";
        cout << "Round " << R << endl;

        if(R%2){
            A.attack_to(B);
            if (B.Non_live()) {
                cout << "Summoner " << B.name << " has been defeated!" << endl;
                break;}
        }else{
            B.attack_to(A);
            if (A.Non_live()) {
                cout << "Summoner " << A.name << " has been defeated!" << endl;
                break;}
        }
        A.show_info();  // 显示 A 的队伍信息
        B.show_info();  // 显示 B 的队伍信息
    }
    A.show_info();  // 显示 A 的队伍信息
    B.show_info();  // 显示 B 的队伍信息
}