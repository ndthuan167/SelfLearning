from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QTextEdit, QFileDialog
from PyQt5 import QtCore
from PyQt5 import uic
import sys
import os
import numpy as np
import xlrd
import re
from enum import Enum

pulsenumbercourse = []
listcoursenodata = []
listcourseadded = []
IndexList = []
course1 = []
course = []
text = []
textnew = []
course_no_data = ['A', '0', '0', '0', '0', '0', '0']

listcourseconvert = []

listcourse = ["COURSE_NORMAL", "COURSE_TIMEDRY", "COURSE_HEAVYDUTY", "COURSE_QUICKDRY", "COURSE_DELICATES",
              "COURSE_SANITIZE_WITH_STEAM", "COURSE_WRINKLE_AWAY",
              "COURSE_REFRESH", "COURSE_TOWELS", "COURSE_BEDDING", "COURSE_PET_CARE", "COURSE_JEAN", "COURSE_SHIRTS",
              "COURSE_WOOL", "COURSE_PERMPRESS",
              "COURSE_ECONORMAL", "COURSE_AIRFLUFF", "COURSE_RACKDRY", "COURSE_SANITIZE", "COURSE_LOW_TEMP",
              "COURSE_CLOUD", "COURSE_ACTIVEWEAR", "COURSE_WRINKLE_RELEASE", "COURSE_SIZE"]


def ChangeCourseNameCOURSE(coursenamebefore):
    if (coursenamebefore == "Normal"):
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
    elif (coursenamebefore == "Denim"):
        coursenamebefore = "COURSE_JEAN"
    elif (coursenamebefore == "Eco Normal "):
        coursenamebefore = "COURSE_ECONORMAL"
    elif (coursenamebefore == "Low Temp."):
        coursenamebefore = "COURSE_LOW_TEMP"
    elif (coursenamebefore == "Steam Sanitize"):
        coursenamebefore = "COURSE_SANITIZE_WITH_STEAM"
    elif (coursenamebefore == "Small Load"):
        coursenamebefore = "COURSE_SMALL_LOAD"
    elif (coursenamebefore == "Pet Care Dry"):
        coursenamebefore = "COURSE_PET_CARE"
    elif (coursenamebefore == "Sanitize"):
        coursenamebefore = "COURSE_SANITIZE"

    return coursenamebefore


def ChangeCourseNamecourse(coursenamebefore):
    if (coursenamebefore == "COURSE_NORMAL"):
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
        coursenamebefore = "Air Fluff"
    elif (coursenamebefore == "COURSE_SHIRTS"):
        coursenamebefore = "Shirts"
    elif (coursenamebefore == "COURSE_JEAN"):
        coursenamebefore = "Denim"
    elif (coursenamebefore == "COURSE_ECONORMAL"):
        coursenamebefore = "Eco Normal "
    elif (coursenamebefore == "COURSE_LOW_TEMP"):
        coursenamebefore = "Low Temp"
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
    elif (coursenamebefore == "COURSE_WRINKLE_RELEASE"):
        coursenamebefore = "Wrinkle Release"
    elif (coursenamebefore == "COURSE_OPTIMIZED_DRY"):
        coursenamebefore = "Optimized Dry"
    elif (coursenamebefore == "COURSE_CLOUD"):
        coursenamebefore = "Downloaded"
    elif (coursenamebefore == "COURSE_SANITIZE"):
        coursenamebefore = "Sanitize"
    elif (coursenamebefore == "COURSE_QUICKDRY"):
        coursenamebefore = "Quick Dry"
    elif (coursenamebefore == "COURSE_PET_CARE"):
        coursenamebefore = "Pet Care"

    return coursenamebefore


wb = xlrd.open_workbook('C:/Users/dinhthuan.ng/PycharmProjects/pythonProject/test.xlsx')
sheet = wb.sheet_by_index(0)

for indexx in range(2, sheet.nrows):
    for indexy in range(0, sheet.ncols):
        course1.insert(indexy, sheet.cell_value(indexx, indexy))
    course.append(course1)
    course1 = []

for each_course in course:
    for index in range(1, len(each_course)):
        each_course[index] = "".join(re.findall('\d', each_course[index]))

for index in range(0, len(course)):
    pulsenumbercourse.insert(index, ChangeCourseNameCOURSE(course[index][0]))

coursenotuse = np.setdiff1d(pulsenumbercourse, listcourse)

for index in range(len(course), len(listcourse) - 1):
    course.insert(index, course_no_data)
for index in range(0, len(course)):
    listcourseadded.insert(index, ChangeCourseNameCOURSE(course[index][0]))

listcoursenodata = set(listcourseadded) ^ set(listcourse)
listcoursenodata.remove('COURSE_SIZE')
listcoursenodata.remove('A')

listcourseadded[len(listcourseadded) - len(listcoursenodata): len(listcourseadded)] = listcoursenodata

for index in range(0, len(listcourse)):
    for indec in range(0, len(listcourseadded)):
        if (listcourse[index] == listcourseadded[indec]):
            IndexList.insert(index, indec)


class UI(QMainWindow):
    def __init__(self):
        super(UI, self).__init__()
        uic.loadUi("UI_Tool.ui", self)

        self.Text = "This box will show mcau16NoMeetAddTimeByPulse array after gen"
        self.textEdit.setPlainText(self.Text)
        self.pushButton.clicked.connect(self.clickme)
        self.pushButton_2.clicked.connect(self.showtext)
        self.show()

    def showtext(self):
        text = self.textEdit_2.toPlainText()
        textnew = str(text).replace("\n", "")
        textnew = textnew.replace("\t", "")
        listcourseconvert1 = textnew.split(",")
        return listcourseconvert1
        # print(abc[0])

    def clickme(self):
        self.Text = "PRIVATE const U16 mcau16NoMeetAddTimeByPulse[COURSE_SIZE][INITIAL_PULSE_LEVEL_SIZE] =		//종료 3분 전까지 건조가 충분히 이뤄지지 않으면 아래 조건에 맞도록"
        self.textEdit.setPlainText(self.Text)
        self.textEdit.append(
            "{//		PULSE_LEVEL_0,	PULSE_LEVEL_1,	PULSE_LEVEL_2,	PULSE_LEVEL_3,	PULSE_LEVEL_4,	PULSE_LEVEL_5")
        for index in range(0, len(listcourseadded)):
            list = "    {   MIN(" + str(course[IndexList[index]][1]) + "),    MIN(" + str(
                course[IndexList[index]][2]) + "),     MIN(" + str(course[IndexList[index]][3]) + "),    MIN(" + str(
                course[IndexList[index]][4]) + "),    MIN(" + str(course[IndexList[index]][5]) + "),   MIN(" \
                   + str(course[IndexList[index]][6]) + ") },	//" + str(listcourse[index]) + ",       // " + str(
                index) + "  " + str(ChangeCourseNamecourse(listcourseadded[IndexList[index]]))
            self.textEdit.append(list)
        self.textEdit.append("};")


app = QApplication(sys.argv)
window = UI()
app.exec_()
