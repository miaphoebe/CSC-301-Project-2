/*
 * CSC-301
 * project2.cpp
 * Fall 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project2.hpp"

using namespace std;

/*
 * Depth First Search
 */
vector<int> DFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    
    // Reset all vertices 
    for (Vertex v : adjList){
        v.visited = false;
        v.previous = -1;
    }//for

    stack<int> s;
    start.visited = true;
    start.previous = -1; 
    s.push(start.label);

    while(!s.empty()) {
        
        int curr = s.top();
        s.pop();

        if (curr == exit.label){
            break;
        } //if

        for (int neighbor : adjList[curr].neighbors){
            if (!adjList[neighbor].visited) {
                adjList[neighbor].visited = true;
                adjList[neighbor].previous = curr;
                s.push(neighbor);
            } //if
        }//for
    }//while

    vector<int> path;
    int currStep = exit.label;
    
    // Retrace path
    while (currStep != -1) {
        path.push_back(currStep);
        currStep = adjList[currStep].previous;
    }//while
    
    reverse(path.begin(), path.end());

    // Return empty if start is not equal to the front of the path
    if (path.front() != start.label) {
        path.clear();
    }//if

    return path;
}

/*
 * Breadth First Search
 */
vector<int> BFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    // Reset all vertices 
    for (Vertex v : adjList){
        v.visited = false;
        v.previous = -1;
    }//for

    queue<int> q;
    start.visited = true;
    start.previous = -1; 
    q.push(start.label);

    while(!q.empty()) {
        
        int curr = q.front();
        q.pop();

        if (curr == exit.label){
            break;
        } //if

        for (int neighbor : adjList[curr].neighbors){
            if (!adjList[neighbor].visited) {
                adjList[neighbor].visited = true;
                adjList[neighbor].previous = curr;
                q.push(neighbor);
            } //if
        }//for
    }//while

    vector<int> path;
    int currStep = exit.label;
    
    // Retrace path
    while (currStep != -1) {
        path.push_back(currStep);
        currStep = adjList[currStep].previous;
    }//while
    
    reverse(path.begin(), path.end());

    // Return empty if start is not equal to the front of the path
    if (path.front() != start.label) {
        path.clear();
    }//if

    return path;
}