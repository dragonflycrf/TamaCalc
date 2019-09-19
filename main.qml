import QtQuick 2.12
import QtQuick.Controls 2.5
import TamaDataSet 1.0
import Qt.labs.calendar 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    TamaDataSet {
        id: dataSet
    }

    Button {
        id: loadBtn
        x: 0
        y: 0
        width: 63
        height: 32
        text: qsTr("Load")
        z: 1
    }

    ScrollView {
        id: scrollView
        y: 100
        height: 440
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        ListView {
            y: 100
            width: 640
            height: 440
            z: 1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            model: dataSet.getTamaData()
            delegate: ItemDelegate {
                text: "Item " + (index + 1)
                width: parent.width
            }
        }
    }
    Connections {
        target: loadBtn
        onClicked: {
            dataSet.loadData()
        }


    }
}

/*##^## Designer {
    D{i:3;anchors_height:440}
}
 ##^##*/
