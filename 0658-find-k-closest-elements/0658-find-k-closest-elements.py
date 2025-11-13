class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        max_heap = []
        heapq.heapify(max_heap)

        for ele in arr:
            diff = abs(ele - x)
            heapq.heappush(max_heap, (-diff, -ele))

            if len(max_heap) > k:
                heapq.heappop(max_heap)
        

        result = []
        while max_heap:
            result.append(-heapq.heappop(max_heap)[1])

        result.sort()

        return result
