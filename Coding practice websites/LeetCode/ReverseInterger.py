### https://leetcode.com/problems/reverse-integer/
## Thuan - 23.11.14

class Solution(object):
    def reverse(self, x):
        x_backup = x
        if x > 0: number = len(str(x))
        else:
            number = len(str(x)) - 1
            x = x * (-1)
        x_reverse = 0
        
        while number > 0 :
            x_reverse += (x % 10) * pow(10, number - 1)
            x = x // 10
            number = number -1
        if x_reverse > (pow(2,31) -1):
            return 0
        if x_backup > 0: return x_reverse
        else:
                return x_reverse *(-1)
        
if __name__ == '__main__':
    solu = Solution()
    print(solu.reverse(-15342364))