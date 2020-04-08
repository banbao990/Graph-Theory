# 第5章 连通度·匹配·网络流

## 5.1 连通度(无向图)

### 5.1.1 割点,割边和块

+ 设 $v$ 是 $G$ 中的一个结点, 若 $\kappa(G-v) > \kappa(G)$, 则称 $v$ 是 $G$ 的一个**割点**
  + 若 $v$ 是连通图 $G$ 的一个割点, 那么 $G-v$ 是分离图
  + 树的所有分支结点都是割点, 所有树叶都不是割点
  + $G$ 是阶不小于 $3$ 的连通图, 若 $G$ 没有割点, $G$ 一定没有割边
    + $\Leftrightarrow$ $G$ 有割边, $G$ 则一定有割点
+ 设 $e$ 是 $G$ 中的一条边, 若 $\kappa(G-e) > \kappa(G)$, 则称 $e$ 是 $G$ 的一条**割边**
+ **块** : $G$ 的极大的没有割点的连通子图称为**块**
  + 若 $G$ 本身没有割点, 则图 $G$ 本身就是一个**块**
  + 边集的一个划分

---

+ $任何两个块至多有一个交点,且这个交点为割点$

+ $证明:反证法$

---

---

+ $若v是连通图G的一个结点,则以下论断等价$

  + $(1)\ v是G的一个割点$

  + $(2)\ 存在与v不同的两个结点u,w,使任意一条从u到w的道路P_{u,w}都经过v$

  + $(3)\ V-v可以划分为两个结点子集U,W,$

    ​      $使得对任意 u \in U.w \in W,结点v都在任意一条从u到v的道路P_{u,w}上$ 

+ $证明:$
  
  + $(1) \Rightarrow (2) \Rightarrow  (3) \Rightarrow  (1)$

---

+ **边的剖分运算**
  + 称边 $e$ 被**剖分**, 是指用一条长度为 $2$ 的道路代替边 $e$, 该道路的内部结点时新增的一个结点 $v_e$
+ $G$ 中某边被剖分之后的图记为 $G'$
  + $G'$ 是 $G$ 的同胚图
  + $G是块 \Leftrightarrow G'是块$
  + $e是G的割边 \Leftrightarrow v_e是G'的割点$

---

+ $设e是连通图G的一条边,则下列论断等价$

  + $(1)\ e是G的一条割边$

  + $(2)\ e不属于G的任何回路$

  + $(3)\ 存在两个结点u,w,使任意一条从u到w的道路P_{u,w}都经过v$

  + $(4)\ G-e的结点集可以划分为两个结点子集U,W,$

    ​      $使得对任意 u \in U.w \in W,G中任意一条从u到v的道路P_{u,w}都经过e$

+ $剖分$

---

---

+ $Whitney$
+ $设G为n(n \geq 3)阶无向连通图, G是块 \Leftrightarrow G的任意两个结点都在同一回路上$

+ $证明:$

  + $\Leftarrow:证明任意一点v不是割点$

    + $任取不同的三点u,v,w \in G$

    + $u,w同在G的一条回路C中$

    + $G中存在两条从u到w的不交的道路,而v只可能在其中一条道路上$

      $\Rightarrow G-v中存在从u到w的道路$

    + $u,w的任意性,v不是割点$

  + $\Rightarrow:数学归纳法,对d(u,v)进行归纳$

    + $设G是块,对任意两个不同的结点u,v,来证u,v同在某一回路上$
    + $d(u,v)=1$
      + $e=(u,v)不是割边,在G-e中存在从u到v的道路P_{u,v}$
      + $u,v在回路P_{u,v}+(v,u)上$
    + $d(u,v)=k$
      + $G中存在长度为k的从u到v的道路(短程线)P_{u,v}$
      + $设w是P_{u,v}上邻接v的结点,那么有d(u,w)=k-1$
      + $由归纳假设,u和w在某一回路C上$
      + $不妨设v \notin C,否则证毕$
      + $w不是割点,G-w连通,在G-w中存在从u到v的道路Q_{u,v}$
      + $设Q_{u,v}与C的最后一个公共结点为x$
      + $所求回路为 \tilde C = C - P_{w,x} + (w,v) + P_{x,v}$

---

---

+ $设G是阶不小于3的连通图,则下列论断等价$
  + $(1)\ G是一个块$
  + $(2)\ G的任意两个结点同属于某回路$
  + $(3)\ G的任何两条边同属于某回路$
  + $(4)\ G的任何一个接二点和任何一条边同属于某回路$
  + $(5)\  给定任意两结点u,v和任意一条边e,存在一条包含e的道路P_{u,v}$
  + $(6)\ 对G的任意三个不同的结点u,v,w,存在道路P_{u,v}经过w$ 
  + $(7)\  对G的任意三个不同的结点u,v,w,存在道路P_{u,v}经过w$
+ $证明:$
  + $之前定理+剖分运算:(1) \Leftrightarrow (2) \Leftrightarrow (3) \Leftrightarrow  (4)$
  + $(3) \Rightarrow (5):$
    + $结点u和边e通过属于某回路C,设w是G-u中e的某端点v_e到v的某道路与C的最后一个公共结点$
    + $所求道路为P_{u,v}=C-P_{u,w}+P_{w,v}$
  + $(5) \Rightarrow (6) \Rightarrow (7) \Rightarrow (1):显然$

---

+ $在图G的边集上定义一个关系 ``\sim":e_1 \sim e_2 \Leftrightarrow e_1与e_2同在某一回路上$
  + $``\sim"是E上的等价关系$
  + $``\sim"的等价类即是G的块$
  + $G可以表示为其所有块的并(边不交)$

### 5.1.2 连通度

+ **点断集**,**边断集** : 割点和割边的推广

+ 若连通图 $G$ 删去某些结点之后称为非连通图, 则这些结点组成的集合称为 $G$ 的一个**点断集**, 记为 $A$,

  并称 $\mu(G) = \min\limits_{A是点断集}|A|$ 为 $G$ 的**点连通度**, 简称 **$G$ 的连通度**

  + 规定 $\mu(K_n) = n-1$

    + $\mu(K_1) = 0$

  + $若G \ne K_n \Rightarrow \mu(G) < n-1$

    + $G \ne K_n \Rightarrow \exists u,v \in V(G), 使得u,v不相邻,$

      $删去剩下的n-2个点,G[\lbrace u,v \rbrace]不连通$

+ 若连通图 $G$ 删去某些边之后称为非连通图, 则这些边组成的集合称为 $G$ 的一个**边断集**,简称为**断集**,

   记为 $B$, 并称 $\lambda(G) = \min\limits_{B是断集}|B|$ 为 $G$ 的**边连通度**

+ $\lambda(G) = 1 \Leftrightarrow G有割边$ 
+ $\mu(G)=1 \Leftrightarrow G有割点$
+ **边连通度**, **点连通度**反映了连通图的连通程度
  
  + 完全图的连通程度最强, 树最弱

---

+ $Whitney$
+ $连通图G中,有 \mu(G) \leq \lambda(G) \leq \delta(G)$
+ $证明:$
  + $part\ 1:\lambda(G) \leq \delta(G)$
    + $找到G中具有最小度的结点v,与v关联的d(v)=\delta(G)条边构成一个断集$
    + $\lambda(G) \leq \delta(G)$
  + $part\ 2:\mu(G) \leq \lambda(G)$
    + $设B是G的一个最小断集(边数为\lambda(G)),B时由跨在某结点子集V_1与 \overline {V_1}之间的所有边组成$
    + $分如下两种情况情况取点断集$
      + $case\ 1:V_1(或\overline {V_1})中存在结点v_0与B中任何边都不关联(防止删成空集)$
        + $从V_1(或\overline {V_1})中删去所有与B中的边关联的结点,G将成为非连通图$
        + $删去的点数小于等于|B|$
      + $case\ 2:V_1,\overline {V_1}中的所有结点都与B中的边相关联$
        + $删去V_1中除了v_0外的所有结点,再删去V_2中与v_0关联的所有结点$
        + $此时G称为非连通图或者平凡图$
          + $平凡图时,G=K_n,\lambda(G)=\mu(G)=n-1$
        + $删去的点数小于等于|B|$
      + $\Rightarrow OK$
+ $一般来说删点的破坏力强于删边(K_n为例外)$
+ $等号可以取到$
  + $G=K_n:$
    + $\mu(G)=\lambda(G)=\delta(G)=n-1$
  + $G=T_n(n \geq 2):$
    + $\mu(G)=\lambda(G)=\delta(G)=1$
  + $G=Q_k(k-方体图):$
    + $\mu(G)=\lambda(G)=\delta(G)=k$

---

---

