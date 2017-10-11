// 求一个矩阵的逆矩阵
/**
先输入多少阶矩阵，然后同时构造一个相同的n阶矩阵，不断把前面的通过行变换进行变成单位矩阵，对后面的也进行相同的操作
首先确定对角元都不是0，如果是0就在这一行上面找一个不是0的加上，如果都是0就返回不存在逆矩阵 
*/ 
#include<iostream>
#include<cstdio>
using namespace std;
double a[100][100];
double b[100][100];
int n;
void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%.2f ",b[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
}
void transA(int line1,int line2,int mul){
	for(int i=0;i<n;i++){
		a[line2][i]+=a[line1][i]*mul;
	}
}
void transB(int line1,int line2,double mul){
	for(int i=0;i<n;i++){
		b[line2][i]+=b[line1][i]*mul;
	}
}
void trans(int line1,int line2,double mul){
	transA(line1,line2,mul);
	transB(line1,line2,mul);
}
void calculate(){
	/*
	for(int i=0;i<n;i++){
		if(a[i][i]==0){
			for(int j=0;j<n;j++){
				if(a[j][i]!=0){
					trans(j,i,1/a[j][i]);
				}
				if(j==n-1&&a[j][i]==0){
					cout<<"逆矩阵不存在"<<endl;
					return; 
				}
			}
		}else{
		      for(int j=0;j<n;j++){
		      	a[i][j]/=a[i][i];
		      	b[i][j]/=b[i][i];
			  }
		}
	}
	*/
	
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
		    if(i!=j){
		    	if(a[i][j]!=0){
		    		int num=a[i][j]/a[j][j];
		    		for(int k=0;k<n;k++){
		    			a[i][k]=a[i][k]-(num)*a[j][k];
		    			b[i][k]=b[i][k]-(num)*b[j][k];	
					}
					print();
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[i][j]/=a[i][i];
		}
	}
	print();
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(i==j){
				b[i][j]=1;
			}else{
				b[i][j]=0;
			}
	}
   }
   calculate(); 
}
