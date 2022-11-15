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

const long long MAX = (int)1e5 + 5;
const long long INF = 1e9;
const long long MOD = 998244353;

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
int f[177200];
signed main(){
	
	read();
	int n;
	cin>>n;
	f[0]=0;
	f[1]=0;
	f[2]=12;
	for(int i=3;i<=177013;i++)
	{
		f[i]=(f[i-3]*2+f[i-2]*4+f[i-1]+24)%MOD;
		if(f[i]<0) f[i]+=MOD;
	}	
	cout<<f[177013];
	
}