#include <stdio.h>
#include <iostream>
#include <limits.h>
 using namespace std;
// Number of vertices in the graph
#define MAX 9
#define LIMIT 9999

// A helper function to print sortest covered path from source tot destnation
void final_src_to_dest_path(int path[],int size,int src,int dest){
int j=0;
j=dest;
cout<<dest;
				do
			{
				j=path[j];
				 cout<<"<-"<<j;
             
			}while(j!=src);
}
void print_data(int dist[],int path[], int size,int src,int dest)
{
   
    int j=0;
  
    //cout<<"Source    Destination    Min Distance from Source      Path Covered For Min Distance\n";
	cout<<"     |";
	
	for (int i = 0; i < MAX; i++)
	{
		
		cout<<"        "<< i;
	}
	
	cout<<endl;
	cout<<"-----|---------------------------------------------------------------------------------------"<<endl;
   for(int i=src;i<dest+1;i++)
   {
       if(i!=src)
		{
            cout<<"   "<<src<<"    ->    "<<i<<"      "<<"            "<<dist[i]<<endl;
			cout<<"\n                                                                Path Covered  "<<i;
			
			 j=i;
			do
			{
				j=path[j];
				cout<<"<-"<<j;
			}while(j!=src);
			cout<<endl;
	    }
   }
cout<<endl;
    cout<<"THE FINAL MINIMUM DISTANCE FROM GIVEN SOURCE TO GIVEN DESTINATION IS LISTED BELOW "<<endl;
       cout<<endl;
cout<<"**********************************************************************"<<endl;
printf("* Source    Destination  Min Distance   Path Covered For Min Distance*\n");
cout<<"*   "<<src<<"      ->      "<<dest<<"           "<<dist[dest]<<"            ";
final_src_to_dest_path(path,size,src,dest);
cout<<"              *"<<endl;
cout<<"**********************************************************************"<<endl;
		
}


void dijkstra_algo(int Graphy[MAX][MAX],int size, int src,int dest)
{
     int graph[MAX][MAX];			//creates the graph matrix
	 int dist[MAX];
	 int path[MAX];					//path[] stores the predecessor of each node
	int visit[MAX];
	int count,min_dist;				//count gives the number of nodes seen so far
	int next_vertex;
	
	
	
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(Graphy[i][j]==0)
				graph[i][j]=LIMIT;
			else
				graph[i][j]=Graphy[i][j];//cout<<"grapth "<<graph[i][j]<<endl;
		}
			
	}
		
	
	//initializing path[],dist[] and visit[]
	for(int i=0;i<size;i++)
	{
		dist[i]=graph[src][i];
		path[i]=src;
		visit[i]=0;
		//cout<<"dist "<<dist[i]<<endl;
		//cout<<"path "<<path[i]<<endl;
		//cout<<"visit "<<visit[i]<<endl;
	}
	
	dist[src]=0;
	visit[src]=1;
	count=1;
	
	while(count<size-1)
	{
		min_dist=LIMIT;
		
		//next_vertex gives the node at minimum dist
		for(int i=0;i<size;i++)
			if(dist[i]<min_dist&&!visit[i])
			{
				min_dist=dist[i];
				next_vertex=i;
				//cout<<"vertex "<<next_vertex<<endl;
			}
			
			//check if a better path exists through next_vertex			
			visit[next_vertex]=1;
			for(int i=0;i<size;i++)
				if(!visit[i])
					if(min_dist+graph[next_vertex][i]<dist[i])
					{
						dist[i]=min_dist+graph[next_vertex][i];
						path[i]=next_vertex;
						//cout<<"path "<<path[i]<<endl;
					}
		count++;
	}
 
     print_data(dist,path, MAX,src,dest);
}
 
int main()
{
   /* Let us create the example graph discussed above */
   int graph[MAX][MAX] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 int source=0;
        int destination=8;
		cout<<"************************************************"<<endl;
cout<<"* Starting point              Ending Point     *" <<endl;
cout<<"*     "<<source<<"                             "<<destination<<"          *"<<endl;
cout<<"************************************************"<<endl;
cout<<endl;
    dijkstra_algo(graph, MAX,source,destination);
 
    return 0;
}