#include <QTest>
#include "fileutilstest.h"
#include "publishertest.h"
#include "pngtest.h"
#include "pvrtest.h"
#include "readertest.h"
#include "writertest.h"
#include "bipwritertest.h"
#include "bipreadertest.h"
#include "png2bipcachetest.h"
#include "etcheadertest.h"
#include "etctest.h"
#include "etcencodetest.h"
#include "s3tcencodetest.h"

int main(int argc, char *argv[])
{
    FileUtilsTest fileUtils;
    PublisherTest publish;
    PngTest png;
    PVRTest pvr;
    ReaderTest reader;
    WriterTest writer;
    BipWriterTest bipWriter;
    BipReaderTest bipReader;
    Png2BipCacheTest png2BipCache;
    ETCHeaderTest etcHeader;
    ETCTest etc;
    ETCEncodeTest etcEncode;
    S3TCEncodeTest s3tcEncode;

    QCoreApplication app(argc, argv);
    QString path = getenv("PATH");
    path += ":" + app.applicationDirPath();
    setenv("PATH", path.toStdString().c_str(), 1);

//    QTest::qExec(&fileUtils, argc, argv);
//    QTest::qExec(&publish, argc, argv);
//    QTest::qExec(&png, argc, argv);

//    QTest::qExec(&pvr, argc, argv);
//    QTest::qExec(&reader, argc, argv);
//    QTest::qExec(&writer, argc, argv);

//    QTest::qExec(&bipWriter, argc, argv);
//    QTest::qExec(&bipReader, argc, argv);
//    QTest::qExec(&png2BipCache, argc, argv);

//    QTest::qExec(&etcHeader, argc, argv);
//    QTest::qExec(&etc, argc, argv);
//    QTest::qExec(&etcEncode, argc, argv);

    QTest::qExec(&s3tcEncode, argc, argv);

    return 0;
}
