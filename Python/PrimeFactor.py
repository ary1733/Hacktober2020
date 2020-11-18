# A function to print all prime factors of a given number n 

import math 
def primeFactors(n): 
    while n % 2 == 0: 
        print 2, 
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            print(i)
            n = n / i 
              
    # Condition if n is a prime 
    # number greater than 2 
    if n > 2: 
        print(n) 
