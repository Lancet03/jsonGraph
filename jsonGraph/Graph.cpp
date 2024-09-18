#include <iostream>

#include "Graph.h"


void Graph::PrintCorrespMatrix() {
	std::vector<std::vector<double>> matrix = this->BuildCorrespMatrix();

	std::cout << "  ";
	for (int i = 0; i < matrix.size(); i++) {
		
		std::cout << this->vertex[i].name << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < matrix.size(); i++) {
		std::cout << this->vertex[i].name << " ";
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


std::vector<std::vector<double>> Graph::BuildCorrespMatrix() {
	int matrixSize = this->vertex.size();
	std::vector<std::vector<double>> matrix;

	for (int i = 0; i < matrixSize; i++) {
		matrix.push_back({});
		for (int j = 0; j < matrixSize; j++) {
			matrix[i].push_back(0);
		}
	}

	for (int i = 0; i < matrixSize; i++) {
		Vertex vertex_i = this->vertex[i];
		
		for (int j = 0; j < matrixSize; j++) {
			Vertex vertex_j = this->vertex[j];
			if (i == 0) {
				matrix[i][j] = this->GetEdgeWeigth(this->vertex[i].id, this->vertex[j].id);
			}
		}
	}

	return matrix;
}

double Graph::GetEdgeWeigth(int from, int to) {
	for (int i = 0; i < this->edges.size(); i++) {
		if (from == this->edges[i].from && to == this->edges[i].to) {
			return this->edges[i].weight;
		}
	}

	return 0;
}