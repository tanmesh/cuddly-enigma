//
// Created by Tanmesh on 22/07/18.
//

#include <iostream>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <math.h>
#include <limits.h>
// #include <bits/stdc++.h>

using namespace std;

vector<int> edges[1000];
int visited[1000];
int v, e;
set<int> node_visited;

bool if_present_in_stack(int i) {
    return node_visited.find(i) != node_visited.end();
}

bool dfs(int node) {
    if(visited[node]) {
        return false;
    }
    visited[node] = true;
    node_visited.insert(node);
    for(const auto& it : edges[node]) {
        if(visited[it] && if_present_in_stack(it)) {
            return true;
        }
        else{
            return dfs(it);
        }
    }
    node_visited.erase(node);
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int n, m;
        cin >> n >> m;
        edges[n].push_back(m);
    }
    for(int i=0; i<v; ++i) {
        if(!visited[i] && dfs(i)) {
            cout << "CYCLE PRESENT\n";
            return 0;
        }
    }
    cout << "CYCLE NOT PRESENT\n";
    return 0;
}