#include "include/pvr.h"

PVR::PVR():
    Image()
  , m_pvrTexture(NULL)
{
}

PVR::PVR(QString filename):
    Image(filename)
  , m_pvrTexture(NULL)
{
}

PVR::PVR(const PVR &pvr):
    Image(pvr)
  , m_pvrTexture(NULL)
{
}

PVR::~PVR()
{
    if (m_pvrTexture != NULL)
    {
        delete m_pvrTexture;
    }
}

bool PVR::load()
{
    if (!exists(filePath()))
    {
        return false;
    }

    if (m_pvrTexture != NULL)
    {
        delete m_pvrTexture;
    }

    m_pvrTexture = new pvrtexture::CPVRTexture(filePath().toStdString().c_str());
    setWidth(m_pvrTexture->getWidth());
    setHeight(m_pvrTexture->getHeight());

    return true;
}
