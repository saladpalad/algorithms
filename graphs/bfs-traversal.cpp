/*
Implementation of BFS-Traversal
Time Complexity: O(m+n)
Ch. 3.2 - 3.3
*/

#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

template <typename T> class Graph {
  std::vector<std::vector<T>> adjList;
  std::vector<bool> discovered;

public:
  explicit Graph(size_t n) : adjList(n), discovered(n, false) {}

  void addEdge(T u, T v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Comment this line for undirected graph
  }

  void BFS(T s) {
    std::queue<T> q;
    discovered[s] = true;
    q.push(s);

    int currentLayer = 0;

    while (!q.empty()) {
      int layerSize = q.size();

      std::cout << "Layer " << currentLayer << ": ";
      for (int i = 0; i < layerSize; ++i) {
        T u = q.front();
        q.pop();

        std::cout << u << " ";

        for (T v : adjList.at(u)) {
          if (!discovered[v]) {
            discovered[v] = true;
            q.push(v);
          }
        }
      }
      std::cout << std::endl;
      currentLayer++;
    }
  }
};

int main() {
  Graph<int> g(6);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(3, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 5);

  std::cout << "BFS Traversal starting from vertex 0: " << std::endl;
  g.BFS(0);

  return 0;
}
