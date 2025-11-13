class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        result = []
        i = 0
        while i < len(intervals):
            if len(result) == 0:
                result.append(intervals[i])
            else:
                start = end = 0
                if result[-1][1] >= intervals[i][0]:
                    result[-1][0] = min(result[-1][0], intervals[i][0])
                    result[-1][1] = max(result[-1][1], intervals[i][1])
                else:
                    result.append([intervals[i][0], intervals[i][1]])
            
            i += 1
        
        return result