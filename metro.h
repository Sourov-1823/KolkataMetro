#ifndef METRO_H
#define METRO_H

#include <vector>
#include <string>
#include <map>
using namespace std;

struct Edge {
    int to;
    double weight;
};

class KolkataMetro {
private:
    map<std::string, int> stationToId;
    vector<std::string> idToStation;
    vector<std::vector<Edge>> adj;
    int stationCount;

    void printPath(const std::vector<int>& parent, int j);

public:
    KolkataMetro();
    void addStation(std::string name);
    void addConnection(std::string u, std::string v, double dist);
    void findShortestPath(std::string startNode, std::string endNode);
};

#endif