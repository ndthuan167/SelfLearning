### 10 points : https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem?isFullScreen=true
## Thuan - 23.10.16

## --->> method 1 <<--- ##
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    
    list_ = list(arr)
    second_max = min(list_)

    for item in list_:
        if item > second_max and item < max(list_):
            second_max = item
    print(second_max)


## --->> method 2 <<--- ##
# if __name__ == '__main__':
#     n = int(input())
#     arr = map(int, input().split())

#     list_result = []
#     number_max = 0

#     for each in arr:
#         list_result.append(each)
#     list_result.sort(reverse=True)

#     for index in list_result:
#         if index == max(list_result):
#             number_max = number_max + 1

#     for index in range(0, number_max):
#         list_result.remove(max(list_result))

#     print(list_result[0])