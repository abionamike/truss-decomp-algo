#include "Graph.h"

void Graph::addEdge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

void Graph::removeEdge(int u, int v) {
    adj[u].erase(v);
    adj[v].erase(u);
}

bool Graph::hasEdge(int u, int v) const {
    return adj.count(u) && adj.at(u).count(v);
}
