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
            titleLabel(new QLabel("Alege ce test ti-ai dori sa rulezi", this)),
            cacheTestButton(new QPushButton("Run Cache Test", this)),
            memoryTestButton(new QPushButton("Run Memory Test", this)),
            statusLabel(new QLabel("", this)) {

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(cacheTestButton);
    buttonLayout->addWidget(memoryTestButton);

    mainLayout->addWidget(titleLabel);
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
    QString s = "";
    for(const auto & result : results){
        resultLogger.logResult(result);
        s.append(result.test_name).append(" a durat ").append(std::to_string(result.exec_time))
        .append(" secunde si a avut performanta de ").append(std::to_string(result.transfer_rate))
        .append(" MB/s\n");
    }
    statusLabel->setText(s);
    resultLogger.exportResultsToCSV("result.csv");
    QMessageBox::information(this, "Test Running", "Cache Test completed!");
    resultLogger.generatePlot();

}

void MemoryTestGUI::runMemoryTest() {
    statusLabel->setText("Running Memory Test...");
    TestRunner testRunner;
    std::vector<Result> results = testRunner.run_test(2);
    ResultLogger resultLogger;
    QString s = "";
    for(const auto & result : results){
        resultLogger.logResult(result);
        s.append(result.test_name).append(" a durat ").append(std::to_string(result.exec_time))
                .append(" ms si a avut performanta de ").append(std::to_string(result.transfer_rate))
                .append(" MB/ms\n");
    }
    statusLabel->setText(s);
    resultLogger.exportResultsToCSV("result.csv");
    QMessageBox::information(this, "Test Running", "Memory Test completed!");
    resultLogger.generatePlot();
}
