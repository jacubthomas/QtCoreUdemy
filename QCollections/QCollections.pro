QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        q_deleteall.cpp \
        q_deleteall_map.cpp \
        q_list.cpp \
        q_map.cpp \
        q_set.cpp \
        q_sharedptr_w_qlist.cpp \
        q_sharedptr_w_qmap.cpp \
        q_stringlist.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    q_deleteall.h \
    q_deleteall_map.h \
    q_list.h \
    q_map.h \
    q_set.h \
    q_sharedptr_w_qlist.h \
    q_sharedptr_w_qmap.h \
    q_stringlist.h
