#include"all.h"
/*
	图：
	表示”多对多“的关系
	包含：1.一组顶点：通常用V（Vertex）表示顶点集合
	2.一组边：通常用E(Edge)表示边的集合
		边是顶点对：（V，W）属于E，其中V，W属于V
		有向边<V,W>便是从V指向W的边（单行线）
		不考虑重边和自回路

	邻接矩阵：
		好处：
			直观、简单、好理解
			方便检查任意一对顶点间是否存在边
			方便找任一顶点的所有“邻接点”（有边直接相连的顶点）
			方便计算任一顶点的“度”（从该点发出的边数为“出度”，指向该点的边数为“入度”）
		坏处：
			浪费空间，浪费时间
	邻接表：
	方便找任一顶点的所有“邻接点”
	节约稀疏图的空间
		需要N个头指针+2E个结点（每个结点至少2个域）
	方便计算任一顶点的度
		对无向图：是的
		对有向图：只能计算“出度”：需要构造“逆邻接表”（村指向自己的边）来方便计算“入度”
	方便检查任意一对顶点间是否存在边

*/


/*
深度优先搜索（Depth First Search，DFS）

void DFS(Vertex V){
	visited[V]=true;
	for(V的每个邻接点W)
		if(!visited[W])
			DFS(W);
}
*/

/*
广度优先搜索（Breadth First Search，BFS)

void BFS(Vertex V){
	visited[V] = true;
	Enqueue(V,Q);
	while(!IsEmpty(Q)){
		V = Dequeue(Q);
		for(V的每个邻接点W)
			if(!visited[W]){
				visited[W] = true;
				Enqueue(W,Q);
			}
	}
}
*/


/*
连通：如果从V到W存在一条（无向）路径，则称V和W是连通的
路径：V到W的路径是一系列顶点{V，V1，V2,...,Vn,W}的集合，其中任一对相邻的顶点间都有图中的边，
	路径的长度是路径中的边数（如果带权，则是所有边的权重和）。如果V到W之间的所有顶点都不同，则称简单路径.
回路：起点等于终点的路径
连通图：图中任意两顶点均连通
连通分量：无向图的极大连通子图
	极大顶点树：再加一个顶点就不连通了
	极大边数：包含子图中所有顶点相连的所有边
强连通：有向图中顶点V和W之间存在双向路径，则称V和W是强连通
强连通图：有向如中任意两顶点均强连通
强连通分量：有向图的极大强连通子图
*/

/*
图不连通
void ListComponents(Graph G){
	for(each V in G)
	if(!visited[V]){
		DFS(V);  //or BFS(V);
	}
}
*/

/*
拯救007

void Save007(Graph G){
	for(each V in G){
		if(!visited[V] && FirstJump(V)){ //FirstJump() 功能  第一跳能不能跳到
			answer = DFS(V);
			if(answer == yes)break;
		}
	}
	if(answer == yes)output("Yes");
	else output("No");
}


int DFS(Vertex V){
	visited[V]=true;
	if(IsSafe(V))answer = Yes; //IsSafe() 能不能跳上岸
	else
	for(V的每个邻接点W)
		if(!visited[W] &&Jump(V,W)){ //Jump() 算一个V和W的距离可不可以跳上去
			answer = DFS(W);
			if(answer == yes)break;
		}
		return answer;
}
*/

