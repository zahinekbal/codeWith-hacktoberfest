def bubble_sort(array):        #function to sort array using bubble sort
    swaps=0
    comparison=0
    for i in range(0,len(array)):
        for j in range(1,len(array)):
            if(array[j-1]>array[j]):
                swaps+=1
                temp=array[j]
                array[j]=array[j-1]
                array[j-1]=temp
            comparison+=1
        print("Array after ",i,"th pass is : ",array)
    print("Array after sorting is : ",array)
    print(swaps," number of swaps and",comparison," comparisons")

def input_array():                       #function for taking input of array
    attended=[]
    number_of_attendee=int(input("Enter total : "))
    for i in range(number_of_attendee):
        tep=int(input("Enter number :"))
        attended.append(tep)
    return attended

if __name__ == '__main__':
    arr=input_array()
    bubble_sort(arr)
    print("Array after sorting using selection sort : ",arr)
    