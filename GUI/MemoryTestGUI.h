#ifndef MEMORYTESTGUI_H
#define MEMORYTESTGUI_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class MemoryTestGUI : public QWidget {
Q_OBJECT

public:
    explicit MemoryTestGUI(QWidget *parent = nullptr); // Constructor
    ~MemoryTestGUI(); // Destructor

private slots:
    void runCacheTest();
    void runMemoryTest();

private:
    QPushButton *cacheTestButton;
    QPushButton *memoryTestButton;
    QLabel *statusLabel;
};

#endif // MEMORYTESTGUI_H
