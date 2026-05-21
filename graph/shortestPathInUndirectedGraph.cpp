// algorithm
// here we will be using bfs to find the shortest path in an undirected graph
// we also use parent array to keep track of the parent of each node and at the end we will be backtracking from the destination node to the source node using the parent array to find the path and also we will be counting the number of edges in the path to find the distance.
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
    int src,dest;
    cin>>src>>dest;
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    queue<int> q;
    q.push(src);
    visited[src]=true;
    bool found=false;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==dest){
            found=true;
            break;
        }
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=true;
                parent[it]=node;
                q.push(it);
            }
        }
    }
    if(found){
        vector<int> path;
        int node=dest;
        while(node!=-1){
            path.push_back(node);
            node=parent[node];
        }
        reverse(path.begin(),path.end());
        cout<<"Shortest Path: ";
        for(auto it:path){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<"Distance: "<<path.size()-1<<endl; // number of edges in the path
    }
    else{
        cout<<"No Path Found"<<endl;
    }
}