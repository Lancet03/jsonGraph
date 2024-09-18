#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

void from_json(const nlohmann::json& j, Edge& edge) {
    if (j.contains("from") && j.contains("to")) {
        edge.from = j["from"];
        edge.to = j["to"];
    }
    else {
        throw std::invalid_argument("Invalid JSON provided");
    }

    if (j.contains("weight")) {
        edge.weight = j["weight"];
    }
    else {
        edge.weight = 1;
    }
}

void from_json(const nlohmann::json& j, Vertex& vertex) {

}

void from_json(const nlohmann::json& j, Graph& graph)
{
    if (j.contains("name")) {
        graph.name = j["name"];
    }
    else {
        graph.name = "";
    }
    
    graph.edges = j["edges"].get<std::vector<Edge>>();
    graph.vertex = j["vertex"].get<std::vector<Vertex>>();
}

void to_json(nlohmann::json& j, const Edge& edge) {
    j = {
        { "from", edge.from },
        { "to", edge.to },
        { "weight", edge.weight }
    };
}

void to_json(nlohmann::json& j, const Vertex& vertex) {
    j = {
        { "id", vertex.id },
        { "name", vertex.name }
    };
}

void to_json(nlohmann::json& j, const Graph& graph)
{
    j = {
        { "edges", graph.edges },
        { "vertex", graph.vertex },
        { "name", graph.name }
    };
}

std::vector<Graph> LoadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file");

    nlohmann::json j;
    file >> j;

    return j.get<std::vector<Graph>>();
}

void PrintBooksList(const std::vector<Graph>& books)
{
    for (const auto& book : books)
    {
        /*std::cout << "Author: " << book.author << std::endl
            << "Title: " << book.title << std::endl
            << "Pages: " << book.pages << std::endl
            << "Shelf: " << book.shelf << std::endl
            << "=================" << std::endl;*/
    }
}

int main()
{
    Graph graph;
    graph.name = "G";
    graph.edges = std::vector<Edge>{ {1, 2, 1} };
    graph.vertex = std::vector<Vertex>{ {1, "a"}, {2, "b"} };

    try
    {
        auto books = LoadFromFile("books.json");
        PrintBooksList(books);
    }
    catch (std::exception e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    int n;
    std::cin >> n;
}