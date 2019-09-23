BASEDIR   = ..
DESTDIR   = $$BASEDIR/bin
FORMSDIR  = $$BASEDIR/forms
SOURCEDIR = $$BASEDIR/src
ASSETSDIR = $$BASEDIR/assets

NAME      = QtCalc1

CONFIG   += qt c++11
QT       += widgets

macx {
    ICON = $$ASSETSDIR/QtCalc.icns
}

HEADERS += \
        $$SOURCEDIR/MainWindow.hpp \
        $$SOURCEDIR/AboutDialog.hpp \
        $$SOURCEDIR/AlgebraicTreeExpression.hpp \
        $$SOURCEDIR/AlgebraicTreeNode.hpp \
        $$SOURCEDIR/AlgebraicTreeNumber.hpp \
        $$SOURCEDIR/AlgebraicTreeOperation.hpp \
        $$(NULL)

SOURCES += \
        $$SOURCEDIR/main.cpp \
        $$SOURCEDIR/MainWindow.cpp \
        $$SOURCEDIR/AboutDialog.cpp \
        $$SOURCEDIR/AlgebraicTreeExpression.cpp \
        $$SOURCEDIR/AlgebraicTreeNode.cpp \
        $$SOURCEDIR/AlgebraicTreeNumber.cpp \
        $$SOURCEDIR/AlgebraicTreeOperation.cpp \
        $$(NULL)

FORMS = \
        $$FORMSDIR/MainWindow.ui \
        $$FORMSDIR/AboutDialog.ui \
        $$(NULL)
