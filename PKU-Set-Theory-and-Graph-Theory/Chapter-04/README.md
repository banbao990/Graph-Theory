# 第四章 平面图与图的着色

[TOC]



<div style="page-break-after: always;"></div>  

## 4.1 平面图

+ 实际应用
  + 单面印刷电路板的设计
  + 大规模集成电路的布线
  + 交通, 通讯, 城市建筑等
+ **可平面图**与**平面图**
  + 若能把图 $G$ 画在一个平面上, 使得任何两条边都不相交, 则称 $G$ **可嵌入平面**, 称 $G$ 为**可平面图**
  + **可平面图**在平面上的的一个**嵌入**(**画法**)称为**平面图**
+ 举例 
  + $K_4$ 是**可平面图**, $(b)(c)$为 $K_4$ 的两个平面嵌入, $(b)(c)$为**平面图** 

```C
只有o是结点,其他的都是边
                                                                           
                                                                           
                       +----------------+                                  
                       |                |                    o             
     o-------o         o-------o        |                   /|\            
     |\     /|         |      /|        |                  / | \           
     | \   / |         |     / |        |                 /  o  \          
     |  \ /  |         |    /  |        |                /  / \  \         
     |   X   |         |   /   |        |               / /     \ \        
     |  / \  |         |  /    |        |              //         \\       
     | /   \ |         | /     |        |             o-------------o      
     |/     \|         |/      |        |                                  
     o-------o         o-------o        |                                  
                       |                |                                  
                       +----------------+                                  
                                                                           
        K4                    (b)                            (c)           
```

