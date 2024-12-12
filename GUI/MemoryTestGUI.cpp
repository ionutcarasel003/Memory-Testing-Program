#include "MemoryTestGUI.h"
#include "../MemoryTests/TestRunner.h"
#include "../MemoryTests/MatrixTest.h"
#include "../MemoryTests/VectorTest.h"
#include "../Results/Result.h"
#include "../Results/ResultLogger.h"
#include <vector>
#include <QMessageBox>

MemoryTestGUI::MemoryTestGUI(QWidget *parent)
        : QWidget(parent),
          cacheTestButton(new QPushButton("Run Cache Test", this)),
          memoryTestButton(new QPushButton("Run Memory Test", this)),
          statusLabel(new QLabel("Ready", this)) {

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(cacheTestButton);
    buttonLayout->addWidget(memoryTestButton);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(statusLabel);

    setLayout(mainLayout);

    connect(cacheTestButton, &QPushButton::clicked, this, &MemoryTestGUI::runCacheTest);
    connect(memoryTestButton, &QPushButton::clicked, this, &MemoryTestGUI::runMemoryTest);
}

MemoryTestGUI::~MemoryTestGUI() = default;

void MemoryTestGUI::runCacheTest() {
    statusLabel->setText("Running Cache Test...");
    TestRunner testRunner;
    std::vector<Result> results = testRunner.run_test(1);
    ResultLogger resultLogger;
    for(const auto & result : results){
        resultLogger.logResult(result);
    }
    resultLogger.exportResultsToCSV("result.csv");
    QMessageBox::information(this, "Test Running", "Cache Test completed!");
    resultLogger.generatePlot();
    statusLabel->setText("Test Completed");
}

void MemoryTestGUI::runMemoryTest() {
    statusLabel->setText("Running Memory Test...");
    TestRunner testRunner;
    std::vector<Result> results = testRunner.run_test(2);
    ResultLogger resultLogger;
    for(const auto & result : results){
        resultLogger.logResult(result);
    }
    resultLogger.exportResultsToCSV("result.csv");
    QMessageBox::information(this, "Test Running", "Memory Test completed!");
    resultLogger.generatePlot();
    statusLabel->setText("Test completed");
}
