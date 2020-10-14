import math

# global declaration of input list and segment tree list
a = []
seg_tree = []

def buildSegmentTree(root:"int", low:"int", high:"int")->"void":
    """ Builds the segment tree """
    if low == high:
        seg_tree[root] = a[low]
        return
    
    mid = math.floor(low + ((high - low) / 2))
    
    buildSegmentTree(2*root+1, low, mid)
    buildSegmentTree(2*root+2, mid+1, high)
    
    seg_tree[root] = seg_tree[2*root+1] + seg_tree[2*root+2]

def query(root:"int", l:"int", r:"int", low:"int", high:"int")->"int":
    """ queries the segment tree to give sum of range [l, r] """
    if l > high or r < low:
        return 0
    elif l <= low and high <= r:
        return seg_tree[root]
    
    mid = math.floor(low + ((high - low) / 2))
    
    return query(2*root+1, l, r, low, mid) + query(2*root+2, l, r, mid+1, high)

def update(idx:"int", val:"int", root:"int", low:"int", high:"int")->"void":
    """ updates index idx to val in segment tree """
    if low == high:
        seg_tree[root] = val
        return
    
    mid = math.floor(low + ((high - low) / 2))
    
    if idx <= mid:
        update(idx, val, 2*root+1, low, mid)
    else:
        update(idx, val, 2*root+2, mid+1, high)

if __name__ == '__main__':
    # Code for testing
    a = [1, 2, 3, 4, 5]
    n = len(a)
    print(n)
    seg_tree = [0] * (4*n)
    buildSegmentTree(0, 0, n-1)
    print(query(0, 0, 3, 0, n-1))
    update(3, 5, 0, 0, n-1)
    print(query(0, 0, 3, 0, n-1))

