#include<bits/stdc++.h>
#include "Graph.cpp"

using namespace std;
VertexType v, w;

int main(){
	ALGraph G;
	CreateGraph(G); 
	printf("�����������:\n"); 
	BFSTraverse(G); 
	printf("�����������:\n");
	DFSTraverse(G);
	
	printf("�������ڵ�֮����ӱ�:\n"); 
	cin>>v>>w; 
	InsertArc(G, v, w);
	DFSTraverse(G);
	
	printf("ɾ�������ڵ�֮��ı�:\n"); 
	cin>>v>>w;
	DeleteArc(G, v, w);
	DFSTraverse(G);
} 
