#include <SDL/SDL.h>

int main( int argc, char* args[] )
{
    //The images
    SDL_Surface *circuit = NULL;
    SDL_Surface *screen = NULL;

    //Set up screen
    screen = SDL_SetVideoMode( 640, 480, 24, SDL_HWSURFACE );

    //Load image
    circuit = SDL_LoadBMP( "circuit.bmp" );

    //Apply image to screen
    SDL_BlitSurface( circuit, NULL, screen, NULL );
    //Update Screen
    SDL_Flip( screen );
    //Pause
    SDL_Delay( 8000 );

    //Free the loaded image
    SDL_FreeSurface( circuit );

    //Quit SDL
    SDL_Quit();
    return 0;
}
