//
// Created by c1533 on 2022/9/10.
//
/**基本操作：(注：无向边用圆括号表示，有向边用尖括号表示)
 * Adjacent(G,x,y)      判断图G中是否存在边<X, Y>或(X, Y)     邻接矩阵更方便
 * Neighbors(G,x)       列出G中与结点x邻接的边        无向图邻接表更方便，有向非稀疏图邻接矩阵方便
 * Insert(G,x) ; Delete(G,x)    G中插入、删除顶点x
 * AddEdge(G,x,y)         若边<>或()不存在，则添加该边
 * RemoveEdge(G,x,y)    若该边存在，则删除
 * # FirstNeighbor(G,x)     G中顶点x的第一个邻接点，有则返回顶点号，无返回-1
 * # NextNeighbor(G,x,y)  G中y是x的邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，返回-1
 * GetEdgeValue(G,x,y)  获取G边<>或()对应的权值
 * SetEdgeValue(G,x,y,v) 设置边权值为v
 * */
//十字链表和邻接多重表如何实现？











