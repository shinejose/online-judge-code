

def L(x) : 
    return (x<<1)
def R(x): 
    return (x<<1)+1 

class Node: 
    def __init__(self, l, r, f, value):
        self.l =l 
        self.r =r
        self.f =f 
        self.value =value
    def __repr__(self):
        return '[l: {0}, r: {1}, f: {2}, value: {3}]'.format(
            self.l, self.r, self.f, self.value)

def create(node, l, r, f) :
    global tree
    tree[node] = Node(l, r, f, 0)
    if l == r- 1:
        global index
        index[l] = node
    else :
        mid = int((l+r) >> 1)
        create((node<<1), l, mid, node)
        create((node<<1)+1,mid,r ,node)

def push(node, l, r, value) :
    global tree 
    if tree[node].l ==l and tree[node].r ==r and tree[node].value==0:
        tree[node].value = value
    elif tree[node].value ==0 :
        if tree[L(node)].r >= r : 
            push(L(node), l, r, value ) 
        elif tree[R(node)].l <= l :
            push(R(node), l, r, value) 
        else :
            push(L(node), l, tree[L(node)].r, value) 
            push(R(node), tree[R(node)].l, r, value) 
            
def up(node) : 
    global tree 
    while tree[node].f != -1 : 
        if tree[node].value !=0 : 
            return tree[node].value
        else :
            node =  node>>1 
    return 0


read = lambda : map(int, input().split() ) 
n, m = read() 

tree = {} 
index ={} 

create(1, 1, n+1, -1)

for i in range(m): 
    f= [[]]*3
    f[0], f[1], f[2]= read()
    if f[0] <= f[2] -1 :
        push(1, f[0], f[2]  , f[2])
    if f[2] +1  <=  f[1] : 
        push(1, f[2]+1,f[1]+1 , f[2])

out = open('out','w') 
for i in range(1,n+1) : 
    print(up(index[i]) , end=' ', file = out ) 
print(file = out) 
out.close()

