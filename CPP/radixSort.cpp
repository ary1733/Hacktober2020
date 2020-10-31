//MIT License
//Copyright (c) 2020 sarthaka1310

#include<iostream>
#include<vector>
#include<functional>

using namespace std;

#define ll long long

vector<ll> counting_sort(vector<ll> v, function<ll(ll)> key = [](ll x){return x;}, ll k=-1)
{
	vector<ll> w;
	w.reserve(v.size());

	if(k==-1){
		for(auto i : v)
		if(k<i)k=i;
	}

	vector<vector<ll>> table(k+10); //vector<type_of_unsorted_vector>

	for(auto i : v)
		table[key(i)].push_back(i);

	for(ll i=0; i<=k+5; i++)
		for(auto j : table[i])
			w.push_back(j);

	return w;
}

vector<ll> radix_sort(vector<ll> v, ll k=-1)
{
	if(k==-1){
		for(auto i : v)
		if(k<i)k=i;
	}

	ll b=v.size(); //base for radixsort is size of array
	
	// MSB 'd' in maximum element 'k' in base b
	ll d=0, temp=k;
	while(temp/=b)
		d++;
	
	ll power_count=1;
	for(ll i=0;i<=d;i++){
		function<ll(ll)> key;
		key = [power_count,b](ll x){return ((x/power_count)%b);};
		v=counting_sort(v, key, k);
		power_count*=b;
	}

	return v;
}

int main()
{
	vector<ll> v = {10, 9, 4, 5, 7};

	for(auto i : v)
		cout<<i<<" ";

	v=radix_sort(v);

	cout<<"\n Sorted:\n";
	for(auto i : v)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}
