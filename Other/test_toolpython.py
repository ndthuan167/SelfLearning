# import sys
# from PyQt5 import QtWidgets, uic
#
# import pandas as pd
# import numpy as np
#
# app = QtWidgets.QApplication(sys.argv)
#
# window = uic.loadUi("untitled.ui")
# window.show()
# app.exec()

import xlrd
import re
from enum import Enum

wb = xlrd.open_workbook('test.xlsx')
sheet = wb.sheet_by_index(0)
course1 = []
course = []

IndexTrueCourse = []

listcourse = ["COURSE_NORMAL", "COURSE_TIMEDRY", "COURSE_HEAVYDUTY", "COURSE_HIGH_SPEED", "COURSE_SMALL_LOAD", "COURSE_DELICATES", "COURSE_SANITIZE_WITH_STEAM", "COURSE_WRINKLE_AWAY",	"COURSE_REFRESH",	"COURSE_TOWELS", "COURSE_BEDDING", "COURSE_ACTIVEWEAR", "COURSE_JEAN", "COURSE_SHIRTS", "COURSE_WOOL", "COURSE_PERMPRESS", "COURSE_ECONORMAL",	"COURSE_AIRFLUFF", "COURSE_RACKDRY", "COURSE_SIZE"]


for indexx in range(2, sheet.nrows):
    for indexy in range(0, sheet.ncols):
        course1.insert(indexy, sheet.cell_value(indexx, indexy))
    course.append(course1)
    course1 = []

for each_course in course:
    for index in range(1, len(each_course)):
        each_course[index] = "".join(re.findall('\d', each_course[index]))

def ChangeCourseName(coursenamebefore):
    if(coursenamebefore == "Normal"):
        coursenamebefore = "COURSE_NORMAL"
    elif (coursenamebefore == "Heavy Duty"):
        coursenamebefore = "COURSE_HEAVYDUTY"
    elif (coursenamebefore == "Bedding"):
        coursenamebefore = "COURSE_BEDDING"
    elif (coursenamebefore == "Delicates"):
        coursenamebefore = "COURSE_DELICATES"
    elif (coursenamebefore == "Perm Press"):
        coursenamebefore = "COURSE_PERMPRESS"
    elif (coursenamebefore == "Active Wear"):
        coursenamebefore = "COURSE_ACTIVEWEAR"
    elif (coursenamebefore == "Towels"):
        coursenamebefore = "COURSE_TOWELS"
    elif (coursenamebefore == "Air Sanitize"):
        coursenamebefore = "COURSE_SANITIZE"
    elif (coursenamebefore == "Shirts"):
        coursenamebefore = "COURSE_SHIRTS"
    elif (coursenamebefore == "Jeans"):
        coursenamebefore = "COURSE_JEAN"
    elif (coursenamebefore == "Eco Normal "):
        coursenamebefore = "COURSE_ECONORMAL"
    elif (coursenamebefore == "Low Temp."):
        coursenamebefore = "COURSE_LOW_TEMP"
    elif (coursenamebefore == "Steam Sanitize"):
        coursenamebefore = "COURSE_SANITIZE_WITH_STEAM"
    elif (coursenamebefore == "Small Load"):
        coursenamebefore = "COURSE_SMALL_LOAD"

    return  coursenamebefore

# for index in range(0,len(course)):
#     if(ChangeCourseName(course[index][0]) == "COURSE_SMALL_LOAD"):
#         print(index)

# print("PRIVATE const U16 mcau16NoMeetAddTimeByPulse[COURSE_SIZE][INITIAL_PULSE_LEVEL_SIZE] =		//종료 3분 전까지 건조가 충분히 이뤄지지 않으면 아래 조건에 맞도록")
# print("{//		PULSE_LEVEL_0,	PULSE_LEVEL_1,	PULSE_LEVEL_2,	PULSE_LEVEL_3,	PULSE_LEVEL_4,	PULSE_LEVEL_5")

# print("   {	MIN("+ str(course[indexx][1]) +"),		MIN(" + str(course[indexx][2]) +"),		MIN("+ str(course[indexx][3]) +"),		MIN("+ str(course[indexx][4]) +"),		MIN("+ str(course[indexx][5]) +"),		MIN("+ str(course[indexx][6]) +"	},	//" + str(course[indexx][0]) + ",					// "+ str(indexx) + "  "+ str(course[indexx][0])  + ")" )

# print("};")

for index in range(0, 19):
    for indec in range(0,len(course)):
        if(listcourse[index] == ChangeCourseName(course[indec][0])):
            IndexTrueCourse.insert(indec, index)
print(IndexTrueCourse)
