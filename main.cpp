#include <QApplication>
#include "GUI/MemoryTestGUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MemoryTestGUI window;
    window.setWindowTitle("Memory Test Application");
    window.resize(600, 400);
    window.show();

    return app.exec();
}

