#include "authwidgetinterface.h"
#include "authplugin.h"
#include <pluginloader.h>
#include <QtPlugin>

AuthInterface::AuthInterface(QObject *object)
{
}

PlexyDesk::AbstractSource *AuthInterface::instance()
{
    return new AuthPlugin(this);
}

Q_EXPORT_PLUGIN2(AuthInterface, AuthInterface)
