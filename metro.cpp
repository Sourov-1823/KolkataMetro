#include "metro.h"
#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;

const double INF = 1e9;

KolkataMetro::KolkataMetro() : stationCount(0) {}

void KolkataMetro::addStation(string name) {
    if (stationToId.find(name) == stationToId.end()) {
        stationToId[name] = stationCount++;
        idToStation.push_back(name);
        adj.push_back({});
    }
}

void KolkataMetro::addConnection(string u, string v, double dist) {
    addStation(u);
    addStation(v);
    int idU = stationToId[u], idV = stationToId[v];
    adj[idU].push_back({idV, dist});
    adj[idV].push_back({idU, dist});
}

void KolkataMetro::findShortestPath(string startNode, string endNode) {
    if (stationToId.find(startNode) == stationToId.end() ||
        stationToId.find(endNode) == stationToId.end()) {
        cout << "Error: Station not found in database.\n";
        return;
    }

    int src = stationToId[startNode], dest = stationToId[endNode];
    vector<double> dist(stationCount, INF);
    vector<int> parent(stationCount, -1);

    priority_queue<
        pair<double, int>,
        vector<pair<double, int>>,
        greater<pair<double, int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        double d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                parent[edge.to] = u;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    cout << "\nShortest Distance: "
         << fixed << setprecision(2)
         << dist[dest] << " km\nRoute: ";
    printPath(parent, dest);
    cout << "\n";
}

void KolkataMetro::printPath(const vector<int>& parent, int j) {
    if (parent[j] == -1) {
        cout << idToStation[j];
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << idToStation[j];
}



int main() {
    KolkataMetro km;

    // --- BLUE LINE (North-South: Dakshineswar to Kavi Subhash) ---
    km.addConnection("Dakshineswar", "Baranagar", 2.3);
    km.addConnection("Baranagar", "Noapara", 2.4);
    km.addConnection("Noapara", "Dum Dum", 2.1);
    km.addConnection("Dum Dum", "Belgachia", 2.2);
    km.addConnection("Belgachia", "Shyambazar", 1.6);
    km.addConnection("Shyambazar", "Shobhabazar Sutanuti", 1.1);
    km.addConnection("Shobhabazar Sutanuti", "Girish Park", 1.0);
    km.addConnection("Girish Park", "Mahatma Gandhi Road", 0.9);
    km.addConnection("Mahatma Gandhi Road", "Central", 0.8);
    km.addConnection("Central", "Chandni Chowk", 0.7);
    km.addConnection("Chandni Chowk", "Esplanade", 0.7); // INTERCHANGE
    km.addConnection("Esplanade", "Park Street", 0.8);  // INTERCHANGE
    km.addConnection("Park Street", "Maidan", 0.7);
    km.addConnection("Maidan", "Rabindra Sadan", 1.0);
    km.addConnection("Rabindra Sadan", "Netaji Bhavan", 1.1);
    km.addConnection("Netaji Bhavan", "Jatin Das Park", 0.8);
    km.addConnection("Jatin Das Park", "Kalighat", 0.7);
    km.addConnection("Kalighat", "Rabindra Sarobar", 1.2);
    km.addConnection("Rabindra Sarobar", "Mahanayak Uttam Kumar", 1.3);
    km.addConnection("Mahanayak Uttam Kumar", "Netaji", 1.2);
    km.addConnection("Netaji", "Masterda Surya Sen", 1.1);
    km.addConnection("Masterda Surya Sen", "Gitanjali", 1.2);
    km.addConnection("Gitanjali", "Kavi Nazrul", 1.2);
    km.addConnection("Kavi Nazrul", "Shahid Khudiram", 1.1);
    km.addConnection("Shahid Khudiram", "Kavi Subhash", 1.3); // INTERCHANGE

    // --- GREEN LINE (East-West: Howrah Maidan to Salt Lake Sector V) ---
    km.addConnection("Howrah Maidan", "Howrah", 1.2);
    km.addConnection("Howrah", "Mahakaran", 1.5);
    km.addConnection("Mahakaran", "Esplanade", 1.3); // INTERCHANGE
    km.addConnection("Esplanade", "Sealdah", 2.2);
    km.addConnection("Sealdah", "Phoolbagan", 2.1);
    km.addConnection("Phoolbagan", "Salt Lake Stadium", 1.4);
    km.addConnection("Salt Lake Stadium", "Bengal Chemical", 1.1);
    km.addConnection("Bengal Chemical", "City Centre", 1.1);
    km.addConnection("City Centre", "Central Park", 1.0);
    km.addConnection("Central Park", "Karunamoyee", 1.1);
    km.addConnection("Karunamoyee", "Salt Lake Sector V", 1.0);

    // --- PURPLE LINE (Joka to Majerhat segment) ---
    km.addConnection("Joka", "Thakurpukur", 1.4);
    km.addConnection("Thakurpukur", "Sakherbazar", 1.2);
    km.addConnection("Sakherbazar", "Behala Chowrasta", 1.1);
    km.addConnection("Behala Chowrasta", "Behala Bazar", 1.3);
    km.addConnection("Behala Bazar", "Taratala", 1.2);
    km.addConnection("Taratala", "Majerhat", 1.1);

    // --- ORANGE LINE (Kavi Subhash to Hemanta Mukhopadhyay) ---
    km.addConnection("Kavi Subhash", "Satyajit Ray", 1.6); // INTERCHANGE
    km.addConnection("Satyajit Ray", "Jyotirindra Nandi", 1.2);
    km.addConnection("Jyotirindra Nandi", "Kavi Sukanta", 1.3);
    km.addConnection("Kavi Sukanta", "Hemanta Mukhopadhyay", 1.2);

    // User Interface
    string start, end;
    cout << "========================================\n";
    cout << "   KOLKATA METRO ROUTE FINDER (DSA)     \n";
    cout << "========================================\n";
    cout << "Available Interchanges: Esplanade, Central, Kavi Subhash\n\n";
    
    cout << "Enter Starting Station: ";
    getline(cin, start);
    cout << "Enter Destination Station: ";
    getline(cin, end);

    km.findShortestPath(start, end);

    return 0;
}
