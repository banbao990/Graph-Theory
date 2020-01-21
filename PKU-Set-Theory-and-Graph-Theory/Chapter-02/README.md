# 第二章 道路与回路

## 2.1 道路与回路概述

### 2.1.1 路径

+ 无向图 $G$

  + 无向图 $G$ 的一个有限点边交替序列 $P=\lbrace v_0,e_1,v_1,e_2,v_2,...,e_m,v_m  \rbrace$
  
    若对 $\forall i \in \lbrack 1,m \rbrack \land N,e_i$ 的端点是 $v_{i-1}$ 和 $v_i$ , 则称 $P$ 是图 $G$ 的一条**路径** 
    
    + $v_0$ 称为 $P$ 的**起点**
    + $v_m$ 称为 $P$ 的**终点**
    + $m$ 称为 $P$ 的**长度**
    
  + 边均不相同的路径称为**链**
  
  + 结点均不相同(**起点和终点允许相同**)的路径称为**道路**/**路**
  
  + 起点和终点相同的路径称为**闭路径**
  
  + 起点和终点相同的链称为**闭链**
  
  + 起点和终点相同的道路称为**回路**

+ 有向图 $D$ 

  + 有向图 $D$ 的一个有限点边交替序列 $P=\lbrace v_0,e_1,v_1,e_2,v_2,...,e_m,v_m  \rbrace$

    若对 $\forall i \in \lbrack 1,m \rbrack \land N,e_i=(v_{i-1},v_i)$ , 则称 $P$ 是图 $D$ 的一条**有向路径** 

  + **起点**,**终点**,**长度**

  + **有向链**, **有向道路**, **有向闭链**, **有向回路**, **有向闭路径**

+ **弦**

  + 设 $C$ 是无向简单图 $G$ 中含顶点数大于 $3$ 的一个回路, 如果结点 $v_i$ 和 $v_j$ 在 $G$ 中不相邻

    但$(v_i,v_j) \in E(G)$, 则称 $(v_i,v_j)$ 是 $C$ 的一条**弦**

+ **最长道路** $P$ : 长度最长
+ **极长道路** $P$ : 不存在其他道路以 $P$ 为其中一段

+ 问题解决
  
  + 起始状态(结点), 目标状态(结点), 动作(边)
  + 三个量筒 $(3,5,8)$ 分别装了 $(0,0,8)$ 的水, 怎么得到两个 $4$ 的水
    + 寻找一条从 $(0,0,8)$ 到 $(0,4,4)$ 的有向路径

---

+ $给定无向图G,若 \delta(G) \geq 2,则G必包含回路$
+ 非简单图显然, 简单图**极大路径法**(**极大性原则**/**极小性原则**)

---

---

+ $若 \delta(G) \geq 3, 则G中必含带弦回路$
+ **极大路径法**

---

### 2.1.2 连通(考虑简单图)

+ 在无向图 $G$ 中, 若两结点 $u,v$ 之间存在路径, 则称 $u,v$ 是**连通**的, 记作 $u \sim v$
  + 是一种 **等价关系**
  + 规定 $u \sim u$
