# 第一章 图的基本概念

## 1.1 图的概念

### 1.1.1 基本概念

+ **图** : **二元关系**的模型
+ 例子 :

  + **循环赛问题**(球队, 是否比赛, 有向边表示胜方)
  + **交通问题**(城市, 道路, 无向边表示双向道路/有向边表示单行道)
+ **图** : 由 **结点** 和 **边** 组成的对象, 表示某种 **二元关系**
+ **有序对**$(a,b)$, **无序对**$\lbrace a,b \rbrace$
+ **有序积** $A \times B$ , **无序积** $A$ & $B$ 
+ **有向图** $D(V, E)$ ,**无向图** $G(V, E)$
  +  $G$ 也指一般图
  + 边集$E$, 结点集$V$
  + $|E|=m,E=\lbrace e_1,e_2,...,e_m \rbrace$
  + $|V|=n,V=\lbrace v_1,v_2,...,v_n \rbrace$
+ **重边/平行边**
+ **自环**
+ **有限图**$($$V,E$都有限$)$, **无限图**
+ 图 $G$ 的**阶**
+ **零图** : $E(G)=\phi$
  +  $n$ 阶零图记作 $N_n$
  + $N_1$ 又称**平凡图**
+ **空图**  $\phi$
  + $V(G)=\phi$
+ **基图**: 有向图把边的方向去掉
+ 对于一条边 $e_k(v_i, v_j)$
  + $v_i$ 与 $v_i$ 相邻
  + $e_k$ 分别与 $v_i$ , $v_j$ 相关联
  + 若 $e_k$ 是有向边
    + $v_i$ 是 $v_j$ 的**直接前驱**/**内邻点**
    + $v_j$ 是 $v_i$ 的**直接后继**/**外邻点**
    + $v_i$ 是 $e_k$ **起点**(**head**)
    + $v_j$ 是 $e_k$ **终点**(**tail**)
+ **多重图** : 含有重边的图
+ **简单图** : 不含重边和自环
+ **竞赛图** : 无向完全图的每条边任给一个方向的到的有向图

### 1.1.2 结点度

+ **度数**(**degree**)
  + $d_G(v)$
  + 有向图
    + 出度/正度
      + $d_G^+(v)$
    + 入度/负度
      + $d_G^-(v)$
    + $d_G(v)=d_G^+(v)+d_G^-(v)$
  + 自环对于结点度的贡献为**2**
  + **孤立点** : $d_G(v)=0$
  + **悬挂点** : $d_G(v)=1$
  + $k-$**正则图** : $d_G(v)=k,\forall v \in V(G)$
+ **奇结点**/**偶结点**
+ $K_n$ :  $n$ 阶无向**完全图**
  + $(n-1)$阶正则图
  + $m=\frac{n(n-1)}2$ 

---

+ $二阶以上无向简单图G中一定存在结点度相同的两个结点$
+ $(证明:连通图, 抽屉原理)$

---

---

+ $Euler,1936$
+ $握手定理/图论基本定理$
+ $设图G有n个结点, m条边, 则 \sum_{i=1}^n{d(v_i)=2m}$

---

---

+ $有向图握手定理$
+ $d_G^+(v)=d_G^-(v)=m$

---

### 1.1.3 关联

+ $\forall v \in V(G)$,  $v$ 的邻点集称作点 $v$ 的**邻域**, 记作 $N_G(v)$ 
+ 闭邻域 $\overline{N_G(v)} = N_G(v) \cup \lbrace v \rbrace$
+ $\forall S \subseteq V(G)$, $S$ 的邻域 $N_G(S) = \cup_{v \in V(G)} N_G(v)$
+ $\forall v \in V(G)$,  $v$ 的**关联集**, $I_G(v)=\lbrace e \in E(G):e与v相关联 \rbrace$
+ 有向图
  + $\forall v \in V(G)$, 称 $v$ 的直接后继集为 $v$ 的**外邻域**, 记作 $N_G^+(v)$
  + **内邻域**, $N_G^-(v)$
  + $N_G(v)=N_G^+(v) \cup N_G^-(v)$
+ **最大度** $\Delta (G)=max \lbrace d(v):v \in V(G) \rbrace$
+ **最小度** $\delta (G)=min \lbrace d(v):v \in V(G) \rbrace$
+ 有向图 $D$
  + **最大出度**, **最大入度**, **最小出度**, **最小入度**

---

$任何6人当中,要么有三人互相认识,要么有三人互相不认识$

$G为6阶无向简单图, 则要么K_3\subseteq G, 要么K_3 \subseteq \overline G$

---

---
$Ramsey \quad number$
$R(p,q):最小的n,满足任意n阶无向简单图G,要么K_p \subseteq G,要么 K_q \subseteq \overline G$
+ $R(p,2)=p$
+ $R(p,q)=R(q,p)$
+ $R(p,q) \leq R(p,q-1) + R(p-1,q)$

---

### 1.1.4 子图

+ $G(V,E),G'(V',E')$ 满足 $V' \subseteq V, E' \subseteq E$, 则称 $G'$ 是 $G$ 的一个**子图**, 记作 $G' \subseteq G$
  + **真子图** : $V' \subset V, E' \subset E$, 记作 $G' \subset G$
  + **支撑子图**/**生成子图** : $V'=V$
  + **导出子图** : $E'$ 包含了 $G$ 在结点子集 $V'$ 中的所有边, 记作 $G'=G \lbrack V' \rbrack$
