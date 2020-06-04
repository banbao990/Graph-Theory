# 第三章 树

[TOC]



<div style="page-break-after: always;"></div>  

$不做特殊说明默认无向图$

## 3.1 树的定义及其性质

+ **割边**

  + $e \in E(G)$

    $e$ 是 $G$ 的一条**割边**/**桥** $\Leftrightarrow$ $\kappa(G-e) > \kappa(G)$ 

  + 事实上, $\kappa(G-e) = \kappa(G) + 1$ 

    + 将边 $e$ 所在的连通分支分为两部分

+ 不含任何回路的连通图称为**树**

  + 常用 $T$ 表示树
  + 边
    + $T$ 中的边称为**树枝**
    + $|E(T)|=|V(T)|-1 \Leftrightarrow m=n-1$
    + $T$ 的每一条边都是割边
  + 结点
    + **树叶** $v$ : $d(v)=1$ 
    + **分支点** $v$ : $d(v) > 1$
  + $T$ 是二部图

+ **平凡树** : $|V(T)|=1$

+ **森林** $G$ : 每一个连通分支都是树

  + $G$ 是二部图

---

+ <span name = "theory-01">定理1.1</span>
+ $ e=(u,v)是割边 \Leftrightarrow e 不属于 G的任何回路$
  + $\Rightarrow:反证法$
  + $\Leftarrow:反证法$

---

---

+ $树T的等价刻画$

+ $设T是阶不小于2的无向图, 则下列说法等价$
  + $(1)\ T连通且无回路$
  + $(2)\ T连通且每条边都是割边$
  + $(3)\ T连通且有n-1条边$
  + $(4)\ T有n-1条边且无回路$
  + $(5)\ T的任意两个点之间有唯一道路$
  + $(6)\ T无回路,但任意加上一条边之后恰有一个回路$

+ $证明:$
  + $(1) \Leftrightarrow (2):$[定理1.1](#theory-01)
  + $(2) \Rightarrow (3):$
    + $对T的结点数n进行归纳(删去割边将割边所在的连通分支分为两个连通分支)$
  + $(3) \Rightarrow (4):$
    + $设T回路,在T的回路中删边直至T中没有回路且连通,记作T'$
    + $由(1) \Rightarrow (3), E(T')=n-1=E(T) \Rightarrow 矛盾$
  + $(4) \Rightarrow (1):$
    + $即证\kappa(T)=1$
    + $设\kappa(T)=k,各个连通分支记作T_1,T_2,...,T_k$
    + $T_i无回路(\forall i \in [1,k] \cap N)$
    + $由(1) \Rightarrow (3), n-1=|E(T)|=\sum\limits_{i=1}^k|E(G)|=\sum\limits_{i=1}^k(|V(T_i)|-1)=|V(T)|-k=n-k$
    + $\Rightarrow \kappa(T)=k=1$
  + $至此,(1) \Leftrightarrow  (2) \Leftrightarrow  (3) \Leftrightarrow  (4)$
  + $(1),(2),(3),(4) \Rightarrow (5):反证法$
    + $T连通 \Rightarrow 任意两结点之间都存在一条道路$
    + $设T中结点u,v之间存在两条不一样的道路P(u,v),P'(u,v)$
    + $G'=P(u,v) \oplus P'(u,v) = G[(E(P_{u,v}) \oplus E(P'_{u,v}))] \ne \emptyset$
    + $G'中每一个结点都是偶结点 \Rightarrow G的每个连通分支都是欧拉图 \Rightarrow G中存在回路 \Rightarrow 矛盾$
  + $(5) \Rightarrow (6):$
    + $反证法证明T无回路$
    + $另一部分显然$
  + $(6) \Rightarrow (1):$
    + $真·显然$

---

---

+ $G是森林 \Rightarrow |E(G)| = |V(G)| - \kappa(G),即m=n-k$

---

---

+ $非平凡树T至少存在两片树叶$
+ $证明:$
  + $\sum\limits_{i=1}^nd(v_i)=2(n-1) \Rightarrow \sum\limits_{i=1}^n(d(v_i)-1)=n-2$
  + $d(v_i)-1 \geq 0 \Rightarrow 至少存在两个结点v,使得d(v) - 1 = 0,即至少存在两片树叶$

---

+ **生成树** $T$  : 若树 $T$ 是图 $G$ 的生成子图, 则称树 $T$ 是 $G$ 的一棵生成树, 简称为 $G$ 的树
  + $G有生成树 \Leftrightarrow \kappa(G)=1$
+ 给定图 $G$ 的一棵生成树 $T$ 后, 我们称 $\overline T = G - T$ 为 $T$  的**余树**, $\overline T$ 的边称为 $T$ 的**弦**

## 3.2 回路与割集

### 3.2.1 生成树与基本回路系统

+ 设 $T$ 是连通图 $G$ 的生成树, $e_1,e_2,...,e_{m-n+1}$ 是 $T$ 的弦, 

  记 $C_r(1 \leq r \leq m - n + 1)$ 是 $T$ 加弦 $e_i$ 产生的回路, 称 $C_r$ 为对应于弦 $e_r$ 的**基本回路**。

  称 $\lbrace C_1,C_2,...,C_{m-n+1} \rbrace$ 为对应的**基本回路系统**

+ **环图**
  + 若 $G' \subseteq G$ (**结点集由边集诱导**) , 而且 $G'$ 中的所有结点都是偶结点, $G'$ 称为 $G$ 的**环图**
  + **包括空图**

---

+ $G$ 的所有环图组成一个数域 $\lbrace 0,1 \rbrace$ 上的线性空间 $V$

  + 线性空间 $V$ 的加法

    + $G_1+G_2=G_1 \oplus G_2 = G[E(G_1) \oplus E(G_2)]$

      + 以下证明 : $G_1,G_2是G的不同环图(E(G_1) \ne E(G_2)) \Rightarrow G' = G_1\oplus G_2还是环图$

        + $E(G') \subseteq E(G)$

        + $对任意v \in d_{G'}(v) = d_{G_1 \oplus G_2)}(v) = d_{G_1}(v) + d_{G_2}(v) - 2d_{G_1 \cap G_2}(v) $

          $\Rightarrow d_{G'}(v) 为偶数$

  + 证明 $V$ 是个线性空间

    + $1.$ 交换律 : $G_1 \oplus G_2 = G_2 \oplus G_1$
    + $2.$ 结合律 : $(G_1 \oplus G_2) \oplus G_3 = G_1 + (G_2 \oplus G_3)$
    + $3.$ 存在零元 :  $\emptyset$
    + $4.$ 负元 : $-G_1=G_1$ $G \oplus G = \emptyset$
    + $5.$ 数乘 : $k \in \lbrace 0,1 \rbrace$ 
      + 基本数乘
        + $k=0:$ $0 \cdot G = \emptyset$
        + $k=1:$ $1 \cdot G = G$
      + 数乘定律
        + $1 \cdot G = G$
        + $k_1 \cdot (k_2 \cdot G) = (k_1 \cdot k_2) \cdot G$
        + $(k_1 +k _2) \cdot G = k_1 \cdot G + k_2 \cdot G$
        + $k \cdot (G_1 + G_2) = k \cdot G_1 + k \cdot G_2 $

+ 证明 : $dim(V) = m-n+1$ ($V$ 的维度为 $m-n+1$)

  + 有限图 $\Rightarrow$ $dim(V)$ 有限

  + 以下证明 $\lbrace C_1,C_2,...,C_{m-n+1} \rbrace$ 是 $V$ 的一组基

    + $part\ 1:$ $\lbrace C_1,C_2,...,C_{m-n+1} \rbrace$ 线性无关

      + 即证 : $\sum\limits_{i=1}^{m-n+1}=k_1 \cdot C_1 + k_2 \cdot C_2 + ... + k_{m-n+1} \cdot C_{m-n+1} = 0$

        $\qquad \quad k_i = 0(\forall i \in [1,m-n+1]) \cap N)$

      + 由于 $k \in \lbrace 0,1 \rbrace$, 原命题 $\Leftrightarrow$ $C = C_{i_1} + C_{i_2} + ...  + C_{i_r} \ne 0,(r \ne 0)$

      + 各个环图对应的弦为 $e_{i_1},e_{i_2},...,e_{i_r}$

        $\Rightarrow e_{i_1},e_{i_2},...,e_{i_r} \in C$

        $\Rightarrow C \ne \emptyset$

    + $part\ 2:$ 任意 $G$ 的环图都可以由 $\lbrace C_1,C_2,...,C_{m-n+1} \rbrace$  线性表出

      + 不妨设 $G \ne \emptyset$, (当 $G \ne \emptyset$ 时, $k_i = 0$)

      + 设 $G$ 上的弦为 $e_{i_1},e_{i_2},...,e_{i_r},(1 \leq i_j \leq m-n+1)$​

      + 令$G' = C_{i_1} + C_{i_2} + ...  + C_{i_r}$, 断言 $G = G'$

        若 $G' \ne G,G'' = G \oplus G'$ 不是空图 $\Rightarrow$  $G''$ 含回路 $\Rightarrow$ $G''$ 含弦

        $\Rightarrow$ 这与 $G$ 和 $G'$ 弦集相同矛盾

---

+ $G$ 的任何回路 $C$ 都可以分成若干个基本回路的直和
+ 设连通图 $G$ 的回路个数为 $c$ , 则 $m-n-1 \leq c \leq 2^{m-n+1} - 1$
  + $m=-n+1$ 称为 **回路秩** 

### 3.2.1 生成树与基本割集系统

#### 3.2.1.1 断集

+ 无向图 $G=(V,E)$, $V_1 \subseteq V(G)$, (即 $(V_1,\overline {V_1})$ 是 $G$ 的一个划分)

  所有两端点分别在 $V_1$ 和 $\overline {V_1}$ 的边组成的集合记作 $E(V_1, \overline {V_1})$,  称为 $G$ 的一个**断集** 

+ 退化的**断集** : $E(V(G),\emptyset) = \emptyset$
+ 断集数量 : $2^n/2=2^{n-1}$

---

+ $G$ 的所有断集(包括空集)组成一个一个数域 $\lbrace 0,1 \rbrace$ 上的线性空间 $V$

  + 线性空间 $V$ 的加法, $E_1 + E_2 = E_1 \oplus E_2$

    + 即证明 : $G$ 的任意两个不同的断集 $E(V_1, \overline {V_1})$ 和 $E(V_2,\overline {V_2})$ 的直和也是一个断集

    + $E(V_1, \overline {V_1}) \oplus E(V_2, \overline {V_2}) = E(V_3, \overline {V_3})$

      其中, $V_3=(V_1 \cap V_2)\cup (\overline {V_1} \cap \overline {V_2})$

  + 和以上类似, 证明是线性空间需要满足 $8$ 条计算律

---

#### 3.2.1.2 割集与基本割集系统

+ **割集** : 一种特殊的断集

  + 设 $S$ 是连通图 $G=(V,E)$  的边子集, 如果满足

      $(1)\ $  $G'=(V,E-S)$是分离图

      $(2)\ $ 对于任意 $S_1 \subset S$, $G''=(V,E-S')$ 仍连通

    则称 $S$ 是 $G$ 的一个**割集**

+ $E(V_1,\overline {V_1})$ 是 $G$ 的一个断集, 且 $G[V_1]$ 和 $G[\overline {V_1}]$ 都是连通图, 那么 $E(V_1, \overline {V_1})$ 是一个**割集**

+ 设 $T$ 是连通图 $G$ 的生成树, 则 $T$ 的每一树枝边都对应着 $G$ 的一个割集

+ 设 $T$ 是连通图 $G$ 的生成树, 

  $n-1$ 个树枝对应的割集 $S_1,S_2,...,S_{n-1}$ 称为对应 $T$ 的**基本割集**, 

  称 $\lbrace S_1,S_2,...,S_{n-1} \rbrace$ 为对应 $T$ 的**基本割集系统**

+ $G$ 的所有断集(包括空集)组成一个一个数域 $\lbrace 0,1 \rbrace$ 上的线性空间 $V$

  + 类似于**回路系统**, 我们可以证明 $dim(V)=n-1$
  + 以下证明 $\lbrace S_1,S_2,...,S_{n-1} \rbrace$ 为 $V$ 的一组基
    + $part\ 1:$ $\lbrace S_1,S_2,...,S_{n-1} \rbrace$ 线性无关
    + $part\ 2:$  任何一个 $G$ 的断集都可以由 $\lbrace S_1,S_2,...,S_{n-1} \rbrace$ 线性表出

+ 连通图 $G$ 的每个割集必包含 $G$ 中每棵生成树的至少一个树枝

+ 连通图 $G$ 的任意一个割集都可以表示为生成树 $T$ 对应的若干基本割集的环和

+ 设连通图 $G$ 的割集数目为 $s$, 则 $n-1 \leq s \leq 2^{n-1}-1$

  +  $n-1$ 称为 **割集秩**

### 3.2.3 基本回路与基本割集

---

- $任何一个回路和任何一个割集都有偶数条公共边$
- $证明:$
  - $对任意割集S和任意回路C,设S将G分割成两个各自连通的结点集V_1,V_2$
    - $case\ 1:C的所有结点都在V_1(或V_2)中$
      - $S \cap C = \emptyset$
    - $case\ 2:C上既有V_1上的点,也有V_2上的点$
      - $不妨设v_0 \in (V_1 \cap C), C从v_0出发必须经过偶数条S的标才能从V_1到V_2再回到V_1$

---

---

+ $设T是连通图G的生成树, 弦e_i决定基本回路C_i, 树枝边e_j决定基本割集S_j,则有:$

  $e_i \in S_j \Leftrightarrow e_j \in C_i$

+ ($设T是连通图G的生成树, 则决定基本回路C_i的弦e_i只出现在所有C_i中的树枝边对应的基本割集中)$

+ $(设T是连通图G的生成树, 则决定基本割集S_j的树枝边e_j只出现在所有S_j中的弦对应的基本回路中$)

+ $证明:$

  + $\Rightarrow:$
    + $e_i \in S_j$
    + $|S_j \cap C_i|为偶数 \Rightarrow \exists\ e_k \in (S_j \cap C_i),k \ne i$
    + $e_i,e_k \in C_i \Rightarrow e_k 是树枝边(一个基本回路只有唯一的弦)$
    + $e_k \in S_j \Rightarrow k=j(一个基本割集只有唯一的树枝边)$
    + $e_j \in C_i$
  + $\Leftarrow:$
    + $类似$

---

## 3.3 最小生成树

#### 3.3.1 基本概念与基本树变换

+ **最小生成树**

  + 无向赋权连通图 $G$, $T$ 是 $G$ 的一棵生成树, 

    若 $T$ 满足对于任意 $G$ 的生成树 $T'$,都有 $w(T) \leq w(T')$,

    则称 $T$ 是 $G$ 的一棵**最小生成树**

  + 最小生成树不一定唯一

+ 树枝边与弦

  + 设 $T$ 是连通图 $G$ 的一棵生成树, $e$ 是 $T$ 的一条弦, $C_e$ 是由 $e$ 决定的基本回路。

    若 $C_e$ 不是自环, 必存在边 $e' \in (C_e - e)$,

    于是, $T'=T \oplus \lbrace e, e' \rbrace$ 为 $G$ 的另一棵生成树, 且 $T'$ 与 $T$ 只有一条边不同

  + 树枝边对应的割集也类似

+ $T_1,T_2$ 都是 $G$ 的生成树, 若 $T_1$ 与 $T_2$ 恰有 $k$ 条边不同, 则称 $T_1$ 与 $T_2$ 的**距离**为 $d(T_1,T_2)=k$

+ **基本树变换**

  +  $T_1,T_2$ 都是 $G$ 的生成树, 若 $d(T_1,T_2)=1$,记 $e_1 = T_1 - T_2,e_2 = T_2 - T_1$

    则称 $T_2=T_1 \oplus \lbrace e_1,e_2 \rbrace$ 为 $T_1$ 到 $T_2$ 的**基本树变换**

  + 作业 $2.2$ 的特殊情况

---

+ $若T_0是连通图G的一棵生成树, 则G的任意其他生成树T都可以由T_0通过若干次基本树变换得到$
+ $归纳法证明:$
  + $不妨设d(T_0,T)=k,显然E=E(T_0)-E(T)非空, 因此存在\ e_1 \in E$
  + $由作业2.2, \exists\ e_2 \in E(T) - E(T_0), T'=T_0 \oplus \lbrace e_1,e_2 \rbrace (一次基本树变换)也是G的一棵生成树$
  + $而且满足 d(T',T)=k-1,由归纳假设,证毕$

---

#### 3.3.2 算法正确性系列定理

---

+ $定理\ 3.3.2.1:$
  + $设T是无向赋权连通图G=(V,E,w)的一棵生成树,则以下论断等价$
    + $(1)\ T是G的一棵最小生成树$
    + $(2)\ 对于任意树枝边e(e \in E(T)), 都有e是S_e中权值最小的边$
    + $(3)\ 对于任意的弦e'(e' \in G - E(T)),都有e'是C_{e'}中权值最大的边$
+ $证明:$
  + $(1) \Rightarrow(2):反证法$
    + $否则存在弦e' \in S_e, 满足w(e') < w(e),$
    + $e' \in S_e \Rightarrow e \in C_{e'}, 做基本树变换 T' = T \oplus \lbrace e,e' \rbrace$
    + $有w(T') < w(T), 与T是最小生成树矛盾$
  + $类似可证明:(1) \Rightarrow (3)$
  + $(2) \Rightarrow (3):$
    + $对于任意树枝边e \in C_{e'}, 则有 e' \in S_e$
    + $w(e) \leq w(e')$
  + $类似可证明:(3) \Rightarrow (2)$
  + $(3) \Rightarrow (1):反证法+极化方法$
    + $若T不是G的一棵最小生成树$
    + $设T'是与T有最多公共边的G的一棵最小生成树$
    + $T \ne T', 取e' \in (E(T')-E(T)), 则此时e'是T'的树枝边, e'是T的弦$
    +  $则现在相对于T'的基本割集S_{e'}和相对于T的基本回路C_{e'}有偶数个公共点$
    +  $又因为e' \in (S_{e'} \cap C_{e'}), 即存在T的树枝边e \in (S_{e'} \cap C_{e'})$
    +  $所以, e是T的树枝边  \Rightarrow w(e) \leq w(e'), e是T'的弦 \Rightarrow w(e) \geq w(e')$
    +  $\Rightarrow w(e) = w(e')$
    +  $做基本树变换 T'' = T' \oplus \lbrace e,e' \rbrace, 则T''也是G的最小生成树$
    +  $T''与T的公共树枝边数目 = T'与T的公共树枝边数目 + 1 \Rightarrow 矛盾$ 
  +  $证毕$

---

---

+ $定理3.3.2.2:$
  + $设G=(V,E,w)是无向赋权连通图, e 是 G 的某个断集中权值最小的边,则:$
    + $G存在以e为树枝边的最小生成树$
+ $证明:反证法+极化方法$
  + $设E' = E(V_e,\overline {V_e}) 为满足e权值最小的断集$
  + $设T是G的一棵最小生成树, 不妨设 e \notin T,则断集E'与基本回路 C_e有偶数条公共边$
  + $因为e \in (E' \cap C_e) \Rightarrow 存在T的树枝边 e' \in (E' \cap C_e)$
  + $此时,$
    + $e 是断集 E' 权值最小的边 \Rightarrow w(e) \leq w(e')$
    + $e是基本回路C_e权值最大的边 \Rightarrow  w(e) \geq w(e')$
    + $\Rightarrow w(e) = w(e')$
  + $作基本树变换 T' = T \oplus \lbrace e,e' \rbrace, T'为包含边e的最小生成树$
  + $证毕$ 

---

---

+ $定理3.2.2.3:$

  + $设G=(V,E,w)为无向赋权连通图,且存在以 e 为树枝边的最小生成树$​

    $ G'是G收缩e得到的新图(保留重边, 自环无意义), T是G'的一棵最小生成树, 则:$ 

    + $T' = G[E(T) \cup \lbrace e \rbrace] 是G的最小生成树$

  + $证明:$

    + $显然, T' 是G的一棵生成树,w(T')=w(T)+w(e)$
    + $设 \widetilde {T} 是以e为树枝边的最小生成树,$
    + $设\widetilde T' 是在 \widetilde T 中收缩 e 得到的图, 显然 \widetilde T' 是G' 的一棵生成树,且w(\widetilde T) = w(\widetilde T') + w(e)$
    + $以下证明 w(\widetilde T) = w(T)$
      + $T是G'的一棵最小生成树 \Rightarrow w(T) \leq w(\widetilde T')$
      + $\widetilde T 是G的一棵最小生成树 \Rightarrow w(\widetilde T) \leq w(T') \Rightarrow w(\widetilde T') \leq w(T)$
      + $w(\widetilde T) = w(T'), w(\widetilde T') = w(T)$
    + $T' = G[E(T) \cup \lbrace e \rbrace] 是G的最小生成树$

---

---

+ $定理3.2.2.4:$
  + $设G=(V,E,w)为无向赋权连通图,C是G中任意一条回路, e 是  C 中权值最大的边, 则:$
    + $G-e 的最小生成树也是G的最小生成树$
  + $证明:$
    + $设T是G的一棵最小生成树, 且满足e \in E(T)$
    + $S_e \cap C 有偶数条公共边, e \in (S_e \cap C) \Rightarrow 存在除e之外的其他边 e' \in (S_e \cap C)$
    + $做基本树变换 T' = T \oplus \lbrace e,e' \rbrace$
    + $下证 w(T) = w(T')$
      + $w(e') \leq w(e) \Rightarrow w(T') \leq w(T)$
      + $T是最小生成树 \Rightarrow w(T) \leq w(T')$
      + $\Rightarrow w(T) = w(T')$
    + $T'是不含e的最小生成树$
    + $\Rightarrow 任意含e的最小生成树都能转化为不含e的最小生成树, 证毕$

---

#### 3.3.3 Kruskal 算法(边驱动)

---

+ $Kruskal\ Algorithm$
  + $1.\ T =\emptyset \quad (initial), E = E(G)$
  + $2.\ 当 |T| < n-1,而且E \ne \emptyset\ 时$
    + $Begin$
      + $e = (E中权值最小的边)$
      + $E=E-e$
      + $若T+e无回路, T = T+e$
    + $End$
    + $3.若|T| < n-1, 打印``非连通", 否则输出最小生成树T$

---

+ 算法正确性:
  + 算法留在 $T_{n-1}$ 外的边都是弦, 算法保证这些弦在对应的基本回路中都是带权最大的边
  + 由定理 $3.2.2.1$ , 算法得到的的确是最小生成树

---

#### 3.3.4 Prim算法(结点驱动)

---

---

+ $Prim\ Algorithm$
  + $1.\ U = \lbrace v_0 \rbrace , T = \emptyset;\forall v \in (V-U),t(v) = v_0. \qquad \qquad(initial)$
  + $2.\ While\ U \ne V\ do$
    + $Begin$
      + $u = \mathop{\arg \min}\limits_{u \in (V - U)} w(t(u), u)$ 
      + $U=U+u, T = T + (t(u),u)$
      + $\forall v \in (V-U)$
        + $if\ (w(u,v) < w(t(u),u))$
          + $then\ t(v) = u$
    + $End$

---

+ 算法正确性:
  + 相当于每次都找断集 $E(V, \overline V)$ 中的权值最小的边
  + 定理 $3.3.2.2$ , 定理 $3.3.2.3$ 保证了算法正确性

#### 3.3.5 破圈法

---

+ $Algorithm$

  + $1.\ T = E(V) \qquad \qquad (initial)$

  + $2.\ While\ T中含有回路 \ do$

    + $Begin$
      + $e = (T中任意回路C中权值最大的边)$
      + $T = T - e$
    + $End$

  + $3.\ if\ |T| = n-1\ 打印最小生成树T$

      ​    $else \ 打印 ``非联通"$

---

+ 算法正确性 : 定理 $3.3.2.4$ 保证

## 3.4 无向连通图树的计数

+ $Cayley:K_n的生成树数目为n^{n-2} \qquad (标定图,所有结点编好固定的号码(1-n))$
  + $(V,E_1) = (V,E_2) \Leftrightarrow ((u,v) \in E_1 \Leftrightarrow (u,v) \in E_2, \forall u,v \in V)$

---

+ $设B_0是有向图G关联矩阵的任意一k(1 \leq k \leq n)阶子方阵,则det(B_0) \in \lbrace 0,1,-1 \rbrace$
+ $证明:数学归纳法$
  + $k=1时,显然$
  + $k时$
    + $若有某列全0,det(B_0)=0$
    + $若所有列都含有两个非0元,构成回路,各列线性相关,det(B_0)=0$
    + $有某列含有一个非0元(1或-1),按该列展开,det(B_0)=1(或-1) \cdot det(B_0')=1(或-1)$

---

---

+ $矩阵树定理:$

+ $设G是无向连通图G(可有重边,但不允许有自环), 对G的每一条边加一方向, 变成有向图D$

  $D的关联矩阵B=(b_{i,j})_{n \times m}$

  + $b_{i,j}=1,\qquad i是边e_j的起点$

    $b_{i,j}=-1,\quad i是边e_j的终点$

    $b_{i,j}=0,\qquad otherwise$

  $将B任意删去一行得到B^{\ast},(B^{\ast}称为基本关联矩阵),G的生成树数目为det\lbrace B^{\ast} \cdot (B^{\ast})^t\rbrace$
  
+ $证明:$

  + $Binet-Cauchy\ Formula$

    + $A=(a_{i,j})_{n \times m},B=(b_{i,j})_{m \times n},n \leq m$
    + $det(AB)=\sum\limits_{S \in \lbrace (j_1,j_2,...,j_n):1 \leq j_1 < j_2 <  ... < j_n \leq m  \rbrace} det(A_s) \cdot det(B_s)$
    + $任取A中n列,以及B对应的n行\ (取A中n \times n方阵与B中对应的 n \times n方阵)$

  + $det(B^{\ast} \cdot (B^{\ast})^t) = \sum\limits_{S \in \lbrace (j_1,j_2,...,j_{n-1}):1 \leq j_1 < j_2 <  ... < j_{n-1} \leq m  \rbrace} det(B^{\ast}_s) \cdot det(B^{\ast}_s)^t $

      ​                            $=  \sum\limits_{S \in \lbrace (j_1,j_2,...,j_{n-1}):1 \leq j_1 < j_2 <  ... < j_{n-1} \leq m  \rbrace} {|det(B^{\ast}_s)|}^2$

  + $s决定的n-1条边含有回路 \Leftrightarrow det(B^{\ast}_s) = 0$

    $s决定的n-1条边不含回路 \Leftrightarrow det(B^{\ast}_s) = \pm 1$

  + $以下证明以上结论:$

    + $n=2时,B^{\ast}_s = (1)\ (or (-1)) \Rightarrow {|det(B^{\ast}_s)|}^2=1 \Rightarrow$

      + $设边数m,det(B^{\ast} \cdot (B^{\ast})^t)= \sum\limits_{S \in \lbrace (j_1,j_2,...,j_{n-1}):1 \leq j_1 < j_2 <  ... < j_{n-1} \leq m  \rbrace} {|det(B^{\ast}_s)|}^2={m \choose 1}=m$
      + $\Rightarrow 满足条件$

    + $n=k(k \geq 3)时,$

      + $无向连通图保证删去的一行肯定不是全为0(任意一点都有边与其相连)$

        $\Rightarrow 存在某列a,a列仅有1个1(或-1),剩余都为0$

      + $找回路(无向回路),a列中为1(或-1)的点开始出发找边$

      + $若找到回路,将回路对应的列乘以一个系数 \lambda(正向1,负向-1)相加后得到0向量$

        $\Leftrightarrow 线性相关 \Leftrightarrow det(B^{\ast}_s) = 0$

      + $若没找到回路 \Leftrightarrow 线性无关 \Leftrightarrow  det(B^{\ast}_s) = \pm 1$

---

+ 标定图 $K_n$
  + 结点集 $\lbrace 1,2,...,n \rbrace$
  + 任何一棵树都可以用 $1$ 个 $n-2$ 长的结点序列 $(prufer序列)$ 唯一确定
  + $prufer序列中某个编号出现的次数就等于这个编号的节点在无根树中的度数-1$
  + $K_n的生成树数目为n^{n-2}$
  + $树转序列 \Leftrightarrow 序列转树:逆过程$

```C
(1)树转序列 : 每次找标号最小的结点, 记录其父结点
  树:
          6          5
           \        / 
            1------2  
           /        \ 
          3          4

 过程:
         6          5    6          5   6          5   6              6
          \        /      \        /     \        /     \              \ 
           1------2    ->  1------2   ->  1------2   ->  1------2   ->  1
          /        \               \ 
         3          4               4 

 序列: {1,2,2,1}

(2)序列转树
 序列: {1,2,2,1}
 
 过程: 
      初始化: queue A = {1,2,2,1}, B = {}
      while(A不空)
          m = 不在 A∪B 中的最小元素
          n = A.pop()
          m 和 n 加边
          B = B∪{k}
      最后将不在B中的结点之间加边

 树:
   6      5   |   6      5   |   6      5   |   6      5   |   6      5 
              |              |         /    |         /    |    \    /  
     1  2     |     1  2     |     1  2     |     1--2     |     1--2   
    /         |    /    \    |    /    \    |    /    \    |    /    \  
   3      4   |   3      4   |   3      4   |   3      4   |   3      4 
```

## 3.5 有向树

+ 若有向图D的基图为树, 则称D为**有向树**
+ **根树**
  + 若 $T$ 是非平凡有向树, 如果 $T$ 只有一个结点的入度为 $0$, 其他结点的入度都为 $1$, 那么称 $T$ 为**根树**
  + 入度
    + 入度为 $0$ 的结点称为**树根**
  + 出度
    + 出度为 $0$ 的结点称为**树叶**/**外点**
    + 出度非 $0$ 的结点称为**分支点**/**内点**

---

+ $T为根树, v_0为树根, 那么 v_0到其他结点都存在唯一的有向路径$
+ $证明1:数学归纳法,对根树的阶进行归纳$
  + $n=1时,显然$
  + $n=k时$
    + $至少存在一个树叶u(无向树至少存在两个树叶,在有向树中,根可能是其中之一),与u相连的结点记作v$
    + $容易验证T-n也是根树,由归纳假设, v_0到T-n中的非根节点存在唯一有向路径$
    + $u与T-n仅有一边(v,u)相连, v_0到v存在唯一有向路径 \Rightarrow v_0到u存在唯一有向路径$ 
+ $证明2:$
  + $任意选点一个非根结点u,u的入度为1,因此可以找到u的唯一直接前驱u_1$
  + $任意非根结点的入度都为1, 因此可以向前找直接前驱, 由于是有限图, 最终一定会停止在树根v_0处$
  + $寻找路径便形成v_0到u的唯一路径$ 

---

+ $u,v \in V(T)$ 
  + 若有向边 $(u,v) \in E(T)$, 则称 $u$ 是 $v$ 的**父亲**,  $v$ 是 $u$ 的**儿子**
  + 同一结点的不同儿子互称**兄弟**
  + 若 $u$ 到  $v$ 存在有向路径, 则称 $u$ 是 $v$ 的**祖先**, $v$ 是 $u$ 的**子孙**
  + 从树根到结点 $v$ 的有向路径的长度称为 $v$ 的**层数**
  + 从树根到树叶的最大层数称为树的**高度**/**深度**

