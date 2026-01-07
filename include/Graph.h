#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>

class Graph {
public:
    std::unordered_map<int, std::unordered_set<int>> adj;

    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool hasEdge(int u, int v) const;
};

#endif