+ 设 $G$ 是一个平面图, 由它的若干条边所围成的区域内若不含其他任何边, 就称该区域为 $G$ 的一个**面**/**域**,

  称满足以上条件的边数最少的**闭路径**为该域的**边界**

+ 在平面上, 我们平面图 $G$ 外面的无限区域称为**无限域**, 其他区域称为**内部域**

+ 如果两个域的边界交集不为空, 则称他们是**相邻**的, 否则则是**不相邻**的

+ **开集** : **开集**中的任何两点都可以用一条折线连起来,使得这条折线与平面图的任意结点/边都不交

+ 举例 : 

  + 图 $G$ 域 $x$ 的边界为 $a-b-d-e-a-f-a$
  + 图 $G$ 无限域的边界为 $a-b-c-b-d-e-a$

```C
                                    a---------b------c      
                                    |\        |             
                                    | \   x   |             
                                    |  f      |             
                                    |         |             
                                    e---------d             
                                                            
                                        g                   
```

---

+ $割边一定是一个域的边界, 非割边是一定是某两个域的的公共边界$

---

---

+ $Jordan\ 曲线定理$
+ $一个平面上的一条封闭的连续曲线C将平面分成两个区域,两区域中各取一点, 连接两点的任何曲线一定与C相交$

---

---

+ $K_{3,3},K_5是典型的不可平面图,本质上仅有这两种图不可平面$

---

---

+ $G是可平面的 \Leftrightarrow G是可球面的$

+ $G的平面图的无限域对应G球面图的一个有限域$

+ $旋转使北极点处于某一面内, 从这一点向球面各边界上的点作直线, 交于南极点的切面,$

  $切面上形成的图案将切面划分为不同的面, 切面上的面与球面上的面构成双射$

---

+ **轮胎面**与**球面**拓扑性质不同

---

+ $平面图基本定理:欧拉定理$

+ $若G是平面连通图,则G域的数目d=m-n+2$

  + $生成树加弦$
    + $d=1+(m-(n-1))=m-n+2$

+ $推论1:若\kappa(G)=k,则d=m-n+k+1$

  + $无限域重合$
  + $d = \sum\limits_{i=1}^kd_i -k+1 = \sum\limits_{i=1}^k((m_i-n_i+2)) - k+1= m-n+2k-k+=m-n+k+1$ 

+ $推论2:对于任意平面图G,n-m+d \geq 2$

  + $k=n-m+d-1 \geq 1$

+ $推论3:图G是阶不小于3的简单平面图 \Rightarrow m \leq 3n-6$

  + $case\ 1:G含回路$

    + $无自环重边 \Rightarrow G的回路边数大于等于 3\Rightarrow 平面图G的任何域的边界数大于等于3$

      $\Rightarrow \frac{3d}2 \leq m$

    + $d=m-n+k+1 \geq m-n+2$

    + $\frac23m \geq d \geq m-n+2 \Rightarrow m \leq 3n-6$

  + $case\ 2:G不含回路$ 

    + $m \leq n-1 \leq 3n-6$

  + $证毕$

---

+ $平面连通图G没有割边,且每个域的边界数都是t \Rightarrow m=\frac{t(n-2)}{t-2}$
  + $m=\frac{dt}2$
  + $d=m-n+k+1=m-n+2$
+ $若G是平面简单图, 则 \delta(G) \leq 5$
  + $若 \delta(G) \geq 6,由握手定理m \geq \frac{6n}2 = 3n > 3n - 6,矛盾$ 
+ $若平面图G的每个域的边界上的边数目都大于等于4,则 \leq 2n - 4$
  + $\frac{4d}2 \leq m, d \geq m -n + 2$
  + $\Rightarrow m \leq 2n - 4$
+ $两个典型的非平面图:K_{3,3}(边数最少的非平面图),K_5(结点数最少的非平面图)$
  + $K_{3,3}$
    + $m=9,n=6,K_{3,3}所有域的边界数大于等于4$
    + $若K_{3,3}为平面图,应该满足m \leq 2n - 4,而实际上不满足,矛盾$
  + $K_5$
    + $m=10,n=5$
    + $m > 3n - 6,矛盾$ 
  + $K_5又称K^{(1)}图,K_{3,3}又称K^{(2)}图$
+ **同胚图**
  + $如果对图G进行若干如下操作得到图G', 则称图G与图G'同胚$
    + $a.\ 在图G的某条边中间插入一个结点, 该结点将该边变成两条边$
    + $b.\ 在图G的某个结点度为2的结点关联的两条边(非自环)并成一条边$
  + $G是可平面图 \Leftrightarrow G的任意同胚图是可平面图$
+ $K^{(1)}$ 和 $K^{(2)}$ 的所有同胚图分别称为 **$K^{(1)}$ 型图**和 **$K^{(2)}$ 型图**, 统称 **$K$ 型图**

---

+ $Kuratowski,1930$
+ $G是可平面图 \Leftrightarrow G没有K型子图$

---

+ 图平面性检测算法 $DMP$
+ **对偶图**
  + 设 $G$ 是平面图, 如下方法构造的图 $G^{\ast}$ 称为 $G$ 的**对偶图**
    + $1.\ G中每个域f_i设置一点v^{\ast}_i作为G^{\ast}的结点$
    + $2.\ 对G的非割边e_k, 它必是G中某两个域f_i,f_j的的公共边界, 则画一条G^{\ast}的边e_k^{\ast}=(v_i^{\ast},v_j^{\ast})与e_k相交一次$
    + $3.\ 对G的割边e_k, 它必是某域f_i的边界,则画G^{\ast}的一条自环e_k^{\ast}=(v_i^{\ast},v_i^{\ast})与e_k相交一次$
  + $可平面图在平面上可能有多种嵌入,这些嵌入相互同构,但是这些嵌入的对偶图不一定同构$

---

+ $若G^{\ast}是G的对偶图$
  + $G^{\ast}是唯一的,且m^{\ast}=m,n^{\ast}=d$
  + $G^{\ast}是连通图$
  + $若G^{\ast}是平面连通图,则(G^{\ast})^{\ast}同构于G,且G^{\ast}与G的结点数,边数,域数满足如下关系:$
    + $n^{\ast} = d, m^{\ast}=m, d^{\ast}=n$
  + $G的回路对应G^{\ast}的割集;G的割集对应G^{\ast}的回路$

---

+ **对偶原理**

---

+ $设G是平面图,则下列命题等价:$
  + $(1).\ G是二部图$
  + $(2).\ G的每个域的边界的长度都是偶数$
  + $(3).\ G^{\ast}是欧拉图$
+ $证明:$
  + $(1) \Rightarrow (2):$
    + $G的每个域的边界都是一条闭路径,断言该闭路径为偶闭路径,$
    + $否则,存在奇回路(任何奇闭路径一定存在一条奇回路(Chapter02,极大路径法)),与二部图矛盾$
    + $证毕$
  + $(2) \Rightarrow (1)$
    + $任取G的一条回路C,C内部包含G的若干完整的域的边界,$
    + $而G所有域的边界长度都为偶数,C为偶回路$
  + $(2) \Leftrightarrow (3)$
    + $G的每个域的边界长度即是G^{\ast}的结点的结点度$
    + $(2) \Leftrightarrow G^{\ast}每个结点都是偶结点.而且G^{\ast}连通 \Leftrightarrow G^{\ast}是欧拉图\ (3)$

---



## 4.2 图的着色

+ **点着色**

  + 不同动物,有些动物之间会相互伤害, 为了没有损失, 问最少需要几个房间 ?

+ **边着色**

  + 球队打比赛, 不同的比赛可以同时进行, 问最少需要在几个时间段安排比赛 ?

    + $5个人,任意两人都需要组成双打打单循环赛,$

      $不同的比赛可以同时进行, 问最少需要在几个时间段安排比赛$

      + $a,b,c,d,e \Rightarrow 10个结点, 彼得森图(3-正则图)边着色$
      + $4$

<div style="margin:auto;height:200px;width:240px;" ><img src="../material/Petersen/5_teams_Petersen_letter_50pt.jpg"/></div>

+ **平面图的的域着色**

  + 地图着色问题

+ 以上三类问题等价

  + 图 $G$ 的**边着色**问题可以通过以下方法构造一个图 $G'$

    + 在 $G$ 的每条边 $e_i$ 上取一个点 $v_i$ 作为图 $G'$ 的结点, 

      若在图 $G$ 中边 $e_i$ 与边 $e_j$ 相邻, 则在图 $G'$ 中点 $v_i$ 与点 $v_j$ 相邻 

  + **平面图的域着色**问题可以转化为其**对偶图**的点着色

---

+ $四色定理:任何平面图G,其结点总可以用4种颜色来涂色,使得提任何两相邻结点着不同色$
  + $电子计算机在两千多个特殊图上检验是对的$
  + $未有数学证明$

---

---

+ $五色定理(1890,Heawood)$

  + $任何平面图G,其结点总可以用5种颜色来涂色,使得提任何两相邻结点着不同色$

+ $证明:数学归纳法,对G的结点数n实施归纳$

  + $自环,重边无意义,仅考虑简单图$

  + $\delta(G) \leq 5$

  + $n \leq 5时显然OK$

  + $n=k时$

    + $取G中最小度的结点v_0,G-v_0可以5着色$

    + $d(v_0) = \delta(G) < 5时$

      + $v_0的邻点没有用完5种颜色,v_0可以用剩余颜色进行着色 \Rightarrow G可以5着色$

    + $d(v_0)=\delta(G)=5时$

      + $当v_0的邻点没有用完5种颜色时$

        + $v_0可以用剩余颜色进行着色 \Rightarrow G可以5着色$

      + $当v_0的邻点用完5种颜色(v_0的5个邻点颜色都不相同)时$

        + $设v_0的5个邻点顺时针记为v_1,v_2,v_3,v_4,v_5，分别着色c_1,c_2,c_3,c_4,c_5$

        + $令G_{1,3}为着色c_1,c_3的结点导出的子图$

        + $若v_1,v_3属于G_{1,3}的不同的连通分支$

          + $此时在v_1所在的G_{1,3}的连通分支中,将着色c_1的结点着色c_3,着色c_3的结点着色c_1(换色)$
          + $此时v_1着色c_3,将v_0着色c_1即可将图G成功5着色$

        + $若v_1,v_3属于G_{1,3}的同一个连通分支$

          + $此时存在一条从v_1到v_3的道路P,此时 (v_3,v_0) + (v_0,v_1) + P为回路$

          + $此时v_2和v_4位于平面图G的两个域(顺时针记录5邻点)$

            $\Rightarrow 在着色c_2,c_4的结点导出的子图G_{2,4}中,v_2,v_4位于不同的连通分支$

            $\Rightarrow 同上,图G可以5着色$

---

+ **色数**
  + 给定图 $G$ , 满足相邻结点着以不同颜色所需的最少颜色数称为 $G$ 的**色数**, 记作 $\gamma(G)$
  + 一些典型图的色数
    + $G为零图(E(G)=\emptyset):\gamma(G)=1$
    + $\gamma(K_n)=n$
    + $\gamma(K_n - e)=n-1$
    + $若G是非空二部图:\gamma(G)=2$
      + $G为偶回路,G为非平凡树 \Rightarrow \gamma(G)=2$
    + $若G为奇回路:\gamma(G)=3$

---

+ $设v_i,v_j时简单图G的两个不相邻的结点,记G_{i,j}=G + (v_i,v_j),H_{i,j}=G \circ \lbrace v_i,v_j \rbrace$

  $则\gamma(G)=min \lbrace \gamma(H_{i,j}),\gamma(G_{i,j}) \rbrace$

+ $就是一个分类讨论:v_i,v_j是否着色相同$

+ $算法指数时间复杂度的$
---

+ 用以上定理可以求得下图的色数为 $3$

```C
        o-------o
        | \   / |
        |   o   |
        | /   \ |
        o-------o
```

+ $Petersen$ 图为三部图, 色数为 $3$

<div style="margin:auto;height:200px;width:200px;" ><img src="../material/Petersen/Petersen_3_50pt.jpg"/></div>



---

+ $色数近似算法:贪心$

+ $颜色集:C = \lbrace 1,2,..,n \rbrace;着色:coloring(v_i) \in C(1 \leq i \leq n)$
  + $1.\ 确定结点的一个顺序:v_1,v_2,...,v_n$
  + $2.\ coloring(v_1) = 1$
    + $for\ i = 2 to n do
    + $coloring(v_i) = \min \lbrace k:1 \leq k \leq n,k \notin \lbrace oloring(v_j): 1 \leq j < i, v_j \in N(v_i) \rbrace \rbrace$
    + $end$
+ $算法使用颜色数:\gamma ' = \max\limits_{1 \leq i \leq n} coloring(v_i)$
+ $\gamma ' \leq \Delta(G)+1$

---

---

+ $对于任意简单图G,\gamma(G) \leq \Delta(G)+1$

+ $证明:数学归纳法,对G的结点数n进行归纳$
  + $n=1,OK$
  + $n=k时$
    + $任取G的一个结点v,由归纳假设,\gamma(G-v) \leq \Delta(G-v)+1 \leq \Delta(G) + 1$
    + $可以用\Delta(G) + 1种颜色对G-v进行点着色$
    + $放回v,由于d(v) \leq \Delta(G),因此总可以用剩下的一种颜色对v进行着色$
    + $\gamma(G) \leq \Delta(G) + 1$
    + $证毕$

---

---

+ $Brooks,1941$
+ $对任意连通图G,\gamma(G) \leq \Delta(G),除非G是完全图或者奇回路$

---

---

+ $对任意简单图G,\gamma(G) \leq \max\limits_{H是G的导出子图} \delta(H) + 1$

+ $证明:数学归纳法,对\gamma(G)进行归纳+极化方法$

  + $\gamma(G)=1:G为零图时显然成立$

  + $\gamma(G)=k时$

    + $令\gamma(H)是满足\gamma(G)=k的任何一个G的极小导出子图$

      $即对H的任何结点v来说,都有\gamma(H-v)=k-1$

    + $因此,d_H(v) \geq k - 1,于是\delta(G) \geq k-1,即\gamma(G)=k \leq \delta(H)+1$

---

+ $平面连通图G的域可2着色 \Leftrightarrow G是欧拉图$

+ $证明:$

  + $G是连通图,(G^{\ast})^{\ast}=G$

  + $平面连通图G的域可2着色 \Leftrightarrow G^{\ast}的结点可以2着色 \Leftrightarrow G^{\ast}是二部图$

    $\Leftrightarrow G^{\ast}没有奇回路 \Leftrightarrow G = (G^{\ast})^{\ast}的结点都是偶结点 \Leftrightarrow G是欧拉图$

---

+ **色数多项式** $f(t,G)$
  + $f(t,G)$ 表示用t种颜色对G长得节点进行点着色的不同方案数
  + 当 $t < \gamma(G)$ 时, $f(t,G)=0$
  + 当 $t \geq \gamma(G)$ 时, $f(t,G) > 0$
  + 若用 $m_i$ 表示恰好用 $i$ 种颜色对 $G$ 着色的方案数目, 则
    + $f(t,G)=m_1C_t^1+m_2C_t^2+...+m_nC_t^n$
    + $f(t,G)$ 是一个 $n$ 阶多项式
  + $f(t,K_n)=C_t^n \times n! = A_t^n\ (t \geq n)$
  + $T_n$ 是 $n$ 阶树, $f(t,T_n) = t(t-1)^{n-1}$,
    + **二部图逐点着色**
+ $四色定理 \Leftrightarrow 对任意平面图G,f(4,G) > 0$

---

+ $设v_i,v_j时简单图G的两个不相邻的结点,记G_{i,j}=G + (v_i,v_j),H_{i,j}=G \circ \lbrace v_i,v_j \rbrace$

  $则f(t,G)=f(t,G_{i,j})+f(t,H_{i,j})$

+ $就是一个分类讨论:v_i,v_j是否着色相同$

---

+ $C_n$ 是长度为 $n$ 的回路, $f(t,C_n) = (t-1)^n + (-1)^n(t-1)$
    + 记长度为 $n\ (n \geq 3)$ 的道路为 $P_n$
    + $f(t,P_n) = f(t,C_{n-1}) + f(t,C_n)$
    + $f(t,P_n)=t(t-1)^{n-1}$
    + $t(t-1)^{n-1}=f(t,C_n)+f(t,C_{n-1})$
    + $(-1)^nt(t-1)^{n-1} = (-1)^nf(t,C_n) - (-1)^{n-1}f(t,C_{n-1})$
      + $-t(1-t)^{n-1} = (-1)^nf(t,C_n) - (-1)^{n-1}f(t,C_{n-1})$
    + $n=3 \sim n$ 求和得到 : $\sum\limits_{i=3}^n-t(1-t)^{i-1} =(-1)^nf(t,C_n) - f(t,C_2)$
      + $f(t,C_2)=t(t-1)$
    + $f(t,C_n) = (t-1)^n + (-1)^n(t-1)$



## 4.3 作业

+ $1.\ G为n(n \geq 11)阶无向简单图,证明:G 或 \overline G 必为不可平面图$
+ $2.\ 证明下列图形为不可平面图$
  + $(a)边集:\lbrace AB,AC,AD,BC,BF,BG,CD,CE,DF,DG,EF,EG,FG  \rbrace,n=7,m=13$
  + $(b)边集:\lbrace AB,AD,AG,BC,BH,CD,CE,DF,EF,EG,FH,GH \rbrace,n=8,m=12$
  + $(c)边集:\lbrace AB,AC,AD,AE,BC,BD,BE,BF,CE,CF,DE,DF,EF \rbrace,n=6,m=13$

```C
                                                                                
                                       +--------+             +-----------+     
                                       |        |             |           |     
              A                    +--------+   |             A-----B-----C     
           /  |  \                 |   |    |   |             |\   /|\   /|     
      +---B---C---D---+            A------------B             | \ / | \ / |     
      |   |   |   |   |            |   |    |   |             |  X  |  X  |     
      |   |   E   |   |            |   C----D   |             | / \ | / \ |     
      |    \ / \ /    |            |   |    |   |             |/   \|/   \|     
      |     F---G     |            |   |    |   |             D-----E-----F     
      |     |   |     |            |   E----F   |             |           |     
      |     +---|-----+            | /        \ |             +-----------+     
      +---------+                  G------------H                               
                                                                                
             (a)                         (b)                       (c)  
```

+ $3.\ 画出所有的6阶连通的简单非同构的不可平面图$
+ $4.\ Q_k为k方体图,证明Q_3是可平面图,Q_4是不可平面图$
+ $5.\ 求n阶轮形图W_n=C_{n_1}+T_1的色数与色数多项式$
+ $6.\ 求下图的色数与色数多项式$

```C
                 o      
                / \     
               /   \    
               o---o    
               |  /|    
               | / |    
               |/  |    
               o---o    
```

+ $7.\ 证明:存在G的n个结点的一个顺序:v_1,v_2,...,v_n,使得执行近似贪心着色算法所用的颜色数恰好是G的色数$



## 4.4 参考答案

+ $1.\ 反证法$

  + $G和\overline G都是平面图$

    $\Rightarrow m(G) \leq 3n-6,m(\overline G) \leq 3n-6 \Rightarrow m(K_n)  = \frac12n(n-1) \leq 6n-12$

    $\Rightarrow 3 \leq n \leq 10 \Rightarrow 矛盾$

+ $2.$

  + $(a):存在子图K_{3,3}$
    + $\lbrace BC,BF,BG,DC,DF,DG,EC,EF,EG \rbrace$
  + $(b):去掉边EF,作同胚图(点E,点F)形成K_{3,3}$
  + $(c):m > 3n - 6$

+ $3.\ 12个$
  + $m(K_6)=15$
  + $边数最少K_{3,3},m=9$
  + $K_{3,3}加边$
    + $0(1),m=9:K_{3,3}$
    + $1(1),m=10:K_{3,3}+e$
    + $2(2),m=11:K_{3,3}+e_1,+e_2(分e_1,e_2有无公共点)$
    + $3(2),m=12:两部A,B(A+3/A+2,B+1)$
    + $4(2),m=13:K_6-e_1-e_2(分e_1,e_2有无公共点)$
    + $5(1),m=14:K_6-e$
    + $6(1),m=15:K_6$
  + $K_5加边且与以上不同构$
    + $1(1),2(1),3(0),4(0),5(0)$

+ $4.$

  + $Q_3画出一个平面图即可$
  + $Q_4:n=16,m=36,Q_4没有三角形$
    + $m>2n-4$

+ $5.\ 直接依次着色即可$

  + $先着色T_1,再用t-1种颜色着色C_n$
  + $f(t,W_n)=tf(t-1,C_{n-1})=t((t-1)^{n-1}+(-1)^{n-1}(t-1))$

+ $6.$

  + $直接算$
    + $色数:3$
    + $色数多项式:f(t,G)=C_t^3 \cdot 3! + C_t^4 \cdot 3 \cdot 4! + C_t^5 \cdot 5! = t(t-1)(t-2)^3$
      + $3表示选两个点着相同颜色(10-7)$

  + $公式:收缩与加边$

+ $7.$

  + $设\gamma(G)=k,颜色集 \lbrace 1,2,...,k \rbrace$
  + $G的一种k着色下,着颜色i(1 \leq i \leq k)的点为v_{i,1},v_{i,2},...,v_{i,a_i}$
  + $在如下结点顺序进行贪心算法便得到一个G的k着色$
    + $v_{1,1},v_{1,2},...,v_{1,a_1},v_{2,1},v_{2,2},...,v_{2,a_2},v_{3,1},..., v_{k-1,a_{k-1}}, v_{k,1},...,v_{k,a_k}$

