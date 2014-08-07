#include "fabrica.h"

#include "almacen.h"
#include "visor.h"
#include "operador.h"


Fabrica* Fabrica::s_pInstance = 0;
Fabrica::Fabrica()
{
    //ctor
    m_Ukids = 0;
}

Fabrica::~Fabrica()
{
    //dtor
}

Cliente* Fabrica::fabricar(char* buffer, int len, int socket)
{
    Cliente *c;

    char *pch;
    pch = strtok (buffer," ,.-/\r\n");

    if(strcmp(pch,"visor") == 0)
    {
        c = new Visor();
        pch = strtok (NULL," ,.-/\r\n");
        c->setName(pch);
        c->setId(m_Ukids);
        m_Ukids++;
    }
    else if(strcmp(pch,"operador") == 0)
    {
        c = new Operador();
        pch = strtok (NULL," ,.-/\r\n");
        c->setName(pch);
        c->setId(m_Ukids);
        m_Ukids++;
    }

    else
    {
        c = NULL;
    }

    if(c != NULL)
    {
        c->setSocket(socket);
    }

    return c;

}
