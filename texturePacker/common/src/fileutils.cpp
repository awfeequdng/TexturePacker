#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QFile>
#include <iostream>
#include "include/fileutils.h"

FileUtils::FileUtils() :
    QObject(NULL)
{
}

QVector<QString> FileUtils::getAllImageFiles(const QString & path)
{
    QVector<QString> result;
    QDir dir(path);
    QFileInfoList fileInfoLists = dir.entryInfoList();
    QFileInfoList::const_iterator iterator = fileInfoLists.constBegin();

    for(; iterator != fileInfoLists.constEnd(); iterator++)
    {
        QString filename = iterator->fileName();

        if (!filename.startsWith("."))
        {
            if (iterator->isDir())
            {
                result += getAllImageFiles(iterator->absoluteFilePath());
            }
            else if (iterator->isFile())
            {
                QString ext = iterator->completeSuffix();
                QString extLower = ext.toLower();
                if (extLower.endsWith("png") ||
                        extLower.endsWith("jpg") ||
                        extLower.endsWith("jpeg"))
                {
                    result.push_back(iterator->absoluteFilePath());
                }
            }
            else
            {
                //
            }
        }
    }

    return result;
}

static QString getParentPath(const QString & path)
{
    QFileInfo fileInfo(path);

    return fileInfo.absolutePath();
}

bool FileUtils::hasParentDirectory(const QString & path)
{
    QString parentPath = getParentPath(path);

    if (parentPath.length() > 0)
    {
        QDir parentDir(parentPath);
        return parentDir.exists();
    }

    return false;
}

bool FileUtils::createParentDirectory(const QString & path)
{
    QString parentPath = getParentPath(path);
    QDir parentDir;
    return parentDir.mkpath(parentPath);
}

unsigned char *FileUtils::getFileData(const char *pszFileName, const char *pszMode, unsigned long *pSize)
{
    unsigned char * pBuffer = NULL;

    if (pszFileName == NULL || pSize == NULL || pszMode == NULL)
    {
        return NULL;
    }

    *pSize = 0;

    // read the file from hardware
    FILE *fp = fopen(pszFileName, pszMode);

    if (!fp)
    {
        return NULL;
    }

    fseek(fp,0,SEEK_END);
    *pSize = ftell(fp);
    fseek(fp,0,SEEK_SET);
    pBuffer = new unsigned char[*pSize];
    *pSize = fread(pBuffer,sizeof(unsigned char), *pSize,fp);
    fclose(fp);

    return pBuffer;
}

QString FileUtils::createImageTempFolder()
{
    QString path = QDir::homePath() + "/.tp/tmp";
    QDir dir(path);
    if (!dir.exists())
    {
        dir.mkpath(path);
    }

    return path;
}

QString FileUtils::getRandFileNameString()
{
    srand((int)time(0));
    char strFile[32] = {0};
    sprintf(strFile, "%d", rand());

    return strFile;
}

bool FileUtils::unlink(const QString &filename)
{
    QFile file(filename);
    if (file.exists())
    {
        return file.remove();
    }

    return true;
}
