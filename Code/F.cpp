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

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		string s,a,b;
		cin>>s>>a>>b;
		if(b + a == s)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
}