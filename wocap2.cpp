#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define maxn 100010
#define mmaxn 1000000000
#define pii pair<int,int>
#define pll pair<ll int,ll int>
#define pdd pair<double,double>
#define MOD 1000000007
#define f first
#define s second
using namespace std;
int arr[maxn];
int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		vector<pii> y;
 		for(int i=0;i<x;i++){
			cin>>arr[i];
			y.pb(arr[i],i);
		}
		sort(y.begin(), y.end());
		int flag=0;
		for(int i=0;i<x;i++){
			if(abs(y[i].s-i)>1){
				cout<<"No\n";
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"Yes\n";
		}
	}
}