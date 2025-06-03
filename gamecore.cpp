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
            if (currentUser.password != password)
                showerror("�������");

            return (currentUser.password == password); // ����ƥ�䷵�� true������ false
        }
    }

    inFile.close();
    showerror("�˻�������");

    return false; // �û���������
}
void GameCore::newnumber(int board[4][4], int& score, int n)

{
    // �ռ����п�λλ��
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptyCells.push_back(make_pair(i, j));
            }
        }
    }

    if (emptyCells.empty())
        return; // û�п�λ

    // ���ѡ��һ����λ
    int index = rand() % emptyCells.size();
    int x = emptyCells[index].first;
    int y = emptyCells[index].second;

    // ���������� (2��4��90%����Ϊ2��10%����Ϊ4)
    int newValue = (rand() % 10 < 9) ? 2 : 4;

    // ȷ�������ֲ�����n
    while (newValue > n) {
        newValue /= 2;
    }

    board[x][y] = newValue;
    score += newValue; // ���ӷ���
}

// ��ʱ����ʵ��
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

// ��¼�������ļ�
void GameCore::record(string name, int score, int step)
{
    const string filename = "game_records.txt";
    vector<Player> records;

    // ��ȡ���м�¼
    ifstream inFile(filename);
    if (inFile) {
        Player p;
        while (inFile >> p.name >> p.score >> p.step) {
            records.push_back(p);
        }
        inFile.close();
    }

    // ���»���Ӽ�¼
    bool found = false;
    for (auto& p : records) {
        if (p.name == name) {
            found = true;
            if (score > p.getscore()) {
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

    // ����������
    sort(records.begin(), records.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
        });

    // д���ļ�
    ofstream outFile(filename);
    for (const auto& p : records) {
        outFile << p.name << " " << p.score << " " << p.step << "\n";
    }
    outFile.close();
}

// ��ʾ���м�¼
Player* GameCore::showrecord()
{
    const string filename = "game_records.txt";
    Player* head = nullptr;
    Player* tail = nullptr;

    ifstream inFile(filename);
    if (!inFile)
        return nullptr;

    // ��ȡ��¼����������
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

// �����ض���ҵļ�¼
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

    // ������ʱ����
    while (allRecords) {
        Player* temp = allRecords;
        allRecords = allRecords->next;
        delete temp;
    }

    return result; // �Ҳ���ʱ����nullptr
}