//  Prim's MST algorithm.
#include <bits/stdc++.h> 
using namespace std; 
  
// total vertices 
#define V 5  
  
// to find the vertex with minimum key value
int minKey(int key[], bool mstSet[])  
{  
    // Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  
// to print the constructed MST  
void printMST(int parent[], int graph[V][V])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
  
// Function to construct and print MST
void primMST(int graph[V][V])  
{  
    // Array to store MST  
    int parent[V];  
      
    //to pick minimum weight 
    int key[V];  
      
    //vertices not yet included in MST  
    bool mstSet[V];  
   
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have V vertices  
    for (int count = 0; count < V - 1; count++) 
    {  
        // Pick minimum key which not yet included  
        int u = minKey(key, mstSet);  
  
        // Add vertex to MST Set  
        mstSet[u] = true;  
  
        // Update key value and parent index
        for (int v = 0; v < V; v++)  

            // Update the key only if graph[u][v] is smaller than key[v]  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
    // print the constructed MST  
    printMST(parent, graph);  
}  
  
// Driver code 
int main()  
{  
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    // Print solution  
    primMST(graph);  
  
    return 0;  
}  
