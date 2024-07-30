#include "directedgraph.h"
using namespace std;
template<typename T, int numberOfNodes>
DirectedGraph<T,numberOfNodes>::DirectedGraph(){}

template<typename T, int numberOfNodes>
DirectedGraph<T, numberOfNodes>::DirectedGraph(const DirectedGraph<T,numberOfNodes>& graph){
	nodes = graph.nodes;
	adjacencyMatrix = graph.adjacencyMatrix;
}

template<typename T, int numberOfNodes>
void DirectedGraph<T, numberOfNodes>::insertNode(const T& node, std::vector<std::pair<T, T>>adjacentNodes){
	for(int i=0;i<nodes.size();i++)
		if (nodes[i] == node) {
			cout << "This node is already available." << endl;
			return;
		}
	nodes.push_back(node);
	for (int i = 0; i < adjacentNodes.size(); i++) {
		insertEdge(adjacentNodes[i].first, adjacentNodes[i].second);
	}
}

template<typename T, int numberOfNodes>
void DirectedGraph<T, numberOfNodes>::insertEdge(const T& begin, const T& end){
	int matrixI = -1, matrixJ = -1, i;
	for (i = 0; i < nodes.size(); i++)
		if (nodes[i] == begin)
			matrixI = i;
		else if (nodes[i] == end)
			matrixJ = i;
		else if (matrixI != -1 && matrixJ != -1)
			break;
	if (matrixI == -1 || matrixJ == -1) {
		cout << "Such nodes not found." << endl;
		return;
	}
	adjacencyMatrix[matrixI][matrixJ] += 1;
}

template<typename T, int numberOfNodes>
void DirectedGraph<T, numberOfNodes>::removeEdge(const T& begin, const T& end){
	int matrixI = -1, matrixJ = -1, i;
	for (i = 0; i < nodes.size(); i++)
		if (nodes[i] == begin)
			matrixI = i;
		else if (nodes[i] == end)
			matrixJ = i;
		else if (matrixI != -1 && matrixJ != -1)
			break;
	if (matrixI == -1 || matrixJ == -1) {
		cout << "No such nodes were found." << endl;
		return;
	}
	if (adjacencyMatrix[matrixI][matrixJ] > 0)
		adjacencyMatrix[matrixI][matrixJ] -= 1;
	else cout << "No such edge was found." << endl;
}

template<typename T, int numberOfNodes>
void DirectedGraph<T, numberOfNodes>::removeNode(const T& node){
	int removedIndex = -1;
	for (int i = 0; i < nodes.size(); i++)
		if (nodes[i] == node) {
			removedIndex = i;
			break;
		}
	nodes.erase(nodes.begin() + removedIndex);
	adjacencyMatrix.erase(adjacencyMatrix.begin() + removedIndex);
	for (int i = 0; i < adjacencyMatrix.size(); i++)
		adjacencyMatrix[i].erase(adjacencyMatrix[i].begin() + removedIndex);
}

template<typename T, int numberOfNodes>
void DirectedGraph<T, numberOfNodes>::removeNode(const T* node){
	int removedIndex = node - nodes.begin();
	removeNode(nodes[removedIndex]);
}

template<typename T, int numberOfNodes>
const T* DirectedGraph<T, numberOfNodes>::findPointer(const T& node){
	for (int i = 0; i < nodes.size(); i++)
		if (nodes[i] == node) {
			return &nodes[i];
		}
	return nullptr;
}

template<typename T, int numberOfNodes>
int DirectedGraph<T, numberOfNodes>::findIndex(const T& node) {
	for (int i = 0; i < nodes.size(); i++)
		if (nodes[i] == node) {
			return i;
		}
	return -1;//if the desired node not found returns the index -1 else returns the index of desired node
}

template<typename T, int numberOfNodes>
DirectedGraph<T,numberOfNodes>& DirectedGraph<T, numberOfNodes>::operator=(const DirectedGraph<T,numberOfNodes>& graph){
	nodes = graph.nodes;
	adjacencyMatrix = graph.adjacencyMatrix;
	return *this;
}

template<typename T, int numberOfNodes>
ostream& operator<<(ostream& out, const DirectedGraph<T, numberOfNodes>& graph) {
	for (int i = 0; i < graph.nodes.size(); i++) {
		out << "Node " << i + 1 << ": " << graph.nodes[i];
		out << "The output edges from node " << i + 1 << ": " << endl;
		for (int j = 0; j < numberOfNodes; j++) {
			if (graph.adjacencyMatrix[i][j] != 0) {
				out << "Edge " << j + 1 << ":  " << graph.nodes[i] << ":" << graph.nodes[j]
					<< " " << graph.adjacencyMatrix[i][j] << " times" << endl;
			}
		}
	}
	return out;
}

