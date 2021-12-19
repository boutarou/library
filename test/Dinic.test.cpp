#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
#include <iostream>
#include <vector>
#include "../graph/Dinic.cpp"

int main() {
    int V, E;
    std::cin >> V >> E;
    Dinic<int> graph(V);
    for(int i = 0; i < E; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        graph.add_edge(u, v, c);
    }
    std::cout << graph.max_flow(0, V - 1) << std::endl;
    return 0;
}