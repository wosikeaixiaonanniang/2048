#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include "ui.h"
#include "gamecore.h"
using namespace std;
bool GameCore::slideAndMerge(int line[4], int& score)
{
    bool moved = false;
    int temp[4] = { 0 };
    int index = 0;

    // 1. 移动所有数字到左侧（去除0）
    for (int i = 0; i < 4; i++) {
        if (line[i] != 0) {
            temp[index++] = line[i];
        }
    }

    // 2. 合并相邻相同数字
    for (int i = 0; i < 3; i++) {
        if (temp[i] != 0 && temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            score += temp[i]; // 加分
            temp[i + 1] = 0;
            moved = true;
        }
    }

    // 3. 再次移动（处理合并后可能出现的空位）
    index = 0;
    for (int i = 0; i < 4; i++) {
        line[i] = 0;
        if (temp[i] != 0) {
            line[index++] = temp[i];
        }
    }

    // 检查是否发生移动（与原始数据比较）
    for (int i = 0; i < 4; i++) {
        if (line[i] != temp[i]) {
            moved = true;
        }
    }

    return moved;
}

// 主逻辑函数
void GameCore::numberadd(int board[4][4], int& score, int direction)
{
    bool moved = false;
    int temp[4];

    switch (direction) {
    case DIR_UP:
        // 处理每一列（从上到下）
        for (int j = 0; j < 4; j++) {
            // 提取一列
            for (int i = 0; i < 4; i++) temp[i] = board[i][j];
            // 处理这一列
            if (slideAndMerge(temp, score)) moved = true;
            // 写回
            for (int i = 0; i < 4; i++) board[i][j] = temp[i];
        }
        break;

    case DIR_DOWN:
        // 处理每一列（从下到上）
        for (int j = 0; j < 4; j++) {
            // 提取一列（反向）
            for (int i = 0; i < 4; i++) temp[3 - i] = board[i][j];
            // 处理这一列
            if (slideAndMerge(temp, score)) moved = true;
            // 写回（反向）
            for (int i = 0; i < 4; i++) board[i][j] = temp[3 - i];
        }
        break;

    case DIR_LEFT:
        // 处理每一行（从左到右）
        for (int i = 0; i < 4; i++) {
            // 直接处理行
            if (slideAndMerge(board[i], score)) moved = true;
        }
        break;

    case DIR_RIGHT:
        // 处理每一行（从右到左）
        for (int i = 0; i < 4; i++) {
            // 提取一行（反向）
            for (int j = 0; j < 4; j++) temp[3 - j] = board[i][j];
            // 处理这一行
            if (slideAndMerge(temp, score)) moved = true;
            // 写回（反向）
            for (int j = 0; j < 4; j++) board[i][j] = temp[3 - j];
        }
        break;
    }
}
void GameUI::registerUser(string name, string password)
{
    const string filename = "user.txt";
    vector<User> users;

    // 读取现有用户
    ifstream inFile(filename);
    if (inFile) {
        User u;
        while (inFile >> u.name >> u.password) {
            users.push_back(u);
        }
        inFile.close();
    }

    bool userExists = false;
    for (const auto& u : users) {
        if (u.name == name) {
            userExists = true;
            usercheck = true;
            showerror("账户已存在");

            break;
        }
    }

    // 如果用户名不存在，则注册新用户
    if (!userExists)
    {
        User newUser;
        newUser.name = name;
        newUser.password = password;
        users.push_back(newUser);

        // 写回文件
        ofstream outFile(filename);
        for (const auto& u : users) {
            outFile << u.name << " " << u.password << "\n";
        }
        outFile.close();
        showerror("注册成功");

        //cout << "注册成功！" << endl;
    }
}
bool GameUI::checkUser(string name, string password)
{
    const string filename = "user.txt";
    ifstream inFile(filename);

    if (!inFile) {
        // cerr << "用户数据库不存在或无法打开！" << endl;
        return false;
    }

    User currentUser;
    while (inFile >> currentUser.name >> currentUser.password)
    {
        if (currentUser.name == name) {
            inFile.close(); // 关闭文件流
            if (currentUser.password != password)
                showerror("密码错误");

            return (currentUser.password == password); // 密码匹配返回 true，否则 false
        }
    }

    inFile.close();
    showerror("账户不存在");

    return false; // 用户名不存在
}
void GameCore::newnumber(int board[4][4], int& score, int n)

