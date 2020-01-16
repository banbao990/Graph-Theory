/**********************************************************************
 * author:      banbao                                                *
 * language:    c++                                                   *
 **********************************************************************/

/*
 * bbq: 直接编译会出错, 需要将编码格式调整为 UTF-8-BOM 才可以编译
 *      实现功能: 看 main 函数
*/

#include <iostream>
#include <memory.h>
#include <iomanip>
using namespace std;

void printMatrix(int matrix[101][101], int row, int col) {
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j)
            cout << setw(2) << matrix[i][j] << " ";
        cout << endl;
    }
    return;
}

/*邻接矩阵转化为关联矩阵*/
void adjacencyMatrix_TO_correlationMatrix() {
    int adjacencyMatrix[101][101] = {};     //邻接矩阵
    int correlationMatrix[101][101] = {};   //关联矩阵
    int V;
    int i, j;
    int edge = 0;
    cout << "请输入V (V<=100)" << endl;
    cin >> V;
    cout << "请输入邻接矩阵" << endl;
    for (i = 1; i <= V; ++i)
        for (j = 1; j <= V; ++j)
            cin >> adjacencyMatrix[i][j];
    for (i = 1; i <= V; ++i) {
        for (j = 1; j <= V; ++j) {
            if (adjacencyMatrix[i][j]) {
                ++edge;
                correlationMatrix[i][edge] = 1;
                correlationMatrix[j][edge] = -1;
            }
        }
    }
    cout << "关联矩阵:" << endl;
    printMatrix(correlationMatrix, V, edge);
}

/*关联矩阵转化为邻接矩阵*/
void correlationMatrix_TO_adjacencyMatrix() {
    int adjacencyMatrix[101][101] = {};     //邻接矩阵
    int correlationMatrix[101][101] = {};   //关联矩阵
    int V, E;
    int i, j;
    int x, y;
    cout << "请输入V E(V,E<=100)" << endl;
    cin >> V >> E;
    cout << "请输入关联矩阵" << endl;
    for (i = 1; i <= V; ++i)
        for (j = 1; j <= E; ++j)
            cin >> correlationMatrix[i][j];
    for (j = 1; j <= E; ++j) {
        for (i = 1; i <= V; ++i) {
            if (correlationMatrix[i][j] == 0)
                continue;
            else if (correlationMatrix[i][j] == 1)
                x = i;
            else if (correlationMatrix[i][j] == -1)
                y = i;
        }
        if (x&&y)
            adjacencyMatrix[x][y] = 1;
    }
    cout << "邻接矩阵:" << endl;
    printMatrix(adjacencyMatrix, V, V);
    return;
}

/*邻接矩阵转化为正向表*/
void adjacencyMatrix_TO_forwardTable() {
    int adjacencyMatrix[101][101] = {};         //邻接矩阵
    int forwardTable_A[101] = {};               //正向表A
    int forwardTable_B[101] = {};               //正向表B
    int V;
    int i, j;
    int edge = 0;
    cout << "请输入V(V<=100)" << endl;
    cin >> V;
    cout << "请输入邻接矩阵(不带权)" << endl;
    for (i = 1; i <= V; ++i)
        for (j = 1; j <= V; ++j)
            cin >> adjacencyMatrix[i][j];
    for (i = 1; i <= V; ++i) {
        bool first = true;
        for (j = 1; j <= V; ++j) {
            if (adjacencyMatrix[i][j]) {
                ++edge;
                if (first) {
                    forwardTable_A[i] = edge;
                    first = false;
                }
                forwardTable_B[edge] = j;
            }
        }
    }
    for (i = 1; i <= V; ++i)
        cout << forwardTable_A[i] << " ";
    cout <<  edge << endl;
    for(i=1;i<=edge;++i)
        cout << forwardTable_B[i] << " ";
    cout << endl;
    return;
}

/*正向表转化为邻接矩阵*/
void forwardTable_TO_adjacencyMatrix() {
    int adjacencyMatrix[101][101] = {};         //邻接矩阵              
    int forwardTable_A[101] = {};               //正向表A
    int forwardTable_B[101] = {};               //正向表B
    int V, E;
    int i, j;
    int start, end;
    cout << "请输入V E(V,E<=100)" << endl;
    cin >> V >> E;
    cout << "q(不带权)" << endl;
    for (i = 1; i <= V + 1; ++i)
        cin >> forwardTable_A[i];
    for (i = 1; i <= E; ++i)
        cin >> forwardTable_B[i];
    for (i = 1; i <= V; i++) {
        start = forwardTable_A[i];
        end = forwardTable_A[i+1];
        for (j = start; j < end; ++j)
            adjacencyMatrix[i][forwardTable_B[j]] = 1;
    }
    printMatrix(adjacencyMatrix, V, V);
    return;
}

