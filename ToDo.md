Here Add new algo idea that you can think
## (2)  Add a New algorithm to flatten a dictionary in the python 
### Sample input 
```

# ### flatten a dictionary : ->> 
# 
# example={'name':'HELLO_WORLD',
# 'Age':20,
#  'marks':[{'subject':'english','score':20,'last_yearscores':[{'subject':'english','score':[83,23,12]}]},{'subject':'science','score':80}],
#  'metaData':{'ip':'10.23.102.10','pc_info':'Chrome-X-Build','active_subscriptions':['HT','Heoku','google']}
# }
# flatten_dic(example) ->>
#  ('10.23.102.10', 'root.metaData.ip'),
#  ('Heoku', 'root.metaData.active_subscriptions[1]'),
#  (20, 'root.Age'),
#  ('google', 'root.metaData.active_subscriptions[2]'),
#  ('HT', 'root.metaData.active_subscriptions[0]'),
#  (20, 'root.marks[0].score'),
#  (80, 'root.marks[1].score'),
#  ('english', 'root.marks[0].subject'),
#  ('science', 'root.marks[1].subject'),
#  ('Chrome-X-Build', 'root.metaData.pc_info'),
#  ('HELLO_WORLD', 'root.name')

```



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
