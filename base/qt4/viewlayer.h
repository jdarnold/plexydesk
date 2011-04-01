#ifndef VIEW_LAYER_H
#define VIEW_LAYER_H

#include <config.h>

#include <desktopwidget.h>
#include <plexy.h>

namespace PlexyDesk
{
class PLEXYDESK_EXPORT ViewLayer : public  QObject
{
    Q_OBJECT
public:
    ViewLayer(QObject *object = 0);

    virtual ~ViewLayer();

    /**\brief Adds a DesktopWid to a given layer
    * \param layerName is is the layer to add the item to, if the
    * layer dose not exisit a new layer defined by the layerName is
    * created.
    * \param item is the widget we wish to add
    **/
    void addItem(const QString& layerName , DesktopWidget *item);

    void showLayer(const QString& layer);
    void hideLayer(const QString& layer);
    //void switchLayer(int switchTo = 1);

    QStringList layerIndex() const;
public slots:
    void switchLayer();	

private:
    class Private;
    Private *const d;
    Private *const p;
};
}// namespace PlexyDesk

#endif
