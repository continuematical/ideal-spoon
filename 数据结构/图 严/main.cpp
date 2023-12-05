#include<bits/stdc++.h>
#include "Graph.cpp"

using namespace std;
VertexType v, w;

int main(){
	ALGraph G;
	CreateGraph(G); 
	showGraph(G); 
	printf("广度优先搜索:\n"); 
	BFSTraverse(G); 
	printf("深度优先搜索:\n");
	DFSTraverse(G);
	
	printf("在两个节点之中添加边:\n"); 
	cin>>v>>w; 
	InsertArc(G, v, w);
	printf("深度优先搜索:\n");
	DFSTraverse(G);
	showGraph(G); 
	
	printf("删除两个节点之间的边:\n"); 
	cin>>v>>w;
	DeleteArc(G, v, w);
	printf("深度优先搜索:\n");
	DFSTraverse(G);
	showGraph(G); 
	
	printf("添加新节点：\n");
	cin>>v;
	InsertVex(G, v);
	printf("深度优先搜索:\n");
	DFSTraverse(G); 
	showGraph(G);
	
	printf("删除新节点：\n");
	cin>>v;
	DeleteVex(G, v);
	printf("深度优先搜索:\n");
	DFSTraverse(G); 
	showGraph(G);
} 
