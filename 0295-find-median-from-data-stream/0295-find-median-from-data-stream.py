class MedianFinder:

    def __init__(self):
        self.min_heap = []
        self.max_heap = []

    def addNum(self, num: int) -> None:
        max_heap, min_heap = self.max_heap, self.min_heap
        if len(max_heap) == 0 or num < -max_heap[0]:
            heappush(max_heap, -num)
        else:
            heappush(min_heap, num)

        # rebalancing
        if abs(len(max_heap) - len(min_heap)) > 1:
            heappush(min_heap, -heappop(max_heap))
        elif len(min_heap) > len(max_heap):
            heappush(max_heap, -heappop(min_heap))

    def findMedian(self) -> float:
        max_heap, min_heap = self.max_heap, self.min_heap
        max_heap_size = len(max_heap)
        min_heap_size = len(min_heap)
        if max_heap_size == min_heap_size:
            return (-max_heap[0] + min_heap[0]) / 2.0
        return -max_heap[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()