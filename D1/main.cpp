#include <iostream>
#include <QApplication>
#include "desc.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(300, 300);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    ColorfulCircle *circle = new ColorfulCircle();
    QSlider *slider = new QSlider(Qt::Horizontal);

    slider->setRange(0, 99);
    slider->setValue(99);

    layout->addWidget(circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, [circle](int newValue)
    {
        if (newValue < 33)
        {
            circle->setGreen();
        }
        else if (newValue < 66)
        {
            circle->setYellow();
        }
        else
        {
            circle->setRed();
        }
    });

    window.show();
    return app.exec();
}
