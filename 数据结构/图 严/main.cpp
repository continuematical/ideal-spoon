#include<bits/stdc++.h>
#include "Graph.cpp"

using namespace std;
VertexType v, w;

int main(){
	ALGraph G;
	CreateGraph(G); 
	showGraph(G); 
	printf("�����������:\n"); 
	BFSTraverse(G); 
	printf("�����������:\n");
	DFSTraverse(G);
	
	printf("�������ڵ�֮����ӱ�:\n"); 
	cin>>v>>w; 
	InsertArc(G, v, w);
	printf("�����������:\n");
	DFSTraverse(G);
	showGraph(G); 
	
	printf("ɾ�������ڵ�֮��ı�:\n"); 
	cin>>v>>w;
	DeleteArc(G, v, w);
	printf("�����������:\n");
	DFSTraverse(G);
	showGraph(G); 
	
	printf("����½ڵ㣺\n");
	cin>>v;
	InsertVex(G, v);
	printf("�����������:\n");
	DFSTraverse(G); 
	showGraph(G);
	
	printf("ɾ���½ڵ㣺\n");
	cin>>v;
	DeleteVex(G, v);
	printf("�����������:\n");
	DFSTraverse(G); 
	showGraph(G);
} 
