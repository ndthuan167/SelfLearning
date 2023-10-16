### 10 points : https://www.hackerrank.com/challenges/write-a-function/problem?isFullScreen=true
## Thuan - 23.10.16

def is_leap(year):
    leap = False
    
    if year % 4 == 0 and year % 100 != 0:
        leap = True
    if year % 400 == 0:
        leap = True
    return leap

year = int(input())
print(is_leap(year))
