import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: control
    enabled: false

    // Здесь задаём общий стиль
    background: Rectangle
    {
        color:
        {
            // заблокирована
            if (!control.enabled)
            {
                return "#A0A0A0";
            }

            // нажата
            if (control.pressed)
            {
                return "#1C4E75";
            }

            // наведена
            if (control.hovered)
            {
                return "#1F5783";
            }

            // обычное состояние
            return "#236192";
        }
        radius: 4
        Behavior on color
        {
            ColorAnimation
            {
                duration: 150
            }
        }
    }

    contentItem: Text
    {
        text: control.text
        color: "#FFFFFF"
        font.pixelSize: 16
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
