class Solution:
    
    
    """
        The idea is to sort the array based on end time and count the other balloons can be burst for that end.
            Approach : 
                1. Sort the arr based on the end point.
                2. If the start of the current balloon is smaller than the current end, increment count(burst the current balloon)
                3. If not just update the end. Notice here we are not incrementing the count as this requires an arrow separately.
                4. Count means the number of balloons for which we don't need a separate arrow.

            Time : O(N);
            Space : O(1);
    """
    
    
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key = lambda x: x[1])
        count = 0
        # end = -1000001
        end = points[0][1]
        for i in range(1, len(points), 1):
            if (points[i][0] <= end): count += 1
            else: end = points[i][1]
        
        return len(points) - count
                
        