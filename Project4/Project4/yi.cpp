图(Graph)

表示多对多的关系

包含
一组顶点：通常用V(Vertex)表示顶点集合 
一组边 ：通常用E(Edge)表示边的集合
(v,w)∈E,其中v,w∈V  是一条v和w的无向边
<v,w>表示一条v指向w的有向边
不考虑重边和自回路

抽象数据类型定义

数据对象集:G(V,E)由一个非空的有限顶点集合V(至少有一个顶点)
和一个有限边集合E组成
边上的数字叫权重，带权重的图称为网络


图的表示

1.邻接矩阵
G[N]][N]---N个顶点从0到N-1编号

G[i][j]={1若<vi,vj>是G中的边，0否则
无向边邻接矩阵对称

为了省空间
用一个长度为N(N + 1) / 2的一维数组A存储{G0 0,G1 0,....,Gn-1 0,....,Gn-1 n-1}
1+N * N /2, 总数量 
Gi j在A中的下标是 :
	(i*(1 + i) / 2 + j)

对于网络，只要把G[i][j]的值定义为边<vi,vj>的权重即可
当vi和vj间没边时怎么表示，该问题待解决

好处
直观简单好理解
方便检查任意一对顶点 间是否存在边
方便找任一顶点的所有"邻接点"(有边直接相连的顶点)
方便计算任一顶点的"度"(从该点出发的边数为出度，指向该点的边数为入度):
	无向图:对应行(或列)非0元素的个数
		有向图:对应行非0元素的个数是出度，对应列非0元素的个数是入度 

坏处 
浪费空间
	存稀疏图(点很多边很少)有大量无效元素
浪费时间



2.邻接表
G[N]为指针数组，对应矩阵每行一个链表，只存非0元素
对于网络，结构中要增加权重的域
越稀疏越划算

好处
	方便找任一顶点的所有邻接点 
	节约稀疏图的空间
		需要N个头指针+2E个结点(每个结点至少2个域)
	方便计算任一顶点的度？
		对无向图：是的
		

坏处 ：
	方便计算任一顶点的度？
		对有向图：不是，只能计算出度；需要构造逆邻接表(存指向自己的边)
					俩方便计算入度
	不便于检查任意一对顶点间是否存在边




图的遍历

深度优先搜索//类似于树的先序遍历
---原路返回

void DFS(Vertex v)
{
	visited[v] = true;
	for (v的每个邻接点w)
	{
		if (!visited[w])
			DFS(w);
	}
}
	若有N个结点 、E条边，时间复杂度是
		用邻接表存储图，有O(N+E)
		用邻接矩阵存储图，有O(N^2)
 

广度优先搜索//类似于树的层序遍历

void BFS(Vertex V)
{
	visited[V] = true;
	Enqueue(V, Q);//Q入队
	while (!IsEmpty(Q)) 
	{
		V = Dequeue(Q);
		for(V的每个邻接点W)
			if (!visited[W]) 
			{
				visited[W] = true;
				Enqueue(W, Q);
			}
	}
}


	若有N个结点 、E条边，时间复杂度是
		用邻接表存储图，有O(N + E)
		用邻接矩阵存储图，有O(N ^ 2)