/*关联矩阵转化为边列表*/
void correlationMatrix_TO_edgeList() {
    int edgeList_A[101] = {};               //边列表A
    int edgeList_B[101] = {};               //边列表B
    int correlationMatrix[101][101] = {};   //关联矩阵
    int V, E;
    int i, j;
    int x, y;
    cout << "请输入V E(V,E<=100)" << endl;
    cin >> V >> E;
    cout << "请输入关联矩阵" << endl;
    for (i = 1; i <= V; ++i)
        for (j = 1; j <= E; ++j)
            cin >> correlationMatrix[i][j];
    for (j = 1; j <= E; ++j) {
        for (i = 1; i <= V; ++i) {
            if (correlationMatrix[i][j] == 0)
                continue;
            else if (correlationMatrix[i][j] == 1)
                x = i;
            else if (correlationMatrix[i][j] == -1)
                y = i;
        }
        if (x&&y) {
            edgeList_A[j] = x;
            edgeList_B[j] = y;
        }
    }
    cout << "边列表:" << endl;
    for (i = 1; i <= E; ++i)
        cout << edgeList_A[i] << " ";
    cout << endl;
    for (i = 1; i <= E; ++i)
        cout << edgeList_B[i] << " ";
    cout << endl;
    return;
}

/*边列表转化为关联矩阵*/
void edgeList_TO_correlationMatrix() {
    int edgeList_A[101] = {};               //边列表A
    int edgeList_B[101] = {};               //边列表B
    int correlationMatrix[101][101] = {};   //关联矩阵
    int V, E;
    int i;
    cout << "请输入V E(V,E<=100)" << endl;
    cin >> V >> E;
    cout << "请输入边列表(不带权)" << endl;
    for (i = 1; i <= E; ++i)
        cin >> edgeList_A[i];
    for (i = 1; i <= E; ++i)
        cin >> edgeList_B[i];
    for (i = 0; i <= E; ++i) {
        correlationMatrix[edgeList_A[i]][i] = 1;
        correlationMatrix[edgeList_B[i]][i] = -1;
    }
    printMatrix(correlationMatrix, V, E);
    return;
}

/*邻接矩阵转化为正向邻接表*/
void adjacencyMatrix_TO_forwardAdjacencTable() {
    int adjacencyMatrix[101][101] = {};     //邻接矩阵
    int forwardAdjacencTable[101][101] = {};//正向邻接表
    int V;
    int i, j;
    cout << "请输入V (V<=100)" << endl;
    cin >> V;
    cout << "请输入邻接矩阵" << endl;
    for (i = 1; i <= V; ++i)
        for (j = 1; j <= V; ++j)
            cin >> adjacencyMatrix[i][j];
    for (i = 1; i <= V; ++i) {  
        int number = 0;
        for(j=1;j<=V;++j) { 
            if (adjacencyMatrix[i][j]) {
                ++number;
                forwardAdjacencTable[i][number] = j;
            }
        }
    }
    for (i = 1; i <= V; ++i) {
        cout << setw(2) << i << "->";
        for (j = 1;; ++j) {
            if (forwardAdjacencTable[i][j])
                cout << setw(2) << forwardAdjacencTable[i][j] << "->";
            else
                break;
        }
        cout << "NULL" << endl;
    }
    return;
}

/*正向邻接表转化为邻接矩阵*/
void forwardAdjacencTable_TO_adjacencyMatrix() {
    int adjacencyMatrix[101][101] = {};     //邻接矩阵
    int forwardAdjacencTable[101][101] = {};//正向邻接表
    int V;
    int i, j;
    cout << "请输入V (V<=100)" << endl;
    cin >> V;
    cout << "请输入正向邻接表" << endl << "格式:最后以0结尾(例子)" << endl 
        << "1 2 3 0" << endl << "2 1 3 0" << endl << "3 1 2 0" << endl;
    for (i = 1; i <= V; ++i) {
        int temp;
        j = 0;
        cin >> temp;
        while (temp) {
            ++j;
            forwardAdjacencTable[i][j] = temp;
            cin >> temp;
        }
    }
    for (i = 1; i <= V; ++i) {
        for (j = 2;; ++j) {
            if (forwardAdjacencTable[i][j])
                adjacencyMatrix[i][forwardAdjacencTable[i][j]] = 1;
            else
                break;
        }
    }
    printMatrix(adjacencyMatrix, V, V);
    return;
}

int main() {
    int cmd;
    while (true) {
        cout << "*****有向图 D(V,E)*****" << endl
            << "请输入你要进行的操作(数字):" << endl
            << "注:e(i,j)的编号顺序:①先按i排序,再按j排序②没有自环、重边" << endl
            << "  1.邻接矩阵转化为关联矩阵" << endl
            << "  2.关联矩阵转化为邻接矩阵" << endl
            << "  3.邻接矩阵转化为正向表" << endl
            << "  4.正向表转化为邻接矩阵" << endl
            << "  5.关联矩阵转化为边列表" << endl
            << "  6.边列表转化为关联矩阵" << endl
            << "  7.邻接矩阵转化为正向邻接表" << endl
            << "  8.正向邻接表转化为邻接矩阵" << endl
            << "  9.退出" << endl;
        cin >> cmd;
        if (cmd == 9)
            break;
        switch (cmd) {
        case 1:
            adjacencyMatrix_TO_correlationMatrix();
            break;
        case 2:
            correlationMatrix_TO_adjacencyMatrix();
            break;
        case 3:
            adjacencyMatrix_TO_forwardTable();
            break;
        case 4:
            forwardTable_TO_adjacencyMatrix();
            break;
        case 5:
            correlationMatrix_TO_edgeList();
            break;
        case 6:
            edgeList_TO_correlationMatrix();
            break;
        case 7:
            adjacencyMatrix_TO_forwardAdjacencTable();
            break;
        case 8:
            forwardAdjacencTable_TO_adjacencyMatrix();
            break;
        default:
            break;
        }
    }
    return 0;
}