+ 一般情况下不区分兄弟结点之间的先后顺序
+ 画根树时一般将层数小的画于上方, 此时省略箭头不会引起误会
+ **根树** $\Rightarrow$ **层次结构**
+ **子树**
  + 设 $T$ 是一棵根树, $u$ 是 $T$ 的一个分支结点,  $u$ 及其子孙导出的子图 $T_u$ 称为 $T$ 的**子树**
  + $T_u$ 是以 $u$ 为根的根树
+ **有序树**
  + 考虑兄弟结点之间的顺序
+ $T$ 是一棵根树, $m \geq 2$
  + $T为m元树 \Leftrightarrow T的每个分支结点至多有m个儿子$
  + $T为正则m元树 \Leftrightarrow T的每个分支结点恰有m个儿子$
  + $T为有序m元树 \Leftrightarrow m元树T是有序的$
  + $T为有序正则m元树 \Leftrightarrow 正则m元树T是有序的$
  + $T为完全m元树/满m元树 \Leftrightarrow 正则m元树的所有树叶都在同一层$
  + $T为均衡二元树$
    + $1\ \Leftrightarrow 任意结点的左右子树层数差小于等于1$
    + $2\ \Leftrightarrow 所有的叶子结点只在两层上$
    + $1范围比2大,一般采取2$ 

