#include <bits/stdc++.h>
using namespace std;

int n, arr[1000001], seg_tree[4000001];

int func(int a, int b){
    return a+b; // return value to be changed as per need
}

void constructSegmentTree(int idx, int l, int r){
    if(l==r){
        seg_tree[idx] = arr[l];
        return ;
    }
    int mid = l + (r-l)/2;
    constructSegmentTree(2*idx+1, l, mid);
    constructSegmentTree(2*idx+2, mid+1, r);
    seg_tree[idx] = func(seg_tree[2*idx+1], seg_tree[2*idx+2]);
}

int query(int l, int r, int idx, int low, int high){
    if(r<low || l>high) return 0; // return value to be changed as per need
    else if(low>=l && high<=r) return seg_tree[idx];
    int mid = low + (high-low)/2;
    return query(l, r, 2*idx+1, low, mid) + query(l, r, 2*idx+2, mid+1, high);
}

void update(int idx, int val, int root, int low, int high){
    if(low==high){
        seg_tree[root] = val;
        return ;
    }
    int mid = low + (high-low)/2;
    if(idx<=mid) update(idx, val, 2*root+1, low, mid);
    else update(idx, val, 2*root+2, mid+1, high);
}


int main(){
    // code for testing purposes
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5; 
    constructSegmentTree(0, 0, 4);
    cout<<query(0, 3, 0, 0, 4)<<"\n";
    update(3, 5, 0, 0, 4);
    cout<<query(0, 3, 0, 0, 4)<<"\n";
    return 0;
}