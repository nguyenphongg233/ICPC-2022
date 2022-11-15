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

const long long MAX = (int)2e5 + 5;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;



void faster(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
}
void read(){
	
	faster();

	if(ifstream("task.inp")){
		freopen("task.inp","r",stdin);
		freopen("task.out","w",stdout);
	}
	
}

// End Of My template 
// Keep Watching


struct query{
	char x;
	int u,v,s;
	
};

struct anss{
	int id,s,u,v;
};

query qq[MAX];
anss outt[MAX];

int n,q;
char res[MAX];

int par[MAX];

int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}

bool cmp(anss a,anss b){
	return (a.s == b.s) ? (a.id < b.id) : (a.s < b.s);
	
}

signed main(){
	
	cin>>n>>q;
	int cnt = 0;
	
	for(int i = 1;i <= n;i++)par[i] = i;
	for(int i = 1;i <= q;i++){
		char x;
		cin>>x;
		
		if(x == 'A'){
			int u,v;
			cin>>u>>v;
			qq[i] = {x,u,v,0};
		}else if(x == '?'){
			int u,v;
			cin>>u>>v;
			qq[i] = {x,u,v,0};
			outt[++cnt] = {cnt,-1,u,v};
		}else if(x == 'Q'){
			int s,u,v;
			cin>>s>>u>>v;
			outt[++cnt] = {cnt,s,u,v};
			qq[i] = {x,u,v,s};
		}else if(x == 'C'){
			qq[i] = {x,0,0,0};
		}
		
		
	}
	
	
	sort(outt + 1,outt + 1 + cnt,cmp);
	
	
	
	int id1 = 1;
	// id1 : chay tren 
	
	for(int i = 1;i <= cnt;i++){
		if(outt[i].s > 0){
			id1 = i;
			break;
		}
	}
	
	int id2 = 1;
	// id2 : luu block dang chay 
	
	int id3 = 0;
	for(int i = 1;i <= q;i++){
		char x = qq[i].x;
		int u = qq[i].u;
		int v = qq[i].v;
		int s = qq[i].s;
		
		
		
		while(id2 > outt[id1].s){
			int u1 = outt[id1].u;
			int v1 = outt[id1].v;
			int idd = outt[id1].id;
			
			//cout<<idd<<"\n";
			u1 = find(u1);
			v1 = find(v1);
			
			if(u1 == v1){
				res[idd] = 'Y';
			}else res[idd] = 'N';
			
			id1++;
		}
		if(x == '?'){
			u = find(u);
			
			v = find(v);
			id3++;
			if(u == v){
				res[id3] = 'Y';
			}else{
				res[id3] = 'N';
				//par[u] = v;
			}
		}else if(x == 'Q'){
			id3++;
			if(s == 0){
				res[id3] = 'N';
			}else{
				
				if(outt[id1].id == id3){
					
					cout<<s<<" "<<u<<" "<<v<<" "<<i<<" "<<id2<<"\n";
					u = find(u);
			
					v = find(v);
			
					if(u == v){
						res[id3] = 'Y';
					}else{
						res[id3] = 'N';
						//par[u] = v;
					}
					id1++;
				}
				
				
				
			}
		}else if(x == 'C'){
			//cout<<"?";
			id2++;
			
		}else if(x == 'A'){
			u = find(u);
			v = find(v);
			
			if(u != v){
				par[u] = v;
			}
		}
		
		
		
	}
	
	
	
	for(int i = 1;i <= cnt;i++){
		cout<<res[i];
	}
	
	
}