#!/usr/bin/env python
# coding: utf-8

# In[1]:


#Importing the necessary packages


# In[2]:


import time 

import sys

import os


# In[3]:


#Function for implementing the loading animation 


# In[17]:


def load_animation():
    
    #String to be displayed when the aplication is loading
    load_str = 'starting your console application...'
    ls_len = len(load_str)
    
    #String for creating the rotating line
    animation = '|/-\\'
    anicount = 0
    
    #used to keep the track of the duration of the animation 
    counttime = 0
    
    # Pointer for travelling the loading string
    i = 0
    
    while(counttime != 100):
        
        #used to change the animation speed
        #smaller the value, faster will be the animation
        time.sleep(0.075)
        
        #Converting the string to list
        #as string is immutable
        load_str_list = list(load_str)
        
        #x->obtaining the ASCII code
        x = ord(load_str_list[i])
        
        #y->for storing altered ASCII code
        y = 0
        
        #If the character is '.' or ' ', keep it unaltered
        #switch uppercase to lowercase and vice-versa
        if x!= 32 and x!= 46:
            if x>90:
                y = x-32
            else:
                y = x+32
            load_str_list[i]= chr(y)
        
        #for storing the resultant string 
        res =''
        for j in range(ls_len):
            res = res + load_str_list[j]
        
        #displaying the resultant string 
        sys.stdout.write("\r"+res + animation[anicount])
        sys.stdout.flush()
        
        #Assigning the loading string to the resultant string
        load_str = res
        
        anicount = (anicount + 1)%4
        i =(i + 1)%ls_len
        counttime = counttime + 1
    
    #for windows OS
    if os.name =='nt':
        os.system('cls')
    
    #for linux / Mac OS
    else:
        os.system('clear')

#Driver program
if __name__ == '__main__':
    load_animation()
    
    #Your desired code continues from here
    # s = input("Enter your name: ")
    s = 'Bikramjit'
    sys.stdout.write("\nHappy Programmers' Day "+str(s)+ "\n")
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


# In[40]:


def isPrime(x):
    for n in range(2,x):
        if x%n==0:
            return False
        else:
            return True

filtrObj=filter(isPrime,range(2500))
print("Prime numbers between 1-2500: ",list(filtrObj))


# In[109]:


get_ipython().run_cell_magic('writefile', 'prime.py', '\'\'\'\nThis is a program for prime numbers\n\'\'\'\nimport unittest\nNUM = int(input("Enter the number: "))\nif NUM != 1:\n    for i in range(2, NUM):\n        if(NUM % i) == 0:\n            print(NUM, "is not a prime number")\n            print(i, "times", NUM//i, "is", NUM)\n            break\n    else:\n        print(NUM, "is a prime number")\nelse:\n    print(NUM, "is not a prime number")\nif __name__ == "__main__":\n    unittest.main()  ')


# In[110]:


get_ipython().system(' pylint prime.py')


# In[136]:


#Python program to ask the user for a range and display all armstrong numbers in that interval
#take input from the user

lower= int(input("Enter lower range: "))
upper= int(input("Enter upper range: "))

def func(num):
#     yield(num)
    for num in range(lower,upper + 1):
#         yield(num)
        #initilaize sum
        sum = 0

        #find the sum of the cube of each digit
        temp = num
        while temp!=0:
#             yield(num)
            digit = temp%10
            sum += digit **3
            temp //= 10
            
        if num == sum:
            yield(num)
        
    
    


# In[137]:


print(list(func(2)))


# In[44]:


def isPrime(x):
        for j in range(2,i):
                if i%j==0:
                    break
                else:
                    print(i)
filtrObj=filter(isPrime,range(1,2500))
print("Prime numbers between 1-2500: ",list(filtrObj))


# In[146]:


#Pyhton program to display all the prime numbers within an interval

# lower=900
# upper=1000

# print("Prime numbers between",lower,"and",upper,"are:")
num = range(1,200):
def prime():
#     for num in range(lower,upper+1):
        #all prime numbers are greater than 1
     if num>1:
        for i in range(2,num):
             if (num%i)==0:
                break
        else:
            print(num)
result = filter(prime,num)


# In[149]:


nums = range(2,100)
for i in range(2,10):
    
    nums = filter(lambda x: x==i or x%i,nums)
print(list(nums))


# In[161]:


def check(num):
    for num in range(1,2500):
        if num>1:
            for i in range(2,num):
                 if (num%i)==0:
                    break
            else:
                print(num)


# In[162]:


check(5)


# In[163]:


lst = list(range(1,2500))


# In[164]:


print(lst)


# In[ ]:


lst2=[]

for item in lst:
    if check(item):
        lst2.append(item)


# In[160]:


print(lst2)


# In[ ]:


lst2= filter(check,lst)


# In[ ]:


print(list(lst2))


# In[ ]:


num =input("Enter the sentence: ")
def powsix(num):
    return num.capitalize()


# general_list = range(1,100)
# 
# import math 
# def is_prime(number):
#     for i in range(2,int(sqrt(number)) + 1):
#         if number % i == 0:
#             return False
#     return number > 1

# In[57]:


def filter_primes(general_list):
    return filter(is_prime,set(general_list))


# In[61]:


print(list(filter_primes(general_list)))


# In[62]:


lst = range(1,100)
new_lst= [i for i in lst if isPrime(i)]
print(new_lst)


# In[63]:


filter(lambda x: all(map(lambda p: x%p ! =0, range(2,x))),range(2,n))


# In[69]:


nums = range(2,50)
for i in range(2,8):
    nums = filter(lambda x: x%i,nums)
    
print(list(nums))

