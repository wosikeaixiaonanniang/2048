#include "header.h"
#include <cstdlib>
#include <ctime>

using namespace std::chrono;

// 随机数初始化
namespace {
bool seeded = false;
void initSeed()
{
    if (!seeded) {
        srand(time(nullptr));
        seeded = true;
    }
}
}

// 全局计时变量
static steady_clock::time_point gameStartTime;

// 开始游戏计时
void startGameTimer()
{
    gameStartTime = steady_clock::now();
}

// 获取游戏时长
GameTime getGameDuration()
{
    auto endTime = steady_clock::now();
    auto duration = duration_cast<seconds>(endTime - gameStartTime);

    long long totalSeconds = duration.count();
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    return { hours, minutes, seconds };
}

// 生成新数字
void newnumber(int (&board)[4][4], int& score, int n)
{
    initSeed();
    vector<pair<int, int>> emptyCells;

    // 收集所有空位
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0) {
                emptyCells.emplace_back(i, j);
            }
        }
    }

    if (emptyCells.empty())
        return;

    // 随机选择空位
    int idx = rand() % emptyCells.size();
    auto& pos = emptyCells[idx];

    // 生成候选数字（2的倍数且<=n）
    vector<int> candidates;
    for (int num = 2; num <= n; num *= 2) {
        candidates.push_back(num);
    }

    if (candidates.empty())
        candidates.push_back(2);

    // 随机选择数字并放置
    int numIdx = rand() % candidates.size();
    int newNum = candidates[numIdx];
    board[pos.first][pos.second] = newNum;

    // 更新分数
    score += newNum;
}

// 记录处理
void record(std::string name, int score, int step)
{
    vector<Player> records;

    // 读取现有记录
    ifstream fin("records.txt");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string n;
        int s, st;
        if (ss >> n >> s >> st) {
            records.push_back({ n, s, st, 0, nullptr });
        }
    }
    fin.close();

    // 更新记录
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
        records.push_back({ name, score, step, 0, nullptr });
    }

    // 写入文件
    ofstream fout("records.txt");
    for (const auto& p : records) {
        fout << p.name << " " << p.score << " " << p.step << "\n";
    }
    fout.close();
}

// 获取排行榜
struct Player* showrecord()
{
    vector<Player> temp;

    // 读取记录
    ifstream fin("records.txt");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string name;
        int score, step;
        if (ss >> name >> score >> step) {
            temp.push_back({ name, score, step, 0, nullptr });
        }
    }
    fin.close();

    // 按分数排序
    sort(temp.begin(), temp.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
    });

    // 构建链表
    Player* head = nullptr;
    Player* tail = nullptr;
    int rank = 1;
    for (const auto& t : temp) {
        Player* node = new Player { t.name, t.score, t.step, rank++, nullptr };
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// 查找玩家记录
struct Player findrecord(std::string name)
{
    Player* head = showrecord();
    Player* curr = head;
    Player result { "", -1, -1, -1, nullptr };

    while (curr) {
        if (curr->name == name) {
            result = *curr;
            result.next = nullptr; // 断开链表连接
            break;
        }
        curr = curr->next;
    }

    // 释放内存
    while (head) {
        Player* temp = head;
        head = head->next;
        delete temp;
    }

    return result;
}
