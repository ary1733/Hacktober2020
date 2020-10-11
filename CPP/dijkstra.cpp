/* 
this is the famous Graph algorithm for finding the shortest distance of from any node to all other nodes
complexity is VE(LOGV)
for efficiency i used set you can also use priority queue for that.
AVOID COMMENTS USED FOR DEBUGGING :)
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int , int > > adj[100002];
void dijkstra(int src,int n){
    vector<int> dist(n+2,INT_MAX); //distance of all u vertex is infinity
    
    set<pair<int ,int > > s;//set of (min. distance,vertex) distance is set as a parmeter coz
    //we want source vertex as  of acc. to min distance that's why.
    dist[src]=0;//always
    s.insert(make_pair(0,src));
    
    while(!s.empty()){
        //pair at front
        auto p=*(s.begin());//or s.begin()->second
        int u=p.second;// (min.distance, vertex)
        s.erase(s.begin());
        //iterate over neighbors/children of the current node 
        for(auto it:adj[u]){//adj[v][i] = pair(vertex, weight) iter over this pair
            int v=it.first;
            int weight=it.second;
            //cout<<u<<" ---> "<<v<<"   ,   "<<weight<<endl;
            if(dist[u]+weight<dist[v]){
                auto f=s.find(make_pair(dist[v],v));
                if(f!=s.end()){
                        s.erase(f);
                }
                //cout<<dist[v]<<" updated with ";
                dist[v]=dist[u]+weight;
                //cout<<dist[v]<<endl;
                //cout<<v<<"  par distance hai "<<dist[v]<<endl;
                s.insert(make_pair(dist[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++){
            if(i==src)
            continue;
            else if(dist[i]==INT_MAX){
                cout<<-1<<" ";
            }
            else{
            cout<<dist[i]<<" ";
            }
    }
    dist.clear();
}
int main()
{
    int t;
   int x,y,z,i,j,k,n,e;
   cin>>t;
   while(t--){
           cin>>n>>e;
       
       for(int i=0;i<e;i++)
       {
            cin>>x>>y>>z;
            adj[x].push_back(make_pair(y,z));
            adj[y].push_back(make_pair(x,z));
       }
                /* for(int i=0;i<=n;i++){
                    for(int j=0;j<adj[i].size();j++){
                        cout<<i<<" ---> "<<" ( "<<adj[i][j].first<<" , "<<adj[i][j].second<<" ) ";
                    }
                    cout<<endl;
                }*/
       cin>>k;
       dijkstra(k,n);
       for(int i=1;i<=n;i++){
            adj[i].clear();
       }
       
   }
   
   return 0;
}
