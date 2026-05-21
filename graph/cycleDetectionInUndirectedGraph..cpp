#include<bits/stdc++.h>
using namespace std;
int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V,false);
    bool cycle=false;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            queue<pair<int,int>> q;
            q.push({i,-1});
            visited[i]=true;
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push({it,node});
                    }
                    else if(it!=parent){
                        cycle=true;
                        break;
                    }
                }
                if(cycle) break;
            }
        }
        if(cycle) break;
    }
    if(cycle) cout<<"Cycle Detected"<<endl;
    else cout<<"No Cycle Detected"<<endl;
}