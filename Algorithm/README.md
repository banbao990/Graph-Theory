# 算法汇总

## 1. 拓扑排序( $Topological\ Sort$ )

+ 功能
  + 用于判断一个有向图是否为**有向无环图**( $DAG$ )
  + 给出一个有向无环图的**拓扑排序**
+ 实现
  + [$BFS实现的拓扑排序$](./topological-sort-bfs.cpp)
    + 每次寻找入度为 $0$ 的点
      + 出度为 $0$ 也可以, 需要**逆序**输出( $stack$ )
  + [$DFS实现的拓扑排序$](./topological-sort-dfs.cpp)
    + 使用 $stack$ 实现判断是否为 $DAG$
      + 搜索栈记录当前搜索深度的路径
      + 无需从树根(入度为 $0$ 的点)开始
      + 若已知为 $DAG$ 无需使用栈
    + 本质上还是每次寻找出度为 $0$ 的点
      + 入度为 $0$ 当然也可以



## 2. 最小生成树( $Minimum\ Spanning\ Tree,MST $ )

### 2.1. [$Kruscal\ Algorithm$](./MST-Kruscal.cpp)

+ 最小边使用堆( $heap$ )优化

+ 使用**并查集**来判断新加入边的两个端点是否已经在同一连通分支中(判断是否有环)

### 2.2. [$Prim\ Algorithm$](./MST-Prim.cpp)

+ 找最小边的时候可以使用堆( $heap$ )优化



## 3. 最短路算法