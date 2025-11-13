class dll:
    def __init__(self, key, value):
        self.prev  = None
        self.next  = None
        self.key   = key
        self.value = value

class LRUCache:

    def __init__(self, capacity: int):
        self.cache: Dict[int, dll] = {}
        self.capacity = capacity

        self.head = dll(0, 0)
        self.tail = dll(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if self.cache.get(key, None) != None:
            node = self.cache.get(key)
            self.remove_node(node)
            self.move_to_head(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if self.cache.get(key, None) != None:
            node = self.cache.get(key)
            self.remove_node(node)
        
        new_node = dll(key, value)
        self.cache[key] = new_node
        self.move_to_head(new_node)
        
        if len(self.cache.keys()) > self.capacity:
            node_to_remove = self.tail.prev
            self.remove_node(node_to_remove)
            del self.cache[node_to_remove.key]
    
    def move_to_head(self, node: dll):
        node.next = self.head.next
        self.head.next.prev = node
        node.prev = self.head
        self.head.next = node
    
    def remove_node(self, node: dll):
        node.prev.next = node.next
        node.next.prev = node.prev

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)