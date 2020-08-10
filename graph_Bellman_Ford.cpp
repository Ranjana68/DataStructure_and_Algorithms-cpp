#include<bits/stdc++.h>

using namespace std;

vector<int> g[2000+10];
int main()
{
    int v,e;

    cin>>v>>e;
    int fr,to,w;
    int dis[v]={INT_MAX};
    for(int i=0;i<e;i++)
    {
        cin>>fr>>to>>w;
        g[i].push_back(fr);
        g[i].push_back(to);
        g[i].push_back(w);


    }

for(int i=0;i<v;i++)
        {
           dis[i]=100;
        }
dis[1]=0;
    for(int i=0;i<v-1;i++)
    {
        int j = 0;
        while(g[j].size() != 0){

        cout<<dis[g[j][0]]<<", "<<g[j][2]<<" ,"<<dis[g[j][1]]<<endl;
            if(dis[ g[j][0]  ] + g[j][2] < dis[ g[j][1] ] ){
                dis[ g[j][1] ] = dis[ g[j][0]  ] + g[j][2];
            }
            j++;
    }
    }
for(int i=0;i<v;i++)
        {
            cout<<endl<<i<<" : "<<dis[i];
        }




    return 0;

}
