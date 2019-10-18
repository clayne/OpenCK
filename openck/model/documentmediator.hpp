#ifndef DOCUMENTMEDIATOR_H
#define DOCUMENTMEDIATOR_H

#include "../files/filepaths.hpp"

#include "document.hpp"

#include <QObject>
#include <QVector>

#include <memory>

class Document;

class DocumentMediator : public QObject
{
    Q_OBJECT

public:
    DocumentMediator();
    ~DocumentMediator();

    void setPaths(const FilePaths& filePaths);

public slots:
	void clearFiles();
    void newFile(const QStringList& files);
    void openFile(const QStringList& files, bool isNew, QString author = QString(), QString desc = QString());
	void saveFile(const QString& path);

private:
	void openRelatedFiles(const QStringList& files);
	void loadAllFiles();
	void loadFile(std::shared_ptr<Document> document);

    QVector<std::shared_ptr<Document>> documents;
    FilePaths paths;
};

#endif // DOCUMENTMEDIATOR_H