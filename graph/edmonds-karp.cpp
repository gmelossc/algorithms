#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n;
vector<vector<int>> adj, capacity;

int bfs(int source, int sink, vector<int> &parent) {
    for(int &x : parent) x = -1;
    parent[source] = 0;
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

int maxFlow(int source, int sink) {
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow = 0;

    while(new_flow = bfs(source, sink, parent)) {
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


int main() {

    cin >> n;
    adj.assign(n+1, vector<int>());
    capacity.assign(n+1, vector<int>(n+1));

    int m;
    cin >> m;
    for(int i=0; i<m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        capacity[u][v] = c;
    }

    cout << maxFlow(1, n) << endl;

    return 0;
}