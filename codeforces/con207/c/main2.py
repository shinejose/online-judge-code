#本质还是线段树
#这种方法只是取巧了
#没有用
R = lambda : map(int,input().split()) 

n, m = R()
res = [0] *(n+1) 
t = [ i+1 for i in range(n+1) ] 
for i in range(m): 
    l, r, v = R()
    j = l
    while j<= r  : 
        if j!= v and res[j] ==0 :
            res[j] = v
        tmp = t[j] 
        if j < v : 
            t[j] =v 
        else :
            t[j] = r  +1 
        j = tmp
print(' '.join(map(str,res[1:])))
