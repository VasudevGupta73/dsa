//kahn algorithm is a method for performing topological sorting on a directed acyclic graph (DAG). 
//It works by repeatedly removing nodes with no incoming edges and adding 
//them to the sorted list. Here's an implementation of Kahn's algorithm for topological sorting using BFS in C++14:
// algorithm is applied to DAG
// uses indegree concept to find the nodes with no incoming edges and then we remove those
// nodes and update the indegree of the adjacent nodes and repeat the process until all the nodes are processed.
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> indegree;
    queue<int> q;
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
}
// here no need to use the check about the component since we are using the indegree concept and if there is a cycle in the graph then we will not be able to process all the nodes and the size of the topo vector will be less than V.