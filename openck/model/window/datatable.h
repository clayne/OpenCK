#ifndef DATATABLE_H
#define DATATABLE_H

#include "fileinfo.h"

#include <QAbstractTableModel>

class DataTable : public QAbstractTableModel
{
    Q_OBJECT

public:
    DataTable(const QString& path, QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    FileInfo getInfoAtSelected(const QModelIndex& selected);

private:
    FileInfo getFileInfo(QString fileName, Header header);
    QVector<FileInfo> filesInfo;

signals:
    void newFileSelected(FileInfo info);
};

#endif // DATATABLE_H
