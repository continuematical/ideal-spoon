#include<bits/stdc++.h>

class Employee{
	protected:
		char name[1000];//���� 
		int EmpInfo;//��� 
		double accumPay;//��н�ܶ�
		static int employeeNo;
	public:
		 
};

class Manager:virtual public Employee{
	protected:
		double monthPay;
	public:
		Manager():monthPay(8000){
		};
		void Pay(){
			accumPay=monthPay;	
		}
};

class Technician:virtual public Employee{
	protected:
		double workHour;//ÿСʱ����ʱ��
		double hourlyRate;//ÿСʱ����
	public:
		Technician():hourlyRate(100){
		} 
		
		void setHours(int hours){
			this->workHour=hours;
		}
		
		void Pay(){
			accumPay=workHour*hourlyRate;
		}
};

class Salesman:virtual public Employee{
	protected:
		double CommRate;//��ɰٷֱ�
		double sales;//������ 
	public:
		Salesman():CommRate(0.04){
		} 
		
		void setSales(double s){
			this->sales=s;
		}
		
		void Pay(){
			accumPay=sales*CommRate;
		}
};

class SalesManger:public Salesman, public Manager{
	public:
		SalesManager(){
			CommRate=0.05;
			monthPay=5000;
		}
		
		void Pay(){
			accumPay=sales*CommRate+monthPay;
		}
};
