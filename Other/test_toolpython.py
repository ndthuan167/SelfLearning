from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QTextEdit, QFileDialog, QMessageBox, QFontComboBox, QFontDialog
from PyQt5 import QtCore
from PyQt5 import uic
import sys
import os
import numpy as np
import xlrd
import re
from enum import Enum
from PyQt5.QtWidgets import * 
from PyQt5.QtGui import * 
pulsenumbercourse = []
listcoursenodata = []
listcourseadded = []
IndexList = []
course1 = []
course = []
text = []
textnew = []
course_no_data = ['A', '0', '0', '0', '0', '0', '0']
numberOfReadFile = 0
numberAddlistcourse = 0
listcourseconvert = []

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
class UI(QMainWindow):
    def __init__(self):
        super(UI, self).__init__()
        uic.loadUi("D:/LearningCode/C_programming/Other/UI_Tool.ui", self)

        self.Text = "This box will show mcau16NoMeetAddTimeByPulse array after gen"
        self.textEdit.setPlainText(self.Text)
        self.textEdit.setFont(QFont('Consolas', 10))
        self.pushButton.clicked.connect(self.ShowArrayAfterGenFunction)
        self.pushButton_2.clicked.connect(self.GetListCourseAndArrageFunction)
        self.pushButton_3.clicked.connect(self.ReloadExcelfile)
        self.show()

    def ReloadExcelfile(self):
        global numberOfReadFile
        numberOfReadFile += 1
        os.startfile('D:/LearningCode/Python/test.xlsx')

    def GetListCourseAndArrageFunction(self):
        #Show meesage after set List course
        msgBox = QMessageBox()
        msgBox.setIcon(QMessageBox.Information)
        msgBox.setText("List course is set")
        msgBox.setWindowTitle("Message")
        msgBox.exec()
        # After push set list course -> numberAddlistcourse++
        global course1, numberAddlistcourse
        numberAddlistcourse += 1
        # Process and convert the raw list course to list listcourse
        text = self.textEdit_2.toPlainText()
        textnew = str(text).replace("\n", "")
        textnew = textnew.replace("\t", "")
        textnew = textnew.replace(" ", "")
        listcourseconvert1 = textnew.split(",")
        listcourseconvert1.remove('')
        # read excel file
        wb = xlrd.open_workbook('D:/LearningCode/Python/test.xlsx')
        sheet = wb.sheet_by_index(0)    # process sheet 0
        # list "course" is a big list, include many "course1" list from data of excel file
        for indexx in range(2, sheet.nrows):
            for indexy in range(0, sheet.ncols):
                course1.insert(indexy, sheet.cell_value(indexx, indexy))
            course.append(course1)
            course1 = []
        # delete charector excep number
        for each_course in course:
            for index in range(1, len(each_course)):
                each_course[index] = "".join(re.findall('\d', each_course[index]))
        # get the name of list course excel file         
        for index in range(0, len(course)):
            pulsenumbercourse.insert(index, ChangeCourseNameCOURSE(course[index][0]))
        # add empty list to course for other course in excel file
        for index in range(len(course), len(listcourseconvert1) - 1):
            course.insert(index, course_no_data)
        for index in range(0, len(course)):
            listcourseadded.insert(index, ChangeCourseNameCOURSE(course[index][0]))
        # find in list course the course has not data in excel file
        listcoursenodata = set(listcourseadded) ^ set(listcourseconvert1)
        listcoursenodata.remove('COURSE_SIZE')
        listcoursenodata.remove('A')
        # replace the 'A' list = "course not has data" list
        listcourseadded[len(listcourseadded) - len(listcoursenodata): len(listcourseadded)] = listcoursenodata
        # find index of course in excel file and other course with the right list course.
        for index in range(0, len(listcourseconvert1)):
            for indec in range(0, len(listcourseadded)):
                if (listcourseconvert1[index] == listcourseadded[indec]):
                    IndexList.insert(index, indec)

    def ShowArrayAfterGenFunction(self):
        if numberOfReadFile == 1 and numberAddlistcourse == 1:
            self.Text = "PRIVATE const U16 mcau16NoMeetAddTimeByPulse[COURSE_SIZE][INITIAL_PULSE_LEVEL_SIZE] =		//종료 3분 전까지 건조가 충분히 이뤄지지 않으면 아래 조건에 맞도록"
            self.textEdit.setPlainText(self.Text)
            self.textEdit.append(
                "{//		PULSE_LEVEL_0,	PULSE_LEVEL_1,	PULSE_LEVEL_2,	PULSE_LEVEL_3,	PULSE_LEVEL_4,	PULSE_LEVEL_5")
            for index in range(0, len(listcourseadded)):
                list = "    {   MIN(" + str(course[IndexList[index]][1]) + "),    MIN(" + str(
                    course[IndexList[index]][2]) + "),     MIN(" + str(course[IndexList[index]][3]) + "),    MIN(" + str(
                    course[IndexList[index]][4]) + "),    MIN(" + str(course[IndexList[index]][5]) + "),   MIN(" \
                    + str(course[IndexList[index]][6]) + ") },	//" + str(listcourseadded[IndexList[index]]) + ",       // " + str(
                    index) + "  " + str(ChangeCourseNamecourse(listcourseadded[IndexList[index]]))
                self.textEdit.append(list)
            self.textEdit.append("};")
            self.textEdit.setFont(QFont('Consolas', 8))
app = QApplication(sys.argv)
window = UI()
app.exec_()
