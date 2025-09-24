#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>> AdjList;
    public:
     void add_edge(int u,int v){
        AdjList[u].push_back(v);
     }

     void Kahn_topo_sort(){
        //step-1 : calculate in-degree of nodes
        map<int,int> in_degree; //for in degree
        //in-degree of nodes
        for(auto i:AdjList){
            int u = i.first;
            for(auto v:AdjList[u]){
                in_degree[v]++; 
            //in-degree of neighbouring vertices
            }
            if(in_degree.find(u) == in_degree.end()){
                in_degree[u] = 0; //ensure all nodes are in map
            }
        }

        //step-2 : push nodes with in_degree 0 in queue
        queue<int> q;
        for(auto i:in_degree){
            if(i.second == 0){
                q.push(i.first);
            }
        }

        //step-3: process the queue and store result in topo order vector
        vector<int> topo_order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo_order.push_back(node);
            for(int neighbour:AdjList[node]){
                in_degree[neighbour]--;
                if(in_degree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        //step-4 : check for a cycle
        if(topo_order.size() != AdjList.size()){
            cout<<"cycle detected"<<endl;
        }else{
            cout<<"topological sort"<<endl;
            for(auto node:topo_order){
                cout<<node<<" ";
            }
            cout<<endl;
        }
     }
};
int main(){
    Graph g;
    g.add_edge(5,0);
    g.add_edge(5,2);
    g.add_edge(2,3);
    g.add_edge(3,1);
    g.add_edge(4,1);
    g.add_edge(4,0);
    g.Kahn_topo_sort();
    return 0;
}