def decToBinary(n): 
    for i in range(31, -1, -1):  
        k = n >> i; 
        if (k & 1): 
            print("1", end = ""); 
        else: 
            print("0", end = ""); 
n = 64; 
decToBinary(n); 
