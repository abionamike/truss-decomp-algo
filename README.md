# **K-Truss Decomposition Experiment**

## **Project Overview**

This project implements the **k-truss decomposition** algorithm in C++ for analyzing large graphs.
The k-truss of a graph is a subgraph in which each edge is part of at least *(k-2)* triangles. This experiment allows testing the algorithm on different datasets and generating k-truss decomposition results.

The project is structured to support **large-scale graphs** and **configurable datasets** without modifying the source code.

---

## **Project Structure**

```
MyExperimentProject/
│
├── src/               # All C++ source files
│   ├── main.cpp       # Program entry point
│   ├── KTruss.cpp     # K-Truss algorithm implementation
│   ├── Graph.cpp      # Graph data structures and utilities
│   └── EdgeListLoader.cpp # Functions to read datasets
│
├── include/           # Header files
│   ├── KTruss.h
│   ├── Graph.h
│   └── EdgeListLoader.h
│
├── data/              # Graph datasets
│   └── sample_graph.txt
│
├── experiments/       # Experiment scripts or configs
│   └── run_ktruss.sh  # Script to build and run experiments
│
├── build/             # Build output (ignored by version control)
│
├── output/            # Decomposition results and logs
│
├── CMakeLists.txt     # CMake build configuration
└── README.md
```

---

## **Prerequisites**

* macOS, Linux, or Windows environment
* **C++17** compatible compiler (e.g., `g++`, `clang++`)
* **CMake** (minimum version 3.10)

### **Check CMake installation**

```bash
cmake --version
```

If not installed, use Homebrew (macOS) or your package manager:

```bash
brew install cmake
```

---

## **Building and Running Experiments**

We provide a **fully automated script** `run_ktruss.sh` to handle building the project and running experiments on a dataset.

### **Usage**

```bash
./experiments/run_ktruss.sh <path_to_edge_list_file>
```

**Example:**

```bash
./experiments/run_ktruss.sh ../data/sample_graph.txt
```

What happens when you run the script:

1. Creates the `build/` folder (if it doesn’t exist).
2. Runs **CMake** to generate Makefiles.
3. Compiles the project into the `ktruss` executable.
4. Runs `ktruss` with the dataset you provide.
5. Saves the output automatically in the `output/` folder with a descriptive filename:

   ```
   output/sample_graph_ktruss_output.txt
   ```

---

## **Input Data Format**

* The program expects the dataset as a text file containing an **edge list**.
* Each line represents an edge as two vertex IDs, separated by a space:

```
1 2
1 3
2 3
...
```

---

## **Output**

* Decomposes the graph into **k-truss levels**.
* Outputs results to the `output/` folder.
* Can be further processed for visualization or analysis using Python, R, or other tools.


---

## **Notes**

* The number of vertices (`n`) is currently hardcoded for SNAP datasets but can be easily made configurable.
* Designed for **large-scale graphs**; ensure your system has sufficient memory for very large datasets.

---

## **References**

* [SNAP Datasets](http://snap.stanford.edu/data/)
* VLDB 2022 paper: *Efficient Triangle-Connected Truss Community Search in Dynamic Graphs*