+ 若图中任意两个顶点都是连通的, 就称 $G$ 是**连通图**
  否则则称 $G$ 是**非连通图**/**分离图**
+ 若 $u,v$ 之间存在路径, 必存在路(**极小路径法**)

+ 连通关系 $"\sim"$ 是 $V(G)$ 上的等价关系

  设**商集** $\frac{V(G)}{\sim}=\lbrace V_1,...,V_k \rbrace$ 

  则导出子图 $G[V_i],(1 \leq i \leq k)$ 为 $G$ 的**极大连通子图**, 称为 $G$ 的**连通分支**

  $k$ 称为 $G$ 的**连通分支数**, 记作 $\kappa(G)$

+ $\kappa(G)=1 \Leftrightarrow $ $G$ 是连通图

  $\kappa(G) > 1 \Leftrightarrow  $ $G$ 是非连通图, $G$ 可以表示成 $\kappa(G)$ 个连通分支的并 $\Leftrightarrow$ $G=\bigcup_{i=1}^kG[V_i]$ 

---

+ $设图G是无向简单图,\kappa(G)=k,则有 n-k \leq m \leq \frac12(n-k)(n-k-1) $
+ $k=1 \Leftrightarrow n-1 \leq m \leq \frac12n(n-1) $
  + 只需证明 $n-1 \leq m$
  + **归纳法**
+ $k > 1,连通分支的和$
  + $a(a+1)+b(b+1) \leq (a+b)(a+b+1), \forall a,b \geq 0$

---

+ **树** : $G是连通图,|E(G)|=|V(G)|-1$

### 2.1.3 距离

+ 无向图 $G$ 中

  + 若结点 $u,v$ 是连通的, 则称$u,v$之间长度最短的路径为 $u,v$ 之间的**短程线**(**测地线**)

    短程线的长度称为 $u$ 到 $v$ 的距离, 记作 $d(u,v)$

  + 若结点 $u,v$ 是不连通的, $d(u,v)= +\infty$ 

  + $d(u,v) \geq 0,当且仅当u=v时等号成立$

  + $d(u,v)=d(v,u)$

  + $d(u,v)+d(v,w) \geq d(u,w)$

+ 有向图 $D$ 中

  + $d(u,v) = d(v,u)$ 不一定成立

+ **直径** : $d(G)=max \lbrace d(u,v):u,v \in V(G) \rbrace$

### 2.1.4 r部图/二部图

+ 若无向图 $G$ 的结点集 $V$ 存在一个 $r(r \geq 2)$划分$(V_1,...,V_r)$,

  使得 $G$ 中每一条边的两个端点都分别属于不同的 $V_i$ ,

  则称 $G$ 是 **$r$ 部图**, 记作 $G=(V_1,...,V_r:E)$ 

+ **完全 $r$ 部图**

  $G$ 是 $r$ 部简单图, 且 $\forall i,j \in \lbrace (i \in N) \land (j \in N) \land(1 \leq i < j \leq r) \rbrace$,$V_i$中所有结点与$V_j$中所有结点都相邻

  则称 $G$ 是**完全 $r$ 部图**, 记作 $G=K_{n_1,...,n_r}$, 其中 $n_i=|V_i|$

---

+ $无向图G是二部图 \Leftrightarrow G中不包含奇回路$

+ $\Leftarrow:$

  + 非连通图, 考虑其连通分支

  + 连通图, 取定一点 $v_0$

    + 二部 : $V_1 = \lbrace v \in V(G):d(v_0,v)$ $is$ $even \rbrace $

      ​           $V_2 = \lbrace v \in V(G):d(v_0,v)$ $is$ $odd \rbrace$

+ $ \Rightarrow:$

  + 证明 $V_1$ 内的任意两点不相邻
  + $V_2$ 同理

---

+ $任何一个奇闭路径都有一个奇回路$

+ **最短奇闭路径**, 断言其为奇回路

---

### 2.1.5 有向图的连通问题

+ 有向图 $D$, $u,v \in V(D)$
  + **可达关系**
  + $u \rightarrow v:$ $u$ **可达** $v$, 存在一条从 $u$ 到 $v$ 的有向路径
  + 约定 $u \rightarrow u$
+ **强连通图**/**双向连通图** : $D$ 中任意两点互相可达
  + 是等价关系
+ **单连通图** : $D$ 中任意两点 $u,v,u \rightarrow v$ 或者 $v \rightarrow u$ 
+ **弱连通图** : $D$ 的基图是连通图
+ 强连通 $\Rightarrow$ 单连通 $\Rightarrow$弱连通
+ **强连通分支**
  + 有向图的所有边不一定都在某一强连通分支中
  + $D \ne \bigcup_{i=1}^kG \lbrack V_i \rbrack$
+ 有向图的一个**核** $S$
  + $S \subseteq V(G)$
  + $S$ 是独立集, 且 $S$ 外的点在 $S$ 中都有一个直接后继
  + 直接前驱

---

+ $单连通图 D(V,E)中的所有点可以排成一个序列 \lbrace n_1',n_2',...,n_n' \rbrace, 满足n_1' \rightarrow n_2' \rightarrow ... \rightarrow n_n'$
+ 取定一点 $v_0$ , 令$V_2 = \lbrace v:(v_0 \rightarrow v) \land(v \in V) \rbrace$
+ $V_1 =V-V_2-v_0$
+ 对 $V_1$ 归纳

---

