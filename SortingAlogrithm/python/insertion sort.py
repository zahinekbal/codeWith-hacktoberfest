def insertion_sort(array):         #function to sort array using insertion sort
    comparison=0
    shift=0
    for i in range(1,len(array)):
        j=i-1
        val=array[i]
        while(j>=0 and val<array[j]):
            shift+=1
            comparison+=1
            array[j+1]=array[j]
            array[j]=val
            j-=1
        comparison+=1
        print("Array after ",i+1,"th pass is : ",array)
    print("Array after sorting is : ",array)
    print(shift," number of shift and",comparison," comparisons")

def input_array():                       #function for taking input of array
    attended=[]
    number_of_attendee=int(input("Enter total : "))
    for i in range(number_of_attendee):
        tep=int(input("Enter number :"))
        attended.append(tep)
    return attended

if __name__ == '__main__':
    arr=input_array()
    insertion_sort(arr)
    print("Array after sorting using selection sort : ",arr)
    