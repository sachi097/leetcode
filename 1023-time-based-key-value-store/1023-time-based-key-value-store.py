class TimeMap:

    def __init__(self):
        self.store: [str, list] = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if self.store.get(key) != None:
            self.store[key].append([timestamp, value])
            return
        
        self.store[key] = [[timestamp, value]]

    def get(self, key: str, timestamp: int) -> str:
        if self.store.get(key) == None:
            return ""
        
        return self.find_value(self.store[key], timestamp)
    
    def find_value(self, arr: list, search_timestamp: int):
        res = ""
        low, high = 0, len(arr) - 1
        while low <= high:
            mid = ( low + high ) // 2
            if arr[mid][0] <= search_timestamp:
                res = arr[mid][1]
                low = mid + 1
            else:
                high = mid - 1
        
        return res


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)