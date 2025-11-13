class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # freq_map = Counter(tasks)
        # max_heap = [-freq for freq in freq_map.values()]

        # heapq.heapify(max_heap)
        
        # q = deque()
        # counter = 0

        # while max_heap or q:
        #     counter += 1

        #     if max_heap:
        #         current_task = heappop(max_heap)
            
        #         # used current task
        #         current_task += 1

        #         if current_task < 0:
        #             q.append([counter + n, current_task])
            
        #     if q and counter == q[0][0]:
        #         heappush(max_heap, q.popleft()[1])

        # return counter

        if n == 0:
            return len(tasks)

        freq_map = Counter(tasks)
        freqs =  list(freq_map.values())
        freqs.sort()
        max_freq = freqs[-1]
        num_of_blanks = max_freq - 1
        num_of_idle_spots = num_of_blanks * n

        for freq in freqs[:-1]:
            num_of_idle_spots -= min(num_of_blanks, freq)
        

        if num_of_idle_spots > 0:
            return len(tasks) + num_of_idle_spots
        
        return len(tasks)
