def shell_sort(array):            #function to sort the array using shell sort 
    gap = len(array)//2
    shift=0
    times=0
    comparison=0
    while gap > 0:
        times+=1
        for i in range(gap,len(array)):
            temp = array[i]
            j = i
            while  j >= gap and array[j-gap] >temp:
                array[j] = array[j-gap]
                j -= gap
                comparison+=1
                shift+=1
            array[j] = temp
            comparison+=1
        print("Array after ",times,"th pass is : ",array)
        gap = gap//2
    print("Array after sorting is : ",array)
    print(shift," number of shift and",comparison," comparisons")

def input_array():                       #function for taking input of array
    attended=[]
    number_of_attendee=int(input("Enter number of attendee : "))
    for i in range(number_of_attendee):
        tep=int(input("Enter roll number of attendee:"))
        attended.append(tep)
    return attended

if __name__ == '__main__':
    arr=input_array()
    shell_sort(arr)
    print("Array after sorting using shell sort : ",arr)