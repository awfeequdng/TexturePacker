#include <QThread>
#include "include/publishrannable.h"

class PubThread : public QThread
{
public:
    explicit PubThread(Publisher * pub);

private:
    void run();

private:
    Publisher * m_pub;
};

PubThread::PubThread(Publisher *pub):
    QThread()
  , m_pub(pub)
{

}

void PubThread::run()
{
    if (NULL != m_pub)
    {
        m_pub->publish();
    }
}

PublishRannable::PublishRannable(const SettingsVO & svo):
    QRunnable()
  , m_svo(svo)
  , m_publish(NULL)
{
}

PublishRannable::~PublishRannable()
{
    if (NULL != m_publish)
    {
        delete m_publish;
    }
}

void PublishRannable::run()
{
    m_publish = new Publisher(m_svo);
    PubThread pb(m_publish);
    pb.start();

    while(m_publish->isFinished() == false)
    {
        update("this is a test......");
        QThread::usleep(500);
    }

    finished();
}