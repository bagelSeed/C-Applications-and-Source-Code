#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

SDL_Surface *loadImage(string filename)
{
    SDL_Surface *tempImage;
    SDL_Surface *depthImage;
    tempImage = IMG_Load(filename.c_str());
    if(tempImage==NULL)
        return NULL;
    depthImage = SDL_DisplayFormat(tempImage);
    SDL_FreeSurface(tempImage);
    return depthImage;
}

int main(int argc, char *args[])
{
    SDL_Surface *circuit=NULL;
    SDL_Surface *screen=NULL;
    const int screenWidth = 640;
    const int screenHeight = 480;
    const int screenDepth = 32;
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return 0;
    screen = SDL_SetVideoMode(screenWidth, screenHeight, screenDepth, SDL_HWSURFACE);
    SDL_WM_SetCaption("Test", NULL);
    circuit = loadImage("circuit.jpg");
    SDL_Event event;
    SDL_BlitSurface(circuit, NULL, screen, NULL);
    SDL_Flip(screen);

    bool isRunning = true;
    while(isRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                isRunning=false;
                break;
            }
        }
    }
    SDL_FreeSurface(circuit);
    SDL_Quit();
    return 0;
}
