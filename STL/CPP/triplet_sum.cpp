// given array of distinct elements find no of triplets such that
// sum of 2 numbers = 3rd number
// time O(N^2) space O(1)
int countTriplet(int arr[], int n)
	{
	    
	    sort(arr,arr+n);
	    int i,j,k,ans = 0;
	    
	    for(k = n-1; k >= 2; k--){
	        
	        for(i = 0, j = n-1; i < j;){
	            
	            if(arr[i] + arr[j] == arr[k]){
	                ans++;
	                i++;
	                j--;
	            }
	            else if(arr[i] + arr[j] < arr[k]){
	                i++;
	            }
	            else{
	                j--;
	            }
	        }
	    }
	    return ans;
	}