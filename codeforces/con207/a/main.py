#! /usr/bin/env python 

m = int(input()) 
c = input().split()
c = [ int(i) for i in c ] 
x, y = input().split()
x, y = int(x), int(y) 
sum = sum(c) 
ans =0 
count = 0
for i in range(m) : 
    if count >= x and count <=y and sum -count >=x and sum-count <=y  :
        ans = i+1
        break
    count += c[i]
print(ans) 


