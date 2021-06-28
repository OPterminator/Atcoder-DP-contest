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
void run_test(){
    int n,w;
    cin>>n>>w;
    vl dp(w+1);
    //0---w
    for(int i=0;i<n;i++){
        int weight,value;
        cin>>weight>>value;
        for(int j=w-weight;j>=0;j--){
            dp[j+weight]=max(dp[j+weight],dp[j]+value);
        }
    }
    ll ans=0;
    for(int i=0;i<=w;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<'\n';
}
int main(int argc, char const *argv[]) 
{
    clock_t begin = clock();
    fastio;
    int tt=1;
    // cin>>tt;
    while(tt--)
    {
        run_test();
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