+ **有序正则二元树**
  + **表达式树**

---

+ $设T是一棵正则二元树,T的分支结点数i和树叶数t满足:i=t-1$

+ $证明:$
  + $所有结点数=i+t=2i+1(一个分支结点有两个儿子,树根不由分支结点产生) \Rightarrow i=t-1$
+ $推广到m元:(m-1)i=t-1$

---

---

+ $设T是一棵正则二元树,i表示T的分支结点数,I表示各分支结点的层数之和,E表示各树叶层数之和,则:$
  + $E=I+2i$
  + $(E:外部路径长度之和;I:内部路径长度之和)$
+ $证明:数学归纳法,对根树的分支结点数i进行归纳$
  + $i=1时$
    + $n=3,E=2,I=0 \Rightarrow E=2i+1$
  + $i=k时$
    + $设T的高度为h,存在两兄弟v_1,v_2, 它们的高度为h, 记它们父亲为u$
    + $删去v_1,v_2$
      + $E'=E-2h+(h-1)=E-h+1$
      + $I'=I-(h-1)=I-h+1$
    + $由归纳假设, E‘ = I' + 2(k-1) \Rightarrow E-h+1=I-h+1+2(k-1) \Rightarrow E=I+2k$
  + $证毕$
+ $推广到m元:E=(m-1)I+mi$

