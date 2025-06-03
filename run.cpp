#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include "ui.h"
#include "gamecore.h"

bool GameCore::slideAndMerge(int line[4], int& score) 
{
    bool moved = false;
    int temp[4] = { 0 };
    int index = 0;

    // 1. �ƶ��������ֵ���ࣨȥ��0��
    for (int i = 0; i < 4; i++) {
        if (line[i] != 0) {
            temp[index++] = line[i];
        }
    }

    // 2. �ϲ�������ͬ����
    for (int i = 0; i < 3; i++) {
        if (temp[i] != 0 && temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            score += temp[i]; // �ӷ�
            temp[i + 1] = 0;
            moved = true;
        }
    }

    // 3. �ٴ��ƶ�������ϲ�����ܳ��ֵĿ�λ��
    index = 0;
    for (int i = 0; i < 4; i++) {
        line[i] = 0;
        if (temp[i] != 0) {
            line[index++] = temp[i];
        }
    }

    // ����Ƿ����ƶ�����ԭʼ���ݱȽϣ�
    for (int i = 0; i < 4; i++) {
        if (line[i] != temp[i]) {
            moved = true;
        }
    }

    return moved;
}

// ���߼�����
void GameCore::numberadd(int board[4][4], int& score, int direction) 
{
    bool moved = false;
    int temp[4];

    switch (direction) {
    case DIR_UP:
        // ����ÿһ�У����ϵ��£�
        for (int j = 0; j < 4; j++) {
            // ��ȡһ��
            for (int i = 0; i < 4; i++) temp[i] = board[i][j];
            // ������һ��
            if (slideAndMerge(temp, score)) moved = true;
            // д��
            for (int i = 0; i < 4; i++) board[i][j] = temp[i];
        }
        break;

    case DIR_DOWN:
        // ����ÿһ�У����µ��ϣ�
        for (int j = 0; j < 4; j++) {
            // ��ȡһ�У�����
            for (int i = 0; i < 4; i++) temp[3 - i] = board[i][j];
            // ������һ��
            if (slideAndMerge(temp, score)) moved = true;
            // д�أ�����
            for (int i = 0; i < 4; i++) board[i][j] = temp[3 - i];
        }
        break;

    case DIR_LEFT:
        // ����ÿһ�У������ң�
        for (int i = 0; i < 4; i++) {
            // ֱ�Ӵ�����
            if (slideAndMerge(board[i], score)) moved = true;
        }
        break;

    case DIR_RIGHT:
        // ����ÿһ�У����ҵ���
        for (int i = 0; i < 4; i++) {
            // ��ȡһ�У�����
            for (int j = 0; j < 4; j++) temp[3 - j] = board[i][j];
            // ������һ��
            if (slideAndMerge(temp, score)) moved = true;
            // д�أ�����
            for (int j = 0; j < 4; j++) board[i][j] = temp[3 - j];
        }
        break;
    }
}
void GameUI::registerUser(string name, string password) 
{
    const string filename = "user.txt";
    vector<User> users;

    // ��ȡ�����û�
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
            showerror("�˻��Ѵ���");

            break;
        }
    }

    // ����û��������ڣ���ע�����û�
    if (!userExists) 
    {
        User newUser;
        newUser.name = name;
        newUser.password = password;
        users.push_back(newUser);

        // д���ļ�
        ofstream outFile(filename);
        for (const auto& u : users) {
            outFile << u.name << " " << u.password << "\n";
        }
        outFile.close();
        showerror("ע��ɹ�");

        //cout << "ע��ɹ���" << endl;
    }
}
bool GameUI::checkUser(string name, string password) 
{
    const string filename = "user.txt";
    ifstream inFile(filename);

    if (!inFile) {
       // cerr << "�û����ݿⲻ���ڻ��޷��򿪣�" << endl;
        return false;
    }

    User currentUser;
    while (inFile >> currentUser.name >> currentUser.password) 
    {
        if (currentUser.name == name) {
            inFile.close(); // �ر��ļ���
            if(currentUser.password != password)
                showerror("�������");

            return (currentUser.password == password); // ����ƥ�䷵�� true������ false
        }
    }

    inFile.close();
    showerror("�˻�������");

    return false; // �û���������
}