+ $设D是有向图$
  + $D是强连通图 \Leftrightarrow 存在一条闭路径包含D的所有顶点$
  + $D是单连通图 \Leftrightarrow 存在一条路径包含D的所有顶点$

---

---

+ $有向图 D 是连通图,D是二部图 \Leftrightarrow D无奇回路$

---

---

+ $不含奇回路的有向图D必有核$

+ $case\ 1:D$ 是强连通图

  + 取定 $D$ 中一个结点 $x$ , 设 $S$ 是到 $x$ 距离为偶数的结点子集

    则每一个到 $x$ 距离为奇数的点都在 $S$ 中有一个直接后继

  + 反证法说明 $S$ 是独立集

    任取 $S$ 中两点 $u,v$, 若$(u,v) \in E(G) \Rightarrow$ 存在奇闭路径 $\Rightarrow$ 存在奇回路

+ $case\ 2:$ $D$ 是一般有向图
  + $D$ 中必有一强连通分支 $D_1$ ,使得 $D_1$ 没有外邻点(**反圈**)
  + $D_1$ 存在核 $S_1$
  + 设 $D'$ 是 $D$ 中删去 $S_1$ 中的点及其所有直接前驱得到的有向图( $D_1$ 都被删去)
  + 对 $D'$ 使用归纳推理, $D'$ 存在核 $S'$
  + $S_1 \cup S'$ 是 $D$ 的核

---


### 2.1.6 反圈

+ **反圈** : **有向无环图**$(DAG)$

  + 将有向图的每一个强连通分支收缩成一个点形成的图是**反圈**
  + 反圈存在**拓扑排序**

+ 拓扑排序

  + $D$ 是反圈, $|V(D)|=n$, 则存在一个从 $V(D)$ 到 $\lbrace i:(i \in N) \land (\ 1 \leq i \leq n) \rbrace$ 的**双射 **$T$

    能够满足 $(u,v) \in E(D) \Rightarrow T(u) < T(v) $

  + 数学归纳法
    + 依次找入度为0的点
      + 有限性, 一定存在一条极长道路 $P:\lbrace v_0,...,v_l \rbrace$
      + $d^-(v_0)=0,d^+(v_l)=1$
    + 依次找出度为0的点(**反序**)

+ [拓扑排序算法](../../Algorithm/topological-sort.cpp)

### 2.1.7 道路存在判定, 连通性判定

#### 2.1.7.1 代数法

+ **邻接矩阵** $A(a_{i,j})_{n \times n}$

+ **路径矩阵** $P(p_{i,j})_{n \times n}$

  + $p_{i,j}=1,\ if(v_i \rightarrow v_j)$

    $p_{i,j}=0,\ else$

  + 约定 $p_{i,i}=1$ $\Leftrightarrow$ 存在 $v_i$ 到 $v_i$ 的闭路径

+ 邻接矩阵,路径矩阵中的元素视作**布尔元**

  + $a,b \in \lbrace 0,1 \rbrace$
  + $a \lor b,a \land b \in \lbrace 0,1 \rbrace$
  + 布尔和 : $a\lor b=0 \Leftrightarrow a=b=0$
  + 布尔积 : $a \land b =1 \Leftrightarrow a=b=1$
  + $\land ,\lor$ 满足交换律, 结合律, 分配律($\times 2$)

---

+ $P=A \lor A^2 \lor ... \lor A^n=\bigvee_{s=1}^nA^s$ 
+ 暴力算法时间复杂度 $O(n^4)$

---

---

+ $Warshall\ 算法$
+ 跳点
+ 算法
  + $Begin:$
  + $1.\ P \leftarrow  A /* 初始化 */$
  + $2.\ for\ k = 1\ to\ n\ do /* 外循环 */$
  + $3.\quad   for\ i = 1\ to\ n\ do /* 内循环 */$
  + $       \ \qquad for\ j = 1\ to\ n\ do$
  + $       	\quad \qquad P_{i,j} \leftarrow  P_{i,j} \cup (P_{i,k} \cap P_{k,j})$

  + $End$

+ 时间复杂度 $O(n^3)$

#### 2.1.7.2 搜索法

+ $DFS$
+ $BFS$
+ 一般用**邻接表**存图

## 2.2 最短道路

## 2.3 欧拉图

