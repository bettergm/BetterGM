#include "CentralWidget.h"

#include <QPainter>
#include <QAction>
#include <QDebug>

Titlebar::Titlebar(QString title, QWidget *parent) :
    QWidget(parent),
    mTitle(title),
    mLayout(new QHBoxLayout(this)),
    mToolbar(new QToolBar(this)),
    mLabel(new QLabel(mTitle, this)),
    mBox(new QComboBox(this))
{
    setFixedHeight(22);
    mLayout->setContentsMargins(0, 0, 0, 0);
    QFont f = mLabel->font();
    f.setPointSize(18);
    //mLabel->setFont(f);
    mLabel->setStyleSheet(QString("background: #101010;"));
    
    mLayout->addWidget(mToolbar);
    
    //QAction *closeAction = new QAction(QIcon(":/Images/16x16/close3.png"), QString(), this);
    //connect(closeAction, SIGNAL(triggered()), this, SLOT(closeCurrentDocumentClicked()));
    //mToolbar->addAction(closeAction);
    
    mToolbar->addWidget(mLabel);
    mToolbar->addSeparator();
    //mToolbar->addWidget(mBox);
    mBox->addItem("yo");
    mBox->addItem("bro");
    mBox->addItem("thing");
    mBox->setVisible(false);
    //mBox->setGeometry(64, rect().top(), mBox->width(), 24);
    
    mToolbar->setIconSize(QSize(12, 12));
    mToolbar->setStyleSheet(QString("background: #101010;"));
}

void Titlebar::setName(const QString &name) {
    mLabel->setText(name);
}

void Titlebar::closeCurrentDocumentClicked() {
    emit closeCurrentDockument();
}

void Titlebar::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.fillRect(rect(), QColor(0x10, 0x10, 0x10));
    
    //QWidget::paintEvent(e);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent),
    mTitlebar(new Titlebar(QString(tr("Script")), 0)),
    mStack(new QStackedWidget(this)),
    mLayout(new QVBoxLayout(this)),
    mTitlebarAdded(false),
    mTitlebarHidden(false)
{
    mLayout->setContentsMargins(0, 0, 0, 0);
    mLayout->setSpacing(0);
    
    connect(mStack, SIGNAL(currentChanged(int)), this, SLOT(indexChanged(int)));
    connect(mTitlebar, SIGNAL(closeCurrentDockument()), this, SLOT(closeCurrentDocumentClicked()));
}

void CentralWidget::indexChanged(int index) {
    emit currentChanged(index);
}

void CentralWidget::closeCurrentDocumentClicked() {
    int index = mStack->currentIndex();
    
    mNames.removeAt(mStack->currentIndex());
    mStack->removeWidget(mStack->currentWidget());
    
    if (mStack->count() == 0) {
        mTitlebar->hide();
        mTitlebarHidden = true;
    } else {
        mTitlebar->setName(mNames.at(mStack->currentIndex()));
    }
    
    emit closeCurrentDocument(index);
}

void CentralWidget::addWidget(QWidget *widget, QString name) {
    if (!widget)
        return;
    
    if (!mTitlebarAdded) {
        mLayout->addWidget(mTitlebar);
        mLayout->addWidget(mStack);
        mTitlebarAdded = true;
    }
    
    if (mTitlebarHidden) {
        mTitlebar->show();
        mTitlebarHidden = false;
    }
    
    mStack->addWidget(widget);
    mTitlebar->setName(name);
    mNames.append(name);
}

void CentralWidget::setCurrentIndex(int index) {
    mStack->setCurrentIndex(index);
}

int CentralWidget::getCurrentIndex() {
    return mStack->currentIndex();
}

QWidget *CentralWidget::getCurrentWidget() {
    return mStack->currentWidget();
}

QString CentralWidget::getCurrentWidgetName() const {
    return mNames.at(mStack->currentIndex());
}

void CentralWidget::setName(QString name) {
    mTitlebar->setName(name);
}
