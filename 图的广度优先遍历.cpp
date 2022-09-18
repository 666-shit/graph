//
// Created by c1533 on 2022/9/14.
//
#include<iostream>
#include "图基本操作.cpp"

#define MAXVERTEXNUM 100
/**图的遍历
 * 广度优先(BFS)
 * 深度优先(DFS)
 * */
/**BFS
 * 通过某一结点找到与其相邻的结点，遇到回路，或无向边，可对结点进行标记，保证每个结点被访问一次
 * 要点：1. 找到与一个顶点相邻的所有顶点；2. 标记哪些顶点被访问过；3. 需要一个辅助队列
 * 方法：1. FirstNeighbor()找到某顶点第一个邻接点，NextNeighbor()可以找到后一个邻接的顶点
 *           2. bool visited[MAXVERTEXNUM] //标记访问过的数组
 * */
bool visited[MAXVERTEXNUM]; //标记访问数组

void BFS(Graph G, int v) {      //从v出发广度优先遍历G
    visit(v);       //访问初始顶点v
    visited[v] = True;      //标记
    Enqueue(Q, v);      //入队
    //空间复杂度：最坏情况，辅助队列大小为O(|V|)，即所有顶点都在队列中
    while (!isEmpty(Q)) {
        DeQueue(Q, v);      //出队
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))        //检测v所有邻接点
            if (!visited[w]) {      //w为v的尚未访问的邻接顶点
                visit(w);       //访问顶点w
                visited[w] = True;      //标记
                Enqueue(Q, w);
            }
    }
}

void BFSTraverse(Graph G) {
    for (i = 0; i < G.vexnum; i++) {
        visited[i] = False;
    }
    InitQueue(Q);
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            BFS(G, i);
}
/**时间复杂度分析：
 * 时间复杂度可看作访问每一条边和每一个顶点，不同存储方式复杂度不同
 * 邻接矩阵：V个顶点，每个顶点O(|V|)，所以总共O(|V|^2)
 * 邻接表：V个顶点O(|V|)，各个顶点邻接点O(|E|)，所以总共O(|V|+|E|)
 * */
/**广度优先生成树
 * 由广度优先遍历过程确定，邻接表的表示方法不唯一，所以生成树不唯一
 * */