---

## 3.6 最优树

### 3.6.1 最优树

+ 讨论**树叶带权**的 $m$ 元树(主要 $2$ 元)

+ **赋权二元树**

  + 设二元树 $T$ 有 $t$ 片树叶 $v_1,v_2,...v_t$, 分别带权 $w_1,w_2,...,w_t$ ($w_i$为正实数), 

    则称 $T$ 为**赋权二元树**, 称 $w(T)=\sum\limits_{i=1}^tw_i \cdot l(v_i)$ 为二元树的权, 其中 $l(v_i)$ 是树叶 $v_i$ 的层数

+ **最优二元树**
  
  + 在所有的含 $t$ 片树叶分别带权 $w_1,w_2,...,w_t$ 的二元树中, 权最小的二元树称为**最优二元树**

---

+ $最优二元树一定存在$

+ $证明:$

  + $part\ 1:最优二元树一定是正则二元树$

    + $若T不是正则二元树,总可以通过收缩T中所有只有一个儿子的分支结点u得到一棵正则二元树T',$

      $满足w(T')<w(T)$

      $(将u的父亲和u的儿子相连,u子树中的节点层数变小,u子树外的结点层数不变,整体权变小)$

  + $part\ 2:正则二元树数目有限$

    + $构造单射,标定法:$

      + $首先标记叶子结点,按照权值从小到大标记1,2,...,t$

      + $标记内部节点,按层数从小到大标记t+1,t+2,...,2t-1,$

        $层数相同的比较其子树内最小的叶子结点的标号,小的先标$

      + $构造出了从正则二元树到K_n的标定图的单射$

      + $正则二元树数目N有限,N \leq (2t-1)^{2t-3}$

    + $数学归纳法$

    + $比较法(构造单射)$

      + $叶子结点数目为t的正则二元树结点数为(2t-1)$

      + $n个结点的有序二元树的数目为 \frac{1}{n+1}{2n \choose n}$
        + $Catalan数$
      + $正则二元树数目 < 二元树数目 < 二元有序树数目 = \frac{1}{n+1}{2n \choose n}$

  + $有限棵树里面一定有最优(N全序集)$

---

---

+ $存在带权为w_1 \leq w_2 \leq ... \leq w_t的最优二元树T,使得带权为w_1,w_2为最深层的兄弟$

+ $证明:$

  + $不妨令带权w_i的叶子结点记作v_i,所在层数记作l_i,$

  + $设T_0为带权w_1,w_2,...,w_t的最优二元树,高度为h,满足l_1,l_2 < h,$

  + $T_0为正则二元树,因此存在两个层数为h的兄弟结点v_i,v_j,$

  + $将v_i与v_1,v_j与v_2作交换,得到新的一棵正则二元树T$

  + $w(T)-w(T_0)=w_1(h-l_1)+w_2(h-l_2)+w_i(l_1-h)+w_j(l_2-h)$

     ​                           $=(w_1-w_i)(h-l_1)+(w_2-w_j)(h-l_2) \leq 0$
     
  + $而w(T)-w(T_0) \geq 0$
  
  + $\Rightarrow,w_1=w_i,w_2=w_j,w(T)=w(T_0),T为满足题意的最优二元树$
  
+ $证明过程我们可以看到带权最小的两片树叶恰为最优二元树的最深层的兄弟$

---

---

+ $设有一棵带权为w_1+w_2,w_3,...,w_t的最优二元树T', 其中 w_1 \leq w_2 \leq w_3 \leq ... \leq w_t$

  $在T'中,让带权为w_1+w_2的树叶产生两个儿子,分别带权w_1,w_2$

  $则得到的二元树T是带权w_1,w_2,w_3,...,w_t的最优二元树$

+ $证明:$

  + $w(T)=w(T')+w_1+w_2$
  + $设T_1是带权w_1,w_2,w_3,...,w_t的最优二元树, 那么有带权为w_1,w_2是T_1最深层的两个兄弟$
    + $w(T_1) \leq w(T)$
  + $将T_1中带权为w_1,w_2的两个树叶删去,让它们的父亲带权w_1,w_2,得到一棵新的正则二元树T_1'$
    + $w(T_1)=w(T_1')+w_1+w_2$
  + $w(T') \leq w(T_1')$
  + $w(T)=w(T_1)$
  + $T是最优二元树$

---

---

+ $Huffman\ Algorithm(二元树)$
+ $Algorithm$
  + $1.\ S=\lbrace w_1,w_2,...,w_t \rbrace, V = \lbrace v_1,v_2,...,v_t \rbrace, E = \emptyset,w(v_i)=w_i \qquad \qquad (initial)$
  + $2.\ S中取出最小的两个权 w_x, w_y, w' =w_x+w_y$
  + $3.\ S = S \oplus \lbrace w_x,w_y \rbrace \cup \lbrace w' \rbrace, V = V \cup \lbrace v' \rbrace, 满足w(v')=w',E=E\cup \lbrace (v',v_x),(v',v_y) \rbrace$
  + $4.\ 若S = \emptyset,输出Huffman树T=(V,E),否则转2$
+ $w(T) = \sum\limits_{v \in V,v不是树叶}w(v) = \sum\limits_{v \in V,v是树叶}(w(v)l(v))$

---

---

+ $Huffman\ Algorithm(m元树)$

+ $给定t个正实数w_1  \leq w_2 \leq ... \leq w_t, 求一棵最优m元树$

+ $i = \frac{t-1}{m-1}$

+ $Algorithm$

  + $0.\ 若 \frac{t-1}{m-1}不是整数, 添加最少的树叶(权值为0)至\frac{t’-1}{m-1}为整数;否则t'=t$

  + $1.\ S=\lbrace w_1,w_2,...,w_{t'} \rbrace, V = \lbrace v_1,v_2,...,v_{t'} \rbrace, E = \emptyset,w(v_i)=w_i \qquad \qquad (initial)$

  + $2.\ S中取出最小的m个权 w_{x_1},w_{x_2},...,w_{x_m}, w' = \sum\limits_{i=1}^{m}w_{x_i}$

  + $3.\ S = S \oplus \lbrace w_{x_1},w_{x_2},...,w_{x_m} \rbrace \cup \lbrace w' \rbrace, V = V \cup \lbrace v' \rbrace, 满足w(v')=w',$

    $E=E\cup \lbrace (v',v_{x_i}):i \in ([1,m] \cap N) \rbrace$

  + $4.\ 若S = \emptyset,输出Huffman树T=(V,E),否则转2$

---

### 3.6.1 最优树的应用 : 编码 

+ 设 $\alpha_1\alpha_2...\alpha_n$ 是长度为 $n$ 的字符串,称其子串 $\alpha_1,\ \alpha_1\alpha_2,\ \alpha_1\alpha_2\alpha_3,\ \alpha_1\alpha_2...\alpha_n$ 分别是

  $\alpha_1\alpha_2...\alpha_{n-1}$ 的长度为 $1,2,3,...,n-1$ 的**前缀**

+ 设 $A=\lbrace \beta_1,\beta_2,\beta_3,..,\beta_n \rbrace$ 是一个符号串集合, 若对任意的 $\beta_i,\beta_j \in A,i \ne j$, 都有 $\beta_i$ 不是 $\beta_j$ 的前缀,

  则称 $A$ 为**前缀码**, $A$ 中的符号串 $\beta_i(1 \leq i \leq m)$ 称为**码字**

  + 特别的, 若码字均为二进制序列, 则称 $A$ 为**二元前缀码**

---

+ $一个二元前缀码唯一的对应着一棵有序二元树$
+ $从根开始,给边标号, 向左的边标0,向右的边标0,形成了一棵有序二元树$
+ $从构造过程可以看出唯一性,双射$

---

+ **最优二进制编码** : 编码后字符串的总长度最短
  + 频率作权值, 求最优二元树

## 3.7 有向弱连通图根树的计数

+ 若根树是有向弱连通图 $D$ 的生成子图, 则称 $T$ 是 $D$ 的一棵**根树**
+ 计数问题 : **在图中任意选定一点 $v_k$ ,问以 $v_k$ 为树根的根树有多少棵?**
+ **基本关联矩阵** :
  + $B_k$ 是 $B$ 删去 $v_k$ 对应的行的矩阵, 称 $B_k$ 为 $v_k$ 对应的关于 $D$ 的**基本关联矩阵**

---

+ $设B是弱连通图D的v_k对应的基本关联矩阵,令\vec B为B_k将所有1元改为0元之后得到的矩阵,则:$

  $D的以v_k为树根的根树数目为det(\vec {B_k} \cdot {B_k}^t)$

  + $det(\vec {B_k} \cdot {B_k}^t) = \sum\limits_{S \in \lbrace (j_1,j_2,...,j_{n-1}):1 \leq j_1 < j_2 <...<j_{n-1} \rbrace}(det \vec B_{k-s} \cdot {B_{k-s}}^t)$

+ $证明:见《图论与代数结构》一书$

---


## 3.8 作业

+ $1.1:非平凡树(|V(T)| \geq 2)中道路最长的端点一定是树叶$

+ $1.2:G为n(n \geq 5)阶无向简单图 \Rightarrow G或\overline G必含回路$

+ $1.3:设d_1,...,d_n为n(n \geq 2)个正整数, 证明:$
  
  + $若 \sum\limits_{i=1}^nd_i = 2(n-1), 则一定存在一棵结点度分别为d_1,...,d_n的树$
  
+ $2.1:完全图K_n(n \geq 3)的所有边都赋以整数权,每一个回路的权定义为其所有边权之和,试证明:$
  
  + $K_n的每个回路的权都为偶数 \Rightarrow K_n 的每个三角形回路的权都为偶数$
  
+ $2.2:设T_1,T_2是无向连通图G的两棵生成树,e_1 \in E(T_1)-E(T_2),试证明:$
  
  + $存在\ e_2 \in E(T_2)-E(T_1), 使得\ T'_1=T_1-e_1+e_2和\ T'_2=T_2-e_2+e_1都是G的生成树$
  
+ $3.1:设T是赋权连通图G的生成树, 用max(T)表示T的最大边权,$

  ​         $用minmax表示所有生成树中最小的max(T),试证明:$

  + $1.\ 若T是G的最小生成树, 则max(T)=minmax.$
  + $2.\ 反之不然$

+ $3.2:$

  $设G=(V,E,w)是一个赋权连通图,$

  $T_1=\lbrace e_{i_1},e_{i_2},...,e_{i_{n-1}} \rbrace,T_2=\lbrace e_{j_1},e_{j_2},...,e_{j_{n-1}} \rbrace 是G的两颗不同的最小生成树,$

  $且满足w(e_{i_1}) \leq w(e_{i_2}) \leq ... \leq w(e_{i_{n-1}}),\ w(e_{j_1}) \leq w(e_{j_2}) \leq ... \leq w(e_{j_{n-1}}),$

  $试证明:$

  + $w(e_{i_k})=w(e_{j_k}), \forall k \in (N \cap [1,n-1])$

+ $3.3:设T,T'是赋权连通图G的两个不同的最小生成树, 试证明:$

  + $经过一系列基本树变换可以将T变为T',且这些基本树变换过程中产生的树都是G的最小生成树$ 

+ $4.1:给出字符串``state\ act\ as\ a\ seat"$

  + $a.\ 的最优二进制编码$
  + $b.\ 若字符串不允许带空格,求该字符串的最优二进制编码$

+ $4.2:设t \geq 2, l_1,l_2,...,l_t是t个正整数, 存在二元前缀码 \lbrace \beta_1,\beta_2,..,\beta_t \rbrace,$

  ​      $使得码字\beta_1,\beta_2,..,\beta_t 的长度分别为l_1,l_2,...,l_t的充要条件为:\sum\limits_{i=1}^t2^{-l_i} \leq 1(Kraft\ 不等式)$

+ $4.3:$

  + $给定一个点集P= \lbrace p_1,p_2,...,p_n \rbrace 和其上的距离函数d, d满足:$

    + $a.\ d(p_i,p_j) = d(p_j,p_i) >0, i \ne j$
    + $b.\ d(p_i,p_i) = 0$

  + $我们可以如下构造P上的分层距离\tau:构作一个含n片叶子的根树T,对T的每个结点v赋以高度h_v,h_v满足:$

    + $a.\ 如果v是叶子,则h_v=0$
    + $b.\ 如果u 是v的祖先,则h_u \geq h_v$

  + $将P中的点分别放在不同的叶子上,对任意两点p_i和p_j,定义\tau(p_i,p_j)=h_v,其中v是p_i与p_j最近的公共祖先$

    $我们说分层距离\tau与d是相容的,如果对任意两点p_i,p_j,又\tau(p_i,p_j) \leq d(p_i,p_j)$

  + $请设计多项式时间复杂度的算法,$

    $以P= \lbrace p_1,p_2,...,p_n \rbrace和其上的函数d为输入,以满足下面性质的分层距离\tau为输出:$

    + $a.\ \tau与d是相容的$
    + $b.\ 若 {\tau}'任意与d相容的分层距离,则对任意两点p_i,p_j,有{\tau}'(p_i,p_j) \leq \tau(p_i,p_j)$


## 3.9 参考答案

+ $1.1:最长道路+T无回路$

+ $1.2:反证法$

  + $假设G和\overline G都不含回路$
  + $G不含回路 \Rightarrow G的每个连通分支都是树 \Rightarrow m(G)=n-\kappa(G)$
  + $同理有, m(\overline G) = n -\kappa(\overline G)$
  + $m(G) + m(\overline G) = \frac12n(n-1) = 2n - \kappa(G) - \kappa(\overline G) \leq 2n-2 \Rightarrow 1 \leq n \leq 4 \Rightarrow 矛盾$

+ $1.3:数学归纳法$

  + $n=2时,d_1=d_2=1 \Rightarrow \circ-\circ \Rightarrow OK$

  + $n \geq 3时:$

    + $一定存在k, 使得d_k=1,否则 \sum\limits_{i=1}^nd_i \geq 2n \Rightarrow 矛盾$

    + $一定存在j, 使得d_j \geq 2, 否则 \sum\limits_{i=1}^nd_i \leq n \Rightarrow 矛盾$

    + $令\ d_i' = d_i'-1=0 ,\ \qquad (i=k)$

      $\quad d_i'=d_i-1,\qquad \qquad \ (i=j)$

      $\quad d_i'=d_i,\ \qquad \qquad \qquad else $

    + $\sum\limits_{i=1,i\ne k}^nd_i'=2((n-1)-1), 由归纳假设存在一棵结点度为d_i'(i \in [1,n] \cap N \cap \lbrace k \rbrace)的树T_{n-1},$

      $V(T_{n-1})=\lbrace v_i:1 \leq i \leq n, i \in N, i \ne k \rbrace, d(v_i)=d_i$

    + $新加结点v_k, d(v_k)=0, 在 v_k 和 v_j 加新边形成树T_n, 此时构造出一棵结点度分别为d_i的树$

    + $证毕$

+ $2.1:$

  + $\Rightarrow:显然$
  + $\Leftarrow:$
    + $任取K_n的一个回路C = v_0v_1...v_kv_0$
    + $令C_i = v_0v_iv_{i+1}v_0(C_i的权为偶数),则C= \mathop{\oplus}\limits_{i=1}^{k-1}C_i$
    + $以下证明 : 若C_1,C_2的权为偶数,  则C' = C_1 \oplus C_2的权也为偶数$
      +  $w(C')=w(C_1)+w(C_2)-2w(C_1 \cap C_2)$
      +  $证毕$

+ $2.2:$

  + $T_1 - e_1将G的结点划分为两个部分V_1,V_2$
  + $由e_1 \in T_1(树), G[V_1],G[V_2]连通$
  + $E(V_1,V_2)为割集,记为S,e_1 \in S$
  + $|S| \geq 2,否则G-e_1不连通,这与T_2是树矛盾(e_1 \notin T_2)$
  + $由于G - S不连通, 一定存在e_2 \in (E(T_2) \cap S), 由e_1 \in E(T_2)可知, e_2 \ne e_1$
  + $e_1,e_2 \in S$
  + $由割集性质,T_1-e_1+e_2和T_2-e_2+e_1都连通$
  + $而且|T_2-e_2+e_1|=|T_2|=n-1=|T_1|=|T_1-e_1+e_2|$
  + $T_1-e_1+e_2和T_2-e_2+e_1都是G的生成树$

+ $3.1:$

  + $1.$

    + $max(T) \geq minmax$

    + $设e_i是T中带权最大的边, 以下反证法证明max(T)=w(e_i)=minmax$

      + $若 w(e_i) > minmax,则存在最小生成树T_x,  满足max(T_x) =minmax$

      + $ w(e_i) > w(e), \forall e \in E(T_x)$

      + $e_i \in (E(T) - E(T_x)), 由作业2.2,$

        $存在 e' \in (E(T_x) - E(T)), 满足T' = T \oplus \lbrace e_i,e' \rbrace 也是G的一棵生成树$

      + $w(T') = w(T) -w(e_i) + w(e') < w(T) \Rightarrow 与T是最小生成树矛盾$

    + $max(T) = minmax$

  + $2.\ 举反例,G如下图所示$

    + $G的一棵最小生成树为T = \lbrace e_2,e_3 \rbrace, w(T) = 3,minmax = max(T) = 2$
    + $T' = \lbrace e_1,e_3 \rbrace 也是一棵生成树且满足max(T')=2,但T'不是最小生成树, w(T') = 4$

```C
    w(e1) = 2       w(e3) = 2
A---------------B---------------C    
|               |
+---------------+
    w(e2) = 1 
```

+ $3.2:$
  + $设k是两个边列表中第一次出现不同边的位置,$
    + $也就是说 k = \mathop{\arg \max}\limits_{1 \leq k \leq n-1}(e_{i_l} = e_{j_l},\forall l \in N \cap [1,k)\ )$
  + $不妨设w(e_{i_k}) \geq w(e_{j_k})$
  + $case\ 1:T_1中含有边e_{j_k}$
    + $则存在k'>k,使得e_{i_{k'}}=e_{j_k},$
    + $此时,w(e_{j_k})=w(e_{i_{k'}}) \geq w(e_{i_k}) \geq w(e_{j_k}) \Rightarrow w(e_{j_k}) = w(e_{i_{k'}}) = w(e_{i_k})$
    + $此时交换 T_1中e_{i_k} 与 e_{i_k'} 的位置, 重新开始判断(由于是有限图,一定能结束,落入case\ 2)$
  + $case\ 2:T_1中不含边e_{j_k}$
    + $为表示方便, 记e_{j_k} = e, E = \bigcup\limits_{l=1}^{k-1} \lbrace e_{i_l} \rbrace = \bigcup\limits_{l=1}^{k-1} \lbrace e_{j_l} \rbrace$
    + $对于T_1来说, e是一条弦,因此在e决定的基本回路C_e中, e的权值最大,即w(e) \geq w(e'),\forall\ e' \in E$
    + $C_e - e的边不可能都在E中$
      + $若C_e - e中的边都在E中 \Rightarrow C_e \subseteq T_2 \Rightarrow 矛盾$
    + $ \Rightarrow 存在m \geq k, 使得 e_{i_m} \in C_e - e \subset C_e$
    + $w(e_{i_m}) \geq w(e_{i_k}) \geq w(e) \geq w(e_{i_m}) \Rightarrow w(e_{i_m}) = w(e_{i_k}) = w(e)$
      + $case\ 2.1:k=n-1,证毕$
      + $case\ 2.2:k<n-1$
        + $对T_1做基本树变换 T_1' = T_1 \oplus \lbrace e_{i_m},e \rbrace,T_1'也是G的最小生成树,而且T'和T的边权列表集合相同$
        + $令T_1 = T_1', 重新开始判断(由于是有限图,一定能结束,落入case\ 2.1)$
  + $由于是有限图,一定能结束,证毕$

+ $3.3:$
  
+ $证明3.2的过程便是基本树变换的过程,而且过程中产生的树都是G的最小生成树$
  
+ $4.1:一个答案$
  + $a:\ s:01,\ t:10,\ a:11,\ e:001,\ c:000$
  + $b:\ s:001,\ t:10,\ a:01,\ e:0001,\ c:0000,\ 空格:11$

+ $4.2:$
  + $\Leftrightarrow 证明:存在一棵有序二元树,其各叶节点的深度为l_1,l_2,...,l_t的充要条件为:\sum\limits_{i=1}^t2^{-l_i} \leq 1$
  + $给所有树叶赋权 \frac{1}{2^h}(h为结点层数), 则树叶权值之和为\sum\limits_{i=1}^t2^{-l_i}$
  + $容易看出 : 两兄弟结点的权之和恰好等于其父亲结点为树叶时的权值$
  + $\Leftrightarrow 树叶权值之和 = \sum\limits_{i=1}^t2^{-l_i} \leq 当根结点为树叶时的权值 = 1$
  + $取等条件为 : 该有序二元树为正则二元树$

+ $4.3:$

  + $算法$

    + $step\ 0:$

      + $相当于一种数学归纳法$
      + $\tau存在的条件下(\tau不一定存在),\tau(p_i,p_j) \geq {\tau}'(p_i,p_j)$

    + $\star step\ 1:构造出n片树叶的根树T,将P中的点分别放在T的不同树叶上$

      + $1.\ 设\lbrace p_1,p_2 \rbrace = \mathop{\arg\min}\limits_{i \ne j}d(p_i,p_j),(不唯一时,任取一对)$

      + $2.\ 令 p_1,p_2的父亲为p_{n+1}$

        ​    $此时形成n-1规模的同类型问题$

        + $令d(p_{n+1},p_i) = d(p_i,p_{n+1})=min(d(p_i,p_1),d(p_i,p_2)),if\ 3 \leq i \leq n$
        + $d(p_{n+1},p_{n+1})=0$

      + $3.$

        + $if\ n =2$
          + $树:p_1\longleftarrow p_{n+1} \longrightarrow p_2,结束$
        + $else\ if\ n\geq 3$
          + $树:\bullet {{\longrightarrow \bullet \qquad\qquad\qquad} \atop {\longrightarrow ... \longrightarrow p_{n+1} \longrightarrow \lbrace {{\longrightarrow p_1} \atop {\longrightarrow p_2}}}}$

    + $step\ 2:确定根树T中各结点v的高度h_v(算法按照层数从小到大进行,同层结点任意顺序)$

      + $1.\ 若v是根节点$
        + $则h_v \leq \min\limits_{p_i,p_j为v不同子树(左/右)中的任意树叶} d(p_i,p_j)$
      + $2.\ 若v是T中层数为l(l \geq 1)的非叶子结点$
        + $则h_v需要满足:$
          + $a.\ h_v \leq \min\limits_{p_i,p_j为v不同子树(左/右)中的任意树叶} d(p_i,p_j)$
          + $b.\ h_v \leq h_u, u 为 v的父结点$
      + $3.\ 若v是叶子结点, h_v =0$

    + $step\ 3:确定分层距离\tau_h$

      + $step\ 4中都取最大值$

      + $在走完step\ 1的情况下,与d相容的分层距离\tau容易确定,$

        $只需在确定v的高度h_v时对应的不等式都取等号即可$

      + $这个根树最大的分层距离记作\tau'(一般情况下记作\tau_T)$

  + $step\ 1的正确性证明$

    + $\star\ 对任意根树T,存在正则二元树T', 使得\tau_T \leq \tau_{T'}$

      + $若是二元树,但不是正则树,将只有一个子结点的结点于其子结点收缩为一个点,分层距离不变$
+ $若有一个结点的儿子多于2个,则保留一个子结点,$
      + $将其余的子节点作为一个新增儿子的子结点(子树跟过去),此时分层距离变大(或相等)$
+ $举例:A{{{\longrightarrow a} \atop {\longrightarrow b}} \atop {{\longrightarrow c }\atop {\longrightarrow d}}} \Rightarrow A{{\longrightarrow a \quad\ } \atop {\longrightarrow b {{\longrightarrow c } \atop {\longrightarrow d}} }}$
        + $此时A的约束变少,h_A可能会变大,此时导致a,b,c,d的范围也可能变大$

    + $\star\ 假设p_1,p_2为n个点中距离最小的两个点,$
    
  $对任意正则二元树T,存在正则二元树T',使得T'中p_i,p_j是兄弟结点,且\tau_T \leq \tau_{T'}$
  
  + $最小二点x,y,x的兄弟为p_1,y的兄弟为p_2,x与y的最近公共祖先为u,$
    
    $设以v为根的子树中任意二点为t_1,t_2$
    
    + $T:\tau(t_1,t_2) \leq h_u \leq d(p_1,p_2)$
    
  + $x与p_2作交换得到T'$
    
    + $T':\tau(t_1,t_2) \leq h_u \geq d(p_1,p_2)$
        + $条件放宽了$

