'''You need to pass a message to the bunny prisoners, but to avoid detection, the
code you agreed to use is... obscure, to say the least. The bunnies are given food on
standard-issue prison plates that are stamped with the numbers 0-9 for easier sorting,
and you need to combine sets of plates to create the numbers in the code. The signal
that a number is part of the code is that it is divisible by 3. You can do smaller
numbers like 15 and 45 easily, but bigger numbers like 144 and 414 are a little trickier.
Write a program to help yourself quickly create large numbers for use in the code,
given a limited number of plates to work with.

You have L, a list containing some digits (0 to 9). Write a function solution(L) which
finds the largest number that can be made from some or all of these digits and is
divisible by 3. If it is not possible to make such a number, return 0 as the solution.
L will contain anywhere from 1 to 9 digits. The same digit may appear multiple times
in the list, but each element in the list may only be used once.

-- Test cases --
Input :
solution.solution([3, 1, 4, 1])
Output:
    4311

Input:
solution.solution([3, 1, 4, 1, 5, 9])
Output:
    94311
'''

l =[3,1,4,1]

def solution(l):
    
    number=''
    ans=''
    l = sorted(l,reverse=True)
    for i in l:
        number +=str(i)
    
    lis0= [x for x in l if x%3==0]
    lis1= [x for x in l if x%3==1]
    lis2= [x for x in l if x%3==2]
    
    if int(number)%3==0:
        return int(number)
    elif int(number)%3!=0 and len(lis0)==0 and (len(lis1)==0 or len(lis2)==0):
        return 0
    elif int(number)%3==1:   
        if len(lis1)==0 and len(lis2)>=2:
            lis2.pop()
            lis2.pop()
        else :
            lis1.pop()
        final_lis= lis0+lis1+lis1
       # if len(final_lis==0):return 0
        final_lis =  sorted(final_lis,reverse=True)
        
        for i in final_lis:
            ans +=str(i)
        return int(ans)
    
    elif int(number)%3==2:
        if len(lis2)==0 and len(lis1)>=2:
            lis1.pop()
            lis1.pop()
        else:
            lis2.pop()
        final_lis= lis0+lis1+lis1
       # if len(final_lis==0):return 0
        final_lis = sorted(final_lis,reverse=True)
        for i in final_lis:
            ans +=str(i)
        return int(ans)

print(solution(l))

        
    
    
