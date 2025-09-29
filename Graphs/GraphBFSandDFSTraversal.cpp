#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>> AdjList;
    public:
     void add_edge(int u,int v){
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
     }
     
     void DfsHelper(int node,unordered_set<int> &visited){
        cout<<node<<" ";
        visited.insert(node);
        for(auto i:AdjList[node]){
            if(visited.find(i) == visited.end()){
                DfsHelper(i,visited);
            }
        }
     }
     void DFS(int start){
        unordered_set<int> visited;
        cout<<"dfs traversal"<<endl;
        DfsHelper(start,visited);
        cout<<endl;
     }

     void BFS(int start){
        cout<<"BFS traversal:"<<endl;
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int i:AdjList[node]){
                if(visited.find(i) == visited.end()){
                    q.push(i);
                    visited.insert(i);
                }
            }
        }
     }
     
};
int main(){
    Graph g;
    g.add_edge(1,0);
    g.add_edge(2,0);
    g.add_edge(1,2);
    g.add_edge(3,0);
    g.DFS(1);
    g.BFS(1);
}