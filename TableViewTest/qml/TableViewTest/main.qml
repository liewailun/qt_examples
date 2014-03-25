import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Rectangle {
    width: 360
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
                    employeeModel.setFilterFixedString(filterEdit.text)
                }
            }
        }

        TableView
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: employeeModel
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
                model.sort(sortIndicatorColumn,sortIndicatorOrder)
                console.debug("COLUMN: " + sortIndicatorColumn)
            }
        }
    }
}