+ 图的**同构**,  $G_1 = (V_1, E_1), G_2 = (V_2, E_2)$
  + 存在从 $V_1$ 到 $V_2$ 的双射 $f$, 使得对任意的 $u,v \in V_1$, 有 $(u,v) \in E_1 \Leftrightarrow (f(u),f(v)) \in E_2$ 
  + 记作 $G_1 \cong G_2$
+ 若 $G_1 \cong G_2$  
  + $|V(G_1)|=|V(G_2)|,|E(G_1)|=|E(G_2)|$
  + $G_1,G_2$ 的结点度的集合(多重集合)相同
  + $G_1,G_2$ 的导出子图一一同构

+ **补图** : $\overline G,V(\overline G) = V(G), E(\overline G)=E(K_n)-E(G)$
+ **自补图** : $G \cong \overline G$

### 1.1.5 图的运算

#### 1.1.5.1 删除运算

+ 无向图 $G=(V,E)$, $E' \subseteq E$, $V' \subseteq V$
    + **删除**$E'$, $G-E'=(V,E-E')$ 
    + **删除**$V'$, $G-V'=G[V-V']$
    + $G-e=G- \lbrace e \rbrace$
    + $G-v=G - \lbrace v \rbrace$

#### 1.1.5.2 加新边

+ $e(u,v) \notin E$
  + $G+(u,v)=(V,E \cup \lbrace (u,v) \rbrace)$

#### 1.1.5.3 收缩

+ 在 $G=(V,E)$ 中收缩 $V'$, $V' \subseteq V$
+ 记作 $G'(V',E')=G \circ V'$
  + 将$V'$中的点收缩成一个 **伪点** $v'$
  + $E$自然分为$3$个部分
    + $E_1=\lbrace e=(v1,v2)|(e \in E) \land (v_1 \in V') \land (v_2 \in V') \rbrace$
      + $E_1' = \cup_{e \in E_1}(v',v')$ 
      + (多个)自环
    + $E_2= \lbrace e=(v_1,v_2)|(e \in E) \land (v_1 \notin V') \land (v_2 \notin V') \rbrace$
      + $E_2'=\cup_{e \in E_2}(v_1,v_2)$
      + 保留
    + $else$
      + $E_3'= (\cup_{(e \in E_3) \land (v_1 \in V')}(v',v_2))\cup(\cup_{(e \in E_3) \land (v_2 \in V')}(v_1,v'))$
      + 收缩
  + $E'=E_1 \cup E_2 \cup E_3$
+ $G_1 \subseteq G$, 在 $G=(V,E)$ 中收缩 $G_1$ $\Leftrightarrow$ 在 $G=(V,E)$ 中收缩 $V(G_1)$
+ $e(v_1,v_2) \in E$, 在 $G=(V,E)$ 中收缩 $e(v_1,v_2)$ $\Leftrightarrow$  在 $G=(V,E)$ 中收缩 $\lbrace v_1,v_2 \rbrace$
  + 也记作 $G \circ (v_1,v_2)$

#### 1.1.5.4 并图/交图/差图/环和

+ $G_1=(V_1,E_1),G_2=(V_2,E_2)$
  + $G_1$ 与 $G_2$ **不交**  $\Leftrightarrow$ $V_1 \cap V_2 = \phi$
  + $G_1$ 与 $G_2$ **边不交**/**边不重**  $\Leftrightarrow$ $E_1 \cap E_2 = \phi$
+ $G_1=(V_1,E_1),G_2=(V_2,E_2)$, $G_1,G_2$ 均无孤立点
  + **边集诱导形成结点集**, 即以下新图的结点集 $V$  为 $E$ 中的边关联的结点
  + **并图** : $G_1 \cup G_2 = (V,E)$, 其中$E=E_1 \cup E_2$
  + **交图** : $G_1 \cap G_2 = (V,E)$, 其中$E=E_1 \cap E_2$
  + **差图** : $G_1 - G_2 = (V,E)$, 其中$E=E_1 - E_2$
  + **环和** : $G_1 \oplus G_2 = (V,E)$, 其中$E=E_1 \oplus E_2$
+ 一些计算, **本质上就是边集的计算**
  + $G_1 \oplus G_2 = (G_1 \cup G_2) - (G_1 \cap G_2)$
  + $G - G = G \oplus G = \phi$

#### 1.1.5.5 联图

+ $G_1, G_2$ 为两个不交的无向图

+ **联图** $ G=G_1 + G_2 =(V,E) $
  + $V = V_1 \cup V_2 $
  + $E=E_1 \cup E_2 \cup \lbrace (v_1,v_2):v_1 \in V_1,v_2 \in V_2 \rbrace $
  + 结点数 : $n=n_1+n_2$
  + 边数 : $m=m_1+m_2+n_1n_2$
+ $K_{n_1} + K_{n_2} = K_{n_1+n_2}$

#### 1.1.5.6 积图

+ $G_1, G_2$ 为两个无向图
+ **积图** $G=G_1 \times G_2=(V,E)$
  + $V=V_1 \times V_2$
  + $E = \lbrace ((u_1,u_2),(v_1,v_2)):((u_1=v_1) \land ((u_2,v_2) \in E_2) ) \lor ( (u_2=v_2)\land((u_1,v_1) \in E_1)) \rbrace $
  + 结点数 : $n = n_1n_2$
  + 边数 : $m=n_1m_2+n_2m_1$
+ **$k-$方体图** $Q_k$
  + 用 $\lbrace 0,1 \rbrace$表示 $K_2$ 的两个结点
  + $Q_1=K_2$
  + $Q_k=Q_{k-1} \times K_2(k \ge 2)$
  + $|V(Q_k)|= 2^k$
  + $|E(Q_k)|=k2^{k-1}$ 
    + $ m_k = 2^{k-1} \times 1+ 2 \times m_{k-1}$ 

#### 1.1.5.7 赋权图

+ $G=(V,E)$, $f$ 是 $E$ 上的实函数,  $g$ 是 $V$ 上的实函数
+ **赋权图**(一般指**边**赋权)
  + $G_1=(V,E,f)$
  + $G_2=(V,E,g)$
  + $G_3=(V,E,f,g)$
+ **正权图** : 边权都为正数

## 1.2 图的代数表示

### 1.2.1 邻接矩阵

+ $A=(a_{i,j})_{n \times n}$

$$
a_{i,j}=
\begin{equation}
\left\lbrace
\begin{array}{l}
1, \quad if(v_i,v_j) \in E\\
0, \quad else\\
\end{array}
\right.
\end{equation}
$$



## 1.3 作业

$1.证明对于任意一个9阶无向简单图,要么K_4 \subseteq G,要么K_3 \subseteq \overline G$

$2.对于任意竞赛图都有 \sum_{i=1}^n(d^+(v_i))^2=\sum_{i=1}^n(d^-(v_i))^2$

$3.若G \cong \overline G,则必有n=4k或n=4k+1$