
// Java program to generate hailstone  
// numbers and calculate steps required  
// to reduce them to 1 
//AUTHOR: NISHANT SABBARWAL
import java.util.*; 
class GFG 
{ 
static int c; 

static int HailstoneNumbers(int N) 
{ 
    System.out.print(N + " "); 

    if (N == 1 && c == 0) { 

        return c; 
    }  
    else if (N == 1 && c != 0) { 

        c++; 
        return c; 
    }  
    else if (N % 2 == 0) { 

        c++; 
        HailstoneNumbers(N / 2); 
    }  
    else if (N % 2 != 0) { 

        c++; 
        HailstoneNumbers(3 * N + 1); 
    } 
    return c; 
} 

// Driver function 
public static void main(String[] args) 
{ 
    int N = 7; 
    int x; 

    // Function to generate Hailstone 
    // Numbers 
    x = HailstoneNumbers(N); 

    // Output: Number of Steps 
    System.out.println(); 
    System.out.println("Number of Steps: " +x); 
} 
} 
