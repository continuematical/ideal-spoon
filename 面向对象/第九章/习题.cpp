#include<bits/stdc++.h>
using namespace std;

//1.ʹ����������װ������1-10������ʹ�õ�����iterator��accumulate�㷨ͳ��ʮ��Ԫ�صĺ�
void one(){
	vector<int> res;
	//װ��
	for(int i=1;i<=10;i++)	res.push_back(i);
	//int sum=0;
	//for(vector<int>::iterator ite=res.begin();ite!=res.end();ite++)	sum+=*ite;
	cout<<accumulate(res.begin(), res.end(), 0)<<endl; 
} 

//2.ʹ��stl�㷨�͵�������д������ 
void two(){
	const int SIZE = 10;
	int num[SIZE]={10,3,8,11,20,7,19,5,16,1};
	vector<int> res(num,num+SIZE);
	ostream_iterator<int> output(cout," ");
	
	cout<<"������֮ǰ��"<<endl;
	copy(res.begin(), res.end(), output);
	cout<<endl;
	
	make_heap(res.begin(), res.end());
	cout<<"����֮��"<<endl;
	copy(res.begin(), res.end(), output);
	cout<<endl;
	
	//������
	sort_heap(res.begin(), res.end());
	cout<<"������֮��"<<endl;
	copy(res.begin(), res.end(), output); 
}

//3.ʹ��stl��׼��͵��������ʵ�����򼯺ϵİ��� �� �� �� ����
void three(){
	int* ptr;
	
	const int SIZE1=10, SIZE2=5, SIZE3=20;
	int set1[SIZE1]={0,1,2,3,4,5,6,7,8,9};
	int set2[SIZE2]={1,2,3,4,5};
	int set3[SIZE3]={1,2,3,11,12};
	ostream_iterator<int> output(cout," ");
	
	cout<<"set1�е�Ԫ�أ�"<<endl;
	copy(set1,set1+SIZE1,output);
	
	cout<<"\nset2�е�Ԫ��"<<endl;
	copy(set2,set2+SIZE2,output);
	
	cout<<"\nset3�е�Ԫ��"<<endl;
	copy(set2,set2+SIZE2,output);
	
	//������ϵ 
	if(includes(set1,set1+SIZE1,set2,set2+SIZE2))	cout<<"\nset1����set2"<<endl;
	else	cout<<"\nset1������set2"<<endl; 
	
	if(includes(set1,set1+SIZE1,set3,set3+SIZE3))	cout<<"\nset1����set3"<<endl;
	else	cout<<"\nset1������set3"<<endl; 
	
	//��
	int diff[SIZE1];
	ptr=set_difference(set1,set1+SIZE1,set2,set2+SIZE2,diff);
	cout<<"\nset1��set2�Ĳ"<<endl; 
	copy(diff,ptr,output);
	
	//��
	int intersection[SIZE1];
	ptr=set_intersection(set1,set1+SIZE1,set2,set2+SIZE2,intersection);
	cout<<"\nset1��set2�Ľ���"<<endl;
	copy(intersection,ptr,output);
	
	//��
	int set_union[SIZE1];
	ptr=std::set_union(set1,set1+SIZE1,set2,set2+SIZE2,set_union);
	cout<<"\nset1��set2�Ĳ���"<<endl;
	copy(set_union,ptr,output); 
} 

//4.��������������Ʋ�ʵ��һ��ͼ�������������ͼ���������
//���������ͼ�����ɾ�� ����Ȳ���
class Review{
	private:
		string title;
		int rating;
	public:
		bool FillReview(Review& rv);
		void showReview(Review& rv);
}; 

bool Review::FillReview(Review& rv){
	cout<<"������������quit������\n"<<endl;
	cin>>rv.title;
	if(rv.title=="quit")	return false;
	cout<<"����������0-5��\n"<<endl;
	cin>>rv.rating;
	if(!cin)	return false;
	cin.get();
	return true;
}

void Review::showReview(Review& rv){
	cout<<rv.title<<'\t'<<rv.rating<<endl;
}

void four(){
	
}

int main(){
	three();
	return 0;
} 
