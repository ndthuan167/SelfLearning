# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'd:\LearningCode\Git code\SelfLearning\Personal projects\MyApp\popupchi.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_PopupChi(object):
    def setupUi(self, PopupChi):
        PopupChi.setObjectName("PopupChi")
        PopupChi.resize(492, 302)
        self.PopupChi_2 = QtWidgets.QFrame(PopupChi)
        self.PopupChi_2.setGeometry(QtCore.QRect(0, 0, 240, 227))
        self.PopupChi_2.setStyleSheet("#PopupChi_2{\n"
"    background-color: #EDE4E0;\n"
"    border-radius: 15;\n"
"    border: 2px solid white;\n"
"}")
        self.PopupChi_2.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.PopupChi_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.PopupChi_2.setObjectName("PopupChi_2")
        self.comboBox_2 = QtWidgets.QComboBox(self.PopupChi_2)
        self.comboBox_2.setGeometry(QtCore.QRect(45, 45, 181, 28))
        font = QtGui.QFont()
        font.setFamily("SamsungOne")
        font.setPointSize(11)
        font.setBold(False)
        self.comboBox_2.setFont(font)
        self.comboBox_2.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.comboBox_2.setAutoFillBackground(False)
        self.comboBox_2.setStyleSheet("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 10px;\n"
"    min-width: 6em;\n"
"    padding-left: 25;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"    border-bottom-left-radius: 0px;\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border-bottom-right-radius: 10px;\n"
"    border-bottom-left-radius: 10px;\n"
"    background: transparent;\n"
"    border: 1px solid gray;\n"
"    padding: 4px 4px 4px 4px\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    image: url(\":/Icon/Image/icons8-down-25.png\");\n"
"    width:20;\n"
"    padding-left: 5\n"
"}\n"
"")
        self.comboBox_2.setEditable(False)
        self.comboBox_2.setMaxVisibleItems(10)
        self.comboBox_2.setObjectName("comboBox_2")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.plainTextEdit_4 = QtWidgets.QPlainTextEdit(self.PopupChi_2)
        self.plainTextEdit_4.setGeometry(QtCore.QRect(45, 123, 181, 67))
        font = QtGui.QFont()
        font.setFamily("SamsungOne")
        font.setPointSize(11)
        font.setBold(False)
        self.plainTextEdit_4.setFont(font)
        self.plainTextEdit_4.setStyleSheet("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5")
        self.plainTextEdit_4.setPlainText("")
        self.plainTextEdit_4.setObjectName("plainTextEdit_4")
        self.label_14 = QtWidgets.QLabel(self.PopupChi_2)
        self.label_14.setGeometry(QtCore.QRect(10, 45, 25, 25))
        self.label_14.setText("")
        self.label_14.setPixmap(QtGui.QPixmap(":/Icon/Image/icons8-goal-40.png"))
        self.label_14.setScaledContents(True)
        self.label_14.setObjectName("label_14")
        self.label_15 = QtWidgets.QLabel(self.PopupChi_2)
        self.label_15.setGeometry(QtCore.QRect(10, 85, 25, 25))
        self.label_15.setText("")
        self.label_15.setPixmap(QtGui.QPixmap(":/Icon/Image/icons8-money-40.png"))
        self.label_15.setScaledContents(True)
        self.label_15.setObjectName("label_15")
        self.label_16 = QtWidgets.QLabel(self.PopupChi_2)
        self.label_16.setGeometry(QtCore.QRect(10, 140, 25, 25))
        self.label_16.setText("")
        self.label_16.setPixmap(QtGui.QPixmap(":/Icon/Image/icons8-note-40.png"))
        self.label_16.setScaledContents(True)
        self.label_16.setObjectName("label_16")
        self.label_2 = QtWidgets.QLabel(self.PopupChi_2)
        self.label_2.setGeometry(QtCore.QRect(190, 90, 35, 20))
        font = QtGui.QFont()
        font.setFamily("Samsung Sharp Sans")
        font.setPointSize(12)
        font.setBold(True)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.pushButton_SetChi = QtWidgets.QPushButton(self.PopupChi_2)
        self.pushButton_SetChi.setGeometry(QtCore.QRect(80, 195, 71, 25))
        font = QtGui.QFont()
        font.setFamily("Samsung Sharp Sans")
        font.setPointSize(10)
        font.setBold(True)
        self.pushButton_SetChi.setFont(font)
        self.pushButton_SetChi.setStyleSheet("#pushButton_SetChi\n"
"{\n"
"    border: 0px solid white;\n"
"    background-color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"#pushButton_SetChi::pressed\n"
"{\n"
"    background-color: #99FFFF;\n"
"    border-style: inset;\n"
"}\n"
"#pushButton_SetChi::hover\n"
"{\n"
"    background-color: #BBBBBB;\n"
"    border-style: inset;\n"
"}")
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/Icon/Image/icons8-next-50.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_SetChi.setIcon(icon)
        self.pushButton_SetChi.setIconSize(QtCore.QSize(20, 20))
        self.pushButton_SetChi.setObjectName("pushButton_SetChi")
        self.plainTextEdit_5 = QtWidgets.QPlainTextEdit(self.PopupChi_2)
        self.plainTextEdit_5.setGeometry(QtCore.QRect(45, 83, 141, 33))
        font = QtGui.QFont()
        font.setFamily("SamsungOne")
        font.setPointSize(12)
        font.setBold(False)
        self.plainTextEdit_5.setFont(font)
        self.plainTextEdit_5.setStyleSheet("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 15")
        self.plainTextEdit_5.setPlainText("")
        self.plainTextEdit_5.setObjectName("plainTextEdit_5")
        self.label_17 = QtWidgets.QLabel(self.PopupChi_2)
        self.label_17.setGeometry(QtCore.QRect(8, 8, 31, 31))
        self.label_17.setText("")
        self.label_17.setPixmap(QtGui.QPixmap(":/Icon/Image/icons8-calendar-48.png"))
        self.label_17.setScaledContents(True)
        self.label_17.setObjectName("label_17")
        self.plainTextEdit_6 = QtWidgets.QPlainTextEdit(self.PopupChi_2)
        self.plainTextEdit_6.setGeometry(QtCore.QRect(45, 10, 181, 28))
        font = QtGui.QFont()
        font.setFamily("Samsung Sharp Sans")
        font.setBold(True)
        self.plainTextEdit_6.setFont(font)
        self.plainTextEdit_6.setStyleSheet("border-radius: 10;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"padding-left: 5")
        self.plainTextEdit_6.setPlainText("")
        self.plainTextEdit_6.setObjectName("plainTextEdit_6")
        self.pushButton_Selectday = QtWidgets.QPushButton(self.PopupChi_2)
        self.pushButton_Selectday.setGeometry(QtCore.QRect(200, 12, 21, 24))
        self.pushButton_Selectday.setStyleSheet("#pushButton_Selectday\n"
"{\n"
"    border: 0px solid white;\n"
"    background-color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"#pushButton_Selectday::pressed\n"
"{\n"
"    background-color: #99FFFF;\n"
"    border-style: inset;\n"
"}\n"
"#pushButton_Selectday::hover\n"
"{\n"
"    background-color: #BBBBBB;\n"
"    border-style: inset;\n"
"}")
        self.pushButton_Selectday.setText("")
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(":/Icon/Image/icons8-calendar-48.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_Selectday.setIcon(icon1)
        self.pushButton_Selectday.setIconSize(QtCore.QSize(20, 20))
        self.pushButton_Selectday.setObjectName("pushButton_Selectday")
        self.label_date_selected = QtWidgets.QLabel(self.PopupChi_2)
        self.label_date_selected.setGeometry(QtCore.QRect(60, 12, 91, 25))
        font = QtGui.QFont()
        font.setFamily("SamsungOne")
        font.setPointSize(11)
        font.setBold(False)
        self.label_date_selected.setFont(font)
        self.label_date_selected.setStyleSheet("#label_date_selected{\n"
"    background-color: white;\n"
"    border-radius: 10;\n"
"    border: 1px solid white;\n"
"    color: black\n"
"}")
        self.label_date_selected.setText("")
        self.label_date_selected.setAlignment(QtCore.Qt.AlignCenter)
        self.label_date_selected.setObjectName("label_date_selected")
        self.PopupselectDay = QtWidgets.QFrame(PopupChi)
        self.PopupselectDay.setGeometry(QtCore.QRect(280, 10, 191, 71))
        self.PopupselectDay.setStyleSheet("#PopupselectDay{\n"
"    background-color: white;\n"
"    border-radius: 15;\n"
"    border: 2px solid white;\n"
"}")
        self.PopupselectDay.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.PopupselectDay.setFrameShadow(QtWidgets.QFrame.Raised)
        self.PopupselectDay.setObjectName("PopupselectDay")
        self.label_20 = QtWidgets.QLabel(self.PopupselectDay)
        self.label_20.setGeometry(QtCore.QRect(40, 37, 31, 31))
        self.label_20.setText("")
        self.label_20.setPixmap(QtGui.QPixmap(":/Icon/Image/icons8-calendar-48.png"))
        self.label_20.setScaledContents(True)
        self.label_20.setObjectName("label_20")
        self.pushButton_SelectedDay = QtWidgets.QPushButton(self.PopupselectDay)
        self.pushButton_SelectedDay.setGeometry(QtCore.QRect(70, 40, 71, 25))
        font = QtGui.QFont()
        font.setFamily("Samsung Sharp Sans")
        font.setPointSize(10)
        font.setBold(True)
        self.pushButton_SelectedDay.setFont(font)
        self.pushButton_SelectedDay.setStyleSheet("#pushButton_SelectedDay\n"
"{\n"
"    border: 0px solid white;\n"
"    background-color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"#pushButton_SelectedDay::pressed\n"
"{\n"
"    background-color: #99FFFF;\n"
"    border-style: inset;\n"
"}\n"
"#pushButton_SelectedDay::hover\n"
"{\n"
"    background-color: #BBBBBB;\n"
"    border-style: inset;\n"
"}")
        self.pushButton_SelectedDay.setIcon(icon)
        self.pushButton_SelectedDay.setIconSize(QtCore.QSize(20, 20))
        self.pushButton_SelectedDay.setObjectName("pushButton_SelectedDay")
        self.pushButton_back_day = QtWidgets.QPushButton(self.PopupselectDay)
        self.pushButton_back_day.setGeometry(QtCore.QRect(0, 10, 30, 30))
        self.pushButton_back_day.setStyleSheet("#pushButton_back_day\n"
"{\n"
"    background-color: white ;\n"
"    border-radius: 15;\n"
"}\n"
"#pushButton_back_day:pressed\n"
"{\n"
"    background-color: white;\n"
"    border-style: inset;\n"
"}\n"
"#pushButton_back_day:hover\n"
"{\n"
"    background-color: #CCFFFF;\n"
"    border-style: inset;\n"
"}")
        self.pushButton_back_day.setText("")
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap(":/Icon/Image/back.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_back_day.setIcon(icon2)
        self.pushButton_back_day.setIconSize(QtCore.QSize(30, 30))
        self.pushButton_back_day.setObjectName("pushButton_back_day")
        self.pushButton_next_day = QtWidgets.QPushButton(self.PopupselectDay)
        self.pushButton_next_day.setGeometry(QtCore.QRect(160, 10, 30, 30))
        self.pushButton_next_day.setStyleSheet("#pushButton_next_day\n"
"{\n"
"    background-color :white ;\n"
"    border-radius: 15;\n"
"}\n"
"#pushButton_next_day:pressed\n"
"{\n"
"    background-color: white;\n"
"    border-style: inset;\n"
"}\n"
"#pushButton_next_day:hover\n"
"{\n"
"    background-color: #CCFFFF;\n"
"    border-style: inset;\n"
"}")
        self.pushButton_next_day.setText("")
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap(":/Icon/Image/next.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pushButton_next_day.setIcon(icon3)
        self.pushButton_next_day.setIconSize(QtCore.QSize(30, 30))
        self.pushButton_next_day.setObjectName("pushButton_next_day")
        self.label_date_select = QtWidgets.QLabel(self.PopupselectDay)
        self.label_date_select.setGeometry(QtCore.QRect(30, 10, 131, 25))
        font = QtGui.QFont()
        font.setFamily("Samsung Sharp Sans")
        font.setPointSize(10)
        font.setBold(True)
        self.label_date_select.setFont(font)
        self.label_date_select.setStyleSheet("#label_date_select{\n"
"    background-color: white;\n"
"    border-radius: 10;\n"
"    border: 1px solid gray;\n"
"    color: black\n"
"}")
        self.label_date_select.setText("")
        self.label_date_select.setAlignment(QtCore.Qt.AlignCenter)
        self.label_date_select.setObjectName("label_date_select")

        self.retranslateUi(PopupChi)
        self.comboBox_2.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(PopupChi)

    def retranslateUi(self, PopupChi):
        _translate = QtCore.QCoreApplication.translate
        PopupChi.setWindowTitle(_translate("PopupChi", "Dialog"))
        self.comboBox_2.setItemText(0, _translate("PopupChi", "Tiền trọ"))
        self.comboBox_2.setItemText(1, _translate("PopupChi", "Sinh hoạt"))
        self.comboBox_2.setItemText(2, _translate("PopupChi", "Đi chơi"))
        self.comboBox_2.setItemText(3, _translate("PopupChi", "Ăn uống"))
        self.comboBox_2.setItemText(4, _translate("PopupChi", "Khác"))
        self.label_2.setText(_translate("PopupChi", "VNĐ"))
        self.pushButton_SetChi.setText(_translate("PopupChi", "Enter"))
        self.pushButton_SelectedDay.setText(_translate("PopupChi", "Enter"))
import ResourceFile_rc
