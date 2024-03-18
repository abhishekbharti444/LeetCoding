class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key = lambda x: x[1])
        count = 0
        # end = -1000001
        end = points[0][1]
        for i in range(1, len(points), 1):
            if (points[i][0] <= end): count += 1
            else: end = points[i][1]
        
        return len(points) - count
                
        