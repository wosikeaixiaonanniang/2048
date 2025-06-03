#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// �������λ����������
void newnumber(int board[4][4], int& score, int n)
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
void startTimer(GameTimer& timer)
{
    timer.startTime = clock();
    timer.elapsedSeconds = 0;
    timer.isPaused = false;
}

void pauseTimer(GameTimer& timer)
{
    if (!timer.isPaused) {
        timer.pauseTime = clock();
        timer.isPaused = true;
        timer.elapsedSeconds += static_cast<int>((timer.pauseTime - timer.startTime) / CLOCKS_PER_SEC);
    }
}

void resumeTimer(GameTimer& timer)
{
    if (timer.isPaused) {
        timer.startTime = clock();
        timer.isPaused = false;
    }
}

GameTime getGameTime(GameTimer& timer)
{
    int totalSeconds = timer.elapsedSeconds;
    if (!timer.isPaused) {
        totalSeconds += static_cast<int>((clock() - timer.startTime) / CLOCKS_PER_SEC);
    }

    GameTime time;
    time.hours = totalSeconds / 3600;
    time.minutes = (totalSeconds % 3600) / 60;
    time.seconds = totalSeconds % 60;
    return time;
}

// ��¼�������ļ�
void record(string name, int score, int step)
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
Player* showrecord()
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
Player* findrecord(string name)
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