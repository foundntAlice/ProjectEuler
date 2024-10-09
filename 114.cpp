#include<bits/stdc++.h>

//yup, i'm kinda bad at DP but luckily this problem is easy enough
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

//the length of the measuring
const int N = 50;

void Solve(){
	//dp[i] denotes the answer til position i
	vector<vector<ll>> dp(N + 1, vector<ll> (2));
	for(int i = 0; i <= N; i++)
		dp[i][0] = 1;

	for(int i = 3; i <= N; i++){
		for(int j = 3; j <= N; j++){
			if(i - j >= 0){
				dp[i][1] += dp[i - j][0];
			}
		}
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
	}
	cout<<dp[N][0] + dp[N][1]<<nl;

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}
