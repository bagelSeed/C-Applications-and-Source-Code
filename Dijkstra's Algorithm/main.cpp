#include <iostream>
#include <vector>
#include <algorithm>//for max()
#include <limits>

using namespace std;
typedef vector<int> ivec;
typedef vector<bool> bvec;
typedef vector<ivec> imatrix;

struct graph
{
    imatrix edges;
    int numVertices;
};

ostream &operator<<(ostream &stream, ivec &vec)
{
    for(int i = 0; i < (int)vec.size(); i++)
    {
        stream << vec[i]<<" ";
    }
    return stream;
}

ostream &operator<<(ostream &stream, graph &g)
{
    stream <<endl<<"numVectices = "<<g.numVertices<<endl;
    for(int i = 0; i<g.numVertices; i++)
    {
        stream << "vertex "<<i+1<<" :edges "<<g.edges[i]<<endl;
    }
    return stream;
}

const int sentinel = -1;
bvec inTree;
ivec distanceNodes;
ivec parents;

void initGraph(graph *g);
void insertEdge(graph *g, int nodeNum, int edgeNum);
void initSearch(graph *g);
void shortestPath(graph *g, int start, int end);

int main()
{
    graph g;
    initGraph(&g);
    insertEdge(&g, 1, 2);
    insertEdge(&g, 1, 3);
    insertEdge(&g, 2, 1);
    insertEdge(&g, 2, 3);
    insertEdge(&g, 2, 4);
    insertEdge(&g, 3, 1);
    insertEdge(&g, 3, 2);
    insertEdge(&g, 3, 4);
    insertEdge(&g, 4, 2);
    insertEdge(&g, 4, 3);
    insertEdge(&g, 4, 5);
    insertEdge(&g, 5, 4);
    insertEdge(&g, 6, 7);
    insertEdge(&g, 7, 6);

    cout <<"after building, the graph is "<<g<<endl;
    shortestPath(&g, 1, 5);
    shortestPath(&g, 2, 4);
    shortestPath(&g, 5, 2);
    shortestPath(&g, 1, 7);

    return 0;
}

void initGraph(graph *g)
{
    g->numVertices=0;
}

void insertEdge(graph *g, int nodeNum, int edgeNum)
{
    int numVertices = max(nodeNum, edgeNum);
    numVertices = max(1, numVertices);
    if(numVertices>g->numVertices)
    {
        for(int i = g->numVertices; i<=numVertices; i++)
        {
            ivec nodes;
            if(g->edges.size()<i)
            {
                g->edges.push_back(nodes);
            }
        }
        g->numVertices=numVertices;
    }
    g->edges[nodeNum-1].push_back(edgeNum);
}

void initSearch(graph *g)
{
    if(g==NULL)
        return;
    inTree.clear();
    distanceNodes.clear();
    parents.clear();
    for(int i = 0; i <=g->numVertices; i++)
    {
        inTree.push_back(false);
        distanceNodes.push_back(numeric_limits<int>::max());
        parents.push_back(sentinel);
    }
}

void shortestPath(graph *g, int start, int end)
{
    initSearch(g);
    int edge, curr, dist;
    distanceNodes[start]=0;
    curr = start;
    while(!inTree[curr])
    {
        inTree[curr]=true;
        ivec edges=g->edges[curr-1];
        for(int i=0; i<edges.size(); i++)
        {
            edge=edges[i];
            if(distanceNodes[edge]>distanceNodes[curr]+1)
            {
                distanceNodes[edge]=distanceNodes[curr]+1;
                parents[edge]=curr;
            }
        }
        curr = 1;
        dist = numeric_limits<int>::max();
        for(int i=1; i<g->numVertices; i++)
        {
            if((!inTree[i])&&(dist>distanceNodes[i]))
            {
                dist=distanceNodes[i];
                curr=i;
            }
        }
    }
    ivec path;
    if(distanceNodes[end]==numeric_limits<int>::max())
    {
        cout<<"there is no way to get from "<<start<<" to "<<end<<endl;
    }
    else
    {
        int temp = end;
        while(temp!=start)
        {
            path.push_back(temp);
            temp = parents[temp];
        }
        path.push_back(temp);
        reverse(path.begin(), path.end());
        cout <<"the path from "<<start<<" to "<<end<<" is "<<path<<endl;
    }
}
