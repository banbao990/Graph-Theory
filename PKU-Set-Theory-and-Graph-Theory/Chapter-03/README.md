# 第三章 树

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

+ $G$ 的所有环图组成一个数域 $\lbrace 0,1 \rbrace$ 上的线性空间 $V$

  + 线性空间 $V$ 的加法

    + $G_1+G_2=G_1 \oplus G_2 = G[E(G_1) \oplus E(G_2)]$

      + 以下证明 : $G_1,G_2是G的不同环图(E(G_1) \ne E(G_2)) \Rightarrow G' = G_1\oplus G_2还是环图$

        + $E(G') \subseteq E(G)$

        + $对任意v \in d_{G'}(v) = d_{G_1 \oplus G_2)}(v) = d_{G_1}(v) + d_{G_2}(v) - 2d_{G_1 \cap G_2}(v) $

          $\Rightarrow d_{G'}(v) 为偶数$

    + $1.$ 交换律  $\surd$ 

    + $2.$ 

    + $3.$

    + $4.$

    + $5.$

    + $6.$

    + $7.$

## 3.3 最小生成树

## 3.4 有向树

## 3.5 最优树

## 3.6 作业

+ $1.1:非平凡树(|V(T)| \geq 2)中道路最长的端点一定是树叶$
+ $1.2:G为n(n \geq 5)阶无向简单图 \Rightarrow G或\overline G必含回路$
+ $1.3:设d_1,...,d_n为n(n \geq 2)个正整数, 证明:$
  + $若 \sum\limits_{i=1}^nd_i = 2(n-1), 则一定存在一棵结点度分别为d_1,...,d_n的树$
+ $1.4:

## 3.7 参考答案

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

+ $1.4: