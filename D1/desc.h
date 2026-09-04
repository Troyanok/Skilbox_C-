#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>

class ColorfulCircle : public QWidget
{
    Q_OBJECT
public:
    ColorfulCircle(QWidget *parent = nullptr)
        : QWidget(parent)
     {
        setFixedSize(200, 200);
        mGreenCircle = QPixmap("/home/troya/Desktop/Prog/skill/3.png");
        mYellowCircle = QPixmap("/home/troya/Desktop/Prog/skill/2.png");
        mRedCircle = QPixmap("/home/troya/Desktop/Prog/skill/1.png");
        mCurrentCircle = mRedCircle;
    }

    void setGreen()
    {
        mCurrentCircle = mGreenCircle;
        update();
    }

    void setYellow()
    {
        mCurrentCircle = mYellowCircle;
        update();
    }

    void setRed()
    {
        mCurrentCircle = mRedCircle;
        update();
    }

    QSize minimumSizeHint() const override
    {
        return QSize(200, 200);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        painter.drawPixmap(rect(), mCurrentCircle);
    }

private:
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
    QPixmap mCurrentCircle;
};
