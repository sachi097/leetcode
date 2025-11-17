class Trie:
    def __init__(self):
        self.ptr = [None] * 26
        self.is_end = False

class WordDictionary:

    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        node = self.trie
        for ch in word:
            idx = ord(ch) - ord('a')
            if not node.ptr[idx]:
                node.ptr[idx] = Trie()
            node = node.ptr[idx]
        node.is_end = True

    def search(self, word: str) -> bool:
        
        def dfs(node, i):
            # reached end of word
            if i == len(word):
                return node.is_end

            ch = word[i]

            if ch == '.':
                # try all children
                for child in node.ptr:
                    if child and dfs(child, i + 1):
                        return True
                return False
            else:
                idx = ord(ch) - ord('a')
                child = node.ptr[idx]
                if not child:
                    return False
                return dfs(child, i + 1)

        return dfs(self.trie, 0)