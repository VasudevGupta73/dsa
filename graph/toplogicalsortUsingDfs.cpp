// applied to dag
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& visited,stack<int>& st){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,st);
        }
    }
    st.push(node);
}
int main(){
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> visited;
    stack<int> st;
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
} 
// sol when ever we return ed from the dfs call we push the node in stack and at the end we pop all the elements from stack and print them.