//
// Created by c1533 on 2022/9/17.
//
/**AOV网*/
/*
用顶点表示活动的网
用DAG表示一个工程，顶点表示活动，有向边<Vi, Vj>表示活动Vi先于Vj进行
拓扑排序：找到做事的先后顺序

        拓扑排序实现：
1.   从AOV网中选择一个没有前驱的顶点并输出
2.   从网中删除该顶点和所有以它为起点的有向边
3.   重复上述步骤知到当前AOV网空或当前网中不存在无前驱顶点为止
        每一个AOV网可以有多个序列，有回路的图无法进行拓扑排序
*/
#include<iostream>

#define MaxVertexNum 100        //顶点数目最大值

typedef struct ArcNode {     //边表结点
    int adjvex;         //该弧所指向的顶点的位置
    struct ArcNode *nextarc;        //指向下一条弧的指针
    //InfoType info;        //网的边权值
} ArcNode;
typedef struct VNode {       //顶点表结点
    VertexType data;        //顶点信息
    ArcNode *firstarc;      //指向第一条衣服该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];
typedef struct {
    AdjList vertices;       //邻接表
    int vexnum, arcnum;     //图的顶点数和弧数
} Graph;     //图G以邻接表存储

bool TopologicalSort(Graph G) {
    InitStack(S);       //初始化栈，存储入度为0的顶点
    for (int i = 0; i < G.vexnum; i++)
        if (indegree[i] == 0)      //声明数组indegree，表示当前入度
            Push(S, i);     //入度为0的点入栈
    int count = 0;        //记录当前已经输出的顶点数
    while (!isEmpty(S)) {     //栈不空，则存在入度为0的顶点
        Pop(S, i);      //栈顶元素出栈
        print[count++] = i;       //声明数组print，记录拓扑序列，输出顶点i
        for (p = G.vertices[i].firstarc; p; p = p.nextarc) {        //将所有i指向的顶点入度-1，并将入度减为0的顶点压入栈S
            v = p.adjvex;
            if (!(--indegree[v]))
                Push(S, v);     //入度为0，则入栈
        }
    }
    if (count < G.vexnum)
        return false;       //拓扑排序失败，有回路
    else
        return true;        //排序成功
}
/**
 * 逆拓扑排序
 * 拓扑排序的入度变出度
 * */
//拓扑排序DFS
void DFS(Graph G, int v){
    visited[v]=true;
    for(w=FirstNeighbor(G, v);w>=0;w=NextNeighbor(G,v,w))
        if(!visited[w]){
            DFS(G,w);
        }
    print(v);
}

/**AOE
 * 1. 只有在某顶点所代表的时间发生后，从该顶点出发的各有向边所代表的活动才能开始；
 * 2. 只有在进入某顶点的各有向边所代表的活动都已经结束是，该顶点所代表的时间才能法师
 * 另外，有些活动可以并行进行
 *
 * 事件最迟发生时间vl(k)——不推迟整个工程完成的前提下事件最迟发生时间
 * 活动最迟开始时间l(i)——活动的重点表示事件的最迟发生时间与该活动所需时间之差
 * 时间余量d(i)=l(i)-e(i)
 * */
/**求关键路径步骤
 * 1. 求所有时间的最早发生时间ve()
 * 2. 求所有时间的最迟发生时间vl()
 * 3. 求所有活动的最早发生时间e()
 * 4. 求所有活动的最晚发生时间l()
 * 5. 求所有活动的时间余量d()
 * d(i)=0的活动为关键活动，关键活动可以得到关键路径
 * */









