#include "Creature.h"
#include "Summoner.h"
#include <iostream>
#include <iomanip>

using namespace std;

Creature::Creature(int HP, int ATK, const std::string& name, int DEF )
    : HP(HP), ATK(ATK), DEF(DEF), name(name) {}

Creature::Creature(const Creature& c)
    : HP(c.HP), ATK(c.ATK), DEF(c.DEF),  name(c.name) {}

shared_ptr<Creature> Creature:: clone() const {
    return make_shared<Creature>(*this);
}

void Creature::show_info() {
    cout << left << setw(10) << name;
    cout << "HP:" << setw(5) << ((HP > 0) ? HP : 0);
    cout << "ATK:" << setw(5) << ATK; 
    if (DEF) {
        cout << "DEF:" << setw(5) << DEF;
    }
    cout << endl;
}

void Creature::show_HP() {
    cout << this->name << "  ";
    if (this->HP <= 0)
        cout << "HP:0" << endl;
        return ;
    cout << "HP:(" << this->HP << ") " << std::string(this->HP/10 +1, 'x') << endl;
}

bool Creature::have_died() {
    if (this->HP <= 0) {
        cout << this->name << " has died." << endl;
        return true;
    } else {
        return false;
    }
}

void Creature::action(Summoner& master,Summoner& opponent) {
    attack_to(opponent.team);
}

void Creature::attack_to(Cteam& team) {
    for(auto& c: team){
        if(c->HP <= 0)
            continue;
        else{
            if (this->ATK > c->DEF) {
                cout << this->name << " hits " << c->name << " " << this->ATK - c->DEF << "HP" << endl;
                c->HP -= this->ATK - c->DEF;
            }
            if (c->ATK > this->DEF) {
                cout << c->name << " in turn reduces " << this->name << " " << c->ATK - this->DEF << "HP" << endl;
                this->HP -= c->ATK - this->DEF;
            }
            break;
        }
    }
}


Warrior::Warrior(int level, const std::string& name)
    : Creature
    (Warrior_level_HAD(level)[0],
    Warrior_level_HAD(level)[1], 
    name, 
    Warrior_level_HAD(level)[2] ) {}

Warrior::Warrior(int HP, int ATK, const std::string& name, int DEF)
    : Creature(HP, ATK, name, DEF) {}

Warrior::Warrior(const Warrior& w)
    : Creature(w) {}  // 调用基类的拷贝构造函数

vector<int> Warrior::Warrior_level_HAD(int level){
    vector<int> HAD(3);
    HAD[0] = 100 + 10 * level;
    HAD[1] = 10 + 5 * level;
    HAD[2] = 5 + 3 * level;
    return HAD;
}

shared_ptr<Creature> Warrior::clone() const{
    return make_shared<Warrior>(*this);
}

Mage::Mage(int level, const std::string& name)
    : Creature
    (Mage_level_HAD(level)[0],
    Mage_level_HAD(level)[1], 
    name, 
    Mage_level_HAD(level)[2] ) {}

Mage::Mage(int HP, int ATK, const std::string& name, int DEF)
    : Creature(HP, ATK, name, DEF) {}

Mage::Mage(const Mage& m)
    : Creature(m) {}

vector<int> Mage::Mage_level_HAD(int level){
    vector<int> HAD(3);
    HAD[0] = 60 + 10 * level;
    HAD[1] = 10 + 5 * level;
    HAD[2] = 0 + 1 * level;
    return HAD;
}

shared_ptr<Creature> Mage::clone() const{
    return make_shared<Mage>(*this);
}

void Mage::action(Summoner& master,Summoner& opponent){
    Lightning_Chain(opponent.team);
}

void Mage::Lightning_Chain(Cteam& team){
    cout << this->name << " casts Lightning Chain." << endl;
    for(auto& c: team){
        if(c->HP <= 0)
            continue;
        else{
            cout << "Lightning Chain hits " << c->name << " 30HP" << endl;
            c->HP -= 30;
        }
    }
}

shared_ptr<Creature> CList::createCreature(const string& jobType, int level, const string& name) {

    if (jobType == "Warrior") {
        if(name == "Unknown")
            return make_shared<Warrior>(level);
        else
            return make_shared<Warrior>(level, name);
    } else if (jobType == "Mage") {
        if(name == "Unknown")
            return make_shared<Mage>(level);
        else
            return make_shared<Mage>(level, name);
    }
    // 如果未找到，输出提示信息并返回默认的 Warrior 对象
    cout << "无效职业选择，已自动设置为 Warrior。" << endl;
    return make_shared<Warrior>(level, name);
}
