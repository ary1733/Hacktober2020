print("--------------SIMPLE CALCULATOR------------ ")
print("Enter the type of operation you want to perform: ")
print("+ for addition")
print("- for subtraction")
print("* for multiplication")
print("/ for division")
ch = input()
a, b = map(int, input("Enter two numbers separated by a space, you want to perform the operation on: ").split())
if ch == "+":
    print("The sum is:", a + b)
if ch == "-":
    print("The difference is:", a - b)
if ch == "*":
    print("The product is:", a * b)
while ch == "/":
    if b != 0:
        print("The quotient is:", a / b)
        break
    else:
        b = int(input("Enter a divisor which is not 0: ")) 
