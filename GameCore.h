class GameCore
{
private:
    int board[4][4] = {0}; // 棋盘状态
    int score = 0;         // 当前分数
    int step = 0;          // 当前步数
    bool moved = false;    // 上次操作是否移动

    bool slideAndMerge(int line[4])
    {
        int temp[4] = {0};
        int index = 0;

        for (int i = 0; i < 4; i++)
            if (line[i] != 0)
                temp[index++] = line[i];

        for (int i = 0; i < 3; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;
                score += temp[i];
                temp[i + 1] = 0;
                moved = true;
            }
        }

        index = 0;
        for (int i = 0; i < 4; i++)
        {
            line[i] = temp[i] != 0 ? temp[index++] : 0;
        }
        return moved;
    }

public:
    void init();
    void newNumber(int maxMultiple);
    void handleMove(int direction);

    // 接口
    int getScore() const { return score; }
    int getStep() const { return step; }
    const int (&getBoard() const)[4][4] { return board; }
    bool isMoved() const { return moved; }
};