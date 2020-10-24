#include<bits/stdc++.h>
using namespace std;

int* lis(int* arr, int n){

    int* result1 = new int[n];
    result1[0] = 1;
    
    for(int i=1 ; i<n ; i++){
        
        result1[i] = 1;
        for(int j=i-1 ; j >= 0 ; j--){
        
            if(arr[j] >= arr[i])
                continue;
            int temp = result1[j] + 1;
            if(temp > result1[i])
                result1[i] = temp;
        }
    }
    return result1;
}

int* lis_b(int* arr, int n){

	int* result2 = new int[n];
	result2[n-1] = 1;
	
    for(int i=n-2 ; i >= 0 ; i--){
		
        result2[i] = 1;
		for(int j=i+1 ; j<n ; j++){
		
        	if(arr[j] >= arr[i])
				continue;
			int temp = result2[j] + 1;
			if(temp > result2[i])
				result2[i] = temp;
		}
	}
	return result2;
}

int longestBitonicSubarray(int * arr, int n){

    int* lis_ = lis(arr, n);
    int* dis_ = lis_b(arr, n);

    int lengthLBS = 0;
    for(int i=0 ; i<n ; i++){
        
    	int temp = lis_[i] + dis_[i] - 1;
    	if(temp > lengthLBS)
    		lengthLBS = temp;

    }
    return lengthLBS;
}
int main(){
    int n;
    cin >> n;

    int * arr = new int[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int lengthLBS = longestBitonicSubarray(arr ,n);
    cresult2 << lengthLBS << endl;

    delete [] arr;
    return 0;
}
