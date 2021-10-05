#Python program for Array Rotation   
arr = [1, 2, 3, 4, 5];     
#n is the int value that determine times of rotation   
n = 3;

#Initilize an empty list
temp = []

#Store the Non-rotating elements to temp 
for i in range(n, len(arr)):
    temp.append(arr[i])

#Append the rotated elements to temp
for i in range(n):
    temp.append(arr[i])

#Printing the rotated array
for i in temp:
    print(i, end=" ")
