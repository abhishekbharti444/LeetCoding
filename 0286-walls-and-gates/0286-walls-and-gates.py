class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        maxVal = 2147483647
        self.m = len(rooms)
        self.n = len(rooms[0])
        visited = [[False] * self.n for _ in range(self.m)]
        q = collections.deque()
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
        def isValid(x,y):
            return x >= 0 and x < self.m and y >= 0 and y < self.n
        for i in range(self.m):
            for j in range(self.n):
                if rooms[i][j] == 0:
                    q.append((i,j))
                    
        
        level = 0
        while q:
            k = len(q)
            for i in range(k):
                (x,y) = q.popleft()
                visited[x][y] = True
                if rooms[x][y] != 0:
                    rooms[x][y] = min(level, rooms[x][y])
                for j in range(4):
                    r = x+dx[j]
                    c = y+dy[j]
                    if isValid(r,c) and not visited[r][c] and rooms[r][c] != -1 and rooms[r][c] == maxVal:
                        q.append((r,c))
            level += 1
                            
                        
                    
                    