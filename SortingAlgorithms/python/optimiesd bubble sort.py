def optimised_bubble_sort(array):    #function to sort the array using optimised bubble sort
    swaps=0
    comparison=0
    isSwap=True
    i=0
    while(isSwap and i<len(array)):
        isSwap=False
        for j in range(1,len(array)):
            if(array[j-1]>array[j]):
                swaps+=1
                isSwap=True
                temp=array[j]
                array[j]=array[j-1]
                array[j-1]=temp
            comparison+=1
        print("Array after ",i+1,"th pass is : ",array)
        i+=1
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
    optimised_bubble_sort(arr)
    print("Array after sorting using selection sort : ",arr)
    