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