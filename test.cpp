#include <stdio.h>
#include <limits.h>
#include<iostream>
using namespace std;
 
// Number of vertices in the graph
#define V 9
 
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int dist[], int n,int src,int dest)
{
   printf("Source    Destination   Min Distance from Source\n");
   for (int i = src; i < dest+1; i++)
      cout<<"   "<<src<<"      ->      "<<i<<"                  "<<dist[i]<<endl;
       //printf("%d \t\t %d\n", i, dist[i]);
cout<<endl;
       cout<<"THE FINAL MINIMUM DISTANCE FROM SOURCE TO DESTINATION IS LSITED BELOW "<<endl;
       cout<<endl;
cout<<"***************************************"<<endl;
printf("* Source    Destination  Min Distance *\n");
cout<<"*   "<<src<<"      ->      "<<dest<<"           "<<dist[dest]<<"     *"<<endl;
cout<<"***************************************"<<endl;
}
 
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src,int dest) 
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
 
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
 
     // Find shortest path for all vertices
     for (int count = src; count < dest+1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
         cout<<u<<endl;
       // Mark the picked vertex as processed
       sptSet[u] = true;
 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
 
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
            
     }
 
     // print the constructed distance array
     printSolution(dist, V,src,dest);
}
 
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
        int s=4;
        int e=7;
cout<<"************************************************"<<endl;
cout<<"* Starting point              Ending Point     *" <<endl;
cout<<"*     "<<s<<"                             "<<e<<"          *"<<endl;
cout<<"************************************************"<<endl;
cout<<endl;
    dijkstra(graph, s,e);
 
    return 0;
}