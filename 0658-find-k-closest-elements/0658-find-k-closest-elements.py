class Solution:
    
    def binary_search(self, arr: List[int], key: int):
        low, high = 0, len(arr) - 1

        while low <= high:
            mid = ( low + high ) // 2
            if arr[mid] == key:
                return mid
            
            if arr[mid] > key:
                high = mid - 1
            else:
                low = mid + 1
        
        return low

    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # max_heap = []
        # heapq.heapify(max_heap)

        # for ele in arr:
        #     diff = abs(ele - x)
        #     heapq.heappush(max_heap, (-diff, -ele))

        #     if len(max_heap) > k:
        #         heapq.heappop(max_heap)
        

        # result = []
        # while max_heap:
        #     result.append(-heapq.heappop(max_heap)[1])

        # result.sort()

        # return result

        closest_first_element = self.binary_search(arr, x)

        low = closest_first_element - 1
        high = closest_first_element

        # start selecting k elements

        result = []

        while(low >= 0 and high < len(arr) and k > 0):
            if abs(arr[low] - x) <= abs(arr[high] - x):
                result.append(arr[low])
                low -= 1
            else:
                result.append(arr[high])
                high += 1
            
            k -= 1
        
        while k > 0 and low >= 0:
            result.append(arr[low])
            low -= 1
            k -= 1

        while k > 0 and high < len(arr):
            result.append(arr[high])
            high += 1
            k -= 1

        return sorted(result)


