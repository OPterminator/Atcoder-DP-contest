#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
const int mod=(int)1e9+7;
const int nax=(int)1e3+5;
int main() 
{
    fastio;
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n+1,vector<char>(m+1));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    dp[n][m]=1;
    for(ll i=n;i>=1;i--){
        for(ll j=m;j>=1;j--){
            if(i==n&&j==m){
                continue;
            }
            if(grid[i][j]=='#'){
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=(((i==n)?0:dp[i+1][j])%mod+((j==m)?0:dp[i][j+1])%mod)%mod;
        }
    }
    cout<<dp[1][1]<<'\n';
return 0;
}
