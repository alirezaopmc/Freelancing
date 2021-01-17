class DSU:
    def __init__(self, size):
        self.size = size
        """Roote har component dar self.root zakhire mishe, avale kar hame roote khodeshoonan"""
        self.root = [ i for i in range(size) ]
        """Tedade node haye har component dar self.component_size[root] zakhire mishe, aval hame 1"""
        self.component_size = [ 1 for i in range(size) ]

    def find(self, u):
        """Roote u ra peyda mikonad, agar root nabood recusive path compression mikonad"""
        if self.root[u] == u:
            return u
        else:
            self.root[u] = self.find(self.root[u])
            return self.root[u]

    def nodes(self, v):
        """Tedade node haye componenti ke v dar aan hast ro mide, in ham mese find compression mitune dashte bashe comment krdm"""
        # if self.component_size[v] == self.component_size[self.find[v]]:
        #     return self.component_size[v]
        # else:
        #     self.component_size[v] = self.nodes(self.find(v))
        #     return self.component_size[v]
        return self.component_size[self.find(v)]
    
    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u == root_v:
            """Ham componenti"""
            return
        
        size_u = self.nodes(root_u)
        size_v = self.nodes(root_v)

        if self.nodes(root_v) > self.nodes(root_u):
            self.root[root_u] = root_v
            self.component_size[root_v] = size_u + size_v
        else:
            self.root[root_v] = root_u
            self.component_size[root_u] = size_u + size_v

    def show(self):
        for i in range(self.size):
            print(self.root[i], end=' ')
        print()

dsu = DSU(10)

dsu.union(1, 2)
dsu.union(7, 2)
print(dsu.find(7))
dsu.show()