# Graph Algorithms and Asymptotic Analysis in C++

This repository contains four independent C++ projects implementing classical graph algorithms and performance analysis methods. Each project is self-contained and demonstrates a specific algorithmic concept, including shortest paths, minimum spanning trees, disjoint-set operations, and asymptotic runtime measurement.

All projects are structured for clarity and simplicity, making them suitable for educational use, algorithm study, or coursework.

---

## 1. Dijkstra – Shortest Path Algorithm

The project implements Dijkstra’s algorithm for finding the shortest path between two vertices in a weighted undirected graph.
The graph is loaded from an input file and represented as a weight matrix.

### Features
- Adjacency matrix representation
- Reconstruction of the shortest path
- Handling unreachable vertices
- Modular structure (Graph + Algorithm)

### Build and Run
Using g++:
```
g++ main.cpp Graph.cpp Dijkstra.cpp -o dijkstra
./dijkstra
```

Using Visual Studio: open solution, build, run.

---

## 2. Kruskal – Minimum Spanning Tree Algorithm

This project implements Kruskal’s MST algorithm with the use of a Disjoint Set Union (DSU) structure utilizing path compression and union by rank.

### Features
- Sorting edges by weight
- Efficient cycle detection via DSU
- Output of MST edges and total weight
- Weight matrix is optional; core algorithm works on edge list

### Build and Run
Using g++:
```
g++ main.cpp Graph.cpp DSU.cpp -o kruskal
./kruskal
```

Using Visual Studio: open solution, build, run.

---

## 3. Prim – Minimum Spanning Tree Algorithm

This project implements Prim’s MST algorithm using a greedy expansion strategy.
The graph is loaded from file and converted into an adjacency matrix.

### Features
- Classical O(n²) implementation
- Selection of minimal edge leading to a new vertex
- Output of MST edges and total weight
- Simple and deterministic structure

### Build and Run
Using g++:
```
g++ main.cpp Graph.cpp Prim.cpp -o prim
./prim
```

Using Visual Studio: open solution, build, run.

---

## 4. Asymptotic Analysis – Runtime Measurement

This project studies empirical runtime behavior by repeatedly executing a nested computation on large matrices.
The program computes geometric means for columns of a lower-triangular matrix and measures total execution time across several runs.

### Features
- Matrix sizes up to 6000×6000
- Five repeated timing measurements
- Geometric mean computation using logarithms
- Demonstration of O(n²) runtime behavior

### Build and Run
Using g++:
```
g++ main.cpp -o asymptotic -O2
./asymptotic
```

Using Visual Studio: open or create a project containing main.cpp, then build and run.

---

## Repository Structure

```
project-root/
│
├── cpp-dijkstra/
│   ├── Graph.* 
│   ├── Dijkstra.*
│   ├── main.cpp
│   └── input.txt
│
├── kruskal-mst-cpp/
│   ├── Graph.*
│   ├── DSU.*
│   ├── Edge.h
│   ├── main.cpp
│   └── input.txt
│
├── prim-mst-cpp/
│   ├── Graph.*
│   ├── Prim.*
│   ├── Edge.h
│   ├── main.cpp
│   └── input.txt
│
└── asymptotic-analysis/
    └── main.cpp
```

---

## General Build Information

All projects can be built with either:
- Visual Studio (.sln files), or
- g++ from command line.

To compile with g++:
```
g++ main.cpp [other-source-files] -o program-name
./program-name
```

To ensure proper execution, place `input.txt` next to the executable in projects where required.

---

## Purpose of the Repository

This repository serves as a compact collection of algorithmic implementations designed for:

- studying graph theory algorithms,
- practicing modular C++ programming,
- comparing MST methods (Prim vs Kruskal),
- analyzing empirical runtime growth,
- preparing lab reports or coursework in algorithms and data structures.
