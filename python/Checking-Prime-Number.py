# Program to check whether a number is prime number or not

# To take input from the user 
number = int(input("Enter the number: "))

# prime numbers are greater than 1
if number > 1:
   # check for factors
   for i in range(2,number):
       if (number % i) == 0:
           print(f"The given number {number} is not a prime number")
           break
   else:
       print(f"The given number {number} is a prime number")
       
# if the given input number is less than or equal to 1, it is not prime.
# So we are giving an else condition.

else:
   print(num,"is not a prime number")
        
