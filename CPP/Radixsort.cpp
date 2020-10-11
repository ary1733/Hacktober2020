#include<bits/stdc++.h>
using namespace std;
 

void radix_sort(int arr[], int n){
    
    int maxelement = arr[0];
 
    for(int i=1;i<n;i++){
        maxelement = max(maxelement, arr[i]);
    }

    int digits = 0;
 
    while(maxelement > 0){
        digits++;
        maxelement /= 10;
    }
 
  
    for(int i=0;i<digits;i++){
 
        int power = pow(10, i);
 
        int n_arr[n];
        int count[10];
        memset(count, 0, sizeof(count));
        for(int j=0;j<n;j++){
 
            int num = (arr[j]/power) % 10;
 
            count[num]++;
        }
 
        for(int j=1;j<10;j++){
            count[j] += count[j-1];
        }
 
        for(int j=n-1;j>=0;j--){
 
       
            int num = (arr[j]/power) % 10;
 
            n_arr[count[num]-1] = arr[j];
            count[num]--;
        }
 
    
        for(int j=0;j<n;j++)
            arr[j] = n_arr[j];
     
    }
 
	cout<<"\nRadix Sorted Array is: "<<endl;
    for(int x=0;x<n;x++)
    {
	
    	
        cout<<arr[x]<<" ";
 	}
               
}
 

int main(){
 	int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
    	cout<<"Enter element "<<i+1<<" : ";
    	cin>>array[i];
	}
	
	cout<<"Before sorting: "<<endl;
	
	for(int j=0;j<n;j++)
	{
		
		cout<<array[j]<<" ";
	}

    radix_sort(array, n);
 
    return 1;
}