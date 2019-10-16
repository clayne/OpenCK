#ifndef FILEINFO_H
#define FILEINFO_H

#include "../files/esm/esmreader.hpp"

struct FileInfo
{
    QString fileName;
    QString author;
    QString description;
    Flags flags;
    float version;
    QStringList masters;
};

#endif // FILEINFO_H
