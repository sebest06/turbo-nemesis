#include "espectaculo.h"
#include "almacen.h"
#include "servidor.h"

Espectaculo* Espectaculo::s_pInstance = 0;
Espectaculo::Espectaculo()
{
    //ctor
}

Espectaculo::~Espectaculo()
{
    //dtor
}

void Espectaculo::setPlayVideo(std::string videoName)
{
    char buff[100];
    buff[0] = playVideo;
    strncpy( buff+1,videoName.c_str(),videoName.length());
    sendToAllVisor(buff,(videoName.length()) + 1);
    printf("el tam es %d\n",videoName.length() + 1);
}

void Espectaculo::setPauseVideo(void)
{
    char buff[100];
    buff[0] = pauseVideo;
    sendToAllVisor(buff, 1);
}

void Espectaculo::setStopVideo(void)
{
    char buff[100];
    buff[0] = stopVideo;
    sendToAllVisor(buff, 1);
}


void Espectaculo::sendToAllVisor(char* message, int len)
{

    for(size_t i=0; i<ElAlmacen::Instance()->clientes.size(); i++)
    {
        if(ElAlmacen::Instance()->clientes[i]->getStateID() == "VISOR")
        {
            TheServidor::Instance()->sendData(ElAlmacen::Instance()->clientes[i]->getSocket(),message, len, 0);
        }
    }

}
