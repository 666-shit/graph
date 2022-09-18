//
// Created by c1533 on 2022/9/10.
//
/**邻接矩阵法
 * 无向图中0表示没有边相连，1表示有边相连
 * 有向图中A指向B，则在A行B列为1，B行A列为0
 * */
#include<iostream>

#define MaxVertexNum 100    //顶点数目最大值
#define INFINITY 999    //定义“无穷大”，用来表示两顶点之间无边(带权图)

typedef char VertexType;    //顶点数据类型(带权图)
typedef int EdgeType;          //边上权值数据类型(带权图)

typedef struct {
    char Vex[MaxVertexNum];     //顶点表
    int Edge[MaxVertexNum][MaxVertexNum];       //邻接矩阵，边 表
    int vexnum, arcnum;     //图的当前定点数和边数
}MGraph;
//无向图某顶点的度：该顶点所在行的“1”的数量，复杂度O(n)，n表示顶点个数
//有向图某顶点出度：行有多少1；入度：列有多少1；总度：出度+入度
/**邻接矩阵性能分析
 * 空间复杂度O(n^2)+O(n)，n表示顶点个数，只和顶点数相关，和实际的边数无关。
 * 邻接矩阵适合存储稠密图
 * 无向图中邻接矩阵对称，可以用对称压缩存储
 * 邻接矩阵自乘，得到新矩阵(A^n)[I][J]，n个矩阵自乘，I表示起点J表示终点，
 * I行*J列表示I到J路径长度为n的路径有多少条。
 * */


/**邻接表
 * 顺序+链式存储
 * 一维数组存储顶点信息
 * 与树的孩子表示法相同
 * */
//边/弧
typedef struct ArcNode{
    int adjvex;     //边指向的顶点
    struct ArcNode *next;   //指向下一条边的指针
    //InfoType info;    //边权值
}ArcNode;

 //顶点
typedef struct VNode{
    VertexType data;    //顶点信息
    ArcNode *first;      //指向的第一条边
}VNode, AdjList[MaxVertexNum];

//用邻接表存储的图
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
/**
 * 无向图中边的数据有冗余边的数量是2|E|，空间复杂度为O(|V|+2|E|)；有向图为O(|V|+|E|)
 * 顶点的度，入度，出度：
 * 无向图的度：遍历该顶点的边链表，有多少个边结点就有多少个度
 * 有向图入度：遍历所有顶点的边链表，找到所求顶点的序号
 * 有向图出度：遍历该顶点的边链表，同无向图的度
 * */

/**十字链表-只用于存储有向图
 * 解决找入边不方便的问题，且空间复杂度和邻接表相同
 * */
/**邻接多重表-只用于存储无向图
 * 解决了邻接矩阵空间复杂度高，邻接表有冗余的问题，且空间复杂度和邻接表相同
 * */
//以上两种方式理解，不需要实现










