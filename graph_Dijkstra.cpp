#include<bits/stdc++.h>

using namespace std;


int main()
{
    int v,e;
    cin>>v>>e;
    int dist[v];
    bool vis[v];
    vector< pair <int,int> > g[v];

    int f,t,w;
    for(int i=0;i<e;i++)
    {
        cin>>f>>t>>w;



    }

    for(int i=0;i<v;i++)
    {

        for(int j=0;j<g[i].size();j++)
        {
            cout<<endl<<i<<": "<<g[i][j].first<<"----- "<<g[i][j].second<<endl;
        }
    }
        memset(vis, false , v);            // set all vertex as unvisited

for(int i=0;i<v;i++)
        dist[i]=INT_MAX;
        dist[1]=0;

    multiset< pair<int,int> > s; //store dist and vertex
    s.insert({0,1});

    while(!s.empty())
    {
        pair<int,int>p=*s.begin();
        s.erase(s.begin());

        int x=p.second,d=p.first;
        cout<<endl<<"-------x,d(min)-------  "<<x<<" , "<<d<<endl;
        if(vis[x]) continue;

        vis[x]=true;

        for(int i=0;i<g[x].size();i++)
        {
            int ver=g[x][i].first;
            int wei=g[x][i].second;

            cout<<endl<<"fkdjjnfc  "<<dist[x]<<" , "<<wei<<" , "<<dist[ver]<<endl;
            if(dist[x]+wei<dist[ver])
            {

                dist[ver]=dist[x]+wei;
                s.insert({dist[ver],ver});
            }
        }
    }


    for(int i=0;i<v;i++)
    {
        cout<<endl<<i<<" : "<<dist[i];
    }
    return 0;


}
