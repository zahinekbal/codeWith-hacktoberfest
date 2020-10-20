# Python program to find the factorial of a number.

#To take the number, input from the user
number = int(input("Enter the number: "))

# Assigning 1 to a variable named 'factorial'.
# The factorial value will be stored inside this variable
factorial = 1

# To check whether the number is negative, positive or zero.

# To check whther the number is negative
if number < 0:
   print("Sorry, factorial does not exist for negative numbers")

# To check whether the input number is zero
elif number == 0:
   print("The factorial of 0 is 1")

# If both the above conditions fails then the number is a positive integer.
else:
   for i in range(1,number + 1):
       factorial = factorial*i
   print(f"The factorial of the number {number} is: {factorial}")
