#ifndef KTRUSS_H
#define KTRUSS_H

#include <vector>
#include <unordered_set>
#include <unordered_map>

class KTruss {
public:
  // ✅ THIS IS THE FIX
  explicit KTruss(int numVertices);

  void addEdge(int u, int v);
  void decompose();

private:
  int n;  // number of vertices

  // adjacency list
  std::vector<std::unordered_set<int>> adj;

  // support of each edge (u,v) stored as u < v
  std::unordered_map<long long, int> support;

  long long edgeKey(int u, int v);
};

#endif
