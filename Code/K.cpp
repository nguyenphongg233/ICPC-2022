/**
*  Author : nguyenphong233 
*  Date   :
**/

#include<bits/stdc++.h>

// My Template 

using namespace std;

//#define int long long 
#define ii pair<int,int> 
#define vi vector<int>

#define X first
#define Y second

const long long MAX = (int)1e5 + 5;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;

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



int n;
vector<ii> a;

void solve(){
	
	for(int i = 1;i <= 5000;i++){
		for(int j = i + 1;j <= 7000;j++){
			int x = sqrt(i * i + j * j);
			if(x * x == i * i + j * j){
				a.push_back({i,j});
			}
		}
	}
	
	//int x = 0,y = 0;
	int x = -1000000,y = -1000000;
	cout<<x<<" "<<y<<"\n";
	sort(a.begin(),a.end(),[&](const ii &b,const ii &c){
		return b.X * c.Y < c.X * b.Y;
	});
	
	int sum = -1e6;
	int cnt = 0;
	
	vector<ii> b;
	for(int i = 1;i < a.size();i++){
		if(a[i].X * a[i - 1].Y == a[i - 1].X * a[i].Y)continue;
		b.push_back(a[i]);
		sum += a[i].X;
	}
	
	//cout<<b.size()<<"\n";
	//cout<<sum<<"\n";
	int id = 0;
	for(int i = 2;i <= n - 1;i++){
		x = x + b[id].X;
		y = y + b[id].Y;
		
		cout<<x<<" "<<y<<"\n";
		id++;
	}
	
	cout<<x<<" "<<-1000000;
	
	
	
}

signed main(){
	read();
	
	
	cin>>n;
	//cout<<int(1e6)<<"\n";
	if(n <= 2)return cout<<"NO",0;
	
	cout<<"YES\n";
	
	solve();
	
	
}