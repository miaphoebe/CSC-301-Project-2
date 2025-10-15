/*
 * CSC-301
 * project2.cpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Mia Hoffmann Kamrat
 * Date: Oct 15, 2025
 */

#include "project2.hpp"

using namespace std;

/*
 * Depth First Search: Use a stack to find a path from start to exit.
 *
 * Args:
 *  adjList: The adjacency list of the graph.
 *  start: The starting vertex.
 *  exit: The exit vertex.
 * 
 * Returns:
 *  A vector of ints representing the path from start to exit. If no path is found, 
 * return an empty vector.
 */
vector<int> DFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    // Lazy return when start is exit.
    if (start == exit) {
        return {start.label};
    }

    // Reset all vertices 
    for (Vertex &v : adjList){
        v.visited = false;
        v.previous = -1;
    };

    // Initialize the stack with the start vertex label.
    stack<int> s;
    adjList[start.label].visited = true;
    s.push(start.label);

    // Process the stack until it's empty or we find the exit.
    while(!s.empty()) {
        int curr = s.top();
        s.pop();

        if (curr == exit.label){
            break;
        };

        for (int neighbor : adjList[curr].neighbors){
            if (!adjList[neighbor].visited) {
                adjList[neighbor].visited = true;
                adjList[neighbor].previous = curr;
                s.push(neighbor);
            };
        };
    };

    // Initialize path retracing
    vector<int> path;
    int currStep = exit.label;
    
    // Retrace path
    while (currStep != -1) {
        path.push_back(currStep);
        currStep = adjList[currStep].previous;
    };
    
    // Reverse the path to get it from start to exit
    reverse(path.begin(), path.end());

    // Return empty if start is not equal to the front of the path
    if (path.front() != start.label) {
        path.clear();
    };

    return path;
}

/*
 * Breadth First Search: Use a queue to find a path from start to exit. Should
 * find the shortest path.
 * 
 * Args:
 *  adjList: The adjacency list of the graph.
 *  start: The starting vertex.
 *  exit: The exit vertex.
 * 
 * Returns:
 *  A vector of ints representing the path from start to exit. If no path is found
 * return an empty vector.
 */
vector<int> BFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    // Lazy return when start is exit.
    if (start == exit) {
        return {start.label};
    }

    // Reset all vertices 
    for (Vertex &v : adjList){
        v.visited = false;
        v.previous = -1;
    };

    // Initialize the queue with the start vertex label.
    queue<int> q;
    adjList[start.label].visited = true;
    q.push(start.label);

    // Process the queue until it's empty or we find the exit.
    while (!q.empty()) {
        int curr_label = q.front();
        q.pop();

        Vertex curr = adjList[curr_label];

        // Check if we found the exit.
        if (curr == exit) {
            break;
        };

        // Explore neighbors.
        for (int neighborLabel : curr.neighbors) {
            // Only add unvisited neighbors to the queue.
            if (adjList[neighborLabel].visited == false) {
                adjList[neighborLabel].visited = true;
                adjList[neighborLabel].previous = curr.label;
                q.push(neighborLabel);
            };
        };
    };

    // Initialize path retracing
    vector<int> path;
    int currStep = exit.label;

    // Retrace path
    while (currStep != -1) {
        path.push_back(currStep);
        currStep = adjList[currStep].previous;
    }

    // Reverse the path to get it from start to exit
    reverse(path.begin(), path.end());

    // If the path is empty or doesn't start with the start label, return an empty vector.
    if (path.empty() || path.front() != start.label) {
        return {};
    }

    return path;
};
