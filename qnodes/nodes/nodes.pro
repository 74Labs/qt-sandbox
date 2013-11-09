#-------------------------------------------------
#
# Project created by QtCreator 2013-11-04T09:26:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qnodes
TEMPLATE = app

INCLUDEPATH += ../nodeeditor

SOURCES += \ 
    mainwindow.cpp \
    main.cpp \
    ../nodeeditor/QFlowEditorNodePin.cpp \
    ../nodeeditor/QFlowEditor.cpp \
    ../nodeeditor/QFlowEditorNode.cpp \
    ../nodeeditor/QFlowEditorNodePinConnection.cpp \
    ../nodeeditor/FlowManager.cpp \
    ../nodeeditor/NodePinList.cpp \
    ../nodeeditor/NodeType.cpp

HEADERS  += \ 
    mainwindow.h \
    ../nodeeditor/QFlowEditorNodePin.h \
    ../nodeeditor/QFlowEditor.h \
    ../nodeeditor/QFlowEditorNode.h \
    ../nodeeditor/QFlowEditorNodePinConnection.h \
    ../nodeeditor/FlowEditor.h \
    ../nodeeditor/FlowEditorNodeItem.h \
    ../nodeeditor/Node.h \
    ../nodeeditor/FlowManager.h \
    ../nodeeditor/NodeType.h \
    ../nodeeditor/NodePinList.h

FORMS    += \ 
    mainwindow.ui

RESOURCES += \
    nodes.qrc
