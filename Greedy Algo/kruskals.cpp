// Kruskals ALgorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include<ctime>
#include<chrono>
using namespace std::chrono;
using namespace std;
struct Edge
{
    int u, v, w; // source, destination and weight
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int x, vector<int> &parent)
{
    if (parent[x] != x)
    {
        // Path compression
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void merge(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = find(a, parent);
    b = find(b, parent);
    if (a == b)
    {
        return;
    }
    if (rank[a] < rank[b])
    {
        swap(a, b);
    }
    parent[b] = a;
    if (rank[a] == rank[b])
    {
        rank[a]++;
    }
}

vector<Edge> kruskal(vector<Edge> &edges, int n)
{

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<Edge> mst;
    int count = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u, parent) != find(v, parent))
        {
            merge(u, v, parent, rank);
            mst.push_back(edges[i]);
            count++;
        }
        if (count == n - 1)
        {
            break;
        }
    }
    return mst;
}
int main()
{

    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter the edges in the format 'u v w':" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

	auto start = high_resolution_clock::now();
    vector<Edge> mst = kruskal(edges, n);
    

    int total_weight = 0;
    for (int i = 0; i < mst.size(); i++)
    {
        total_weight += mst[i].w;
    }

    cout << "\nEdges in the minimum spanning tree:" << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].u + 1 << " " << mst[i].v + 1 << " " << mst[i].w << endl;
    }

    cout << "Total weight of the minimum spanning tree: " << total_weight << endl;
    
    auto stop = high_resolution_clock::now();// ending time
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"\nTime taken by Quick sort using median of median " <<duration.count()<< " ms";
    
    return 0;
}



/*Output
Enter the number of vertices and edges: 6 9
Enter the edges in the format 'u v w':
1 2 7
2 3 5
3 4 4
4 5 2
5 6 3
6 1 8
2 6 3
3 5 2
3 6 6

Edges in the minimum spanning tree:
4 5 2
3 5 2
5 6 3
2 6 3
1 2 7
Total weight of the minimum spanning tree: 17

Time taken by Quick sort using median of median 0 ms
*/






/*
#include<bits/stdc++.h>
using namespace std;
const int N = 50;

int parent[N],sz[N];

void make(int v) //add new node
{
   parent[v]=v;
   sz[v]=1;
} // namespace std;

int find(int v) //parent of group
{
    if(parent[v]==v)
    {
        return parent[v];
    }
    return parent[v]=find(parent[v]);
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
           swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

int main()
{
    int n,m;
    cout<<"Enter total number of vertices and edges:";
    cin>>n>>m;

    vector<pair<int , pair<int,int>>>edges;
    cout<<"Enter edges in the format of 'u v w:"<<endl;
    for(int i=0;i<m;++i)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i=1;i<=n;++i)
    {
        make(i);
    }
    int total_cost=0;
    for(auto &edge : edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v)) 
          continue;
        Union(u,v);
        total_cost+=wt;
        cout<<"Edges selected:"<<u<<" "<<v<<endl;
    }
    cout<<"Total cost of minimum spanning tree:"<<total_cost<<endl;
}
*/

















