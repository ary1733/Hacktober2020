#include<iostream>
using namespace std;

void add(){
	long num1, num2, x;
	cout << "Enter two numbers: \n";
    cin >> num1 >> num2;
    x = num1 + num2;
    cout << "Sum = " << x;
	
}

void sub(){
	long num1, num2, x;
	cout << "Enter two numbers: \n";
    cin >> num1 >> num2;
    x = num1 - num2;
    cout << "Subtraction = " << x;
}

void mul(){
	long num1, num2, x;
	cout << "Enter two numbers: \n";
         cin >> num1 >> num2;
         x = num1 * num2;
         cout << "Product = " << x;
	
}

void div(){
	long num1, num2, x;
	cout << "Enter Dividend: ";
         cin >> num1;
         cout << "Enter Divisor: ";
         cin >> num2;

         //while loop checks for divisor whether it is zero or not
         while(num2 == 0)
         {
            cout << "\nDivisor cannot be zero."
                    "\nEnter divisor once again: ";
            cin >> num2;
         }
         x = num1 / num2;
         cout << "\nQuotient = " << x;
	
}

void sqr(){
	long num1, num2, x;
	cout << "Enter any number: \n";
         cin >> num1;
         x = num1 * num1;
         cout << "Square = " << x;
	
}

int main()
{
   int ch;
   int a=1;
   long num1, num2, x;
    do{
    	cout << "\nPlease choose your option:"
           "\n1 = Addition"
           "\n2 = Subtraction"
           "\n3 = Multiplication"
           "\n4 = Division"
           "\n5 = Squares"
           "\n6 = exit"
           "\n\nChoice: ";
        cin >> ch;
    	switch (ch)
       {
      //Addition
        case 1: add(); 
                break;

      //Subtraction
        case 2: sub();
            break;

      //Multiplication
      case 3: mul(); 
              break;

      //Division
      case 4: div(); 
              break;

      //Square
      case 5: sqr(); 
        break;

      case 6:
      	exit(0);
         

      default: cout << "\nError";
               break;
   }
 	
} while(a==1);
   //displaying different options
   return 0;

}

/* Output:
Please choose your option:
1 = Addition
2 = Subtraction
3 = Multiplication
4 = Division
5 = Squares
6 = exit

Choice: 1
Enter two numbers:
5
9
Sum = 14
Please choose your option:
1 = Addition
2 = Subtraction
3 = Multiplication
4 = Division
5 = Squares
6 = exit

Choice: 2
Enter two numbers:
4
9
Subtraction = -5
Please choose your option:
1 = Addition
2 = Subtraction
3 = Multiplication
4 = Division
5 = Squares
6 = exit

Choice: 3
Enter two numbers:
4
8
Product = 32
Please choose your option:
1 = Addition
2 = Subtraction
3 = Multiplication
4 = Division
5 = Squares
6 = exit

Choice: 4
Enter Dividend: 9
Enter Divisor: 3

Quotient = 3
Please choose your option:
1 = Addition
2 = Subtraction
3 = Multiplication
4 = Division
5 = Squares
6 = exit

Choice: 5
Enter any number:
7
Square = 49
Please choose your option:
1 = Addition
2 = Subtraction
3 = Multiplication
4 = Division
5 = Squares
6 = exit

Choice: 6 */

