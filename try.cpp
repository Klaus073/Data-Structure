#include <stdio.h>
#include <iostream>
#include <limits.h>
 using namespace std;
// Number of vertices in the graph
#define MAX 6
#define LIMIT 9999

//A helper function to print sortest covered path from source tot destnation
int* final_src_to_dest_path(int path[],int src,int dest)
{
    int j=0;
    int sub=2;
    int i=0;
    int* ptr=new int[3];
    int *ext=new int[3];
    j=dest;
//cout<<dest;
			do
			{
				j=path[j];
                ptr[i]=j;
				// cout<<"<-"<<j;
             i++;
			}while(j!=src);
            
            for (int i = 0; i < 3; i++)
            {
                ext[i]=ptr[3-i-1];
                   // cout<<ext[i]<<endl;
                sub--;
            }
            return ext;
}

int* findLowest(int ext[MAX][MAX], int size,int src,int dest)
{
    
    int x=0;
    int *ptr=new int[size-1];

   for (int i = 0; i < size-1; i++) 
   { 
       int min=ext[i][0];
        for (int j = 0; j < size-1; j++) 
        { 
            if (min>ext[i][j] ) { 
                min = ext[i][j]; 
               x=j; 
               //cout<<j<<endl;
            } 
        } 
        //cout<<min<<endl;
       ptr[i]=x;
    } 
    return ptr;
}

int** two_D_modifier(int array[][5],int src,int dest)
{
    int** arr = new int*[4];
        for (int i=0; i<4; i++) // initializing 2D
            arr[i] = new int[5];

    int count=0;
    int basic_count=0;
    int adv_count=0;

    for (int i = 0; i < 4; i++)
    {
        array[i][0]=0;
        count++;
        if (count>1 )
        {
            if (count>1 && count<5)
            {
                array[i][3]=array[i-1][3];
                basic_count++;
                if (basic_count>1 && basic_count<4)
                {
                    array[i][2]=array[i-1][2];
                    adv_count++;
                    if (adv_count>1 && adv_count<3)
                    {
                        array[i][4]=array[i-1][4];
                    }
                    
                }
            }
            
        }
        for (int j = 0; j < 5; j++)
        {
            arr[i][j]=array[i][j];   
           // cout<<array[i][j]<<"   ";
        }
        cout<<endl;
    }

    return arr;
}

void print(int  test[],int path[],int ext[MAX][MAX],int size,int src,int dest,int dist[])
{
    int** ob = new int*[4];
       for (int i=0; i<4; i++) 
	        ob[i] = new int[5];

    int *ptr=new int[4];
    ptr=final_src_to_dest_path(path,src,dest);
    ptr[3]=dest;
    int ar[4][5];
        for (int i = 0; i < 4; i++)
        {
             for (int j = 0; j < size-1; j++)
            {
             ar[i][j]=ext[ptr[i]][j];
            }
       
        }
    ob= two_D_modifier(ar,src,dest);

    cout<<"**************************************"<<endl;
    cout<<"*             NOTE:                  *"<<endl;
    cout<<"*        9999=INIFINITY              *"<<endl;
    cout<<"**************************************"<<endl;  

    int runner=1;


    while (runner<=4)
    {
        cout<<"\n\n\n";
        cout<<"     ITERTAION  =   "<<runner<<endl;
        cout<<"\n\n\n";

        cout<<"Vertex|";
	
	for (int i = 0; i < MAX-1; i++)
	{
		
		cout<<"\t"<< i<<"      ";
	}
    cout<<endl;
    	cout<<"------|---------------------------------------"<<endl;
  
    for (int i = 0; i < runner; i++)
    {
        cout<<ptr[i]<<"     |";
       
        for (int j = 0; j < size-1; j++)
        {
            
            cout<<"\t"<<ob[i][j]<<"   ";
            
          
        }
        cout<<endl;
        cout<<"------|---------------------------------------"<<endl;
        cout<<endl;
        
    }

    runner++;
    cout<<endl;
    }


    cout<<"\n\n";
cout<<"*************************************"<<endl;
cout<<"*             RESULTS:              *"<<endl;
cout<<"* Distance Of Shortest Path = "<<dist[dest]<<"    *"<<endl;
cout<<"* Shortest Path = ";
    for (int i = 0; i < 4; i++)
    {
        cout<<"->"<<ptr[i];
    }
cout<<"      *"<<endl;
cout<<"*************************************"<<endl;
cout<<endl;

}

void dijkstra_algo(int Graphy[MAX][MAX],int size, int src,int dest)
{
    int test[MAX];
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
				graph[i][j]=Graphy[i][j];//  cout<<"grapth "<<graph[i][j]<<endl;
		}
			
	}
  
	//initializing path[],dist[] and visit[]
	for(int i=0;i<size-1;i++)
	{
		dist[i]=graph[src][i];
       // int *ptr;
       test[i]=dist[i];
       
       // print(dist[i]);
		path[i]=src;
		visit[i]=0;
		//cout<<"   "<<dist[i];
		//cout<<"path "<<path[i]<<endl;
		//cout<<"visit "<<visit[i]<<endl;
	}
	
	dist[src]=0;
	visit[src]=1;
	count=1;
	//cout<<dist[src]<<endl;
	while(count<size-1)
	{
		min_dist=LIMIT;
		
		//next_vertex gives the node at minimum dist
		for(int i=0;i<size;i++)
			if(dist[i]<min_dist&&!visit[i])
			{
				min_dist=dist[i];
                //cout<<"min d "<<min_dist<<endl;
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
                        //cout<<dist[4]<<endl;
						path[i]=next_vertex;
						//cout<<"path "<<path[i]<<endl;
					}
		count++;
	}
    print(test,path,graph,size,src,dest,dist);
    
  
}
 
int main()
{
   int graph[MAX][MAX] = {{0, 70,0,30,100},
                      {70,0,50,0,0},
                      {0,50,0,20,10},
                      {30,0,20,0,60},
                      {100,0,70,60,0}};
                   
 int source=0;
        int destination=4;
		cout<<"************************************************"<<endl;
cout<<"* Starting point              Ending Point     *" <<endl;
cout<<"*     "<<source<<"                             "<<destination<<"          *"<<endl;
cout<<"************************************************"<<endl;
cout<<endl;
    dijkstra_algo(graph, MAX,source,destination);
 
    return 0;
}
/*

****************GRAPGH*****************

                       100
                  0------------|
                / \            |
           70  /  \30          |
              /   \     60     | 
             /      3----------4
            1      /          /
             \   /           /
        50    \ / 20        / 10
               2-----------/


*/