//
// Created by c1533 on 2022/9/14.
//
/**图的遍历
 * 广度优先(BFS)
 * 深度优先(DFS)
 * */
/**DFS
 * 先根遍历/后根遍历
 * 先根遍历类似于图的遍历
 * */
//树的先根遍历
/**
void PreOrder(TreeNode *R){
    if(R!=nulltpr){
        visit(R);
        while(NextTree)
            PreOrder(T);
    }
}
*/
bool visited[MAXVERTEXNUM]; //访问标记数组

void DFS(Graph G, int v) {      //顶点v出发，深度优先遍历G
    visit(V);       //访问v
    visited[v]=true;    //设已访问标记
    for(w=FirstNeighbor(G, v); x>=0;w=NextNeighbor(G,v,w)){
        if(!visited[w]){        //w为u的尚未访问的邻接顶点
            DFS(G,w);
        }
    }
}

void DFSTraverse(Graph G){
    for(v=0;v<G.vexnu;v++){
        visited[v]=false;
    }
    for(v0;v<G.vexnum;v++){
        if(!visited[v]){        //找到第一个visit值为false的顶点，从该顶点调用dfs
            DFS(G,v);
        }
    }
}
/**复杂度分析：
 * 空间复杂度：来自函数调用栈，最坏情况是递归深度为O(|V|)，最好情况为O(1)。空间复杂度来自于递归工作栈
 * 时间复杂度：访问各结点所需时间+探索各条边所需时间
 *                     邻接矩阵：访问|V|各顶点需要O(|V|)的时间；查找每个顶点的邻接点需要O(|V|)，时间复杂度=O(|V|^2)
 *                     邻接表：时间复杂度=O(|V|+|E|)
 * 邻接矩阵存储表示唯一，邻接表不唯一，不同邻接表所得序列不同
 * */
/**深度优先生成树
 *
 * 生成森林：多个连通图无法一次访问，需要多次调用DFS
 * */










