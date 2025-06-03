#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


bool slideAndMerge(int line[4], int& score) {
    bool moved = false;
    int temp[4] = { 0 };
    int index = 0;

    for (int i = 0; i < 4; i++) {
        if (line[i] != 0) {
            temp[index++] = line[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (temp[i] != 0 && temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            score += temp[i]; // 加分
            temp[i + 1] = 0;
            moved = true;
        }
    }

    index = 0;
    for (int i = 0; i < 4; i++) {
        line[i] = 0;
        if (temp[i] != 0) {
            line[index++] = temp[i];
        }
    }

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
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) temp[i] = board[i][j];
            if (slideAndMerge(temp, score)) moved = true;
            for (int i = 0; i < 4; i++) board[i][j] = temp[i];
        }
        break;

    case DIR_DOWN:
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) temp[3 - i] = board[i][j];
            if (slideAndMerge(temp, score)) moved = true;
            for (int i = 0; i < 4; i++) board[i][j] = temp[3 - i];
        }
        break;

    case DIR_LEFT:
        for (int i = 0; i < 4; i++) {
            if (slideAndMerge(board[i], score)) moved = true;
        }
        break;

    case DIR_RIGHT:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) temp[3 - j] = board[i][j];
            if (slideAndMerge(temp, score)) moved = true;
            for (int j = 0; j < 4; j++) board[i][j] = temp[3 - j];
        }
        break;
    }
}
void registerUser(string name, string password) 
{
    const string filename = "user.txt";
    vector<User> users;

    ifstream inFile(filename);
    if (inFile) {
        User u;
        while (inFile >> u.name >> u.password) {
            users.push_back(u);
        }
        inFile.close();
    }

    // 检查是否重名
    bool userExists = false;
    for (const auto& u : users) {
        if (u.name == name) {
            userExists = true;
            cout << "用户名已存在，请选择其他用户名！" << endl;
            break;
        }
    }

    // 注册新用户
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
            inFile.close(); 
            return (currentUser.password == password); // 密码匹配返回 true，否则 false
        }
    }

    inFile.close();
    return false; 
}
