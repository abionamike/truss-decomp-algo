#include "EdgeListLoader.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <stdexcept>

int loadEdgeListAndRemap(
  const std::string& filename,
  std::vector<std::pair<int,int>>& edges
) {
  std::ifstream fin(filename);
  if (!fin) throw std::runtime_error("Cannot open file");

  std::unordered_map<int,int> id;
  int next = 0;

  std::string line;
  int u, v;

  while (std::getline(fin, line)) {
    if (line.empty() || line[0] == '#') continue;

    std::stringstream ss(line);
    ss >> u >> v;

    if (!id.count(u)) id[u] = next++;
    if (!id.count(v)) id[v] = next++;

    edges.emplace_back(id[u], id[v]);
  }

  return next;  // exact number of vertices
}
