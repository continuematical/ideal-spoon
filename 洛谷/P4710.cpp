#include<bits/stdc++.h>
using namespace std;

double v,the;
int main(){
	cin>>v>>the;
	double t=v*cos(the)/10;
	double x=v*sin(the)*t;
	double y=v*v*cos(the)*cos(the)/20;
	printf("%lf %lf",x,y); 
	return 0;
}
