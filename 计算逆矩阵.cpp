// ��һ������������
/**
��������ٽ׾���Ȼ��ͬʱ����һ����ͬ��n�׾��󣬲��ϰ�ǰ���ͨ���б任���б�ɵ�λ���󣬶Ժ����Ҳ������ͬ�Ĳ���
����ȷ���Խ�Ԫ������0�������0������һ��������һ������0�ļ��ϣ��������0�ͷ��ز���������� 
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
					cout<<"����󲻴���"<<endl;
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
