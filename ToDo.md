Here Add new algo idea that you can think


## (1) Algo Description:
***A Simple C++ program which takes 'n' integer input on the first line, a
vector array of size 'n' as the input on the next 'n' lines, and displays the 
user-input array and sorted array using bubble sort as the output.***

# Code:
```

#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	vector<int>arr;
	int hold;
	int i;
	int j;
	int num;
	int n;
	cout<<"\nEnter total number of elements: ";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter Number "<<i+1<<" : ";
		cin>>num;
		arr.push_back(num);
	}
	cout<<"\nThe array entered by the user is\n";
	for(i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i]<<"\t";
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				hold=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=hold;
			}
		}
	}
	cout<<"\nThe sorted array is\n";
	for(i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i]<<"\t";
    }
    system("pause");
    return 0;
}

```