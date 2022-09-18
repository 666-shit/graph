//
// Created by c1533 on 2022/9/16.
//
/**最短路径
 * 常考：单源最短路径(单独的一个源头出发，到其他任意一个顶点)
 *                  广度优先(BFS)算法(无权图)
 *                  Dijkstra算法(带权图和无权图)
 *           每对顶点间最短路
 *                  Floyd算法(带权图和无权图)
 * */
 //BFS
#define INF 999
void BFS_MIN_Distance(Graph G, int u){
    //d[i]表示从u到i结点的最短路径
    for(i=0;i<G.vexnum;i++){
        d[i]=INF;       //初始化路径长度
        path[i]=-1;     //最短路径从哪个顶点过来
    }
    d[u]=0;
    visited[u]=true;
    EnQueue(Q, u);
    while(!isEmpty(Q)){         //BFS算法过程
        DeQueue(Q, u);      //出队
        for(w=FirstNeighbor(G, u); w>=0;w=NextNeighbor(G,u,w)){
            if(!visited[w]){        //w为u的尚未访问的邻接顶点
                d[w]=d[u]+1;        //路径长度+1
                path[w]=u;          //最短路径应从u到w
                visited[w]=true;        //标记已访问
                EnQueue(Q,w);       //w入队
            }
        }
    }
}
//BFS

/**Dijkstra
 * 初始：从v0开始初始化三个数组信息如下：
 *      final[v]标记各项顶点是否已找到最短路径
 *      dist[v]最短路径长度
 *      path[v]路径上的前驱
 * 步骤：初始：
 *      若从v0开始，令final[0]=true; dist[0]=0; path[0]=-1。
 *      其余顶点final[k]=false;dist[k]=arcs[0][k]; path[k]=(arcs[0][k]==∞)? -1:0
 *      n-1轮处理：
 *      循环遍历所有结点，找到没确定最短路径，且dist最小的顶点Vi，令final[i]=true
 *      检查所有邻接自Vi的顶点，若其final值为false且dist[i]+arcs[i][j]<dist[j]
 *      则更新dist和path信息，令dist[j]=dist[i]+arcs[i][j]
 *      重复以上步骤
 *      时间复杂度O(n^2)即O(|V|^2)
 *      注：Dijkstra算法不适用于有负权值的带权图
 * */
//Dijkstra

//Dijkstra











