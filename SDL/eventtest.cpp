#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

SDL_Surface *loadImage(string filename);

int main( int argc, char* args[] )
{
    //The images
    SDL_Surface *circuit = NULL;
    SDL_Surface *screen = NULL;

    const int screenWidth = 640;
    const int screenHeight = 480;
    const int screenDepth = 32;

    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
        return 0;   // couldn't initialize SDL.  Panic and quit

    //Set up screen
    screen = SDL_SetVideoMode( screenWidth, screenHeight, screenDepth, SDL_HWSURFACE );
    SDL_WM_SetCaption( "Mouse Test", NULL );

    //Load image
    circuit = loadImage("circuit.jpg");

    SDL_Event event;

    //Apply image to screen
    SDL_BlitSurface( circuit, NULL, screen, NULL );
    //Update Screen
    SDL_Flip( screen );
    //Pause

    bool isRunning = true;
    while( isRunning == true )
    {
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has clicked the close button on the top right
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                isRunning = false;
            }
        }
    }

    //Free the loaded image
    SDL_FreeSurface( circuit );
    //Quit SDL
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
