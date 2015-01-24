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
void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *dest)
{
    SDL_Rect offset;
    offset.x=x;
    offset.y=y;
    SDL_BlitSurface(source, NULL, dest, &offset);
}

int main(int argc, char *args[])
{
    SDL_Surface *background=NULL;
    SDL_Surface *screen=NULL;
    SDL_Surface *target=NULL;
    const int screenWidth = 640;
    const int screenHeight = 480;
    const int screenDepth = 32;
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return 0;
    screen = SDL_SetVideoMode(screenWidth, screenHeight, screenDepth, SDL_HWSURFACE);
    SDL_WM_SetCaption("Test", NULL);
    background = loadImage("circuit.jpg");
    target = loadImage("circle.png");
    int x = screenWidth/2;
    int y = screenHeight/2;
    applySurface(0,0,background, screen);
    applySurface(x,y,target, screen);
    SDL_Flip(screen);
    int delx=10;
    int dely=5;
    SDL_Event event;

    bool isRunning = true;
    bool message = false;
    while(isRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_KEYDOWN)
            {
                message=true;
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: y-=dely;break;
                    case SDLK_DOWN: y+=dely;break;
                    case SDLK_LEFT: x-=delx;break;
                    case SDLK_RIGHT: x+=delx;break;
                    default: break;
                }
            }
            else if(event.type==SDL_QUIT)
            {
                isRunning=false;
                break;
            }
        }
        if(message)
        {
            applySurface(0,0,background,screen);
            applySurface(x,y,target,screen);
            message=false;
        }
        SDL_Flip(screen);
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(target);
    SDL_Quit();
    return 0;
}
