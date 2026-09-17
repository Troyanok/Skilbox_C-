import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: root
    width: 420
    height: 220
    visible: true
    title: "Phone Validator"

    /// Регулярка: ^\+ ровно 11 цифр $
    /// Литерал /.../ — в нём обратный слэш пишется один раз.
    readonly property var phoneRegex: /^\+\d{11}$/

    Column {
        anchors.centerIn: parent
        spacing: 20

        TextField {
            id: inputField
            width: 340
            font.pixelSize: 18
            placeholderText: "+11111111111"

            // Обработчик прямо на виджете — работает всегда.
            onTextChanged: {
                if (root.phoneRegex.test(text)) {
                    resultText.text = "Ок"
                    resultText.color = "green"
                } else {
                    resultText.text = "Not Ok"
                    resultText.color = "red"
                }
            }
        }

        Text {
            id: resultText
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 26
            font.bold: true
            text: "Not Ok"
            color: "red"
        }
    }
}