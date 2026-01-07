#include <iostream>
#include <string>
#include "KTruss.h"
#include "EdgeListLoader.h"

int main(int argc, char* argv[]) {
  // Check if the user provided a path
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <path_to_edge_list_file>" << std::endl;
    return 1; // exit with error
  }

  std::string dataPath = argv[1];

  // Number of vertices known from SNAP metadata
  int n = 100000000;
  KTruss kt(n);

  // Load the edge list from the file path provided by the user
  loadEdgeList(dataPath, kt);

  kt.decompose();

  return 0;
}
