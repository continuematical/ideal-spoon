#include<bits/stdc++.h>
#include "Graph.cpp"

using namespace std;
VertexType v, w;

int main(){
	ALGraph G;
	CreateGraph(G); 
	printf("深度优先搜索:\n"); 
	BFSTraverse(G); 
	printf("广度优先搜索:\n");
	DFSTraverse(G);
	
	printf("在两个节点之中添加边:\n"); 
	cin>>v>>w; 
	InsertArc(G, v, w);
	DFSTraverse(G);
	
	printf("删除两个节点之间的边:\n"); 
	cin>>v>>w;
	DeleteArc(G, v, w);
	DFSTraverse(G);
} 
