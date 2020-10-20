def quicksort(blist, start, end):
    ##'Sorts the list from indexes start to end - 1 inclusive.'
    if end - start > 1:
        p = partition(blist, start, end)
        quicksort(blist, start, p)
        quicksort(blist, p + 1, end)
 
 
def partition(blist, start, end):
    pivot = blist[start]
    i = start + 1
    j = end - 1
 
    while True:
        while (i <= j and blist[i] <= pivot):
            i = i + 1
        while (i <= j and blist[j] >= pivot):
            j = j - 1
 
        if i <= j:
            blist[i], blist[j] = blist[j], blist[i]
        else:
            blist[start], blist[j] = blist[j], blist[start]
            return j
 
 
blist = input('Enter the list of numbers: ').split()
blist = [int(x) for x in blist]
quicksort(blist, 0, len(blist))
print('Sorted list: ', end='')
print(blist)

## The user has to enter a list of numbers.
## The list is passed to the quicksort function.
## The sorted list is displayed.

