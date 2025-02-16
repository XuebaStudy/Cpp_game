#include <iostream>
#include <string>
#include <sstream>

#include "Creature.h"
#include "UserIO.h"

using namespace std;


string inputJob() {
    string job;
    cout << "请输入职业(w: Warrior, m: Mage)(回车默认设置为 Warrior):";
    getline(cin, job);

    // 转换为小写
    for (char &c : job) c = tolower(c);

    if(job.empty()){
        return "Warrior";
    }
    // 查找 jobType 是否在映射中
    auto it = CList::jobMap.find(job);
    if (it != CList::jobMap.end()) {
       return it->second;
    }

    cout << "无效职业选择，已自动设置为 Warrior。" << endl;
    return "Warrior";
}

// 输入等级
int inputLevel() {
    string levelInput;
    cout << "请输入等级(1~40)(回车默认设置为10):";
    getline(cin, levelInput);

    int level;
    if (levelInput.empty()) {
        level = 10;
    } else {
        stringstream ss(levelInput);
        ss >> level;
        if (ss.fail() || !ss.eof()) {
            cout << "输入无效，已自动设置为10。" << endl;
            level = 10;
        }
    }

    if (level < 1 || level > 40) {
        cout << "等级超出范围，已自动设置为 10。" << endl;
        level = 10;
    }
    return level;
}

// 输入姓名
string inputName() {
    string name;
    cout << "请输入姓名(回车跳过):";
    getline(cin, name);
    return name.empty() ? "Unknown" : name;
}

Cteam inputTeam(int n) {
    Cteam team;
    cout << "请输入" << n << "个角色：" << endl << endl;
    for (int i = 1; i <= n; i++) {
        cout << "第 " << i << " 个角色：" << endl;

        // 输入职业、等级和姓名
        string job = inputJob();
        int level = inputLevel();
        string name = inputName();

        // 使用工厂类创建角色
        auto character = CList::createCreature(job, level, name);
        if (character) {
            team.push_back(character);
        } else {
            cout << "创建角色失败，请检查职业类型。" << endl;
        }

        cout << endl;
    }

    return team;
}
