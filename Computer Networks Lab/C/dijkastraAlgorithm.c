#include <stdio.h>

int main(){
    // FIXED NODES SIZE OF 10
    int cost[10][10];       // Adjacency Matrix Form
    int visited[10]={0};    // keep track of nodes visted
    int distance[10];       // store distance from source to destination node
    int pre[10];            // keep track of previous nodes
    int source,target;       // 1-indexed start and end nodes
    int path[10];           //
    // int min_val = 9999;  // placeholder value
    int numNodes;
    printf("Enter the num of nodes");
    scanf("%d",&numNodes);
    printf("Enter weight of all the paths in adjacency matrix form\n");
    for(int i=1;i<=numNodes;i++)
    {
        for(int j=1;j<=numNodes;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
              cost[i][j]= 9999;
        }
    }
    printf("Enter the source Node\n");
    scanf("%d",&source);
    printf("Enter the target Node\n");
    scanf("%d",&target);

    int start = source;
    for (int i=1;i<=numNodes;i++){
        distance[i] = 9999;
        pre[i] = -1;
    }
    visited[source] = 1;    // source node is visited
    distance[source] = 0;     // source-source distance is 0
    while(visited[target] == 0){ // until target is reached

        int min = 9999; // placeholder value
        int m =0;
        for (int i=1;i<=numNodes;i++){
            int nodeDistance = distance[start] + cost[start][i];
            if (nodeDistance<distance[i] && visited[i] == 0){ // if new distance is lower tha
                distance[i] = nodeDistance;
                pre[i] = start;
            }
            if(min>distance[i] && visited[i] == 0){
                min = distance[i];
                m=i;
            }
             // current node is visited
        }
        start = m;
        visited[m] = 1;
    }
    start=target;
    int j=0;
    // logic for printing path
    while(start!=-1)
    {
        path[j++]=start;
        start=pre[start];
    }
    // printing of the path
   for(int i=j-1;i>=0;i--)
    {
        if(i!=j-1)
          printf(" to ");
         printf("%d",path[i]);
    }

    printf("\n shortest path is %d",distance[target]);
    return 0;


}