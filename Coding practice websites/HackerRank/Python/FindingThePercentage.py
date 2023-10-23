### 10 points : https://www.hackerrank.com/challenges/finding-the-percentage/problem?isFullScreen=true
## Thuan - 23.10.23

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores        
    query_name = input()

    result = "{:.2f}".format(sum(student_marks[query_name])/3)
    print(result)

