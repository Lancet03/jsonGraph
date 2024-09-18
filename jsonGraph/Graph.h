#pragma once
#include <vector>
#include <string>

#include "Edge.h"
#include "Vertex.h"

class Graph {
public:
    std::vector<Edge> edges;
    std::vector<Vertex> vertex;
    std::string name;

    //Graph();
    virtual ~Graph() {};
    void PrintCorrespMatrix();
    std::vector<std::vector<double>> BuildCorrespMatrix();

    void SetVertex(std::vector<Vertex> vertex) { this->vertex = vertex; }
    void SetEdges(std::vector<Edge> edges) { this->edges = edges; }
    void SetName(std::string name) { this->name = name; }

    std::vector<Vertex> GetVertex() { return this->vertex; };
    std::vector<Edge> GetEdges() { return this->edges; };
    std::string GetName() { return this->name; }
private:
    double GetEdgeWeigth(int from, int to);
};
