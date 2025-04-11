#include<iostream>
#include <list>
#include <unordered_map>
#include <cstdlib>
using namespace std;

template <typename T>

class Graph
{
    public:
      unordered_map <T,list<T>> adj;
    // public:
      void addEdge(T u, T v,bool dir)
      {
        adj[u].push_back(v);
        //  dir==0 undirected
        if(dir==0)
        {
            adj[v].push_back(u);
        }
      }

      void printAdj()
      {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
      }
       
};

int main()
{
   Graph <int> g;
   int n;
   cout<<"Enter the number of edges:";
   cin>>n;

   for(int i=0;i<n;i++)
   {
    int a,b;
    cin>>a>>b;
    g.addEdge(a,b,0);
   }

//    g.addEdge(1,2,0);
//    g.addEdge(2,6,0);
//    g.addEdge(2,4,0);
//    g.addEdge(4,6,0);
   g.printAdj();

}