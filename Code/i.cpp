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
const long long MOD = 1e9 + 7;



// End Of My template 
// Keep Watching 
int a[1010][1010];
int deg[1010];
int b[1010];
int res[1010];
bool cmp(int a,int b)
{
	return deg[a]>deg[b];
}
signed main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(a[i][j]>a[i][i])
			{
				if(j>i) deg[i]++;
				else deg[j]++;
			}
			else
			{
				if(j>i) deg[j]++;
				else deg[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		 b[i]=i;
		 // cout<<i<<" "<<deg[i]<<"\n";
	}
	int tmp=1;
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++) res[b[i]]=tmp++;
	for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}