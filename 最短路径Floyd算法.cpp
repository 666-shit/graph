//
// Created by c1533 on 2022/9/17.
//
/**Floyd算法
 * 求出每一对顶点之间的最短路径
 * 使用动态规划思想，将问题的求节分为多个阶段
 * 对n个顶点的图G，求任意一对顶点vi->vj之间的最短路径可以分如下步骤：
 * 1. 若允许在v0中转，最短路径是？
 * 2. 若允许在v0、v1中转最短路径是？
 * …
 * n-1. 若允许在v0、v1、……、vn-1中转，最短路径是？
 *
 * 方法：设置两矩阵A和path
 * 标出A中各顶点到其余顶点距离，自身为0，无法到达为∞
 * path矩阵全设置为-1
 * 假设v0为中转点，则一点经过v0到达另一点的距离小于不中转的距离，则：
 *      A矩阵改变该值，path矩阵将该两点坐标初的值设置为0(表示v0中转)
 * 最后得到各点最短路径表A和中转表path
 * */
//初始化A和path，下为算法循环体
for(
int k = 0;
k<n;
k++){     //vk为中转点
for(
int i = 0;
i<n;
i++){       //遍历矩阵，i为行号
for(
int j = 0;
j<n;
j++){   //j为列号
if(A[i][j]>A[i][k]+A[k][j]){        //以vk为中转点的路径更短
A[i][j]=A[i][k]+A[k][j];        //更新最短路径长度
path[i][j]=
k;       //中转点
}
}
}
}
//时间复杂度O(|V|^3)，空间复杂度O(|V|^2)
//floyd算法不能解决带有负权回路的图，这种图可能没有最短路径
/**
 * BFS算法常用于：求无权图的单源最短路径
 * Dijkstra算法常用于：求带权图的单源最短路径
 * Floyd算法常用于：求带权图中各顶点间的最短路径
 * */
