/*
  Dijikstra’s algorithm for finding the shortest path (single-source shortest path).

  Example adapted from:

  https://www.tutorialspoint.com/c-cplusplus-program-for-dijkstra-s-shortest-path-algorithm

 */
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

/* Number of vertices in the graph */
#define V 6

int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
      if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int flag = 0;
int printPath(int parent[], int j)
{
    if (parent[j] == 0){
	flag = 1;
}

    if (parent[j] == -1){
        printf("%d", j);

 	if (flag == 0){
       	   printf(" <- %d",  j);
           return 1;
        }
    return 1;
    }

    printf("%d <- ", j);
    int count = printPath(parent, parent[j]) + 1;
    return count;
}

void printSolution(int dist[], int parent[])
{
   printf(" ============================================ \n"
          "|           Dijkstra's algorithm             |\n"
          "|        (single-source shortest path)       |\n"
          "|                                            |\n"
          "|              Source vertex = 0             |\n"
          " --------------------------------------------\n"
          "| Vertex | Distance | Path                   |\n"
          " --------------------------------------------\n");

   for (int i = 0; i < V; i++) {
      printf("| %6d | %8d | ", i, dist[i]);
      int pathLength = printPath(parent, i);
      if (pathLength < 3){
//	printf("\t");
//      printf("|\n");
//}
//else
printf("\t\t     |\n");
}
else
printf("\t     |\n");
//      printPath(parent, i);
//      if (strlen(i) > 4)
//	printf("test");
//      printf("%*s|\n", 5, "");
   }
   printf(" --------------------------------------------\n");
}

/*
for (int i = 0; i < V; i++) {
      printf("| %6d | %8d | ", i, dist[i]);
      printPath(parent, i);
      printf("%*s|\n", 15 - (parentCount(i, parent)), "");
   }
   printf("--------------------------------------------\n");
}

int parentCount(int node, int parent[]) {
    int count = 0;
    while(parent[node] != -1) {
        count++;
        node = parent[node];
    }
    return count;
}
*/

/* 
   This function just simulates the correct output. It is just here to test the 
   PASS condition in the test script. The actual solution uses variables to set 
   the values to be printed. 
*/


void printtestFormat()
{
   printf(" ============================================\n"); 
   printf("|           Dijkstra's algorithm             |\n");
   printf("|        (single-source shortest path)       |\n");
   printf("|                                            |\n");
   printf("|              Source vertex = 0             |\n");
   printf(" --------------------------------------------\n");
   printf("| Vertex | Distance | Path                   |\n");
   printf(" --------------------------------------------\n");
   printf("|      0 |        0 | 0 <- 0                 |\n");
   printf("|      1 |        5 | 1 <- 0                 |\n");
   printf("|      2 |        4 | 2 <- 0                 |\n");
   printf("|      3 |        8 | 3 <- 1 <- 0            |\n");
   printf("|      4 |       13 | 4 <- 2 <- 0            |\n");
   printf("|      5 |       12 | 5 <- 3 <- 1 <- 0       |\n");
   printf(" --------------------------------------------");
}

void dijkstra(int graph[V][V], int src)
{
   int dist[V], parent[V];
   bool sptSet[V];

   for (int i = 0; i < V; i++) {
      parent[i] = -1;
      dist[i] = INT_MAX;
      sptSet[i] = false;
   }
   dist[src] = 0;

   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet);
      sptSet[u] = true;
      for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
         {
            parent[v] = u;
            dist[v] = dist[u] + graph[u][v];
         }
   }

   printSolution(dist, parent);
}

int main()
{
   int graph[V][V] = {
      {0, 5, 4, 0, 0, 0},
      {5, 0, 6, 3, 0, 0},
      {4, 6, 0, 10, 9, 0},
      {0, 3, 10, 0, 7, 4},
      {0, 0, 9, 7, 0, 8},
      {0, 0, 0, 4, 8, 0}
   };

   dijkstra(graph, 0);

   return 0;
}




