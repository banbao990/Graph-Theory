/***************************************************
author:     banbao
language:   c++/c
link:       http://dsa.openjudge.cn/graph/0714/
编码格式:   UTF-8-BOM
***************************************************/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <bitset>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#pragma warning(disable:4996)
const int inf = 1 << 22;// 不取 1 << 30 怕加法出错溢出 4194304
// freopen("test.txt", "w", stdout);
// const int MAXNUMBER = 500000;

struct edge {
    int left, right;
    int weight;
    edge(int _left, int _right, int _weight) :left(_left), right(_right), weight(_weight) {}
    bool operator < (const edge &a)const {
        if (weight != a.weight)
            return weight > a.weight;
        if (left != a.left)
            return left > a.left;
        return right > a.right;
    }
};

const char base = 'A';
const int MAXEDGE = 200;// MAXEDGE*=2 无向图
const int MAXVERTICE = 30;

int main() {
    // parameters
    int n1, n2, total;// 结点数
    char left, right;
    int weight;
    edge * e[MAXEDGE] = {};
    // init
    int count = 0;// 总边数
    int ans = 0;// 最小生成树的权值
    // input
    cin >> n1;
    total = n1--;
    while (n1--) {
        cin >> left;
        cin >> n2;
        while (n2--) {
            cin >> right >> weight;
            // 作为无向图处理
            e[count++] = new edge(left - base, right - base, weight);
            e[count++] = new edge(right - base, left - base, weight);
        }
    }
    // init
    // bool *flag = new bool[total];//有没有查看过
    bool flag[20];
    for (int i = 0; i < total; ++i) flag[i] = false;
    int length[MAXVERTICE];// MST 到其他结点的距离
    for (int i = 0; i < MAXVERTICE; ++i) length[i] = inf;
    // prim-start
    flag[0] = true;// A结点标记为已访问
    int now = 0;// 新加入结点
    int i;// i:加入MAT的结点数
    for (i = 1; i < total; ++i) {
        // 更新距离
        // 起点为 now, 终点没有加到集合里(没有访问过)
        for (int j = 0; j < count; ++j) {
            if (e[j]->left == now && !flag[e[j]->right] && length[e[j]->right] > e[j]->weight)
                length[e[j]->right] = e[j]->weight;
            // pre update
        }
        // 找最小边 集合中大另外未访问过结点的最小距离
        int minLength = inf;
        for (int j = 0; j < total; ++j) {
            if (!flag[j] && length[j] < minLength) {
                minLength = length[j];
                now = j;
            }
        }
        if (minLength == inf) break;
        ans += minLength;
        flag[now] = true;
        //pre update
    }
    // prim-end

    if (i != total) cout << "error" << endl;
    else cout << ans << endl;
    // post-effect
    for (int i = 0; i < MAXEDGE; ++i) if (e[i]) delete e[i];
    system("pause");
    return 0;
}
/*
0714:兔子与星空
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 10000kB
描述
很久很久以前，森林里住着一群兔子。兔子们无聊的时候就喜欢研究星座。
如图所示，天空中已经有了n颗星星，其中有些星星有边相连。
兔子们希望删除掉一些边，然后使得保留下的边仍能是n颗星星连通。
他们希望计算，保留的边的权值之和最小是多少？







输入
第一行只包含一个表示星星个数的数n，n不大于26，并且这n个星星是由大写字母表里的前n个字母表示。
接下来的n-1行是由字母表的前n-1个字母开头。最后一个星星表示的字母不用输入。
对于每一行，以每个星星表示的字母开头，然后后面跟着一个数字，
表示有多少条边可以从这个星星到后面字母表中的星星。
如果k是大于0，表示该行后面会表示k条边的k个数据。
每条边的数据是由表示连接到另一端星星的字母和该边的权值组成。权值是正整数的并且小于100。
该行的所有数据字段分隔单一空白。该星星网络将始终连接所有的星星。
该星星网络将永远不会超过75条边。
没有任何一个星星会有超过15条的边连接到其他星星（之前或之后的字母）
。在下面的示例输入，数据是与上面的图相一致的。

输出
输出是一个整数，表示最小的权值和
样例输入
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
样例输出
216
提示
考虑看成最小生成树问题，注意输入表示。
*/