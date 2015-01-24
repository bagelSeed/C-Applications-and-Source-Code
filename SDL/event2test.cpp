#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

SDL_Surface *loadImage(string filename);
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination);

int main( int argc, char* args[] )
{
    //The images
    SDL_Surface *background = NULL;
    SDL_Surface *screen = NULL;
    SDL_Surface *target = NULL;

    const int screenWidth = 640;
    const int screenHeight = 480;
    const int screenDepth = 32;

    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
        return 0;   // couldn't initialize SDL.  Panic and quit

    //Set up screen
    screen = SDL_SetVideoMode( screenWidth, screenHeight, screenDepth, SDL_SWSURFACE );
    SDL_WM_SetCaption( "Event Test", NULL );

    //Load images
    background = loadImage("circuit.jpg");
    target = loadImage("circle.png");

    int x = screenWidth/2;
    int y = screenHeight/2;
    applySurface( 0, 0, background, screen );
    applySurface( x, y, target, screen );
    SDL_Flip( screen );
    int delx = 10;
    int dely = 5;

    SDL_Event event;

    bool isRunning = true;
    bool message = false;
    while( isRunning == true )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                message = true;
                switch( event.key.keysym.sym )
                {
                    case SDLK_UP: y -= dely; break;
                    case SDLK_DOWN: y += dely; break;
                    case SDLK_LEFT: x -= delx; break;
                    case SDLK_RIGHT: x += delx; break;
                    default: break;
                }
            }
            else if( event.type == SDL_QUIT )
            {
                isRunning = false;
            }
        }

        //If a message needs to be displayed
        if( message )
        {
            applySurface( 0, 0, background, screen );
            applySurface( x, y, target, screen );
            message = false;
        }

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    SDL_FreeSurface( background );
    SDL_FreeSurface( target );
    SDL_Quit();
    return 0;
}

SDL_Surface *loadImage(string filename)
{
    SDL_Surface * tmpImage;
    SDL_Surface * depthImage;
    tmpImage = IMG_Load( filename.c_str() );

    // check if loaded
    if (tmpImage == NULL)
        return NULL;

    depthImage = SDL_DisplayFormat(tmpImage);
    SDL_FreeSurface(tmpImage);

    return depthImage;
}

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, NULL, destination, &offset );
}
