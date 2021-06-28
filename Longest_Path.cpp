#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
const int nax=(int)1e5+5;
vector<int> graph[nax];
int  dist[nax];
bool vis[nax];
int in_degree[nax];
void dfs(int src){
    assert(!vis[src]);
    vis[src]=1;
    for(auto it:graph[src]){
        dist[it]=max(dist[it],dist[src]+1);
        --in_degree[it];
        if(in_degree[it]==0){
            dfs(it);
        }
    }
}
int main() 
{
    fastio;
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        ++in_degree[y];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&in_degree[i]==0){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dist[i]);
    }
    cout<<ans<<'\n';
return 0;
}
