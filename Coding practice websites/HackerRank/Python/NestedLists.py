### 10 points : https://www.hackerrank.com/challenges/nested-list/problem?isFullScreen=true
## Thuan - 23.10.16

if __name__ == '__main__':
    
    information = []
    list_information = []
    list_score = []
    number_max = 0
    list_name = []

    for _ in range(int(input())):
        name = input()
        score = float(input())

        information.insert(0, name)
        information.insert(1, score)
        list_information.append(information)
        information = []

    for each in list_information:
        list_score.append(each[1])

    list_score.sort()

    for each in list_score:
        if each == min(list_score):
            number_max = number_max + 1

    for index in range(0, number_max):
        list_score.remove(min(list_score))

    second_min = list_score[0]

    for each in list_information:
        if each[1] == second_min:
            list_name.append(each[0])
    list_name.sort()

    for index in list_name:
        print(index)
