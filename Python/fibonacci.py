def getNthFibonacci(x):
    first,second=1,1
    if x==1:
        return 1
    elif x==2:
        return 1
    else:
        for x in range(x-2):
            ne=first+second
            first=second
            second=ne
    return ne