+ $任取 1 \leq n_1 < n_2 < n_3,可以构造图G,满足\mu(G)=n_1,\lambda(G)=n_2,\delta(G)=n_3$
+ $如下构造即可$
  + $A=K_{n_3+1},B=K_{n_3+1}$
  + $在A中找不同的n_1个点 \lbrace a_1,a_2,...,a_{n_1} \rbrace, 在B中找不同的n_1个点 \lbrace b_1,b_2,...,b_{n_1} \rbrace$
    + $a_i与b_i(1 \leq i \leq n_1)之间加一条边$
  + $在B中另找n_2-n_1个点 \lbrace b_{n_1+1},b_{n_1+2},...,b_{n_2} \rbrace$
    + $a_{n_1}与b_i(n_1 < i \leq n_2)之间加一条边$

---

+ $G$ 是连通图, $k$ 是正整数
  + 若 $\mu(G) \geq k$, 则称 $G$ 是 **$k$ 点连通图**(简称**$k$ 连通图**)
  + 若 $\lambda(G) \geq k$, 则称 $G$ 是 **$k$ 边连通图**
+ 非平凡树 $T_n(n \geq 2)$ 是 $1$ 连通图, 也是 $1$ 边连通图
+ 回路 $C_n(n \geq 3)$ 是 $1$ 连通图, 也是 $2$ 边连通图
+ 至少 $3$ 阶的块是 $2$ 连通图, 也是 $2$ 边连通图
  + 没有割点 $\Rightarrow \mu(G) \geq 2$

---

+ $简单连通图G中,有 \mu(G) \leq \lfloor \frac{2m}{n} \rfloor$

+ $证明:$
  + $握手定理:\sum\limits_{i=1}^nd(v_i)=2m$
  + $2m \geq n\delta(G)$
  + $\mu(G) \leq \delta(G) \leq \lfloor \frac{2m}{n} \rfloor$
+ $令f(k,n)表示n阶k连通图所需最少边数 \Rightarrow f(k,n) \geq \lceil \frac{kn}{2} \rceil$

---

---

+ $Harary\ 图,H_{n,k},1962$

  + $m=\lceil \frac{kn}{2} \rceil$
  + $\mu(G)=\lambda(G)=\delta(G)=k=\lfloor \frac{2m}{n} \rfloor$

+ $构造,H_{n,k}的结点记作0,1,2,...,n-1$

  + $case\ 1:k=2r$
    + $若i-j \leq r(mod\ n),则(i,j) \in E$
  + $case\ 2:k=2r+1,n=2l$
    + $若i-j \leq r(mod\ n) 或 i-j=l(mod\ n),则(i,j) \in E$
  + $case\ 3:k=2r+1,n=2l+1$
    + $若i-j \leq r(mod\ n) 或 0 \leq i \leq l,j=i+l+1,则(i,j) \in E$

+ $证明H_{n,k}是k连通的$

  + $\delta(H_{n,k})=k,只需证明\mu(H_{n,k}) \geq k即可,来证H_{n,k}的每个点断集至少有k个结点$

  + $反证法:$

    + $假定A是G的一个点断集,使得|A|<k,设i,j分别属于H_{n,k}-A的两个不同连通分支$

    + $记S=\lbrace i,i+1,...,j-1,j \rbrace, T = \lbrace j,j+1,...,i-1,i \rbrace(溢出取模)$

    + $按照不同的构造方法进行验证(构造在H_{n,k}-A中从i到j的道路)$

      + $case\ 1:k=2r$

        + $|A|<2r,i,j \notin A(由假设),因此必有|A \cap S|<r 或 |A \cap T|<r(抽屉原理)$

        + $不妨设|A \cap S|<r,此时S中不可能有连续的r个结点属于A$

        + $于是S-A中一定存在若干节点i_1,i_2,...,i_m使得$

          $i_1-i,i_2-i_1,...,i_m-i_{m-1},j-i_m \leq r(mod\ n)$

        + $即H_{n,k}中存在一条从i到j的道路i_1i_2...i_mj,矛盾$

      + $case\ 2:k=2r+1,n=2l$

        + $若|A|<2r,或者|A|=2r但是|A \cap S|<r或|A \cap T|<r时,由case\ 1可证$

        + $|A|=2r,且|A \cap S|=|A \cap T|=r$

        + $k \leq n-1 \Rightarrow r \leq l-1$
      
        + $因为i,j不可能是对角线的两端点(否则i-j=l(mod\ n)属于同一连通分支)$
      
          $所以S或T所含结点数不少于l+2(|S|+|T|=n+2=2l+2)$
      
        + $不妨设|S|\geq l+2,则以下论述在S-A中存在一条从i到j的道路$
      
          + $case\ a:S中没有连续r个结点属于A$
      
            + $论证同case\ 1$
      
          + $case\ b:S中有连续r个结点属于A$
      
            + $由于|A \cap S|=r,r \leq l-1 < l+2,利用对角线(i,i+l),存在从i到j的道路$
      
              $(利用对角线跳过之后剩下的全是S-A中的点,再利用序数相邻点相邻走到j)$
      
      + $case\ 3:k=2r+1,n=2l+1$
      
        + $若|A|<2r,OK$
        
        + $若|A|=2r,|A \cap S|<r或|A \cap T|<r,OK$
        
        + $若|A|=2r,|A \cap S|=|A \cap T|=r,此时类似的有i,j不满足j=i+l+1$
        
          $类似的可以证明在S-A中存在i到j的道路$

---

+ $Harary 图应用$
  + **可靠通讯网络的设计** 
    + 我们需要设计一个通讯网络, 使得当几个通讯站点被破坏时, 其余的通讯站点仍然可以互相连通
    + 两个要求 : 
      + $1.\ $毁坏后不影响连通的站点尽可能多
      + $2.\ $造价低
  + 抽象为数学问题
    + $G是加权连通图,k是给定的正整数,求G的有最小权的k连通子图$
      + $k=1, 最小生成树$
      + $k \geq 2,未解难题$
    + $G=K_n,每边权都为1时,Harary图就是解$

---

+ $设G是n阶简单图,k是一个正整数,假定G的结点度满足d(v_1) \leq d(v_2) \leq ... \leq d(v_n)$

  $且当1 \leq r \leq n-1-d(v_{n-k+1})时,有d(v_r) \geq r + k - 1,则G为k连通图$

+ $证明:反证法$

  + $思路:任取|A| \subseteq V,|A| < k,假设G-A不连通,推出矛盾$

  + $假设G不是k连通图,则存在G的一个点断集A,满足|A|=a<k$

  + $设G-A中含结点数(设为h)最少的一个连通分支为H,则\Delta(H) \leq h-1$

  + $所以H中每个结点在G中的结点度都不大于h-1+a$

  + $所以d(v_h) \leq \max\limits_{v \in H}d(v) \leq a+h-1 < h+k-1$

  + $不满足题中不等式,因此有h > n -1 - d(v_{n-k+1}) \Rightarrow d(v_{n-k+1}) > n-1-h$

  + $又因为G-A中任意结点最多与n-1-h个结点相邻(K_{n-h})$

    $\Rightarrow d(v_{n-a}) \leq n-1-h$

  + $d(v_{n-a}) < d(v_{n-k+1}) \Rightarrow n-a<n-k+1 \Rightarrow a>k-1,矛盾$

---

---

+ $设G是n阶简单图,若\delta(G) \geq \lfloor \frac{n}{2} \rfloor,则有\lambda(G) = \delta(G)$

+ $证明:反证法$

  + $首先G一定是连通图$

    + $若G不是连通图,则G的每个连通分支至少含有\lfloor \frac{n}{2} \rfloor + 1个结点$
    + $(\lfloor \frac{n}{2} \rfloor +1)\cdot \kappa(G) \geq (\lfloor \frac{n}{2} \rfloor +1) \cdot 2 > n,矛盾$

  + $假定\lambda(G) < \delta(G)$

    + $则存在G的一个断集B=E(V_1,\overline {V_1}),满足|B|=\lambda(G)$

    + $设G[V_1]的边数为m_1,则有|V_1| \cdot \delta(G) \leq \sum\limits_{v \in V}d_G(v) = 2m_1 + \lambda(G) < |V_1|(|V_1-1|)+\delta(G)$

      $\Rightarrow |V_1| > \delta(G)$

    + $同理有|\overline {V_1}| > \delta(G)$
    
    + $n=|V_1|+|\overline {V_1}| > 2\delta(G) >2\lfloor \frac{n}{2} \rfloor >n,矛盾$

---

---

+ $Menger\ 定理$
+ $设G是n阶连通图,k \leq n-1$
  + $G是k连通的 \Leftrightarrow G中任意两个结点间至少存在k条内部不交的道路$
  + $G是k边连通的 \Leftrightarrow G中任意两个结点间至少存在k条边不重的道路$

---

## 5.2 二部图的匹配

+ $约定讨论的图G为无向连通图$

### 5.2.1 匹配

