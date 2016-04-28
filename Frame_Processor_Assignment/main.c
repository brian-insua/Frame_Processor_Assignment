//
//  main.c
//  Frame_Processor_Assignment
//
// Instructions:
//
// To use in command line compile with:
//
// "clang Frame_Processor_Assignment.c -l SDL2 -o Frame_Processor_Assignment"
//
//  Created by Brian Insua on 26/04/2016.
//  Copyright © 2016 Brian Insua. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>



int main(int argc, const char * argv[])
{
    printf("Frame Processor Assignment\n"); /* Following from SDL Wiki, Gigi.NullNeuron.net & Eike */
    
    int done = 0; /* E - Starting State set to 0 to keep window open */
    
    SDL_Event ShowFrame; /* G - Declare Opening and Running window an event */
    
    SDL_Window *window; /* W - Declare Pointer */
    
    SDL_Init(SDL_INIT_EVERYTHING); /* W - Initialise SDL2 */
    
    window = SDL_CreateWindow("Frame Prcessor Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN); /* W - Creates Window */
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) /* E - checks if SDL2 initialised */
    {
        printf("Error: %s \n", SDL_GetError());
        return 1;
    } 
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC); /* E - Create Renderer (Frame Buffer) */
    
    SDL_Surface *pic = SDL_LoadBMP("AnotherPicture.bmp"); /* E - Loads Bitmap Image */
    
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, pic); /* E - Converts Texture to Surface */
    
    SDL_FreeSurface(pic); /* E - Frees rendundant surface memory */
    
    SDL_RenderCopy(renderer, tex, NULL, NULL); /* E - Draws Texture to Frame Buffer */
    
    SDL_RenderPresent(renderer); /* W - Shows Render */
    
    SDL_Delay(1000); /* W - Pauses execution for # of miliseconds */
    
	while( ! done ) /* G & E -  While loop to keep window open until user clicks close window option */
    {
		while (SDL_PollEvent(&ShowFrame))
		{
			SDL_WaitEvent(&ShowFrame);
			switch (ShowFrame.type)
			{
				case SDL_QUIT:
					done = 1;
					break;
			}
		}
	}
    
    SDL_DestroyTexture(tex); /* E - Clears Memory */
    
    SDL_DestroyWindow(window); /* W - Closes Window */
    
    SDL_Quit(); /* W - Quits SDL2 */
    
    return 0;
}
