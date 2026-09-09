import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window
{
    width: 640
    height: 520
    visible: true
    title: "Видеопроигрыватель"

    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 5
        spacing: 5

        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#202025"
            radius: 8

            Text
            {
                anchors.centerIn: parent
                text: "▶"
                font.pixelSize: 80
                color: "#555"
            }
        }

        RowLayout
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            Layout.minimumHeight: 50
            Layout.maximumHeight: 50
            spacing: 10

            Button
            {
                text: "⏪"
                font.pixelSize: 20
                Layout.preferredWidth: 45
            }
            Button
            {
                text: "▶"
                font.pixelSize: 20
                Layout.preferredWidth: 45
            }
            Button
            {
                text: "⏸"
                font.pixelSize: 20
                Layout.preferredWidth: 45
            }
            Button
            {
                text: "⏹"
                font.pixelSize: 20
                Layout.preferredWidth: 45
            }
            Button
            {
                text: "⏩"
                font.pixelSize: 20
                Layout.preferredWidth: 45
            }

            ProgressBar
            {
                id: progress
                Layout.fillWidth: true
                Layout.fillHeight: true
                from: 0
                to: 100
                value: 30
            }
        }
    }
}
