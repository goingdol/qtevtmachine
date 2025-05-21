import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import com.example.mysig 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello My String")

    MyString{
        id: myStringInstance2
        myString: "Hello from MyStringInstance2"
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        // Display the string from C++
        Text {
            id: myString
            text: myStringInstance.myString
            font.pixelSize: 24

            Component.onCompleted: {
                console.log(text)
            }
        }

        Text {
            id: myValue
            text: mySenderInstance.m_value
            font.pixelSize: 24

            Component.onCompleted: {
                console.log(text)
            }
        }

        Text {
            id: myStringValue
            text: mySenderInstance.myValue
            font.pixelSize: 24

            Component.onCompleted: {
                console.log(text)
            }
        }

        Text {
            id: myString2
            text: myStringInstance2.myString
            font.pixelSize: 24

            Component.onCompleted: {
                console.log(text)
            }
        }
        // Text input to modify the string
        TextField {
            id: inputField
            placeholderText: "Enter new text"
            placeholderTextColor: "red"
            onAccepted: {
                console.log("onAccepted: " + text)

                var inputText = parseInt(text)

                if (isNaN(inputText)) {
                    myStringInstance.myString = text
                } else {
                    mySenderInstance.m_value = inputText
                }
            }

            signal textFieldinitDone()

            Component.onCompleted: {
                console.log("TextField onCompleted")
                textFieldinitDone()
                console.log("TextField init done")
            }
        }

        Component.onCompleted: {
            console.log("Column onCompleted")
        }
    }

    Connections {
        target: inputField

        function onTextFieldinitDone() {
            console.log("TextField init done signal received")
            inputField.text = "Hello from QML"
            inputField.color = "blue"
        }
    }

    Component.onCompleted: {
        console.log("Window onCompleted")
    }
}