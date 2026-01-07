#!/bin/bash

# ------------------------------
# Full K-Truss Experiment Script
# ------------------------------
# Usage:
#   ./run_experiment.sh <dataset_file>
# Example:
#   ./run_experiment.sh ../data/sample_graph.txt
# ------------------------------

# Check if dataset path is provided
if [ $# -lt 1 ]; then
    echo "Usage: $0 <path_to_edge_list_file>"
    exit 1
fi

DATA_FILE=$1

# Get project root (assumes this script is in experiments/)
PROJECT_ROOT=$(dirname "$(realpath "$0")")/..

# Step 1: Create build folder if it doesn't exist
mkdir -p "$PROJECT_ROOT/build"
cd "$PROJECT_ROOT/build" || exit

# Step 2: Run CMake to generate Makefiles
cmake ..

# Step 3: Build the executable
make

# Step 4: Ensure output folder exists
mkdir -p "$PROJECT_ROOT/output"

# Step 5: Extract filename for output naming
FILE_NAME=$(basename "$DATA_FILE" .txt)

# Step 6: Run the executable with dataset and save output
./ktruss "$PROJECT_ROOT/$DATA_FILE" > "$PROJECT_ROOT/output/${FILE_NAME}_ktruss_output.txt"

echo "Experiment finished. Output saved in output/${FILE_NAME}_ktruss_output.txt"
