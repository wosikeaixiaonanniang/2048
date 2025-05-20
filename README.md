# 2048

这是一个2048有趣♂小游戏

棋盘使用4x4的二维int数组

A

在随机空余位置创建新的数字，需要传入一个2的倍数作为参数，作为生成数字的上限
创建时为积分加上生成数字的值  
void newnumber(int &board[4][4],int &score,int n)
分别传入现在的数字分布，本局得分和最大倍数n

在游戏开始时进行计时，在游戏结束后返回游戏时长  
自己写函数名，返回一个time类或者结构体，有小时分钟秒

把游戏最高分和id存入一个txt文件，每局游戏后检查，如果分数更高就更新最高分
void record(string name,int score,int step)
传入玩家id和分数，还有使用的步数保存在txt里

写一个结构体有id，分数和步数还有排名
从上面的txt文件中读取然后按分数从高到低排序，用结构体返回一个链表头，
struct xxx showrecord();
从上面的txt文件里找到对应的id和他的排名，然后返回结构体
struct xxx findrecord(string name)
B

实现核心玩法上下左右划，需要传入一个方向参数  
数字相加的时候为游戏积分加上等同于相加后的数字
void numberadd(int &board[4][4],int &score,int point)
分别传入现在的数字分布，本局得分，和方向（1234分别代表上下左右，或者别的你自己决定）

