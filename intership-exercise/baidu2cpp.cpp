#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;



int main(){
	int N=0,a=0,b=0;
	string str;
	cin>>N;
	if(N<1||N>1000)
	exit(-1);
	
	
	cin>>str;
	int len=str.length();
	if(len<1||len>100000)
	exit(-1);
	
	
	int i=0,temp=0;
	
	int j=0;
	for(j=0;j<N;++j){
	  cin>>a>>b;
	
		if(a<1||a>len||b<1||b>len)
		exit(-1);
		
		temp=a>b?a:b;
		a=a>b?b:a;
		b=temp;
		
		temp=1;
	for(i=a-1;i<b;++i){
		temp*=(str[i]-28);
		if(temp>9973)
		temp=temp%9973;
		temp=temp==0?9973:temp;
	}
    cout<<temp%9973<<endl;

} 
	
	
	return 0;
}