+ 实际问题

  + 安排工作(二部图的匹配)
    + 结点 : 工人, 任务
    + 边 : 该工人能做该项任务
  + 安排住宿(每间房能住两个人)
    + 结点 : 客人
    + 边 : 边关联的两个结点对应的客人可同住

+ 设 $M$ 是图 $G$ 的边子集, 若 $M$ 中任意两边不相邻, 则称 $M$ 是 $G$ 的一个**匹配**

  + 与 $M$ 中的边关联的结点称为 $M$ 的**饱和点**, 其余的结点称为 $M$ 的**非饱和点**

+ 设 $M$ 是图 $G$ 的一个匹配, 如果对 $G$ 的任意匹配 $M'$, 都有 $|M| \geq |M'|$, 则称 $M$ 是 $G$ 的一个**最大匹配**

  + 特别的, 如果 $G$ 的每个结点都是 $M$ 的饱和点, 就称 $M$ 是 $G$ 的一个**完美匹配**
    + 此时, $|M|=\frac{|V|}2$, 图 $G$ 结点数为偶数

+ 给定 $G$ 的一个匹配 $M$, $G$ 中属于 $M$ 与不属于 $M$ 的边交替出现的道路称为关于 $M$ 的**交错道路**

+ 设 $P$ 是 $G$ 中关于匹配 $M$ 的一条交错道路, 如果 $P$ 的起点和终点都是关于 $M$ 的非饱和点,

  则称 $P$ 是关于 $M$ 的**可增广道路**

  + 可增广道路 $P$ 首尾两条边都是 $M$ 外的边, $P$ 中包含奇数条边, 且其中不在M比在M中的边多一条
  + 令 $M'=M \oplus P$, 对于 $M'$
    + $P$ 上的点都是饱和点
    + $M$ 的饱和点都是 $M'$ 的饱和点
    + $|M'|=|M|+1$, $M'$ 为比 $M$ 更大的匹配
    + $M'$ 称为 $M$ 的**增广匹配**

---

+ $Berge,1957$
+ $M是G的最大匹配 \Leftrightarrow G中不存在关于M的可增广道路$
+ $证明:$
  + $\Rightarrow:反证法$
    + $若存在可增广道路P,则存在增广匹配M', 使得|M'|=|M|+1 > |M|$
  + $\Leftarrow:极化方法$
    + $取G的一个最大匹配M',令G'=M' \oplus M$
    + $若G'是空图,M为G的最大匹配$
    + $若G'不是空图,则有\Delta(G) \leq 2(任何一个结点在一个匹配中最多出现一次)$
    + $以下证明:简单连通图G若有 \delta(G) \leq 2,则G是一个道路或回路$
      + $极化方法:取极大道路$
    + $G'的连通分支有如下两种情况$
      + $case\ 1:由M'中的边和M中的边交错构成的道路P$
        + $P含有偶数条边 \Rightarrow P上M'中的边和M中的边相等$
          + $否则P是M的可增广道路(与题设矛盾)或P是M'的可增广道路(与极大性矛盾)$
      + $case 2:由M'中的边和M中的边交错构成的回路C$
        + $C为偶回路 \Rightarrow P上M'中的边和M中的边相等$
    + $|M|=|M'|,M是一个最大匹配$

---

### 5.2.2 二部图的匹配

+ 二部图 $G=(X,Y,E)$ 的最大匹配 $M$ 包含的边数不会超过 $\min \lbrace |X|,|Y| \rbrace$
  + 当 $|M|= \min \lbrace |X|,|Y| \rbrace$ 时, 称 $M$ 为**完全匹配**
+ 设 $M$ 是二部图 $G=(X,Y,E)$ 的一个匹配, 若 $|M|=|X|$, 则称 $M$ 是 **$G$ 的从 $X$ 到 $Y$ 的完全匹配**
  + 若 $M$ 是 $G$ 的从 $X$ 到 $Y$ 的完全匹配, 则 $M$ 是 $G$ 的最大匹配( $X$ 中的点都是饱和点)
  + 若 $|X|=|Y|=|M|$, 则称 $M$ 是**完美匹配**

---

+ $Hall,1935$
+ $在二部图G=(X,Y,E)中,X到Y存在完全匹配 \Leftrightarrow 对于X的任意子集A,恒有|N(A)| \geq |A|$
+ $证明:$
  + $\Rightarrow:$
    + $X中的结点都是饱和点 \Rightarrow 因此N(A)中至少包括|A|个M的饱和点 \Rightarrow |N(A)| \geq |A|$
  + $\Leftarrow:反证法$
    + $若不存在从X到Y的完全匹配,取G的一个最大匹配M,$
    + $则存在u \in X是M的非饱和点$
    + $设Z是通过M的交错道路与u连通的结点的集合$
    + $u \in Z,且Z- \lbrace u \rbrace中的点都是饱和点$
      + $u是非饱和点,若另一端点也为非饱和点则形成可增广道路$
    + $记S=X \cap Z,T=Y \cap Z,有$
      + $T中所有的点都匹配到S中的点,T \subseteq N(S)$
      + $N(S) \subseteq T$
    + $\Rightarrow N(S)=T$
    + $S-\lbrace u \rbrace 中的结点与T中的结点一一配对(都为饱和点)$
    + $|N(S)|=|S|-1矛盾$

---

---

+ $推论1:$

  + $k为一正整数,若在二部图G=(X,Y,E)中满足:d(x) \leq k(\forall x \in X),d(y) \geq k(\forall y \in Y),$

    $则存在从X到Y的完全匹配.$

+ $证明:$
  + $对X的任意子集A,设A的结点总共与m条边关联,N(A)的结点总共与m'条边关联$
  + $则k|A| \leq \sum\limits_{x \in A}d(x)=m \leq m'=\sum\limits_{y \in N(A)}d(y) \leq k|N(A)|$
  + $|N(A)| \geq |A| \buildrel Hall \over\Rightarrow 存在从X到Y的完全匹配$

---

---

+ $推论2:$

  + $在二部图G=(X,Y,E)中,M是最大匹配 \Leftrightarrow $

    $对任意M的非饱和点u \in X,都存在X的子集S,使得u \in S,S- \lbrace u \rbrace中的点都是M的饱和点,且|N(S)|<|S|$

+ $证明:$
  + $\Rightarrow:Hall定理证明构造部分$
    + $|N(S)|=|S|-1<|S|$
  + $\Leftarrow:$
    + $若M不是最大匹配,设M'是M的一个增广匹配,设u \in X是M'的饱和点但不是M的饱和点$
    + $则对于所有的满足以下条件的X的子集S,都有|N(S)|\geq|S|$
      + $S:u \in S, S- \lbrace u \rbrace中的点都是M的饱和点$
      + $S中的点都是M'的饱和点$
    + $矛盾$

---

+ 设 $M$ 是二部图 $G=(X,Y,E)$ 的一个匹配, $u \in X$ 是 $M$ 的一个非饱和点

  若存在 $X$ 的一个子集 $S$, 使得 $u \in S$ ,$S - \lbrace u \rbrace$ 中的点都是 $M$ 的饱和点, 且 $|N(S)|<|S|$, 

  则称 $u$ 是 $M$ 的**不可饱和点**

---

+ $推论3:$

  + $设M是二部图G=(X,Y,E)的一个匹配,u是M的不可饱和点,M'是M的一个增广匹配,$

    $则u也是M'的不可饱和点$

+ $证明:$
  + $M的饱和点都是M'的饱和点$
  + $u是M的非饱和点 \Leftrightarrow 存在S \subseteq X,使得 u \in S,S-\lbrace u \rbrace中的点都是M的饱和点,且|N(S)|<|S|$
  + $在M'中, S 还是满足 S - \lbrace u \rbrace 中的点都是M'的饱和点$
  + $u是M'的非饱和点$

---

---

+ $Edmonds,1965$
+ $匈牙利算法:求二部图的最大匹配$
+ $算法思路$
  + $先找一个初始匹配M$
  + $对于M的每一个非饱和点x$
    + $试图找到x的一个可增广道路P$
      + $若找到,则增广之,M=M \oplus P$
      + $找不到,x为不可饱和点$
  + $若M的所有非饱和点都是不可饱和点,算法结束$
+ $Algorithm$
  + $1.\ 初始匹配M,饱和点标记1,非饱和点标记0$
  + $2.\ 判断M中是否所有点都有非0标记$
    + $2.1\ 是,M即为最大匹配,算法结束$
    + $2.2\ 否,取一个0标记结点x \in X,令U= \lbrace x \rbrace, V = \emptyset, (|U|=|V|+1,V \subseteq N(U))$
  + $3.\ 判断是否有 V=N(U)$
    + $3.1\ 是,x为不可饱和点,x标记2,转2$
    + $3.2\ 否,在N(U)-V中找一点y_i,判断y_i是否标1$
      + $3.2.1\ 是,则有边(y_i,x_i) \in M,令 U = U \cup \lbrace x_i \rbrace,V = V \cup \lbrace y_i \rbrace, 转3$
      + $3.2.2\ 否,存在从x到y_i的可增广道路P,令M = M \oplus P,给x,y_i标记1,转2$
