### 10 points : https://www.hackerrank.com/challenges/list-comprehensions/problem?isFullScreen=true
## Thuan - 23.10.16

if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    
    list_lexicographic = [0,0,0]
    list_result_sorted = []
    list_result = []
    
    for index_x in range(0, x + 1):
        list_lexicographic[0] = index_x
        for index_y in range(0, y + 1):
            list_lexicographic[1] = index_y
            for index_z in range(0, z + 1):
                list_lexicographic[2] = index_z
                if sum(list_lexicographic) != n :
                    for item in range(0, 3):
                        list_result_sorted.insert(item, list_lexicographic[item])
                    list_result.append(list_result_sorted)
                    list_result_sorted = []
    print(list_result)
        