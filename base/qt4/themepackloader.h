#ifndef THEMEPACKLOADER_H
#define THEMEPACKLOADER_H

#include <QObject>
#include <QSettings>
#include <QPoint>
#include <desktopwidget.h>

namespace PlexyDesk
{

class PLEXYDESK_EXPORT ThemepackLoader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString themeName READ QString WRITE setThemeName)

public:
    explicit ThemepackLoader(const QString &themeName, QObject *parent = 0);
    virtual ~ThemepackLoader();

    void setThemeName(const QString &name);

    QStringList widgets(const QString &type);
    QPoint widgetPos(const QString &name);

    QString wallpaper();
    QString qmlFilesFromTheme(const QString &themeName);
    QString qmlBackdropFromTheme();

    PlexyDesk::DesktopWidget::State widgetView(const QString &name);

Q_SIGNALS:
    void ready();

private:
    void scanThemepackPrefix();

    class ThemepackLoaderPrivate;
    ThemepackLoaderPrivate *const d;
};

} // namespace PlexyDesk

#endif // THEMEPACKLOADER_H
