# Kolkata Metro Navigator (Dijkstra)

A C++ Data Structures and Algorithms (DSA) project that finds the shortest path between Kolkata Metro stations.

## 🗺️ Network Coverage
This project includes all currently operational lines of the [Kolkata Metro Rail Corporation](https://www.kmrc.in):
- **Blue Line:** Dakshineswar to Kavi Subhash (North-South).
- **Green Line:** Howrah Maidan to Salt Lake Sector V (East-West).
- **Purple Line:** Joka to Majerhat.
- **Orange Line:** Kavi Subhash to Hemanta Mukhopadhyay (Ruby).
  
## 🚀 Features
- **Dijkstra's Algorithm:** Uses a priority queue to ensure $O(E \log V)$ efficiency.
- **Interchange Support:** Seamlessly calculates routes across Blue and Green lines via **Esplanade**.
- **Real Data:** Uses actual operational distances for accuracy.
  

## 🛠️ Implementation Details
1. **Graph Representation:** Adjacency List for space efficiency.
2. **Pathfinding:** Implements Dijkstra's greedy approach to find the shortest distance in a weighted graph.
3. **Backtracking:** Uses a `parent` array to reconstruct and print the station names in order.
   

## 🧠 The Algorithm
The project utilizes **Dijkstra's Algorithm**. It treats each station as a node and the distance between them as edge weights. 
- **Time Complexity:** $O((E + V) \log V)$ using a Min-Priority Queue.
- **Space Complexity:** $O(V + E)$ for the Adjacency List.

## 💻 How to Build
```bash
g++ -std=c++17 metro.cpp -o metro
./metro
