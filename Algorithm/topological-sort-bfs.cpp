/**********************************************************************
 * author:      banbao
 * language:    c++/c
 * bbq :        http://dsalgo.openjudge.cn/graph/10/
 * 编码格式:UTF-8-BOM
 * comment: bfs相当于每次寻找入度为0的点(或者出度为0的点)
 **********************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <list>

#pragma warning (disable:4996)

const int MAXN = 100100;
int in[MAXN];
vector<vector<int>> adj;
queue<int> Q;
// queue<int> ans;

/* 1<=N<=100000，1<=M<=500000，1<=T<=5 */
int main() {
    int T;
    int M, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        memset(in, 0, sizeof(in));
        // while(!ans.empty()) ans.pop();
        adj.clear();
        adj.resize(N + 1);
        //for (int i = 0; i <= N; ++i) adj[i].clear();
        int l, r;
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &l, &r);
            ++in[r];
            adj[l].push_back(r);
        }
        int cnt = 0;
        while (!Q.empty()) Q.pop();
        for (int i = 1; i <= N; ++i) {
            if (in[i] == 0) {
                Q.push(i);
                cnt++;
            }
        }
        while (!Q.empty()) {
            int l = Q.front();
            // ans.push(Q.front());
            Q.pop();
            int size = adj[l].size();
            for (int i = 0; i < size; ++i) {
                --in[adj[l][i]];
                if (in[adj[l][i]] == 0) {
                    Q.push(adj[l][i]);
                    ++ cnt ;
                }
            }
        }
        if (cnt == N) cout << "No" << endl;
        else cout << "Yes" << endl;
        /* 输出拓扑排序序列 */
        /*
        if(cnt == N){
            while(!ans.empty()){
                cout << ans.front() << endl;
                ans.pop();
            }
        }
        */
    }
    system("pause");
    return 0;
}

/*
10:舰队、海域出击！
查看 提交 统计 提问
总时间限制: 5000ms 单个测试点时间限制: 2000ms 内存限制: 262144kB
描述
作为一名海军提督，Pachi将指挥一支舰队向既定海域出击！
Pachi已经得到了海域的地图，地图上标识了一些既定目标和它们之间的一些单向航线。
如果我们把既定目标看作点、航线看作边，那么海域就是一张有向图。
不幸的是，Pachi是一个会迷路的提督QAQ，所以他在包含环(圈)的海域中必须小心谨慎，
而在无环的海域中则可以大展身手。
受限于战时的消息传递方式，海域的地图只能以若干整数构成的数据的形式给出。
作为舰队的通讯员，在出击之前，请你告诉提督海域中是否包含环。

例如下面这个海域就是无环的：



而下面这个海域则是有环的（C-E-G-D-C）：





输入
每个测试点包含多组数据，每组数据代表一片海域，各组数据之间无关。
第一行是数据组数T。
每组数据的第一行两个整数N，M，表示海域中既定目标数、航线数。
接下来M行每行2个不相等的整数x,y，表示从既定目标x到y有一条单向航线（所有既定目标使用1~N的整数表示）。
描述中的图片仅供参考，其顶点标记方式与本题数据无关。

1<=N<=100000，1<=M<=500000，1<=T<=5
注意：输入的有向图不一定是连通的。
输出
输出包含T行。
对于每组数据，输出Yes表示海域有环，输出No表示无环。
样例输入
2
7 6
1 2
1 3
2 4
2 5
3 6
3 7
12 13
1 2
2 3
2 4
3 5
5 6
4 6
6 7
7 8
8 4
7 9
9 10
10 11
10 12
样例输出
No
Yes
提示
输入中的两张图就是描述中给出的示例图片。
*/