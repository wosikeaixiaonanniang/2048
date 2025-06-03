#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void newnumber(int board[4][4], int& score, int n)
{
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptyCells.push_back(make_pair(i, j));
            }
        }
    }
    if (emptyCells.empty())
        return;
    int index = rand() % emptyCells.size();
    int x = emptyCells[index].first;
    int y = emptyCells[index].second;
    int newValue = (rand() % 10 < 9) ? 2 : 4;
    while (newValue > n)
        newValue /= 2;
    board[x][y] = newValue;
    score += newValue;
}

// ============= GameTimer 类实现 =============
void GameTimer::start()
{
    startTime = clock();
    elapsedSeconds = 0;
    isPaused = false;
}

void GameTimer::pause()
{
    if (!isPaused) {
        pauseTime = clock();
        isPaused = true;
        elapsedSeconds += static_cast<int>((pauseTime - startTime) / CLOCKS_PER_SEC);
    }
}

void GameTimer::resume()
{
    if (isPaused) {
        startTime = clock();
        isPaused = false;
    }
}

GameTime GameTimer::getGameTime()
{
    int totalSeconds = elapsedSeconds;
    if (!isPaused) {
        totalSeconds += static_cast<int>((clock() - startTime) / CLOCKS_PER_SEC);
    }
    GameTime time;
    time.hours = totalSeconds / 3600;
    time.minutes = (totalSeconds % 3600) / 60;
    time.seconds = totalSeconds % 60;
    return time;
}

// ============= Player 类静态方法实现 =============
void Player::record(string name, int score, int step)
{
    const string filename = "records.txt";
    vector<Player> records;

    ifstream inFile(filename);
    if (inFile) {
        Player p;
        while (inFile >> p.name >> p.score >> p.step) {
            records.push_back(p);
        }
        inFile.close();
    }

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

    sort(records.begin(), records.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
    });

    ofstream outFile(filename);
    for (const auto& p : records) {
        outFile << p.name << " " << p.score << " " << p.step << "\n";
    }
    outFile.close();
}

Player* Player::showrecord()
{
    const string filename = "records.txt";
    Player* head = nullptr;
    Player* tail = nullptr;

    ifstream inFile(filename);
    if (!inFile)
        return nullptr;

    Player p;
    int rank = 1;
    while (inFile >> p.name >> p.score >> p.step) {
        p.rank = rank++;
        Player* newNode = new Player(p); // 调用构造函数
        newNode->next = nullptr;

        if (!head)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    inFile.close();
    return head;
}

Player* Player::findrecord(string name)
{
    Player* allRecords = showrecord();
    Player* current = allRecords;
    Player* result = nullptr;

    while (current) {
        if (current->name == name) {
            result = new Player(*current); // 深拷贝
            result->next = nullptr;
            break;
        }
        current = current->next;
    }

    while (allRecords) {
        Player* temp = allRecords;
        allRecords = allRecords->next;
        delete temp;
    }
    return result;
}
