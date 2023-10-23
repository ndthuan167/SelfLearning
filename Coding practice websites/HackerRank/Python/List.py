### 10 points : https://www.hackerrank.com/challenges/python-lists/problem?isFullScreen=true
## Thuan - 23.10.23

if __name__ == '__main__':
    N = int(input())
    list = []
    request = []
    each_request = []
    for index in range(0, N):
        request.append(input())
    for each in request:
        each_request = each.split()
        if each_request[0] == "insert":
            list.insert(int(each_request[1]), int(each_request[2]))
        elif each_request[0] == "print":
            print(list)
        elif each_request[0] == "remove":
            list.remove(int(each_request[1]))
        elif each_request[0] == "append":
            list.append(int(each_request[1]))
        elif each_request[0] == "sort":
            list.sort()
        elif each_request[0] == "pop":
            list.pop()
        elif each_request[0] == "reverse":
            list.reverse()