+ $算法正确性:推论2,3$

---

---

+ $二部图G=(X,Y,E)的最大匹配的边数是|X|-\varepsilon(G),$

  $其中\varepsilon(G)=\max\limits_{A \subseteq X}\varepsilon(A),\ \varepsilon(A)=\max \lbrace |A|-|N(A)|,0 \rbrace$

- $证明:$

  - $part\ 1:首先说明G的最大匹配的边数不超过|X|-\varepsilon(G)$

    - $不妨设\varepsilon(G)>0$

      - $\varepsilon(G)=0时,对于任意A \subseteq X,|N(A)| \geq |A|\buildrel Hall \over\Leftrightarrow 存在X到Y的完全匹配$

    - $取A \subseteq X,使得\varepsilon(A)=\varepsilon(G)$

      - $\varepsilon(A)=|A|-|N(A)|$

    - $对于G的任意匹配M,A中至多有|N(A)|个饱和点,$

      $于是|M|\leq |X-A|+|N(A)|=|X|-|A|+|N(A)|=|X|-\varepsilon(A)=|X|-\varepsilon(G)$

      - $|M| = (X-A中匹配上的边数)+(A中匹配上的边数)$
      - $(X-A中匹配上的边数)\leq |X-A|$
      - $(A中匹配上的边数) \leq |N(A)|$

  - $part\ 2:以下构造一个边数为|X|-\varepsilon(G)的匹配(数学归纳法)$

    - $\star\ 断言:$
    
      - $若 A \subseteq X, \varepsilon(A)=\varepsilon(G),$
    
        $则(X-A)\cup(Y-N(A))的导出子图G'=(X-A,Y-N(A),E'),满足\varepsilon(G')=0$
    
        - $\varepsilon(G')=0$
    
          $即在G'中,对于任意B \subseteq X-A,|N(B)|\geq|B|\buildrel Hall \over\Leftrightarrow G'存在从X'到Y'的完全匹配M'$
    
        - $|M'|=|X|-|A|$
    
      - $否则,则存在B \subseteq X-A,满足 |N(B)\cap(Y-N(A))|<|B|$
    
      - $于是,|A \cup B|-|N(A \cup B)|=|A|+|B|-|N(A)|-|N(B)\cap(Y-N(A))|$
    
        ​          $>|A|-|N(A)|=\varepsilon(A)=\varepsilon(G)$
    
      - $即|A \cup B|-|N(A \cup B)|>\varepsilon(G),矛盾$
    
    - $对\varepsilon(G)进行归纳$
    
      - $\varepsilon(G)=0\buildrel Hall \over \Rightarrow存在完全匹配,存在匹配M,满足|M|=|X|-\varepsilon(G)$
    
      - $\varepsilon(G)=k \geq 1$
    
        - $取A为满足\varepsilon(A)=\varepsilon(G)的极小点集,$
    
        - $于是,对任意x_0 \in A,\varepsilon(A-\lbrace x_0 \rbrace)=\varepsilon(G)-1$
    
          + $此时,N(A)=N(A-\lbrace x_0 \rbrace)$
    
        - $考虑(A-\lbrace x_0 \rbrace)\cup N(A)的导出子图G''$
    
          + $则\varepsilon(G'')=\varepsilon(G)-1$
    
          + $由归纳假设,存在G''的的匹配M_1,$
    
            $使得|M_1|=|A-\lbrace x_0 \rbrace|-\varepsilon(G'')=|A|-1-(\varepsilon(G)-1)=|A|-\varepsilon(G)$
    
        - $再取(X-A)\cup(Y-N(A))的导出子图G'=(X-A,Y-N(A),E')的完全匹配M_2(上证)$
    
        - $M=M_1 \cup M_2 是G的匹配,$
    
          $满足|M|=|M_1|+|M_2|=A-\varepsilon(G)+|X-A|=|X|-\varepsilon(G)$

---

## 5.3 网络流(netflow)

### 5.3.1 实际背景

+ 各种运输系统中运输量的规划问题

### 5.3.2 一些定义(网络,可行流,饱和边,最大流,割切)

+ 一个**网络** $N(V,E,C)$ 是一个赋权有向简单弱连通图, 满足
  + $1.$ $V$ 中恰有一个**负度**为 $0$ 的结点 $s$, 称为**发点**(**源**)
  + $2.$ $V$ 中恰有一个**正度**为 $0$ 的结点 $t$, 称为**收点**(**汇**)
  + $3.$ 每条边 $(v_i,v_j)$ 的边权 $c_{i,j}$ 是一个非负实数(通常是整数), 称为该边的**容量**
    + $C=(c_{i,j})_{(v_i,v_j)\in E}$ 称为网络的**容量函数**

+ $V$ 中除 $s,t$ 之外的其他结点称为网络 $N$ 的**中间结点**

+ 网络 $N$ 可以看作 : 

  + 表示某种产品从产地 $s$ 分批通过一些中间站点到达销地 $t$, $V$ 中的结点表示各个站点, 

    有向边 $(v_i,v_j)$ 表示从 $v_i$ 到 $v_j$ 的运输线路, 边上的容量表示运输线路的最大货物运输量(固定时间内)

+ 多个产地运往多个销地的运输问题也可以转化为网络问题

  + 增加一个**虚拟源点** $s_0$, 在 $s_0$ 和产地之间连一条边, 边的容量记为 $+\infty/$对应产地的产量$/$实际问题设定值
  + 增加一个**虚拟汇点** $t_0$, 在销地和 $t_0$ 之间连一条边, 边的容量记为 $+\infty$
  + 转化为从 $s_0$ 运往 $t_0$ 的网络问题

+ **可行流**/**容许流**
  + 如果在网络 $N(V,E,C)$ 的边集 $E$ 上定义的非负实值函数 $f=(f_{i,j})_{(v_i,v_j)\in E}$ 满足下列条件, 

    则称 $f$ 为网络 $N$ 的一个**可行流**/**容许流**, 称$w(f)=\sum\limits_{(s,v_j)\in E}f_{s,j}$ 为 **$f$ 的流量**, 所有的 $f_{i,j}$ 称为 **$f$ 的分布**.

    + $1.$ **容量限制条件** : 对任意 $(v_i,v_j)\in E$, 恒有 $f_{i,j} \leq c_{i,j}$
    + $2.$ **平衡条件** : 对于每个中间结点 $v_k$ ,恒有 $\sum\limits_{(v_k,v_j)\in E}f_{k,j}=\sum\limits_{(v_j,v_k)\in E}f_{j,k}$ $(进=出)$

+ **饱和边**/**非饱和边**

  + 在给定容许流 $f$ 的网络中, 满足 $f_{i,j}=c_{i,j}$ 的边称为**饱和边**, 其余的边称为**非饱和边**

+ **最大流**

  + 设 $F$ 是网络 $N(V,E,C)$ 的所有容许流组成的集合,

    称 $f_0 = \mathop{\arg\max}\limits_{f\in F} w(f)$ 为网络 $N(V,E,C)$ 的**最大流**
    
  + $有界闭集上的连续函数一定有最大值$

+ **割切**

  + 设 $S$ 是 $N(V,E,C)$ 的一个结点子集, 如果满足 $s\in S$, $t\in \overline S$, 

    则 $S$ 到 $\overline S$ 的所有有向边 $(v_i,v_j)(v_i\in S,v_j\in\overline S)$组成的集合 称为 $N(V,E,C)$ 的一个**割切**, 记为$(S,\overline S)$.

    $(S,\overline S)$ 中所有边的容量之和 $C(S,\overline S)=\sum\limits_{(v_i,v_j)\in(S,\overline S)}c_{i,j}$ 称为**割切的容量**

  + 取最小容量值的割切为**最小割切**

---

+ $设f是网络N(V,E,C)的任意容许流,(S,\overline S)是N的任一割切,则有w(f)=\sum\limits_{(v_k,v_i)\in(S,\overline S)}f_{k,i}-\sum\limits_{(v_j,v_k)\in(\overline S,S)}f_{j,k}$
+ $证明:$
  + $为讨论方便,不妨认为网络的任意两个结点间都有方向相反的两条边,规定不存在的边容量和流量都是0$
  
  + $对于源点s,有w(f)=\sum\limits_{v_i\in V}f_{s,i}-\sum\limits_{v_j\in V}f_{j,s}\qquad(\ast)$
  
  + $对于任意中间结点v,有\sum\limits_{v_i\in V}f_{k,i}-\sum\limits_{v_j\in V}f_{j,k}=0\qquad(\ast\ast)$
  
  + $(\ast)式与所有v_k\in S-\lbrace s \rbrace(\ast\ast)式求和$
  
    + $w(f)=\sum\limits_{v_i\in V,v_k\in S}f_{k,i}-\sum\limits_{v_j\in V,v_k\in S}f_{j,k}$
  
      $=(\sum\limits_{v_i\in S,v_k\in S}f_{k,i}+\sum\limits_{v_i\in\overline S\,v_k\in S}f_{k,i})-(\sum\limits_{v_j\in S,v_k\in S}f_{j,k}+\sum\limits_{v_j\in\overline S,v_k\in S}f_{j,k})$
  
      $=\sum\limits_{v_i\in\overline S\,v_k\in S}f_{k,i}-\sum\limits_{v_j\in\overline S,v_k\in S}f_{j,k}$
  
      $=\sum\limits_{(v_k,v_i)\in(S,\overline S)}f_{k,i}-\sum\limits_{(v_j,v_k)\in(\overline S,S)}f_{j,k}$
  
+ $特别的,\overline S=\lbrace t \rbrace时,w(f)=\sum\limits_{v_i\in V}f_{i,t}-\sum\limits_{v_j\in V}f_{t,j}$

---

---

+ $设f是网络N(V,E,C)的任意容许流,(S,\overline S)是任一割切,则有w(f)\leq C(S\overline S)$
+ $证明:$
  + $w(f)=\sum\limits_{(v_k,v_i)\in(S,\overline S)}f_{k,i}-\sum\limits_{(v_j,v_k)\in(\overline S,S)}f_{j,k}\leq \sum\limits_{(v_k,v_i)\in(S,\overline S)}f_{k,i}=C(S,\overline S)$

---

+ **增流路径**

  + 设 $f$ 是网络 $N(V,E,C)$ 的任一容许流, 称道路(无向道路) $v_{i_0}v_{i_1}...v_{i_k}$ 是 $f$ 的**增流路径**, 如果
    + $1.\ v_{i_0}=s,v_{i_k}=t$
    + $2.$ 当 $(v_{i_t},v_{i_{t+1}})\in E$ 时, $f_{i_t,i_{t+1}}<c_{i_t,i_{t+1}}$
      + 称 $(v_{i_t},v_{i_{t+1}})$为**向前边**, 向前边未饱和
    + $3.$ 当 $(v_{i_{t+1}},v_{i_{t}})\in E$ 时, $f_{i_{t+1},i_t}>0$
      + 称 $(v_{i_t},v_{i_{t+1}})$为**向后边**, 向后边不为 $0$ 

+ 对于 $f$ 的增流路径 $v_{i_0}v_{i_1}...v_{i_k}$, 令

  + $\delta_1=\min\limits_{(v_{i_t},v_{i_{t+1}})是向前边}(c_{i_t,i_{t+1}}-f_{i_t,i_{t+1}})$
  + $\delta_2=\min\limits_{(v_{i_t},v_{i_{t+1}})是向后边}f_{i_{t+1},i_t}$
  + $\delta=\min(\delta_1,\delta_2)$

  对 $f$ 做如下修改, 

  + $(v_{i_t},v_{i_{t+1}})$ 是向前边 : $f_{v_{i_t},v_{i_{t+1}}}=f_{v_{i_t},v_{i_{t+1}}}+\delta$
  + $(v_{i_t},v_{i_{t+1}})$ 是向后边 : $f_{v_{i_{t+1}},v_{i_t}}=f_{v_{i_{t+1}},v_{i_t}}-\delta$

  此时, $f$ 仍是容许流, 且流量增加了 $\delta$

---

+ $最大流与最小割切定理,Fold-Fulkerson,1956$
+ $若f是网络N(V,E,C)的最大流,则f的流量等于N的最小割切的容量$
+ $证明:$
  + $设f是N的最大流,构造N的一个割切如下(按照下列规则构造结点子集S):$
    + $(1)\ s\in S$
    + $(2)\ 若v_i\in S,(v_i,v_j)\in E，f_{i,j}<c_{i,j},则v_j\in S$
    + $(3)\ 若v_i\in S,(v_j,v_i)\in E，f_{i,j}>0,则v_j\in S$
  + $此时有t\notin S$
    + $若t\in S,则存在一条增流路径,与f是最大流矛盾$
  + $于是(S,\overline S)是割切$
  + $此时$
    + $若(v_i,v_j)\in(S,\overline S),f_{i,j}=c_{i,j}$
    + $若(v_i,v_j)\in(\overline S,S),f_{i,j}=0$
  + $w(f)=\sum\limits_{(v_k,v_i)\in(S,\overline S)}f_{k,i}-\sum\limits_{(v_j,v_k)\in(\overline S,S)}f_{j,k}=C(S,\overline S)$
  + $由任意流量\leq任意割切\Rightarrow C(S,\overline S)是最小割切$

---

---

+ $推论:容许流f是最大流 \Leftrightarrow不存在关于f的增流路径$
+ $\Rightarrow:反证法显然$
+ $\Leftarrow:同以上证明,构造出来一个割切(不存在增流路径\Rightarrow t \in\overline S)等于f的流量$

---

### 5.3.2 Edmonds-Karp Algorithm

#### 5.3.2.1 算法

---

+ $Edmond-Karp\ Algorithm$

+ $算法思路$
  + $从一个初始流开始$
  + $每次试图找一条最短的(边数最少)增流路径$
    + $若找到,则增流$
    + $若找不到,则f是最大流,算法结束$

+ $Algorithm$
  + $1.\ 初始化$
    
    + $任选一个初始流f(可以取零流,即f_{i,j}=0(\forall (v_i,v_j)\in E))$
    
  + $2.\ 标号过程(找最短的增流路径,到t为止)(BFS)$
    + $2.0.\ 给s标号(-,\Delta_s)(其中\Delta_s=\infty),s入队列Q$
    
    + $2.1.(标号至t为止)$
    
      + $2.1.1.\ 如果(v_i,v_j)\in E且f_{i,j}<c_{i,j},则给v_j标号(+v_i,\delta_j),$
    
        ​          $其中\delta_j=\min(\delta_i,c_{i,j}-f_{i,j}),v_j入队列Q$
    
      + $2.1.2.\ 如果(v_j,v_i)\in E且f_{i,j}>0,则给v_j标号(-v_i,\delta_j),$
    
        ​	      $其中\delta_j=\min(\delta_i,f_{j,i}),v_j入队列Q$
    
    + $2.2.\ 若t被标号,转3,否则转2.0$
    
  + $3.\ 增流过程(从t开始沿着记录的增流路径向前更新直至s)$
  
    + $3.1.\ 令v=t$
    + $3.2.\ 设v的标号为(Sv,\Delta_v)$
      + $3.2.1.\ 若Sv=+u,则令f_{u,v}=f_{u,v}+\Delta_t$
      + $3.2.2.\ 若Sv=-u,则令f_{v,u}=f_{v,u}-\Delta_t$
    + $若u=s,删去所有标号,转2(重新标号找增流路径);否则,令v=u,转3.1$
  
+ $每次找的必须是最短的增流路径,否则算法可能不会中止$

  + $一个例子:$
    + $G=(V,E,C)$
      + $V=\lbrace s,1,2,3,4,t \rbrace$
      + $E=\lbrace (s,1),(s,2),(s,4),(2,1),(2,3),(4,3),(1,t),(3,t),(4,t) \rbrace$
      + $c_{s,1}=c_{s,4}=c_{1,t}=c_{4,t}=M,c_{4,3}=r=\frac{\sqrt{5}-1}{2},c_{s,2}=c_{3,t}=c_{2,1}=c_{2,3}=1$
    + $最大流:2M+1$
    + $每次找的如果不是最短的增流路径,如下,算法暴毙$
      + $初始流:零流,记P_a=s4321,P_b=s234t,P_c=s123t$
      + $P_1=s23t,\delta=1$
      + $P_2=P_a,\delta=r$
      + $P_3=P_b,\delta=r$
      + $P_4=P_a,\delta=r^2$
      + $P_5=P_c,\delta=r^2$
      + $P_6=P_a,\delta=r^3$
      + $P_7=P_b,\delta=r^3$
      + $P_8=P_a,\delta=r^4$
      + $P_9=P_c,\delta=r^4$
      + $...(P_aP_bP_aP_c)$
      + $\sum\delta=1+2\sum\limits_{i=1}^{+\infty}r^i\buildrel 0<r<1\over=\frac{1+r}{1-r}$

+ $时间复杂度:O(m^2n),下证$

### 5.3.2.2 时间复杂度证明

#### 5.3.2.2.1 概念引入

---

+ **非饱和路径**
+ $容许流为f时,从节点u到v的一条非饱和路径是指:其中向前边都满足f(e)<c(e),向后边都满足f(e)>0$
  + $向前边都不饱和,向后边流量都大于0$
+ **瓶颈**
+ $设f是网络N的一个容许流分布,P=u_0e_1u_1e_2u_2...u_{k-1}e_ku_k是f的一条增流路径$
  + $令\delta_i=\lbrace {{c(e_i)-f(e_i),e_i是向前边}\atop {f(e_i),\qquad e_i是向后边}},\ \delta=\min\limits_{1\leq i\leq k}\delta_i$
+ $则必存在i,使得\delta_i=\delta,称对应的e_i为该路径的瓶颈$
+ $设增流路径P的瓶颈是e,增流后,若e是向前边,e将饱和;若e是向后边,f(e)将变为0$
+ $假定标号法从初始流分布f_0开始,按照Edmonds-Karp算法依次构造容许流f_1,f_2,...$

#### 5.3.2.2.2 引理1

---

+ $引理1:$

+ $若k_1<k_2,e是从f_{k_1}变为f_{k_1+1}以及f_{k_2}变为f_{k_2+1}时的向前(后)边瓶颈,$

  $则存在l,满足k_1<l<k_2,使得e是从f_l变为f_{l+1}的增流路径的向后(前)边$

+ $证明:$
  
  + $成为增流路径的向前边时必须满足f_{i,j}<c_{i,j};成为增流路径的向后边时必须满足f_{i,j}>0$

---

#### 5.3.2.2.3 引理2

---

+ $引理2:$
+ $对与每个节点v记容许流f_k,恒有\lambda^k(s,v)\leq\lambda^{k+1}(s,v),\lambda^k(v,t)\leq\lambda^{k+1}(v,t)$
  + $\lambda^i(u,v)是指:容许流为f_i时,从u到v的最短非饱和路径的长度$
    + $若不存在u到v的非饱和路径,约定\lambda^i(u,v)=+\infty$
+ $证明:对称性只需证明一半$
  + $case\ 1:若容许流f_{k+1}不存在从s到v的饱和路径,\lambda^{k+1}(s,v)=+\infty\Rightarrow OK$
  + $case\ 2:\lambda^{k+1}(s,v)\ne\infty$
    + $假定P=P=u_0e_1u_1e_2u_2...u_{p-1}e_pu_p是从s到v的一条最短的非饱和路径,u_0=s,u_p=s$
    + $只需要证明对任意1\leq i\leq p,\lambda^k(s,u_i)\leq\lambda^k(s,u_{i-1})+1即可$
      + $\lambda^k(s,v)=\lambda^k(s,u_p)\leq \lambda^k(s,u_{p-1})+1\leq...\leq \lambda^k(s,u_0) +p=p=\lambda^{k+1}(s,v)$
    + $下证$
      + $case\ 1: 若e_i是P的一条向前边,f_{k+1}(e_i)<c(e_i)$
        + $case\ 1.1:f_{k}(e_i)<c(e_i)$
          + $\Rightarrow\lambda^k(s,u_i)\leq\lambda^k(s,u_{i-1})+1$
            + $s到u_{i-1}的最短路径经过u_{i}\Rightarrow OK(f(e_i)\ne0时可能)$
            + $s到u_{i-1}的最短路径不经过u_{i}\Rightarrow OK$
        + $case\ 1.2:f_{k}(e_i)=c(e_i)$
          + $此时e_i在f_k变为f_{k+1}时充当了增流路径上的向后边$
          + $\Rightarrow\lambda^k(s,u_{i-1})=\lambda^k(s,u_{i})+1$
          + $\Rightarrow\lambda^k(s,u_i)\leq\lambda^k(s,u_{i-1})+1$
      + $case\ 2:\ 若e_i是P的一条向后边,f_{k+1}(e_i)>0(证明类似)$
        + $case\ 2.1:f_{k}(e_i)>0$
          + $\Rightarrow\lambda^k(s,u_i)\leq\lambda^k(s,u_{i-1})+1$
            + $s到u_{i-1}的最短路径经过u_{i}\Rightarrow OK(f(e_i)\ne c(e_i)时可能)$
            + $s到u_{i-1}的最短路径不经过u_{i}\Rightarrow OK$
        + $case\ 2.2:f_k(e_i)=0$
          + $此时e_i在f_k变为f_{k+1}时充当了增流路径上的向前边$
          + $\Rightarrow\lambda^k(s,u_{i-1})=\lambda^k(s,u_{i})+1$
          + $\Rightarrow\lambda^k(s,u_i)\leq\lambda^k(s,u_{i-1})+1$

---

#### 5.3.2.2.4 引理3

---

+ $引理3:$

+ $如果边e是从f_k变为f_{k+1}时增流路径的向前(后)边,同时也是从f_l变为f_{l+1}时增流路径的向后(前)边$

  $则有\lambda^l(s,t)\geq\lambda^k(s,t)+2$

+ $证明:$
  + $假定e=(u,v)$
  + $由于e是f_k的增流路径向前边,所以\lambda^k(s,v)=\lambda^k(s,u)+1$
  + $由于e是f_k的增流路径向后边,所以\lambda^l(s,t)=\lambda^l(s,v)+1+\lambda^l(u,t)$
  + $引理2\Rightarrow\lambda^l(s,t)\geq\lambda^k(s,v)+1+\lambda^k(u,t)=\lambda^k(s,u)+2+\lambda^k(u,t)=\lambda^k(s,t)+2$

---

#### 5.3.2.2.5 定理

---

+ $定理:Edmonds-Karp\ Algorithm中至多处理\frac{m(n+2)}2条增流路径后便会中止$
+ $证明:引理1,3$
  + $Edmonds-Karp算法中,每条增流路径都是当前最短的从s到t的非饱和路径$
  + $对于任意边e,设以e为增流路径向前边瓶颈的容许流为f_{k_1},f_{k_2},...,其中k_1<k_2<...$
  + $由引理1,存在另一个容许流序列f_{l_1}, f_{l_2},...,使得k_1<l_1<k_2<l_2<...$
  + $由引理3,\lambda^{l_i}(s,t)\geq\lambda^{k_i}(s,t)+2,\lambda^{k_{i+1}}(s,t)\geq\lambda^{l_i}(s,t)+2$
  + $因此,\lambda^{k_{i+1}}(s,t)\geq\lambda^{k_i}(s,t)+4\Rightarrow \lambda^{k_j}(s,t)\geq\lambda^{k_1}(s,t)+4(j-1)$
  + $而\lambda^{k_j}(s,t)\leq n-1,\lambda^{k_1}(s,t) \geq 1$
  + $n-1 \geq 1+4(j-1)$
  + $j\leq \frac{n+2}{4}\Rightarrow 以e为瓶颈的增流路径最多有\frac{n+2}{4}条$
  + $增流路径最多有\frac{n+2}{4} \times m=\frac{m(n+2)}{4}条$
+ $定理同时说明任何网络都具有最大流$

---

## 5.4 作业

+ $1.1:设G是含n(n \geq 3)个结点的简单图,且\delta(G) \geq n-2,证明:\mu(G)=\delta(G)$
+ $1.2:证明:若v是简单图G的割点,则v一定不是补图\overline G的割点$
+ $1.3:设G是n阶无向简单图,k \leq n-1,若\delta(G)\geq \frac12(n-k+1),证明:G是k连通图$
+ $1.4:在图G的边集上定义一个关系 ``\sim":e_1 \sim e_2 \Leftrightarrow e_1与e_2同在某一回路上,证明:$
  + $(1)\ ``\sim"是E上的等价关系$
  + $(2)\ ``\sim"的等价类即是G的块$

+ $1.5:设连通图G存在割点,证明:G中任意两个快至多有一个公共结点,而且公共结点必为割点$
+ $1.6:$
  + $设连通图存在割点,如下定义G的块割图H:$
    + $G的每个割点和每个块分别对应H的一个结点,$
    + $若G的某割点在某块中,则两者对应的结点连成H的一条边$
  + $证明:H是一棵非平凡树,企业子结点比对应于G的块(这样的块称为叶子块)$
+ $1.7:$
  + $(1)\ 设树T含k条边,无向简单图G满足\delta(G)\geq k.$
    + $证明:T是G的子图(T与G的某子图同构)$
  + $(2)\ 设树T含k条边,n阶(n>k)无向简单图G的边数m满足:m>n(k-1)-\frac12k(k-1).$
    + $证明:T是G的子图$

+ $2.1:设二部图G=(X,Y,E)存在从X到Y的完全匹配,试证明:$

  + $(1)\ S,T \subseteq X,|N(S)|=|S|,|N(T)|=|T| \Rightarrow |N(S \cap T)|=|S \cap T|$

  + $(2)\ 存在x \in X,使得与x关联的任何边都在其另一最大匹配中$

    ​      $(任意与x关联的边e一定属于E=\bigcup\limits_{M是G的一个匹配}\lbrace e:e \in M \rbrace)$

+ $2.2:在8\times 8的国际象棋棋盘的一条主对角线上移去两端的小方格后,所得棋盘能否
  用1\times 2的长方形恰好填满?$
  
+ $2.3:$
  
  + $一次舞会,共有n个小伙子和n个姑娘参加,$
    
    $已知每个小伙子至少认识两个姑娘,而每个姑娘至多认识两个小伙子,$
    
    $问能否将他们分成n对舞伴,使得每对中的姑娘与小伙子相互认识$

+ $2.4:有5个字符串bc,ed,ac,bd,abe,能否用其中的一个字母代表该字符串并且不产生混淆?$

  ​         $如果可以，试给出一种方案$

+ $2.5:$

  + $由0,1元素组成的矩阵每行都恰有k个1元素,每列1元素的数目都不超过k个.$

    $能否使A=P_1+P_2+...+P_k成立,其中P_i(1\leq i\leq k)也是由0,1元素组成的矩阵,$

    $且每行都恰有1个1元素,每列最多有1个1元素?$



## 5.5 参考答案

+ $1.1:分类+反证法$

  + $\delta(G)=n-1时$

    + $G=K_n,\mu(G)=\delta(G)=n-1$

  + $\delta(G)=n-2时$

    + $假设\mu(G)=a<n-2$

    + $n-a>2 \Rightarrow n-a \geq 3$

    + $取G一个点断集A,|A|=a,G-A将G划分为若干个连通分支,结点子集记作V_1,V_2,...,V_m$

    + $此时,V(G)-V(A)至少还有3个点$

    + $case\ a:|V_i|=1(\forall i \in [1,m])$

      + $此时m \geq 3,V_1中的结点v_1与V_2,V_3中的结点在G中都不相邻$

        $\Rightarrow d_G(v_1) < n-2,与\delta(G)=n-2矛盾$

    + $case\ b:\exists i,|V_i| \geq 2$

      + $不妨设|V_1| \geq 2,m\geq 2,任取一点v_2 \in V_2$
      + $则v_2和|V_1|中所有结点在G中不相邻 \Rightarrow d_G(v_2) < n-2,与\delta(G)=n-2矛盾$

+ $1.2:$

  + $先考虑G是连通图,G的结点集设为V$
    + $设v_0是G的割点,则G'=G- \lbrace v_0 \rbrace的结点子集自然划分为V_1,V_2,...,V_m(m \geq 2)$
    + $令V_a=V_1,V_b=\bigcup\limits_{i=2}^mV_i$
    + $case\ 1:v_0与V_a,V_b中所有结点都相互关联$
      + $v_0在\overline G为孤立点,v_0不是\overline G的割点$
    + $case\ 2:V_a,V_b中都存在点与v_0不相关联$
      + $在V_a中取与v_0不相关联的点v_a,在V_b中取与v_0不相关联的点v_b$
      + $此时(v_a,v_0),(v_0,v_b)(v_b,v_a)都不属于G \Rightarrow 回路v_0v_av_bv_0 \in \overline G \Rightarrow v_0不是\overline G 的割点$
    + $case\ 3:仅存在V_a中的点或V_b中的点与v_0不相关联$
      + $不妨设V_a中存在与v_0不相关联的点,V_b中不存在与v_0不相关联的点$
      + $case\ 3.1:V_a中仅有一个点与v_0不相关联$
        + $v_0在\overline G为悬挂点,v_0不是\overline G的割点$
      + $case\ 3.2:V_a中至少有两个点与v_0不相关联$
        + $取其中两个点v_1,v_2,在V_b中取一个点v_b$
        + $此时(v_0,v_1)(v_0,v_2)(v_1,v_b)(v_2,v_b)都不属于G \Rightarrow 回路 v_0v_1v_bv_2v_0 \in  \overline G$
        + $v_0 不是 \overline G的割点$
  + $若G不是连通图,在G的一个连通分支G_0中考虑即可$

+ $1.3:\Leftrightarrow \mu(G) \geq k$

  + $首先证明 \delta(G) \geq \frac{n}2时,G一定为连通图$
    + $若G不连通,则G的每个连通分支中至少含有 \lfloor \frac{n}2 \rfloor+1个结点$
    + $\kappa(G) \cdot (\lfloor \frac{n}2 \rfloor+1) \geq 2 \cdot (\lfloor \frac{n}2 \rfloor+1) > n,矛盾$
  + $即证在G中任意删去(k-1)个结点后得到的G'仍连通$
    + $\delta(G') \geq \delta(G)-(k-1) \geq \frac12(n-k+1)=\frac12n' \Rightarrow G'仍连通$

+ $1.4:$

  + $(1)\ ``\sim"是E上的等价关系$
    + $自反性,对称性:显然$
    + $传递性:$
      + $设e_1 \sim e_2,e_2 \sim e_3$
      + $不妨设e_1,e_2,e_3两两不等(否则显然成立)$
      + $e_1与e_2同在回路C_1上,e_2和e_3同在回路C_2上$
        + $C_1=C_2 \Rightarrow e_1 \sim e_3$
        + $C_1 \ne C_2$
          + $设P是同时在C_1,C_2上,且包含e_2的最长道路$
          
          + $C_1上从e_1=(v_s,v_t)的顶点v_s出发走遍C_1,$
          
          $与C_2的第一个公共结点设为a,最后一个公共结点设为b$
          
          + $由结点a,b,C_1被划分为C_{11},C_{12},e_1 \in C_{11}$
          
          + $由结点a,b,C_2被分为C_{a,b},C_{b,a},则要么e_3 \in C_{a,b}或e_3 \in C_{b,a}$
          
          + $不妨设e_3 \in C_{a,b}$
          
          + $令C=C_{11} \cup C_{a,b},e_1,e_3同在回路C上 \Rightarrow e_1 \sim e_3$
  + $(2)\ ``\sim"的等价类即是G的块$
    
    + $x \sim y \Leftrightarrow x,y同属于G的某一回路 \Leftrightarrow x,y在同一个块上$
  
+ $1.5:G有割点 \Leftrightarrow G不是块$
  + $part\ 1:G中任意两个不同的块至多只有1个公共结点$
    + $反证法:$
    + $设G_1,G_2是G的两个块,G_1与G_2有两个以上的公共结点,取其中两个不同结点v_1,v_2$
    + $G_1是块 \Rightarrow G_1中存在一条从v_1到v_2的道路P_1$
    + $G_2是块 \Rightarrow G_2中存在一条从v_1到v_2的道路P_2$
    + $以下证明G'=G_1 \cup G_2中任意两边同属于某一回路$
    + $以下讨论基于G'$
      + $在G'中任取两条边e_1,e_2$
      + $case\ 1:e_1,e_2同属于E(G_1)或E(G_2)$
        + $显然,e_1与e_2同在某一回路上(G_1,G_2是块)$
      + $case\ 2:e_1,e_2不同属于E(G_1)或E(G_2)$
        + $不妨设 e_1 \in E(G_1),e_2 \in E(G_2)$
        + $在P_1上取边e_1',P_2上取边e_2',e_1'与e_2'同属于回路C=P_1 \cup P_2$
        + $以下利用1.4的语言$
        + $e_1 \sim e_1',e_2 \sim e_2',e_1' \sim e_2' \Rightarrow e_1 \sim e_2(传递性)$
      + $G'_1 \cup G_2'是包含G_1且比G_1结点数更多的不含割点的连通子图,G[V(G')]不含割点$
      + $与G_1是块矛盾$
  + $part\ 2:G的不同块的公共结点必是割点$
    + $设G_1,G_2是G的两个块,v_0是G_1,G_2的唯一公共结点$
    + $设v_1 \in V(G_1)- \lbrace v_0 \rbrace, v_2 \in V(G_2) - \lbrace v_0 \rbrace,断言(v_1,v_2) \notin G$
      + $若(v_1,v_2) \in E,G_1中存在从v_0到v_1的道路P_1,G_2中存在从v_0到v_2的道路P_2$
      + $以下证明G'=G_1 \cup G_2中任意两边同属于某一回路$
      + $以下讨论基于G'$
        + $在G'中任取两条边e_1,e_2$
        + $case\ 1:e_1,e_2同属于E(G_1)或E(G_2)$
          + $显然,e_1与e_2同在某一回路上(G_1,G_2是块)$
        + $case\ 2:e_1,e_2不同属于E(G_1)或E(G_2)$
          + $不妨设 e_1 \in E(G_1),e_2 \in E(G_2)$
          + $在P_1上取边e_1',P_2上取边e_2',e_1'与e_2'同属于回路C=P_1 \cup P_2 \cup (v_1,v_2)$
          + $以下利用1.4的语言$
          + $e_1 \sim e_1',e_2 \sim e_2',e_1' \sim e_2' \Rightarrow e_1 \sim e_2(传递性)$
          + $G'是包含G_1且比G_1结点数更多的不含割点的连通子图,G[V(G')]不含割点$
          + $与G_1是块矛盾$
    + $在G_1-\lbrace v_0 \rbrace中任取一点v_1,G_2-\lbrace v_0 \rbrace中任取一点v_2,断言不存在从v_1到v_2的道路不经过v_0$
      + $若存在这样的一条道路P,那么这条道路跨越不同块一定是通过割点实现的(以上证明)$
      + $将道路P中涉及的其他块(有边在P上)记为G_{a_1},G_{a_2},...,G_{a_m},令G'=\bigcup\limits_{i=1}^mG_{a_i}$
      + $将P第一次出G_1的点前一个记作a(a \in G_1),将P第一次进G_2的点记作b(b \in G_2)$
      + $在道路P上截取道路P_{a,b},显然有P_{a,b} \cap G_1 = \lbrace a \rbrace,P_{a,b} \cap G_2 = \lbrace b \rbrace$
      + $在G_1中存在从a到v_0的道路P_1,在G_2中存在从b到v_0的道路P_2$
      + $存在一个回路C=P_1 \cup P_2 \cup P_{a,b}包含G_{a_i}(1 \leq i \leq m)的边$ 
      + $类似的可以证明G'是包含G_1且比G_1结点数更多的不含割点的连通子图,G[V(G')]不含割点$
      + $与G_1是块矛盾$
    + $v_0是割点$

+ $1.6:H连通且不含回路$
  + $G连通 \Rightarrow H连通$
  + $若含回路一定是割点形成的点和块形成的点交替出现,由1.5的证明过程不存在回路$

+ $1.7:$
  + $(1):数学归纳法,对k实施归纳$
    + $k=1,T_2=K_2=G显然$
    + $k>1$
      + $T含有k条边,由树最少有两片树叶,取树叶v_0,设T_1=T-\lbrace v_0 \rbrace$
      + $\delta(G)\geq k\geq k-1,由归纳假设,T_1是G的子图$
      + $设v_0在T_1与v_1相邻,d_G(v_1)\geq k,因此与v_1关联的至少有一条不在T_1中,设为m$
      + $T_1+m与T同构,是G的子图$
  + $(2):极化方法+(1)$	
    + $设G_1是G的满足以下条件的绩效导出子图$
      + $a.\ n_1>k$
      + $b.\ m_1>n_1(k-1)-\frac12k(k-1)$
    + $断言\delta(G_1)\geq k$
      + $否则存在一个结点v_0,\delta_{G_1}(v_0)<k$
      + $设G_2=G_1-\lbrace v_0\rbrace,则对于G_2$
        + $m_2\geq m_1-(k-1)>(n_1-1)(k-1)-\frac12k(k-1)$
        + $n_2=n_1-1>k$
          + $以下证明n_2>k$
            + $n_2=n_1-1\geq k,只需说明n_2\ne k即可$
            + $若n_2=k,则有m_2>k(k-1)-\frac12k(k-1)=\frac12k(k-1)$
            + $与G为简单图矛盾$
            + $n_2>k$
      + $与G_1极小性矛盾$
    + $由(1)T是G的子图$



+ $2.1:$

  + $(1):Hall$

    + $\buildrel Hall \over\Rightarrow |N(S\cap T)| \geq |S \cap T|$

    + $|N(S\cap T)|\leq|N(S)\cap N(T)|$

      ​                     $=|N(S)|+|N(T)|-|N(S)\cup N(T)|$

      ​                     $=|S|+|T|-|N(S\cup T)|$

      ​                    $\buildrel Hall\over\leq|S|+|T|-|S\cup T|$

      ​                     $=|S\cap T|$

    + $|N(S\cap T)|=|S\cap T|$

  + $(2):$

    + $记\ \mathcal{A}=\lbrace E:E\subseteq X,E\ne\emptyset \rbrace(X的任意非空子集)$

    + $\buildrel Hall \over\Rightarrow |N(A)|\geq|A|,\forall A \in \mathcal{A}$

      + $case\ 1:|N(A)|>|A|,\forall A\in\mathcal{A}$

        + $对于任意x\in X及x的任意邻点y\in Y,记X'=X-\lbrace x\rbrace,Y'=Y-\lbrace y\rbrace,$

          $二部图G'=(X',Y',E')满足Hall条件,即对任意X'的非空子集A',|N_{G'}(A')|\geq|A'|$

          + $|N_G(A'\cup\lbrace x\rbrace)|>|A'\cup\lbrace x\rbrace|=|A'|+1$
          + $由假设,|N_G(A')|>|A'|\Rightarrow|N_G(A')|\geq|A'|+1$
          + $|N_{G'}(A')|\geq|N_{G}(A')|-1$
            + $|N_{G'}(A')|=N_G(A')-\lbrace y\rbrace$
          + $|N_{G'}(A')|\geq|N_{G}(A')|-1\geq|A'|$

        + $即G'存在从X'到Y'的完全匹配M',则M=M'\cup(x,y)是G的从X到Y的完全匹配$

      + $case\ 2:\exists A\in\mathcal{A},\owns|N(A)|=|A|$

        + $不妨设A为满足题设的X的极小非空子集,|N(A)|=|A|$

        + $\Rightarrow G中任意从X到Y的完全匹配M恰好将A中的结点与N(A)中的结点一一匹配$

        + $\Rightarrow M将X-A中的结点匹配给了Y-N(A)中的结点$

        + $即G_1=(A,N(A),E_1)中存在从X_1到Y_1的完全匹配(完美匹配),$

             $G_2=(X-A,Y-N(A),E_2)中存在从X_2到Y_2的完全匹配$

        + $只需证明:存在x\in A,使得与x关联的任何边都在G_1(A,N(A),E_1)的某一最大匹配中$

        + $事实上,对于任意x\in X及x的任意邻点y\in Y,$

          $二部图G_3=(A-\lbrace x\rbrace,N(A)-\lbrace y\rbrace,E_3)满足Hall条件,$

          $即对任意X_3的非空子集A_3,|N_{G_3}(A_3)|\geq|A_3|$

          + $X_3的任意子集A_3,有|N_G(A_3)|>|A_3|$
            + $取等与极小性矛盾$
            + $满足Hall条件的证明同case\ 1$

        + $即G_3存在从X_3到Y_3的完全匹配M_3$

        + $M_1=M_3 \cup(x,y)是G_2的完全匹配$

        + $证毕$

+ $2.2:不能$

  + $8\times 8的国际象棋棋盘的一条主对角线(黑)上移去两端的小方格后得到的图为二部图G=(X,Y,E)$
  + $黑色方块对应结点形成X,白色方块对应结点形成Y,若方块相邻则对应节点之间有一条边,边集形成E$
  + $题目转化判断G的是否存在完美匹配$
    + $|X|=30,|Y|=32,不可能有完美匹配,最大匹配只能与60个结点相关$
  + $不能$
  
+ $2.3:可以$

  + $二部图G=(X,Y,E),X:男生,Y:女生,若男女二人认识,则对应结点之间有一条边$
  + $d(x)\geq 2,\forall x\in X,d(y)\leq 2,\forall y\in Y$
  + $Hall定理推论1,存在从X到Y的完全匹配$
  + $|X|=|Y|,存在完美匹配$

+ $2.4:找一个下图的完全匹配$

  + $G = (X, Y, E)$
    + $X : A(bc), B(ed), C(ac), D(bd), E(abe)$
    + $Y : a, b, c, d, e$
    + $E = \lbrace(A,b),(A,c),(B,e),(B,d),(C,a),(C,c),(D,b),(D,d),(E,a),(E,b),(E,e)\rbrace$
  + $一个完全匹配:A-b,B-e,C-c,D-d,E-a$

+ $2.5:可以$
  
  + $0,1矩阵的每行作为一个元素形成X,每列作为一个元素形成Y$
  + $若A(i,j)=1,则在第i行和第j列之间连一条边,得到二部图G(X,Y,E),|X|=|Y|$
  + $此时,问题归结为:矩阵A对应的二部图G_k(X,Y,E)的边集能否分解为互相边不交的k个从X到Y的匹配$
  + $G_k满足d(x)=k(\forall x\in X),d(y)\leq k(\forall y\in Y)$
  + $数学归纳法$
    + $k=1,OK$
    + $k\geq 2$
      + $设Y'是Y中满足d(y)=k的结点y组成的结点集$
      + $则二部图G(X,Y',E')满足:d(x) \leq k(\forall x\in X),d(y')=k(\forall y'\in Y')$
      + $Hall定理推论1\Rightarrow G_k存在从Y'到X的完全匹配M'$
      + $将M'增广为G_k(X,Y,E)的最大匹配M$
      + $此时由Hall定理推论1\Rightarrow M是从X到Y的完全匹配(完美匹配)$
      + $G_{k-1}=(X,Y,E-M)满足:d(x)=k-1(\forall x\in X),d(y)\leq k-1(\forall y\in Y)$
      + $由归纳假设,证毕$


