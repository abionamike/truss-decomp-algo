#ifndef EDGE_LIST_LOADER_H
#define EDGE_LIST_LOADER_H

#include <string>
#include <vector>

int loadEdgeListAndRemap(
  const std::string& filename,
  std::vector<std::pair<int,int>>& edges
);

#endif
