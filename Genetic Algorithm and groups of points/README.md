# Genetic Algorithm for Optimal Point Clustering  

## Overview  
This project implements a **Genetic Algorithm (GA)** to find an optimal grouping of points in a 2D space, minimizing the **average sum of distances** between points in each group. The goal is to achieve a clustering where points within the same group are as close as possible.  

## Features  
- Uses a **genetic algorithm** for optimization  
- Customizable number of **clusters and points**  
- Supports **mutation and crossover** to explore better solutions  
- Written in **C++** for high performance  

## Installation & Usage  
### Prerequisites  
- C++ compiler (GCC, Clang, MSVC, etc.)  
- CMake (optional, for easy building)  

### Compilation  
```sh
g++ -o clustering main.cpp
./clustering
```
or using CMake:  
```sh
mkdir build && cd build
cmake ..
make
./clustering
```

### Configuration  
Modify parameters inside the source code to adjust:  
- Number of points  
- Number of clusters  
- Genetic algorithm settings (population size, mutation rate, etc.)  

## Algorithm Details  
1. **Initialization**: Generate a random population of cluster assignments.  
2. **Fitness Evaluation**: Compute the average sum of distances within each group.  
3. **Selection**: Choose the best solutions based on fitness.  
4. **Crossover & Mutation**: Create new solutions by recombining and randomly modifying existing ones.  
5. **Iteration**: Repeat until convergence or max iterations reached.  


Let me know if you need any modifications! 🚀
