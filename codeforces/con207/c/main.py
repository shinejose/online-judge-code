#竟然比静态list的实现快 1.8倍
class Node: 
    def __init__(self, l, r, value, cover) :
        self.l = l
        self.r = r
        self.value = value
        self.cover =cover
        self.lc = 0 
        self.rc = 0
    def print(self) : 
        print(self.l,self.r,self.value,self.cover,
                self.lc, self.rc,sep=' ') 


class SegmentTree :
    def __init__(self, l, r) :
        self.index = {} 
        self.segmentTree = self.createSegmentTree(l, r, None)  
    def initCreate(self, l, r) :
        self.L = lambda node : int(node << 1 )
        self.R = lambda node : int((node<<1) +1)
        self.root = 1
        self.size = 0 
        self.node = [[]]*(4*r)
        self.index = [[]]*(4*r) 
        self.create(self.root,l,r) 

    def create(self, node,  l, r) : 
        segmentTree = Node(l, r, 0, 0) 
        if l == r - 1: 
            segmentTree.cover =1 
            segmentTree.value =l
            self.node[self.size] =segmentTree
            self.size += 1 
            return self.size-1
        mid = int((l + r) /2 )
        segmentTree.lc=self.create(self.L(node),l, mid) 
        segmentTree.rc=self.create(self.R(node),mid,r) 
        self.node[self.size] =segmentTree
        self.size += 1 
        return self.size-1

    def createSegmentTree(self,l, r, f) :
        segmentTree = {'l': l, 'r': r ,'cover': 0} 
        if l == r-1  :
            segmentTree['value'] = l
            segmentTree['father'] =f
            self.index[l] = segmentTree 
            return segmentTree
        mid =int(  (l+r) /2 )
        segmentTree['lc'] = self.createSegmentTree(l, mid, segmentTree) 
        segmentTree['rc']  = self.createSegmentTree(mid , r, segmentTree) 
        segmentTree['father'] = f
        return segmentTree
    def _push(self, node, l, r, value) :
        if node['l'] ==l and node['r'] == r and node['cover'] == 0 : 
            node['cover']= value
        elif node['cover'] ==0 : 
            if 'lc' in node and node['lc']['r']  >= r : 
               self._push(node['lc'], l, r, value) 
            elif 'rc' in node and node['rc']['l'] <= l: 
                self._push(node['rc'], l, r, value) 
            else :
                if 'lc' in node :
                    self._push(node['lc'], l, node['lc']['r'], value) 
                if 'rc' in node: 
                    self._push(node['rc'], node['rc']['l'], r, value) 
    def push(self, l, r, value) :
        self._push(self.segmentTree, l, r, value) 
        
    def up(self, node ) :
        while True: 
            #print('l = {0}, r = {1} '.format(node['l'],node['r']))
            if node['cover'] != 0 :
                return node['cover']
            if node['father'] ==  None : 
                break
            node = node['father'] 
        return 0
    def traval(self, node) : 
        print('l={0},r={1},cover={2}'.format(node['l'],node['r'],node['cover']) )
        if 'lc' in node: 
            self. traval(node['lc'] ) 
        if 'rc' in node: 
            self. traval(node['rc'] )




n, m = map(int, input().split()) 

d  = {} 
t = SegmentTree(1,n+1)
#print(t.segmentTree)
#for i in range(1,n+1) : 
    #print(t.index[i]['l'], t.index[i]['r']) 
#print(t.up( t.index[1]  ))
for i in range(m): 
    f = [[]]*3 
    f[0], f[1], f[2] = map(int, input().split())
    if f[0] <= f[2] -1 :
        t.push(f[0], f[2]  , f[2] )
    if f[2] +1  <=  f[1] : 
        t.push(f[2]+1,f[1]+1 , f[2] )

out = open('out','w')
for i in range(1,n+1) : 
    print(t.up(t.index[i]), end=' ',file =out ) 
print(file =out ) 

#t.traval(t.segmentTree) 
