#include<iostream>

using namespace std;

typedef struct edge
{
    int src;
    int dest;
    int wt;
} edge;

void bellman_ford(int nv,edge e[],int src_vert,int ne)
{
    int u,v,weight,i,j=0;
    int dis[ne];

    for(i=0; i<nv; i++)
    {
        dis[i]=99999;
    }

    dis[src_vert]=0;

    for(i=0; i<nv-1; i++)
    {
        for(j=0; j<ne; j++)
        {
            u=e[j].src;
            v=e[j].dest;
            weight=e[j].wt;

            if(dis[u]!=99999 && dis[u]+weight < dis[v])
            {
                dis[v]=dis[u]+weight;
            }
        }

    }

    for(j=0; j<ne; j++)
    {
        u=e[j].src;
        v=e[j].dest;
        weight=e[j].wt;

        if(dis[u]+weight < dis[v])
        {
            cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
        }
    }

    cout<<"\nVertex"<<"  Distance from source";
    for(i=1; i<=nv; i++)
    {
        cout<<"\n"<<i<<"\t"<<dis[i];
    }
}
int main()
{
    int nv = 5,ne = 6,src_vert;

    printf("Enter the source vertex of the graph: ");
    cin>>src_vert;

    edge e[ne] = {  {1,2,1},
                    {1,3,10},
                    {2,4,1},
                    {4,3,-10},
                    {4,5,5},
                    {5,3,3}
                 };

    /*e[].src = {1,1,2,3,4,5}; //source vertex of edges
    e[].dest = {2,3,4,4,5,3}; //destination vertex of edges
    e[].wt = {1,10,1,-10,5,3};; //weight of edges*/


    bellman_ford(nv,e,src_vert,ne);

    return 0;
}
