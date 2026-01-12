#include "KTruss.h"
#include "EdgeListLoader.h"
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage: ./ktruss graph.txt\n";
    return 1;
  }

  std::vector<std::pair<int,int>> edges;
  int n = loadEdgeListAndRemap(argv[1], edges);

  KTruss kt(n);

  for (auto &e : edges) {
    kt.addEdge(e.first, e.second);
  }

  kt.decompose();
  return 0;
}
