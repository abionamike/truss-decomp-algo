#include "EdgeListLoader.h"
#include "KTruss.h"
#include <fstream>
#include <sstream>
#include <iostream>

void loadEdgeList(const std::string& filename, KTruss& kt) {
  std::ifstream fin(filename);
  if (!fin) {
    throw std::runtime_error("Cannot open edge list file");
  }

  std::string line;
  int u, v;
  int edges = 0;

  while (std::getline(fin, line)) {
    if (line.empty() || line[0] == '#') continue;

    std::stringstream ss(line);
    ss >> u >> v;

    kt.addEdge(u, v);
    edges++;
  }

  std::cout << "Loaded " << edges << " edges\n";
}
