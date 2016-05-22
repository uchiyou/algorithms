#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
struct Info{
	int count;//the name counts
	string str;
	int countchar[40];
	int len;//the value length of name char
}; 
Info* getInfo(string);
int countName(vector<struct Info>&f,struct Info*);
int judge(struct Info,struct Info);
int main(){
	
	int n=0,i=0,j=0;
	char str[40];
	struct Info* temp=NULL;
	vector<struct Info> set;
	
	cin>>n;
	for(i=0;i<n;++i){
		cin>>str;
		temp=getInfo(str);
		countName(set,temp);
	}
	
	return 0;
}

int countName(vector<struct Info> &set,struct Info* info){
	int size=set.size();
	int i=0,len=info->len,flag=0;
	struct Info temp;
	for(i=0;i<size;++i){
			
		temp=(set[i]);
		cout<<temp.str<<"----->"<<endl;
		if(judge(temp,*info)==1){// if name existed
		    ++(temp.count);
		    cout<<temp.count<<endl;
			return 1;
		} 
	}
	
	cout<<0<<endl;
	set.push_back(*info);
	return 0;
}

int judge(struct Info info1,struct Info info2){
	

	if(info1.len!=info2.len)
	return 0;
	
	
	int i=0,j=0,len=info1.len;
	for(i=0;i<len;++i){
		for(j=0;j<len;++j){
			if(info1.str[j]==info2.str[i]&&info1.countchar[j]==1){
			info1.countchar[j]=0;
			break;
		}
		}
		if(j==len)
		return 0;
	}
	
	for(i=0;i<len;++i)
	if(info1.countchar[i]==1)
	return 0;
	
	return 1;
}


Info* getInfo(string str){
	int i=0,len=0;
	len=str.length();
	
	Info* info=NULL;
	info=(struct Info*)malloc(sizeof(struct Info));
	info->str.resize(len);

	
	info->count=0;
	info->len=len;
	
	for(i=0;i<len;++i){
	info->str[i]=str[i];
	info->countchar[i]=1;
}

	return info;
}
