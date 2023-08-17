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
import numpy as np
import xlrd
import re
from enum import Enum

pulsenumbercourse = []
listcoursenodata = []
listcourseadded = []
IndexList = []
wb = xlrd.open_workbook('D:/LearningCode/Python/test.xlsx')
sheet = wb.sheet_by_index(0)
course1 = []
course = []

course_no_data = ['A', '0', '0', '0', '0', '0', '0']

listcourse = ["COURSE_NORMAL", "COURSE_TIMEDRY", "COURSE_HEAVYDUTY", "COURSE_HIGH_SPEED", "COURSE_SMALL_LOAD", "COURSE_DELICATES", "COURSE_SANITIZE_WITH_STEAM", "COURSE_WRINKLE_AWAY",	"COURSE_REFRESH",	"COURSE_TOWELS", "COURSE_BEDDING", "COURSE_ACTIVEWEAR", "COURSE_JEAN", "COURSE_SHIRTS", "COURSE_WOOL", "COURSE_PERMPRESS", "COURSE_ECONORMAL",	"COURSE_AIRFLUFF", "COURSE_RACKDRY", "COURSE_SIZE"]

for indexx in range(2, sheet.nrows):
    for indexy in range(0, sheet.ncols):
        course1.insert(indexy, sheet.cell_value(indexx, indexy))
    course.append(course1)
    course1 = []

for each_course in course:
    for index in range(1, len(each_course)):
        each_course[index] = "".join(re.findall('\d', each_course[index]))


def ChangeCourseNameCOURSE(coursenamebefore):
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
        coursenamebefore = "COURSE_AIRFLUFF"
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

def ChangeCourseNamecourse(coursenamebefore):
    if(coursenamebefore == "COURSE_NORMAL"):
        coursenamebefore = "Normal"
    elif (coursenamebefore == "COURSE_HEAVYDUTY"):
        coursenamebefore = "Heavy Duty"
    elif (coursenamebefore == "COURSE_BEDDING"):
        coursenamebefore = "Bedding"
    elif (coursenamebefore == "COURSE_DELICATES"):
        coursenamebefore = "Delicates"
    elif (coursenamebefore == "COURSE_PERMPRESS"):
        coursenamebefore = "Perm Press"
    elif (coursenamebefore == "COURSE_ACTIVEWEAR"):
        coursenamebefore = "Active Wear"
    elif (coursenamebefore == "COURSE_TOWELS"):
        coursenamebefore = "Towels"
    elif (coursenamebefore == "COURSE_AIRFLUFF"):
        coursenamebefore = "Air Sanitize"
    elif (coursenamebefore == "COURSE_SHIRTS"):
        coursenamebefore = "Shirts"
    elif (coursenamebefore == "COURSE_JEAN"):
        coursenamebefore = "Denim"
    elif (coursenamebefore == "COURSE_ECONORMAL"):
        coursenamebefore = "Eco Normal "
    elif (coursenamebefore == "COURSE_LOW_TEMP"):
        coursenamebefore = "Low Temp."
    elif (coursenamebefore == "COURSE_SANITIZE_WITH_STEAM"):
        coursenamebefore = "Steam Sanitize"
    elif (coursenamebefore == "COURSE_SMALL_LOAD"):
        coursenamebefore = "Small Load"
    elif (coursenamebefore == "COURSE_TIMEDRY"):
        coursenamebefore = "Time Dry"
    elif (coursenamebefore == "COURSE_HIGH_SPEED"):
        coursenamebefore = "Super Speed"
    elif (coursenamebefore == "COURSE_WRINKLE_AWAY"):
        coursenamebefore = "Wrinkle Away"
    elif (coursenamebefore == "COURSE_REFRESH"):
        coursenamebefore = "Refresh"
    elif (coursenamebefore == "COURSE_WOOL"):
        coursenamebefore = "Wool"
    elif (coursenamebefore == "COURSE_RACKDRY"):
        coursenamebefore = "Rack Dry"
                
    return  coursenamebefore

for index in range(0,len(course)):
    pulsenumbercourse.insert(index, ChangeCourseNameCOURSE(course[index][0]))

coursenotuse = np.setdiff1d(pulsenumbercourse, listcourse)
for index in range(0,len(course)):
    if(ChangeCourseNameCOURSE(course[index][0]) == coursenotuse):
        course.remove(course[12])
        break

for index in range(len(course), 19):
    course.insert(index,course_no_data)
for index in range(0,len(course)):
    listcourseadded.insert(index, ChangeCourseNameCOURSE(course[index][0]))

listcoursenodata = set(listcourseadded) ^set(listcourse)
listcoursenodata.remove('COURSE_SIZE')
listcoursenodata.remove('A')

listcourseadded[len(listcourseadded) - len(listcoursenodata) : len(listcourseadded)] = listcoursenodata

for index in range(0, len(listcourse)):
    for indec in range(0, len(listcourseadded)):
        if(listcourse[index] == listcourseadded[indec]):
            IndexList.insert(index, indec)

print("PRIVATE const U16 mcau16NoMeetAddTimeByPulse[COURSE_SIZE][INITIAL_PULSE_LEVEL_SIZE] =		//종료 3분 전까지 건조가 충분히 이뤄지지 않으면 아래 조건에 맞도록")
print("{//		PULSE_LEVEL_0,	PULSE_LEVEL_1,	PULSE_LEVEL_2,	PULSE_LEVEL_3,	PULSE_LEVEL_4,	PULSE_LEVEL_5")
for index in range(len(listcourseadded)):
    print("   {	MIN("+ str(course[IndexList[index]][1]) +"),    MIN("+ str(course[IndexList[index]][2])+"),     MIN("+str(course[IndexList[index]][3])+"),    MIN("+ str(course[IndexList[index]][4])+ "),    MIN("+ str(course[IndexList[index]][5])+"),   MIN("+ str(course[IndexList[index]][6])+") },	//" + str(listcourse[index]) + ",       // "+ str(index) + "  "+ str(ChangeCourseNamecourse(listcourseadded[IndexList[index]])))
print("};")