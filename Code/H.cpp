/**
*  Author : nguyenphong233 
*  Date   :
**/

#include<bits/stdc++.h>

// My Template 

using namespace std;

#define ii pair<int,int> 
#define vi vector<int>

#define X first
#define Y second

const long long MAX = (int)2e6 + 5;
const long long INF = 1e9;
const long long MOD = 998244353;
#define int long long 

void gettime(){
	time_t now = time(0);
	char* x = ctime(&now);
	cerr<<"Right Now Is : "<<x<<"\n";
}

void faster(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
}
void read(){
	
	gettime();
	faster();

	if(ifstream("task.inp")){
		freopen("task.inp","r",stdin);
		freopen("task.out","w",stdout);
	}
	
}

// End Of My template 
// Keep Watching 

int f[MAX];
int g[MAX];
struct mt
{
	int a[6][6]=
			{{1,4,2,0,12,12}, 
			{1,0,0,0,0,0},
		   {0,1,0,0,0,0},
		   {0,0,0,1,4,2},
		   {0,0,0,1,0,0},
		   {0,0,0,0,1,0}
	};
};
mt operator *(mt a,mt b)
{
	mt c;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			c.a[i][j]=0;
			for(int k=0;k<6;k++)
			{
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%MOD;
			}
		}
	}
	return c;
}
mt mu(mt a,int b){
	if(b == 1)return a;
	mt s = mu(a,b / 2);
	s = (s * s);
	if(b & 1)s = (s * a);
	return s;
}
void print(mt x)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<x.a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
signed main(){
	
	read();
	
	
	int n;
	cin>>n;
	if(n==3) return cout<<36,0;
	if(n==2) return cout<<12,0;
	if(n<=1) return cout<<0,0;
	mt x;
	mt st;
	for(int i=0;i<6;i++) for(int j=0;j<6;j++) st.a[i][j]=0;
	st.a[0][0]=36;
	st.a[1][0]=12;
	st.a[2][0]=0;
	st.a[3][0]=11;
	st.a[4][0]=5;
	st.a[5][0]=1;
	x=mu(x,n-3);
	x=x*st;
	// print(x);
	cout<<x.a[0][0];
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}