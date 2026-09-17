import QtQuick 2.12
import QtQuick.Window 2.12

/// @brief Окно с двумя квадратами и кругом.
///        Клик по левому квадрату двигает круг вправо,
///        клик по правому — возвращает круг в исходную позицию.
Window {
    id: root
    width: 800
    height: 400
    visible: true
    title: "Move Circle"

    /// Шаг перемещения круга при клике по левому квадрату
    readonly property int step: 30

    Rectangle {
        id: leftRectangle
        x: 50
        y: 125
        width: 150
        height: 150
        color: "#cfe8ff"
        border.color: "#2b6cb0"
        border.width: 2

        Text {
            anchors.centerIn: parent
            text: "move"
            font.pixelSize: 22
            color: "#2b6cb0"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (ball.x >= rightRectangle.x) {
                    ball.state = "InitialState"
                } else {
                    ball.state = "OtherState"
                    ball.x += root.step
                }
            }
        }
    }

    Rectangle {
        id: rightRectangle
        x: 600
        y: 125
        width: 150
        height: 150
        color: "#ffd6d6"
        border.color: "#c53030"
        border.width: 2

        Text {
            anchors.centerIn: parent
            text: "return"
            font.pixelSize: 22
            color: "#c53030"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                ball.state = "InitialState"
            }
        }
    }

    Rectangle {
        id: ball
        width: 50
        height: 50
        radius: width / 2
        color: "#38a169"

        /// Исходная позиция — центр левого квадрата
        readonly property real initialX: leftRectangle.x
                                          + leftRectangle.width / 2
                                          - width / 2
        readonly property real initialY: leftRectangle.y
                                          + leftRectangle.height / 2
                                          - height / 2

        x: initialX
        y: initialY

        state: "InitialState"

        states: [
            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: ball.initialX
                    y: ball.initialY
                }
            },
            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                    y: ball.y
                }
            }
        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]
    }
}