#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;


struct EdmondsKarp { 
    int n, source, sink;
    vector<vector<int>> adj, capacity;

    EdmondsKarp(int _n, int _source, int _sink) : n(_n), source(_source), sink(_sink) {
        adj.assign(n, vector<int>());
        capacity.assign(n, vector<int>(n));
    };

    void addEdge(int from, int to, int cap) {
        adj[from].push_back(to);
        capacity[from][to] += cap;
    }

    int bfs(vector<int> &parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        queue<pair<int,int>> q;
        q.push({source, INF});

        while(!q.empty()) {
            int curr = q.front().first;
            int flow = q.front().second;
            q.pop();

            for(auto to : adj[curr]) {
                // not visited and has some remaining space
                if(parent[to] == -1 and capacity[curr][to]) {
                    parent[to] = curr;
                    int new_flow = min(flow, capacity[curr][to]);
                    if(to == sink) {
                        return new_flow;
                    }
                    q.push({to, new_flow});
                }
            }
        }
        // sink never reached
        return 0;
    }

    int maxFlow() {
        int flow = 0;
        vector<int> parent(n+1);
        int new_flow = 0;

        while(new_flow = bfs(parent)) {
            flow += new_flow;
            int curr = sink;
            while(curr != source) {
                int prev = parent[curr];
                capacity[prev][curr] -= new_flow;
                capacity[curr][prev] += new_flow;
                curr = prev;
            }
        }
        return flow;
    }
};


int main() {

    EdmondsKarp graph(5, 0, 4);
    
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 4, 2);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 3);
    graph.addEdge(2, 1, 1);

    cout << graph.maxFlow() << endl;

    return 0;
}