#pragma once

#include <set>
#include <map>
#include <iterator>

template<typename KT, typename ET>
class DiGraph {
private:
    std::map<KT, std::map<KT, ET>> graph;
    size_t V;
    size_t E;

public:
    DiGraph() : V(0), E(0) {}

    void addNode(KT v) {
        std::map<KT, ET> neighbors;
        graph.insert({v, neighbors});
        V++;
    }

    void removeNode(KT v) {
        graph.erase(v);
        V--;
    }

    bool hasNode(KT v) {
        return (bool)graph.count(v);
    }

    void addEdge(KT v, KT u, ET e) {
        auto& v_neighbors = graph.at(v);
        v_neighbors[u] = e;
        E++;
    }

    void removeEdge(KT v, KT u) {
        auto& v_neighbors = graph.at(v);
        v_neighbors.erase(u);
        E--;
    }

    bool hasEdge(KT v, KT u) {
        if (graph.count(v)) {
            auto& v_neighbors = graph.at(v);
            return (bool) v_neighbors.count(u);
        }
        return false;
    }

    ET getValue(KT v, KT u) {
        auto& v_neighbors = graph.at(v);
        return v_neighbors.at(u);
    }

    size_t getOrder() {
        return V;
    }
    size_t getSize() {
        return E;
    }

    size_t neighborCount(KT v) {
        return graph.at(v).size();
    }

    typename std::map<KT, ET>::iterator begin(KT v) {
        auto& neighbors = graph.at(v);
        return neighbors.begin();
    }

    typename std::map<KT, ET>::iterator end(KT v) {
        auto& neighbors = graph.at(v);
        return neighbors.end();
    }

    typename std::map<KT, std::map<KT, ET>>::iterator begin() {
        return graph.begin();
    }

    typename std::map<KT, std::map<KT, ET>>::iterator end() {
        return graph.end();
    }
};