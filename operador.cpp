#include "operador.h"
#include "almacen.h"
#include "servidor.h"
#include "espectaculo.h"


const std::string Operador::s_type = "OPERADOR";

Operador::Operador()
{

}

Operador::~Operador()
{

}

void Operador::procesarDatos(char* buffer, int len)
{
    char *pch;
    pch = strtok (buffer," ,.-/\r\n");

    if(strcmp(pch,"playVideo") == 0)
    {
        ElEspectaculo::Instance()->setPlayVideo(strtok (NULL,"\r\n"));
    }
    else if(strcmp(pch,"pauseVideo") == 0)
    {
        ElEspectaculo::Instance()->setPauseVideo();
    }
    else if(strcmp(pch,"stopVideo") == 0)
    {
        ElEspectaculo::Instance()->setStopVideo();
    }
    else if(strcmp(pch,"loopVideo") == 0)
    {
        ElEspectaculo::Instance()->setLoopVideo(strtok (NULL,"\r\n"));
    }



}
