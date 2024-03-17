class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        start = newInterval[0]
        end = newInterval[1]
        index = 0
        res = []
        while (index < n and start > intervals[index][1]):
            res.append(intervals[index])
            index += 1
        while (index < n and end >= intervals[index][0]):
            start = min(start, intervals[index][0])
            end = max(end, intervals[index][1])
            index += 1
        
        res.append([start, end])
        
        while (index < n):
            res.append(intervals[index])
            index += 1
            
        return res