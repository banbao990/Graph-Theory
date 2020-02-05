/**********************************************************************
 * author:      banbao
 * language:    c++/c
 * bbq :        http://dsalgo.openjudge.cn/graph/10/
 *              疑惑: 
 *                    BFS:      1878ms(可能是在记录in数组上耗时较多)
 *                    DFS(S):   1692ms(递归栈耗时)
 *                    DFS(!S):  1820ms
 * 编码格式:UTF-8-BOM
 **********************************************************************/

 /* library */
#include <stdio.h>
#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <cmath>
#include <cstring>
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
#include <iostream>
using namespace std;

/* micros */
#define lowbit(x) ((x)&(-x))
#define leftson(x) ((x<<1)+1)
#define rightson(x) ((x<<1)+2)
#define parent(x) ((x-1)>>1)
#define mid(x,y) (((x)+(y))>>1)

/* functions */
template<class T>
inline int ABS(T a) { return a < 0 ? -a : a; }
template<class T>
inline void MYSWAP(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}
void init();

/* pragmas */
#pragma warning(disable:4996)

/* const variables */
const int INF_INT = 1 << 29;
const double PI = acos((double)-1);
const double INF = 1e20;
const double EPS = 1e-6;
//freopen("test.txt", "w", stdout);

/* code start here */

/* 
   dfs 拓扑排序判断有向图是否有环 
   如果只是记录是否有环不需要记录输出栈 S
   相当于每次寻找出度为0的点
   (需不需要从树根开始寻找:不需要)
*/

const int MAXN = 100100;
const int MAXM = 500100;

char vis[MAXN];/* 表示进入输出的栈中 */
char instack[MAXN];/* 一个搜索深度的序列 */
vector<vector<int>> adj;
int N, M;
int circle;
// stack<int > S;

void dfs(int l) {
    int size = (int)adj[l].size();
    for (int i = 0; i < size; ++i) {
        int r = adj[l][i];
        if (instack[r]) {
            circle = true;
            return;
        }
        if (!vis[r]) {
            instack[r] = 1;
            dfs(r);
            if (circle) return;
            instack[r] = 0;
        }            
    }
    vis[l] = true;
   // S.push(l);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        init();
        while (M--) {
            int l, r;
            scanf("%d %d", &l, &r);
            adj[l].push_back(r);
        }
        /* deal */
        vis[1] = 1;
        instack[1] = 1;
        dfs(1);
        /* output */
        if (circle) printf("Yes\n");
        else printf("No\n");
        /* 输出拓扑排序序列 */
        /*
        if(!circle){
            while (!S.empty()) {
                printf("%d\n",S.top());
                S.pop();
            }
        }
        */
    }
    system("pause");
    return 0;
}

void init() {
    memset(vis, 0, sizeof(vis));
    memset(instack, 0, sizeof(instack));
    adj.clear();
    adj.resize(N + 1);
    circle = false;
   // while (!S.empty()) S.pop();
}
