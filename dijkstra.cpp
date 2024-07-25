#include<bits/stdc++.h>
using namespace std;


#define pp pair<int,int>

void dijkstra(int V,int src,vector<vector<pp>>& graph,vector<int>& dist){

    vector<int> visited(V,0);

    dist.clear();
    dist.resize(V,1e9);

    priority_queue<pp,vector<pp>,greater<pp>> pq;//{cost,vertex}

    pq.push({0,src});
    dist[src] = 0;

    while(pq.size()){
        auto curr = pq.top();
        pq.pop();

        if(visited[curr.second]==1) continue;

        visited[curr.second] = 1;
        
        for(auto neigh : graph[curr.second]){
            int edgeWeight = neigh.second;
            if(dist[neigh.first] > dist[curr.second] + edgeWeight){
                dist[neigh.first]  = dist[curr.second] + edgeWeight;
                pq.push({dist[neigh.first],neigh.first});
            }
        }
    }

}


int main(){

    int V,E;
    cin >> V >> E; //V-> no. of vertices, E -> no. of Edges

    vector<vector<pp>> graph(V,vector<pp>());

    for(int i=0;i<E;i++){
        int u,v,c;
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
    }

    int src = 0;
    vector<int> dist;

    dijkstra(V,src,graph,dist);

    cout << "{ ";
    for(int i=0;i<V;i++){
        cout << i << " : " << dist[i] << ", ";
    }
    cout << "}";

    return 0;
}