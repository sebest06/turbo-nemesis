#ifndef ESPECTACULO_H
#define ESPECTACULO_H

#include <string>
#include <stdio.h>
#include <string.h>

enum Controles{
    playVideo = 1,
    loopVideo = 2,
    stopVideo = 4,
    pauseVideo = 8,
    sendVideo = 16
};

class Espectaculo
{
    public:
        static Espectaculo* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new Espectaculo();
                return s_pInstance;
            }
            return s_pInstance;
        }

        virtual ~Espectaculo();

        void setPlayVideo(std::string videoName);
        void setLoopVideo(std::string videoName);
        void setPauseVideo(void);
        void setStopVideo(void);

    protected:
    private:
        Espectaculo();
        void sendToAllVisor(char* message, int len);
        static Espectaculo* s_pInstance;
};

typedef Espectaculo ElEspectaculo;

#endif // ESPECTACULO_H
