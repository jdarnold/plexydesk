#include <QtTest/QtTest>

class TestIcon: public QObject
{
    Q_OBJECT

public slots:
    void onFinished();
    void onInvalidFinished();

private slots:
    void loadThemePackInit();
    void loadIcons();
    void loadInvalidIcon();

private:
    bool mFetchComplete;
};
