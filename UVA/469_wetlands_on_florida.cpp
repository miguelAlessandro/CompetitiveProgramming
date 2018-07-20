#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x;i<y;i++)
#define pb push_back
#define N 105
using namespace std;
char c[N][N];
int x[8]={1,1,0,-1,-1,-1,0,1},
    y[8]={0,-1,-1,-1,0,1,1,1};
bool visit[N][N];
int contador=0;
int n, m;

void DFS(int s1,int s2){
	if(c[s1][s2] == 'W')
		visit[s1][s2]=true;
	contador++;
	f(i,0,8)
	{
		int a=s1+y[i],b=s2+x[i];
		if(a>=0  &&  a<m  &&  b>=0  && b<n  &&  !visit[a][b]  &&  c[a][b]=='W')
			DFS(a,b);
	}
	//visit[s1][s2] = false;
}



int main(){
	int T;
	cin>>T;
	getchar();
	getchar();

	while(T--){
		m = 0;
		string s;	
		getline(cin, s);
		n = s.length();
		while(!isdigit(s[0]))
		{
			f(i,0,n)
				c[m][i] = s[i];
			getline(cin, s);
			m++;
		}
		int a, b;
		while(s.length() != 0){
			stringstream(s) >> a >> b;
			contador = 0; 
			DFS(a-1, b-1);
			cout << contador << endl;
			getline(cin, s);
			memset(visit, 0, sizeof(visit));
		}
		if(T != 0)
			cout << endl;
		memset(c, 0, sizeof(c));
	}
}
