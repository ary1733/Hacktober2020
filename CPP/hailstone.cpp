//MIT License
//Copyright (c) 2020 sarthaka1310

#include<iostream>

using namespace std;

#define ll long long
#define LIMIT 100*100*100

// Prints hailstone sequence with n as start till min(total stopping time, LIMIT)
// ( refer https://en.wikipedia.org/wiki/Collatz_conjecture#Statement_of_the_problem )
void hailstone(ll n, ll k=1){
    if(n==1){
        cout<<"1\nTotal stopping time: "<<k<<"\n";
        return;
    }

    n = n%2 ? 3*n+1 : n/2;
    cout<<n<<"\n";
    if(k==LIMIT)
        cout<<"Too many iterations\n";
    else
    hailstone(n, k+1);
}

int main(){
    int a[] = {4, 5, 6, 13, 54, 193, 7};

    for(auto i : a)
        hailstone(i);

    return 0;
}
