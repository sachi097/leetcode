class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        res, num, sign = 0, 0, 1

        i = 0
        while i < len(s):
            curr_char = s[i]

            if curr_char.isdigit():
                num = num * 10 + int(curr_char)
            elif curr_char == "+":
                res += (num * sign)
                num = 0
                sign = 1
            elif curr_char == "-":
                res += (num * sign)
                num = 0
                sign = -1
            elif curr_char == "(":
                stack.append(res)
                stack.append(sign)
                num = 0
                res = 0
                sign = 1
            elif curr_char == ")":
                res += (num * sign)
                num = 0

                prev_sign = stack.pop()
                prev_res = stack.pop()
                res = (res*prev_sign) + prev_res
            i += 1

        return res + (num * sign)

        