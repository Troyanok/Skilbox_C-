import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window
{
    width: 240
    height: 680
    visible: true
    title: "Пульт дистанционного управления ТВ"

    // Состояние телевизора
    property int currentChannel: 1
    property int volumePercent: 50

    // Функции управления
    function changeChannel(ch)
    {
        currentChannel = ch
    }

    function nextChannel()
    {
        currentChannel = (currentChannel === 99) ? 0 : currentChannel + 1
    }
    function prevChannel() {
        currentChannel = (currentChannel === 0) ? 99 : currentChannel - 1
    }
    function increaseVolume() {
       volumePercent = Math.min(volumePercent + 10, 100)
    }
    function decreaseVolume() {
        volumePercent = Math.max(volumePercent - 10, 0)
    }
    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 10
        // Заголовок
        Label
        {
            text: "Пульт ТВ"
            font.pixelSize: 20
            font.bold: true
            color: "white"
            Layout.alignment: Qt.AlignHCenter
        }
        // Сетка цифровых кнопок
        GridLayout
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 400
            columns: 3
            rowSpacing: 10
            columnSpacing: 10
            Repeater
            {
                model: ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]
                delegate: Button
                {
                    text: modelData
                    font.pixelSize: 28
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    onClicked: changeChannel(parseInt(modelData))
                }
            }
        }
        // Кнопки переключения каналов
        RowLayout
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 60
            spacing: 10
            Button
            {
                text: "◀"
                font.pixelSize: 24
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: prevChannel()
            }
            Button
            {
                text: "▶"
                font.pixelSize: 24
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: nextChannel()
            }
        }

        // Кнопки громкости
        RowLayout
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 60
            spacing: 10
            Button
            {
                text: "−"
                font.pixelSize: 24
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: decreaseVolume()
            }

            Button
            {
                text: "+"
                font.pixelSize: 24
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: increaseVolume()
            }
        }

        // Мини-дисплей
        Rectangle
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 80
            color: "#111"
            radius: 5
            border.color: "#555"
            Column
            {
                anchors.centerIn: parent
                spacing: 5
                Text
                {
                    text: "Канал: " + currentChannel
                    color: "lime"
                    font.pixelSize: 16
                    font.family: "monospace"
                }
                Text
                {
                    text: "Громкость: " + volumePercent + "%"
                    color: "lime"
                    font.pixelSize: 16
                    font.family: "monospace"
                }
            }
        }
    }
}
