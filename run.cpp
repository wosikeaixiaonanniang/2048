#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


bool slideAndMerge(int line[4], int& score) {
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

void numberadd(int board[4][4], int& score, int direction) {
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
void registerUser(string name, string password) 
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

    // 检查用户名是否已存在
    bool userExists = false;
    for (const auto& u : users) {
        if (u.name == name) {
            userExists = true;
            cout << "用户名已存在，请选择其他用户名！" << endl;
            break;
        }
    }

    // 如果用户名不存在，则注册新用户
    if (!userExists) {
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

        cout << "注册成功！" << endl;
    }
}
bool checkUser(string name, string password) 
{
    const string filename = "user.txt";
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "用户数据库不存在或无法打开！" << endl;
        return false;
    }

    User currentUser;
    while (inFile >> currentUser.name >> currentUser.password) {
        if (currentUser.name == name) {
            inFile.close(); // 关闭文件流
            return (currentUser.password == password); // 密码匹配返回 true，否则 false
        }
    }

    inFile.close();
    return false; // 用户名不存在
}
