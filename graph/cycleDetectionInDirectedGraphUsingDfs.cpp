#include<bits/stdc++.h>
using namespace std;

bool iscyclicdfs(int node,int parent,unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& visited, unordered_map<int,bool>& recstack){

    visited[node]=true;
    recstack[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(iscyclicdfs(it,node,adj,visited,recstack)) return true;
        }
        else if(recstack[it]) return true;
        
    }
    recstack[node]=false;
    return false;
}
int main(){
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> recstack;
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle=false;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(iscyclicdfs(i,-1,adj,visited,recstack)){
                cycle=true;
                break;
            }
        }
    }
    if(cycle) cout<<"Cycle Detected"<<endl;
    else cout<<"No Cycle Detected"<<endl;
}