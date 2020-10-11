#include <bits/stdc++.h> 

int n; 

int factorial (unsigned int n) 
{ 
    if (n == 0) 
        return 1; 
    return n * factorial (n - 1); 
} 

int main() 
{ 
    std::cin >> n;
    
    std::cout << factorial (n);
    
    return 0; 
} 
