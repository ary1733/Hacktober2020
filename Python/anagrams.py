str1=input("enter a word: ")
str2=input("enter another word: ")
a=len(str1)
b=len(str2)
string1=[]
string2=[]
if a==b:
    i=1
    while(i<=a+1):
        r=str1[i-1:i]
        string1.append(r)
        i+=1
    string1.sort()
    
    j=1
    while(j<=b+1):
        s=str2[j-1:j]
        string2.append(s)
        j+=1
    string2.sort()
    
if string1==string2:
    print("the words are anagrams")
else:
    print("the words are not anagrams")
