# Python program to print solid rectangle star pattern


#Number of rows: 3
#Number of columns: 5

#* * * * *
#* * * * *
#* * * * *
#Program to print solid rectangular star pattern
# Function to print solid rectangle

def solid_rectangle(n, m):

for i in range(1, n+1):

for j in range(1, m+1):

print(“*”, end = “”)

print()

rows = int(input(“Enter the number of rows : “))

columns = int(input(“Enter the number of columns : “))

solid_rectangle(rows, columns)