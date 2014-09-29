#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initInputSettingsGroup();
    initOutputSettingGroup();
    initOpGroup();
    initOutputGroup();
    initUI();
    initAction();
    initMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    m_wMainWidget = new QWidget();
    //QWidget::setLayout: Attempting to set QLayout "" on MainWindow "", which already has a layout
    setCentralWidget(m_wMainWidget);

    setWindowTitle(tr("资源转换工具"));
    setMinimumSize(1000, 800);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_gbInputSettingGroup);
    mainLayout->addWidget(m_gbOutputSettingGroup);
    mainLayout->addWidget(m_gbOpGroup);
    mainLayout->addWidget(m_gbOutputGroup);

    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(30);

    m_wMainWidget->setLayout(mainLayout);
}

void MainWindow::initMenu()
{
    m_mAboutMe = menuBar()->addMenu("帮助(&H)");
    m_mAboutMe->addAction(m_aAboutMe);
}

void MainWindow::initAction()
{
    m_aAboutMe = new QAction(tr("关于我(&A)"), this);
    m_aAboutMe->setStatusTip(tr("关于软件的一些说明"));
    connect(m_aAboutMe, SIGNAL(triggered()), this, SLOT(onAboutMeAction()));
}

void MainWindow::onAboutMeAction()
{
    printf("onAboutMeAction.......\n");
}

void MainWindow::initInputSettingsGroup()
{
    m_gbInputSettingGroup = new QGroupBox();
    m_gbInputSettingGroup->setTitle(tr("输入设置"));

    QGridLayout * layout = new QGridLayout();

    QLabel * lbInput = new QLabel();
    lbInput->setText(tr("输入路径:"));
    lbInput->setAlignment(Qt::AlignRight | Qt::AlignHCenter);

    m_leInputSettingPath = new QLineEdit();
    m_leInputSettingPath->setText(tr("请设置输入路径"));
    m_leInputSettingPath->setReadOnly(true);

    m_pbInputSettingPath = new QPushButton();
    m_pbInputSettingPath->setText(tr("设置输入目录"));
    m_pbInputSettingPath->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 4);
    layout->setColumnStretch(2, 1);

    layout->addWidget(lbInput, 0, 0);
    layout->addWidget(m_leInputSettingPath, 0, 1);
    layout->addWidget(m_pbInputSettingPath, 0, 2);

    m_gbInputSettingGroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_gbInputSettingGroup->setLayout(layout);
}

void MainWindow::initOutputSettingGroup()
{
    m_gbOutputSettingGroup = new QGroupBox();
    m_gbOutputSettingGroup->setTitle(tr("输出设置"));

    QGridLayout * layout = new QGridLayout();

    QLabel * lbInput = new QLabel();
    lbInput->setText(tr("输出路径:"));
    lbInput->setAlignment(Qt::AlignRight | Qt::AlignHCenter);

    m_leOutputSettingPath = new QLineEdit();
    m_leOutputSettingPath->setText(tr("请设置输出路径"));
    m_leOutputSettingPath->setReadOnly(true);

    m_pbOutputSettingPath = new QPushButton();
    m_pbOutputSettingPath->setText(tr("设置输出目录"));
    m_pbOutputSettingPath->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 4);
    layout->setColumnStretch(2, 1);

    layout->addWidget(lbInput, 0, 0);
    layout->addWidget(m_leOutputSettingPath, 0, 1);
    layout->addWidget(m_pbOutputSettingPath, 0, 2);

    m_gbOutputSettingGroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_gbOutputSettingGroup->setLayout(layout);
}

void MainWindow::initOpGroup()
{
    m_gbOpGroup = new QGroupBox();
    m_gbOpGroup->setTitle("操作");

    m_pbPublish = new QPushButton();
    m_pbPublish->setText(tr("导出"));
    m_pbPublish->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_pbClosed  = new QPushButton();
    m_pbClosed->setText(tr("关闭"));
    m_pbClosed->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


    connect(m_pbClosed, SIGNAL(clicked()), this, SLOT(close()));

    QFormLayout * layout = new QFormLayout();
    layout->addRow(m_pbPublish, m_pbClosed);
    layout->setFormAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_gbOpGroup->setLayout(layout);
}

void MainWindow::initOutputGroup()
{
    m_gbOutputGroup = new QGroupBox();
    m_gbOutputGroup->setTitle(tr("输出"));

    m_pteOutput = new QPlainTextEdit();

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(m_pteOutput);

    m_gbOutputGroup->setLayout(layout);
}
