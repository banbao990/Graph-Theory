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

## 5.3 网络流(netflow)

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

