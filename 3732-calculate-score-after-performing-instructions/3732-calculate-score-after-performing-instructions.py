class Solution:
    def calculateScore(self, instructions: List[str], values: List[int]) -> int:
        n = len(instructions)
        i = 0
        result = 0
        while i >= 0 and i < n and instructions[i] != "visited":
            current_action = instructions[i]
            instructions[i] = "visited"

            match current_action:
                case "add":
                    result += values[i]
                    i += 1
                case "jump":
                    i += values[i]
                case _:
                    break
        
        return result