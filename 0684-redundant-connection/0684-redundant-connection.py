class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = [0] * (n+1)
        for i in range(len(parent)):
            parent[i] = i;
        def getParent(index):
            if (parent[index] == index):
                return index
            parent[index] = getParent(parent[index])
            return parent[index]
        def unionMethod(a, b):
            pa = getParent(a)
            pb = getParent(b)
            if (pa == pb):
                return False
            elif (pa < pb):
                parent[pb] = pa
            else:
                parent[pa] = pb
            return True
        
        for edge in edges:
            if (not unionMethod(edge[0], edge[1])):
                return edge
            
        return []
        