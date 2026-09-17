#include "desc.h"

#include <QVector>
#include <QtConcurrent>
#include <QtGlobal>

QImage blurImage(QImage source, int blurRadius)
{
    if (source.isNull() || blurRadius <= 0)
    {
        return source;
    }

    source = source.convertToFormat(QImage::Format_ARGB32);

    const int width = source.width();
    const int height = source.height();

    QImage result(width, height, QImage::Format_ARGB32);

    QVector<int> rows;
    rows.reserve(height);
    for (int y = 0; y < height; ++y)
    {
        rows.append(y);
    }

    QtConcurrent::blockingMap(rows, [&](int y)
    {
        QRgb *resultLine = reinterpret_cast<QRgb *>(result.scanLine(y));

        for (int x = 0; x < width; ++x)
        {
            int r = 0;
            int g = 0;
            int b = 0;
            int a = 0;
            int count = 0;

            for (int dy = -blurRadius; dy <= blurRadius; ++dy)
            {
                int ny = qBound(0, y + dy, height - 1);

                for (int dx = -blurRadius; dx <= blurRadius; ++dx)
                {
                    int nx = qBound(0, x + dx, width - 1);
                    QRgb pixel = source.pixel(nx, ny);

                    r += qRed(pixel);
                    g += qGreen(pixel);
                    b += qBlue(pixel);
                    a += qAlpha(pixel);
                    ++count;
                }
            }

            resultLine[x] = qRgba(
                r / count,
                g / count,
                b / count,
                a / count
            );
        }
    });

    return result;
}
