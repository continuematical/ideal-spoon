#include "HuffmanTree.cpp"

int main(){
	HuffmanTree HT;
	initHuffmanTree(HT);
	createHuffmanTree(HT, N);
	//1 4 24 5 6 10 8 31 22 11
	//abcdefghij 
	HuffmanCode HC;
	createHuffmanCode(HT, HC, N);
	showHuffmanCode(HT, HC);
	return 0;
} 
