#include<iostream>
#include<vector>
#include<set> 
#include<stdio.h>
#include<string>
using namespace std;
struct Node{
	int v;
	char c;
};
int a[1000];
vector<Node> g[1000];
set<int> finalstatue;

bool judge(int n) {
    int cnt = 0;
    //bool flag = true;
    for(int i = 0;i<n;i++){
    	set<char> ch;
    	for(int j = 0;j<g[i].size();j++){
    		ch.insert(g[i][j].c);
    		a[g[i][j].v] = 1;
    	}
    	if(ch.size() != g[i].size()) return false;
    }
    for(int i = 0;i<n;i++){
    	if(a[i] == 0) cnt++;
    }
    if(cnt != 1) return false;
    return true;
}

int f(int start,char ch){
		for(int i=0;i<g[start].size();i++){
			if(g[start][i].c==ch){
				return g[start][i].v;
			}
		}
}

bool isaccept(string a,int n){
	cout<<a<<"\n";
	cout<<n<<"\n";
	int h=0;
	for(int j=0;j<n;j++){
		h=f(h,a[j]);
	}
	cout<<"终止于"<<h<<"\n";
	
	if(finalstatue.count(h)){
		cout<<"符合\n";
		return true;
	}else{
		cout<<"不符合\n"; 
		return false;
	}  
} 

int main()
{
	freopen("in.txt","r",stdin);
	int n,m;
	cout<<"请输入dfa的状态数n和边数m\n";
	cin>>n>>m;
	cout<<"请输入dfa,按照0 1 a的格式\n";
	for(int i=0;i<m;i++){
		int a,b;
		char c;
		Node tmp;
		cin>>a>>b>>c;
		tmp.v=b;
		tmp.c=c;
		g[a].push_back(tmp);
	}
	cout<<judge(n)<<"\n";
	
	cout<<"请输入终态个数\n";
	int t;
	cin>>t; cout<<t<<"\n";
	cout<<"请依次输入终态\n";
	for(int i=0;i<t;i++){
		int k;
		cin>>k; cout<<k<<"\n";
		finalstatue.insert(k);
	}
	
	string a;
	cout<<"请输入要匹配的字符串\n";
	cin>>a; 
	//scanf("%s",&a);
	isaccept(a,a.size());
	return 0;
}
