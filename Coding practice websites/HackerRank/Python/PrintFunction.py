### 10 points : https://www.hackerrank.com/challenges/python-print/problem?isFullScreen=true
## Thuan - 23.10.16

if __name__ == '__main__':
    n = int(input())
    
    list_number_str = []
    for index in range(1, n+1):
        list_number_str.append(str(index))
    print(''.join(list_number_str))