// Implement Disjoint Set Data Structure in cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet { 
   unordered_map<int, int> parent;
   public:
   void makeSet(vector<int> const &wholeset){
      for (int i : wholeset) 
      parent[i] = i;
   }
   int Find(int l) { 
      if (parent[l] == l) 
         return l;
      return Find(parent[l]);
   }
   void Union(int m, int n) {  
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
   }
};
void print(vector<int> const &universe, DisjointSet &dis) {
   for (int i : universe)
   cout << dis.Find(i) << " ";
   cout << '\n';
}
int main() {
   vector<int> wholeset = { 6,7,2,1,4 }; 
   DisjointSet dis;
   dis.makeSet(wholeset); 
   dis.Union(7, 6); 
   print(wholeset, dis);
   if (dis.Find(7) == dis.Find(6)) 
      cout<<"Yes"<<endl;
   else
      cout<<"No";
   if (dis.Find(3) == dis.Find(4))
      cout<<"Yes"<<endl;
   else
      cout<<"No";
   return 0;
}
