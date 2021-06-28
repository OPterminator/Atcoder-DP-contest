/****************************************** By Lord Sanskar Bhargava******************************/


#include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define all(v) (v).begin(),(v).end()
#define dll(v) (v).rbegin(),(v).rend()
#define set1(x) __builtin_popcount(x)
#define gcd(a,b) __gcd(a,b)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define bk(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second
#define sz(x) ((ll) (x).size())
#define mid(l,r) (l+(r-l)/2)
#define inf 1e18
const int mod = 1000000007;

int main(int argc, char const *argv[]) 
{
    clock_t begin = clock();
    fastio;
    string s,t;
    cin>>s>>t;
    ll n=s.size(),m=t.size();       
    vector<vl>dp(n+1,vl(m+1,0));
    rep(i,1,n+1){
        rep(j,1,m+1){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    ll ans=dp[n][m];
    string str(ans,' ');
    ll i=n,j=m;
    while(i>0&&j>0){
        if(s[i-1]==t[j-1]){
            str[ans-1]=s[i-1];
            i--,j--,ans--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<str<<'\n';
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
