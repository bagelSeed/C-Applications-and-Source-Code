#include <SDL/SDL.h>

using namespace std;

int main(int argc, char *args[])
{
    SDL_Surface *circuit=NULL;
    SDL_Surface *screen=NULL;
    screen = SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);
    circuit=SDL_LoadBMP("circuit.bmp");
    SDL_BlitSurface(circuit,NULL,screen,NULL);
    SDL_Flip(screen);
    SDL_Delay(8000);
    SDL_FreeSurface(circuit);
    SDL_Quit();
    return 0;
}
