import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Rectangle {
    width: 400
    height: 360
    ColumnLayout
    {
        anchors.fill: parent
        GroupBox
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: "Filter"
            TextField {
                id: filterEdit
                onTextChanged: {
                    business.model.setFilterFixedString(filterEdit.text)
                }
            }
        }

        TableView
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: business.model
            sortIndicatorVisible: true
            alternatingRowColors: true
            TableViewColumn
            {
                role: "LastName"
                title: "LastName"
                width: 100
            }
            TableViewColumn
            {
                role: "FirstName"
                title: "FirstName"
                width: 100
            }
            TableViewColumn
            {
                role: "Title"
                title: "Title"
                width: 100
            }
            onSortIndicatorOrderChanged: {
                business.model.sort(sortIndicatorColumn,sortIndicatorOrder)
            }
        }

        GroupBox
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: "Add"
            RowLayout
            {
                TextField
                {
                    id: lastName
                    Layout.fillWidth: true
                }
                TextField
                {
                    id: firstName
                    Layout.fillWidth: true
                }
                TextField
                {
                    id: title
                    Layout.fillWidth: true
                }
                Button
                {
                    Layout.fillWidth: true
                    text: "ok"
                    onClicked: {
                        business.addEmployee(lastName.text,firstName.text,title.text)
                        lastName.text = ""
                        firstName.text = ""
                        title.text = ""
                    }
                }
            }
        }
    }
}
