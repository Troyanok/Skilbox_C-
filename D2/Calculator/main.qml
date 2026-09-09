import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window
{
    width: 480
    height: 240
    visible: true
    title: Графический калькулятор

    ColumnLayout
    {
        id: calculatorLayout
        anchors.fill: parent
        anchors.margins: 15
        spacing: 15

        property var buttons: [but1, but2, but3, but4]

        // Проверка, является ли строка числом (с поддержкой запятой)
        function isValidNumber(text)
        {
            var normalized = text.trim().replace(/,/g, '.');
            if (normalized === "") return false;
            var num = Number(normalized);
            return !isNaN(num) && isFinite(num);
        }

        // Обновление состояния интерфейса в зависимости от ввода
        function checkInput()
        {
            var valid1 = isValidNumber(input1.text);
            var valid2 = isValidNumber(input2.text);
            var allValid = valid1 && valid2;

            resultText.text = allValid ? "Ready" : "Empty or invalid value";

            for (var btn of buttons)
            {
                btn.enabled = allValid;
            }

            // Подсветка рамок
            input1.borderColor = valid1 ? "#A6A6A8" : "#CF1818";
            input2.borderColor = valid2 ? "#A6A6A8" : "#CF1818";
            resultFrame.borderColor = allValid ? "#236192" : "#CF1818";
        }

        // Выполнение арифметической операции
        function solveOperation(operation)
        {
            var num1 = parseFloat(input1.text.trim().replace(/,/g, '.'));
            var num2 = parseFloat(input2.text.trim().replace(/,/g, '.'));
            var result;

            switch (operation)
            {
                case "add":
                {
                    result = num1 + num2;
                    break;
                }
                case "subtract":
                {
                    result = num1 - num2;
                    break;
                }
                case "multiply":
                {
                    result = num1 * num2;
                    break;
                }
                case "divide":
                {
                    if (num2 === 0)
                    {
                        resultText.text = "Divide by zero";
                        return;
                    }
                    result = num1 / num2;
                    break;
                }
                default:
                {
                    return;
                }
            }

            // Устранение ошибок плавающей точки
            result = parseFloat(result.toFixed(6));
            resultText.text = String(result);
        }

        // Поле ввода 1
        TextField
        {
            id: input1
            property color borderColor: "#A6A6A8"
            Layout.fillWidth: true
            placeholderText: "Input first"
            font.pixelSize: 14
            onTextEdited: calculatorLayout.checkInput()
            background: Rectangle
            {
                implicitWidth: 200
                implicitHeight: 40
                color: "white"
                border.color: input1.borderColor
                border.width: 1
                radius: 4
            }
        }

        // Поле ввода 2
        TextField
        {
            id: input2
            property color borderColor: "#A6A6A8"
            Layout.fillWidth: true
            placeholderText: "Input second"
            font.pixelSize: 14
            onTextEdited: calculatorLayout.checkInput()
            background: Rectangle
            {
                implicitWidth: 200
                implicitHeight: 40
                color: "white"
                border.color: input2.borderColor
                border.width: 1
                radius: 4
            }
        }

        // Область результата
        Rectangle
        {
            id: resultFrame
            property color borderColor: "#236192"
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            color: "#FFFFFF"
            border.color: resultFrame.borderColor
            radius: 5

            Text
            {
                id: resultText
                anchors.centerIn: parent
                text: "Result"
                font.pixelSize: 14
                color: "#202025"
            }
        }

        // Кнопки операций
        RowLayout
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 60

            StyledButton
            {
                id: but1
                text: "+"
                Layout.preferredWidth: 100
                Layout.preferredHeight: 40
                onClicked: calculatorLayout.solveOperation("add")
            }

            StyledButton
            {
                id: but2
                text: "-"
                Layout.preferredWidth: 100
                Layout.preferredHeight: 40
                onClicked: calculatorLayout.solveOperation("subtract")
            }

            StyledButton
            {
                id: but3
                text: "*"
                Layout.preferredWidth: 100
                Layout.preferredHeight: 40
                onClicked: calculatorLayout.solveOperation("multiply")
            }

            StyledButton
            {
                id: but4
                text: "/"
                Layout.preferredWidth: 100
                Layout.preferredHeight: 40
                onClicked: calculatorLayout.solveOperation("divide")
            }
        }
    }
}
