#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
#define  MaxVexNum   20     //最大顶点数目
typedef struct
{
	int  arcs[MaxVexNum][MaxVexNum];
	int  vert, edge;//vexnum是顶点数，arcnum是边数
}AMGraph;

void DFS(AMGraph* myGraph, int vertex, vector<bool>& visited) {
	cout << vertex << " ";//访问vertex节点
	visited[vertex] = true;
	//以vertex为起点进行深度优先搜索
	for (int i = 0; i < myGraph->vert; i++) {
		if (myGraph->arcs[vertex][i] == 1 && !visited[i]) {//节点vertex与节点i有边并且节点i没有被访问过
			DFS(myGraph, i, visited);
		}
	}
}
int main() {
	AMGraph* myGraph = new AMGraph;
	cin >> myGraph->vert >> myGraph->edge;
	int count = 0;//连通分量的个数
	//图的初始化
	for (int i = 0; i < myGraph->edge; i++) {
		int a, b;
		cin >> a >> b;
		myGraph->arcs[a][b] = 1;
		myGraph->arcs[b][a] = 1;
	}
	//标记序列
	vector<bool>visited(myGraph->vert, false);
	for (int i = 0; i < myGraph->vert; i++) {
		if (!visited[i]) {
			DFS(myGraph, i, visited);
			count++;
		}
	}
	cout << "\n" << count << endl;
	cout << myGraph->edge << endl;

	return 0;
}