## 2.4 哈密顿图

## 2.5 作业

+ $1.1\ 无向图G和\overline G至少有一个是连通图$
+ $1.2\ D为有向图,若d^+(D) \geq 1 \Rightarrow D 中含有有向回路$
+ $1.3\ 设G是n(n \geq 2)阶无向图, 则存在G的支撑二部子图H满足\ d_H(v) \geq \frac12d_G(v), \forall v \in V(G)$
+ $1.4\ 无向简单图G,n \geq 4,m \geq 2n-3 \Rightarrow G中含有带弦回路$
+ $1.5\ 无向连通图任意两条最长道路必有公共结点$
+ $1.6\ G不含三角形的无向简单图,求证:$
  + $a. \sum_{i=1}^nd^2(v_i) \leq mn$
  + $b.m \leq \frac{n^2}4$
+ $1.7\ 完全图K_n(n \geq 3)所有边都赋以整数权,证明:$
  + $K_n的每个回路的权都是偶数 \Leftrightarrow K_n的所有奇数权边诱导出一个空图或者支撑完全二部图$

## 2.6 参考答案

+ $1.1\ 分类讨论$
  + $case\ 1:G连通$
  + $case\ 2: G非连通$
    + $G可划分为k=\kappa (G) 个连通分支G_1,G_2,...,G_k$
    + $任取v_1 \in G_1,v_2 \in G_2$
    + $在 \overline G 中,v_1与v_2相邻,v_1与G_i(i \ne 1)中的点都相邻, v_2与G_1中的点都相邻$
    + $ \overline G 连通 $

+ $1.2\ 极大路径法$

+ $1.3\ 边数最多的极大支撑二部子图$
  + $设H是G边数最多的极大支撑二部子图,H的顶点划分为\lbrace V_1,V_2 \rbrace$

  + $设v是G的任一顶点, 不妨设v \in V_1$

    + $则有d_H(v) \geq \frac12d_G(v)$

      $否则,取\lbrace V_1-v,V_2+v \rbrace 为新的划分,得到一个新的支撑二部子图H'$

       $此时 |E(H')| > |E(H)|, 与假设矛盾$

+ $1.4\ 数学归纳法$
  + $case\ 1: n=4,m \geq 5,\Rightarrow \delta(G) \geq 5*2/4 \Rightarrow \delta(G) \geq 3 \Rightarrow OK$
  + $case\ 2: n \geq 5$
    + $case\ 2.1:\delta(G) \geq 3 \Rightarrow OK$
    + $case\ 2.2:\delta(G) \leq 2$
      + $对G-v归纳$
      + $对于G-v, n \geq 4, m \geq 2k-3-2=2(k-1)-3$

+ $1.5\ 反证+最长道路$

+ $1.6\ $

  + $a.$

    + $对于任意的边e(u,v),d(u)+d(v) \leq n$

      $对所有边求和 \Rightarrow OK$

  + $b.$

    + $取G中度最大的点v_0,d(v_0)=k$
    + $N(v_0)中的点互不相邻$
    + $V(G)-N(v_0)中的点度小于k$
    + $握手定理:\sum_{i=1}^nd(v_i) = 2m$
    + $k+k(n-k-1)+(n-k-1+1)k \geq 2m \Rightarrow m \leq k(n-k) \leq \frac{n^2}4$

+ $1.7\ 分类讨论+反证法$

  + $ \Leftarrow:显然$

  + $\Rightarrow:设奇数边权诱导的图为J$

    + $case\ 1:不含奇数权边 \Rightarrow J= \emptyset$

    + $case\ 2:含奇数边权$

      + $断言J是二部图,否则存在奇回路,奇回路边权之和为奇数(J所有边权都是奇数)$

      + $J=( V_1,V_2:E )$

      + $断言J是完全二部图,否则\exists u_1,u_2 \in V_1,v_1,v_2 \in V_2 ,s.t. (u_1,v_1) \in J,(u_2,v_2) \notin J$

        $此时回路 \lbrace u_1,v_1,v_2,u_1.u_2 \rbrace 的权值之和为奇数$

      + $断言|V(J)|=n,否则\exists w \in K_n-J,u \in V_1,v \in V_2,回路 \lbrace w,u,v,w权值之和为奇数$

