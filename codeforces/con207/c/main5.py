class Node:
    def __repr__ (self) : 
        return (' [{0},{1}]'.
                format(self.l,self.r,self.father,self.father)) 

def create(tree, l, r ,f,index) :
    temp = Node() 
    temp.l = l 
    temp.r = r 
    temp.father = f
    temp.cover =0 
    if( l == r -1 ) : 
        mid = (l+r)/2.0 
        tree[mid] =temp 
        tree[mid].lc = None
        tree[mid].rc =None
        index[l]  = tree[mid] 
        return tree[(l+r)/2.] 
    else : 
        mid = int(( l+r) /2 )
        tree[mid] = temp
        tree[mid].lc=create(tree,l,mid,tree[mid] ,index ) 
        tree[mid].rc=create(tree,mid,r,tree[mid] ,index) 
        return tree[mid] 
def traval(node,depth) :
    for i in range(depth): 
        print("    ",end='') 
    print('[{0},{1}],cover={2}'.format(node.l,node.r, node.cover ) ) 
    if( node.lc!= None ) :
        traval(node.lc,depth+1) 
    if( node.rc != None) :
        traval(node.rc,depth+1) 


def push(node, l, r, cover) :
    if(node.cover==0 and node.l ==l and node.r==r) :
        node.cover = cover
    elif(node.cover == 0):
        if(node.lc !=None and node.lc.r >=r  ):
            push(node.lc,l,r,cover) 
        elif(node.rc !=None and node.rc.l<=l) :
            push(node.rc,l,r,cover) 
        else :
            if(node.lc!= None) :
                push(node.lc,l,node.lc.r,cover) 
            if(node.rc!=None):
                push(node.rc,node.rc.l,r,cover) 

def up(node): 
    while(node.father !=-1) :
        if(node.cover != 0) : 
            return node.cover
        node = node.father
    if(node.cover!=0) :
        return node.cover
    else :
        return 0 

    
 



read = lambda : map(int, input().split() ) 
n, m = read() 

tree = {} 
index= {}
root = create(tree,1,n+1,-1, index ) 
for i in range(m): 
    f= [[]]*3
    f[0], f[1], f[2]= read()
    if f[0] <= f[2] -1 :
        push(root, f[0], f[2]  , f[2])
    if f[2] +1  <=  f[1] : 
        push(root, f[2]+1,f[1]+1 , f[2])
for i in range(1,n+1) : 
    print(up(index[i]) , end=' ') 
print() 

