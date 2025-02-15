#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <memory>

class Creature;
class Summoner;
typedef std::vector<std::shared_ptr<Creature>> Cteam;

class Creature {
public:
    std::string name;
    int HP, ATK, DEF;

public:
    Creature(int HP, int ATK, const std::string& name = "Unknown", int DEF = 0 );
    Creature(const Creature& c);

    void show_info();
    void show_HP();
    bool have_died();

    virtual void action(Summoner& master,Summoner& opponent);
    virtual void attack_to(Cteam& team);
};

class Warrior : public Creature {
public:
    Warrior(int level, const std::string& name = "Warrior" );
    Warrior(int HP, int ATK, const std::string& name = "Warrior", int DEF = 0 );
    Warrior(const Warrior& w);

    std::vector<int> Warrior_level_HAD(int level);
};

class Mage : public Creature {
public:
    // int Mage_ATK;

public:
    Mage(int level, const std::string& name = "Mage" );
    Mage(int HP, int ATK, const std::string& name = "Mage", int DEF = 0 );
    Mage(const Mage& m);
    std::vector<int> Mage_level_HAD(int level);

    void action(Summoner& master,Summoner& opponent);

    void Lightning_Chain(Cteam& team);

};

#endif