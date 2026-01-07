#include "KTruss.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// ✅ THIS IS WHAT YOU WERE MISSING
KTruss::KTruss(int numVertices) : n(numVertices), adj(numVertices) {}

long long KTruss::edgeKey(int u, int v) {
    if (u > v) swap(u, v);
    return (static_cast<long long>(u) << 32) | v;
}

void KTruss::addEdge(int u, int v) {
    if (u == v) return;
    adj[u].insert(v);
    adj[v].insert(u);
}

void KTruss::decompose() {
    // Step 1: compute initial supports
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            if (u < v) {
                int cnt = 0;
                for (int w : adj[u]) {
                  if (adj[v].count(w)) cnt++;
                }
                support[edgeKey(u, v)] = cnt;
            }
        }
    }

    int k = 3;

    while (!support.empty()) {
        queue<pair<int,int>> q;

        // Step 4: find edges with support < k-2
        for (auto &e : support) {
            int u = e.first >> 32;
            int v = e.first & 0xffffffff;
            if (e.second < k - 2) {
                q.push({u, v});
            }
        }

        if (q.empty()) {
            cout << "k = " << k << " truss edges:\n";
            // for (auto &e : support) {
            //     int u = e.first >> 32;
            //     int v = e.first & 0xffffffff;
            //     cout << "(" << u << "," << v << ")\n";
            // }
            cout << "-----------------\n";
            k++;
            continue;
        }

        // Step 5–8: remove edges
        while (!q.empty()) {
            auto [u, v] = q.front();
            q.pop();

            long long key = edgeKey(u, v);
            if (!support.count(key)) continue;

            for (int w : adj[u]) {
                if (adj[v].count(w)) {
                    long long e1 = edgeKey(u, w);
                    long long e2 = edgeKey(v, w);

                    if (support.count(e1)) {
                        support[e1]--;
                        if (support[e1] < k - 2)
                            q.push({u, w});
                    }
                    if (support.count(e2)) {
                        support[e2]--;
                        if (support[e2] < k - 2)
                            q.push({v, w});
                    }
                }
            }

            adj[u].erase(v);
            adj[v].erase(u);
            support.erase(key);
        }
    }
}
