class Solution:
    def calculate(self, s: str) -> int:
        i = 0
        curr = prev = res = 0

        curr_operator = "+"

        while i < len(s):
            curr_char = s[i]

            if curr_char.isdigit():
                while i < len(s) and s[i].isdigit():
                    curr = curr * 10 + int(s[i])
                    i += 1
                
                i -= 1

                if curr_operator == "+":
                    res += curr
                    prev = curr

                elif curr_operator == "-":
                    res -= curr
                    prev = -curr

                elif curr_operator == "*":
                    # perform undo
                    # res = 5, curr 2, prev = 2
                    res -= prev # res = 3
                    res += (prev * curr) # res = 3 + (2*2) = 7

                    prev = (prev * curr) # prev = 2 * 2 = 4
                else:
                    # perform undo
                    res -= prev
                    res += int(prev / curr)

                    prev = int(prev / curr)
                
                curr = 0

            elif curr_char != " ":
                curr_operator = curr_char

            i += 1
        
        return res


        # stack
        # stack, curr, curr_operator = [], 0, "+"
        # i = 0
        # while i < len(s):
        #     curr_char = s[i]

        #     if curr_char.isdigit():
        #         curr = curr * 10 + int(curr_char)
            
        #     if (curr_char != " " and not curr_char.isdigit()) or i == len(s) - 1:
        #         if curr_operator == "+":
        #             stack.append(curr)
        #         elif curr_operator == "-":
        #             stack.append(-curr)
        #         elif curr_operator == "*":
        #             stack[-1] *= curr
        #         else:
        #             stack[-1] = int(stack[-1] / curr)
                
                
        #         curr = 0
        #         curr_operator = curr_char
            
        #     i += 1
        
        # return sum(stack)