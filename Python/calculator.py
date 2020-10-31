"""
  Python program for calculator
"""

def add(x, y):
  return x + y

def subtract(x, y):
  return x - y

def multiply(x, y):
  return x * y

def divide(x, y):
  return x / y

def calculator():
  cont = 'Y'
  while cont in ('y', 'Y', 'yes', 'YES', 'Yes'):
    print("Menu")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    print("5. Exit")
    choice = input("Enter choice: ")
    
    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))
    
    if choice in ('1', '2', '3', '4', '5'):
      if choice == '1':
        print(num1, "+", num2, "=", add(num1, num2))
      elif choice == '2':
        print(num1, "-", num2, "=", subtract(num1, num2))
      elif choice == '3':
        print(num1, "*", num2, "=", multiply(num1, num2))
      elif choice == '4':
        while True:
          if (num2 != 0):
            print(num1, "/", num2, "=", divide(num1, num2))
            break
          else:
            print("Invalid Input!")
            num2 = float(input("Enter second number: "))
    else:
      print("Invalid Choice!")
    
    cont = input('Do you want to continue (Y/N): ')
    print()

if __name__ == '__main__':
  calculator()