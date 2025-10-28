class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_gas = sum(gas)
        total_cost = sum(cost)

        if total_cost > total_gas:
            return -1
        
        result = 0
        current_total = 0

        for i in range(len(gas)):
            current_total += gas[i] - cost[i]

            if current_total < 0:
                result = i+1
                current_total = 0
        
        return result