#pragma once



#include <iostream>
#include <vector>
#include <algorithm>
#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
template<typename T, int numberOfNodes>
class DirectedGraph {
	friend std::ostream& operator<<(std::ostream& out, const DirectedGraph<T, numberOfNodes>& graph);
public:
	DirectedGraph();
	DirectedGraph(const DirectedGraph<T,numberOfNodes>& graph);
	void insertNode(const T& node, std::vector<std::pair<T, T>>adjacentNodes);
	void insertEdge(const T& begin, const T& end);
	void removeEdge(const T& begin, const T& end);
	void removeNode(const T& node);
	void removeNode(const T* node);
	const T* findPointer(const T& node);
	int findIndex(const T& node);
	DirectedGraph<T,numberOfNodes>& operator=(const DirectedGraph<T,numberOfNodes>& graph);
private:
	std::vector<T>nodes{ numberOfNodes };
	std::vector<std::vector<int>> adjacencyMatrix{ numberOfNodes, std::vector<int>(numberOfNodes, 0) };
};
#endif
