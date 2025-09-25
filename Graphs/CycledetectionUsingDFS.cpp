#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>> AdjList;
    public:
     void add_edge(int u,int v){
        AdjList[u].push_back(v);
     }

     bool DFS(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &recstack){
        visited[node] = true;
        recstack[node] = true;
        for(int neighbour:AdjList[node]){
            if(!visited[neighbour]){
                if(DFS(neighbour,visited,recstack)){
                    return true;
                }
            }else if(recstack[neighbour]){
                //back edge found
                return true;
            }
        }
        recstack[node] = false;
        return false;
     }
     bool iscyclic(){
        unordered_map<int,bool> visited;
        unordered_map<int,bool> recstack;
        for(auto i:AdjList){
            int node = i.first;
            if(!visited[node]){
                if(DFS(node,visited,recstack)){
                    return true;
                }
            }
        }
        return false;
     }
};
int main(){
    Graph g;
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(0,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    cout<<g.iscyclic()<<endl;
    return 0;
    
}