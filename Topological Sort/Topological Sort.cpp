// Author: Abdallah Hemdan
// Title: Topological Sort

/**
 * Sorts the graph in a topological order using Khan BFS algorithm,
 * and fills the result in the global "sortedNodes" vector.
 *
 * Note that it works correctly with Directed Acyclic Graphs (DAGs).
 *
 * Complexity: O(n+m)
 */
void topoSortBFS() {
    queue<int> q;
    vector<int> inDeg(n + 1, 0);

    // Compute the in degree of each node
    // (i.e. the number of in-edges towards node "u")
    for (int i = 1; i <= n; ++i) {
        for (int v : edges[i]) {
            ++inDeg[v];
        }
    }

    // Push all nodes with zero in degree in the queue
    for (int i = 1; i <= n; ++i) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        sortedNodes.push_back(u);

        for (int v : edges[u]) {
            if (--inDeg[v] == 0) {
                q.push(v);
            }
        }
    }
}
