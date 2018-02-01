#ifndef CUBEMAPFBO_H
#define CUBEMAPFBO_H

#include <QtQuick/QQuickFramebufferObject>
#include "cubemapscheme.h"
#include <QImage>

class CubemapFboRender;

class CubemapQuickRender : public QQuickFramebufferObject
{
    Q_OBJECT
    Q_PROPERTY(Scheme scheme READ scheme WRITE setScheme NOTIFY schemeChanged)
public:
    enum class Scheme{
        VerticalCross,
        HorizontalCross,
        VerticalLine,
        HorizontalLine
    };
    Q_ENUMS(Scheme)

    void setScheme(Scheme _scheme);
    Scheme scheme() const;

    CubemapQuickRender();
    Renderer *createRenderer() const;

    Q_INVOKABLE void saveToFileCubemap(QString fileName);
    Q_INVOKABLE void loadFromFileEquRectMap(QString fileName);

signals:
    void schemeChanged(Scheme);
    void imageLoaded(QImage);

private:
    Scheme m_scheme;
};

#endif // CUBEMAPFBO_H