{
    // 收集所有空位位置
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptyCells.push_back(make_pair(i, j));
            }
        }
    }

    if (emptyCells.empty())
        return; // 没有空位

    // 随机选择一个空位
    int index = rand() % emptyCells.size();
    int x = emptyCells[index].first;
    int y = emptyCells[index].second;

    // 生成新数字 (2或4，90%概率为2，10%概率为4)
    int newValue = (rand() % 10 < 9) ? 2 : 4;

    // 确保新数字不超过n
    while (newValue > n) {
        newValue /= 2;
    }

    board[x][y] = newValue;
    score += newValue; // 增加分数
}

// 计时功能实现
void Time::startTimer(GameTimer& timer)
{
    timer.startTime = clock();
    timer.elapsedSeconds = 0;
    timer.isPaused = false;
}

void Time::pauseTimer(GameTimer& timer)
{
    if (!timer.isPaused) {
        timer.pauseTime = clock();
        timer.isPaused = true;
        timer.elapsedSeconds += static_cast<int>((timer.pauseTime - timer.startTime) / CLOCKS_PER_SEC);
    }
}

void Time::resumeTimer(GameTimer& timer)
{
    if (timer.isPaused) {
        timer.startTime = clock();
        timer.isPaused = false;
    }
}

void Time::getGameTime(GameTimer& timer)
{
    int totalSeconds = timer.elapsedSeconds;
    if (!timer.isPaused) {
        totalSeconds += static_cast<int>((clock() - timer.startTime) / CLOCKS_PER_SEC);
    }

    this->hours = totalSeconds / 3600;
    this->minutes = (totalSeconds % 3600) / 60;
    this->seconds = totalSeconds % 60;
}

// 记录分数到文件
void GameCore::record(string name, int score, int step)
{
    const string filename = "game_records.txt";
    vector<Player> records;

    // 读取现有记录
    ifstream inFile(filename);
    if (inFile) {
        Player p;
        while (inFile >> p.name >> p.score >> p.step) {
            records.push_back(p);
        }
        inFile.close();
    }

    // 更新或添加记录
    bool found = false;
    for (auto& p : records) {
        if (p.name == name) {
            found = true;
            if (score > p.score) {
                p.score = score;
                p.step = step;
            }
            break;
        }
    }

    if (!found) {
        Player newPlayer;
        newPlayer.name = name;
        newPlayer.score = score;
        newPlayer.step = step;
        records.push_back(newPlayer);
    }

    // 按分数排序
    sort(records.begin(), records.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
        });

    // 写回文件
    ofstream outFile(filename);
    for (const auto& p : records) {
        outFile << p.name << " " << p.score << " " << p.step << "\n";
    }
    outFile.close();
}

// 显示所有记录
Player* showrecord()
{
    const string filename = "game_records.txt";
    Player* head = nullptr;
    Player* tail = nullptr;

    ifstream inFile(filename);
    if (!inFile)
        return nullptr;

    // 读取记录并构建链表
    Player p;
    int rank = 1;
    while (inFile >> p.name >> p.score >> p.step) {
        p.rank = rank++;

        Player* newNode = new Player;
        *newNode = p;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    inFile.close();
    return head;
}

// 查找特定玩家的记录
Player* GameCore::findrecord(string name)
{
    Player* allRecords = showrecord();
    Player* current = allRecords;
    Player* result = nullptr;

    while (current) {
        if (current->name == name) {
            result = new Player;
            *result = *current;
            result->next = nullptr;
            break;
        }
        current = current->next;
    }

    // 清理临时链表
    while (allRecords) {
        Player* temp = allRecords;
        allRecords = allRecords->next;
        delete temp;
    }

    return result; // 找不到时返回nullptr
}
