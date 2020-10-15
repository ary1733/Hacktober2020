// https://www.urionlinejudge.com.br/judge/en/problems/view/2449
#include <iostream>
#include <cmath>
using namespace std;

const int tmax = (int)1e3 + 100;

int altura[tmax];

int main() {
		
  int n, m, i, resp = 0;
  cin >> n >> m;
  
  for (i = 0; i < n; i++)
    cin >> altura[i];
    		
  i = 0;
  while( i < n-1 ){
    resp += abs(m-altura[i]);
    if ( altura[i] == altura[i+1] ) i++;
    else altura[i+1] += m-altura[i];
    i++; 
  }
  
  cout << resp << endl;
	
	return 0;
}
