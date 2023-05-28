# Platformer 🙀

When a small cat trying to find her way home. _Actually not yet, I'm still trying to find out how to use SDL2 :)_

## Installation

1. Clone this repo
2. Go to directory `./sdl2-game/platformer` and create a new directory called **bin**
3. Install the game using `make all`
4. Run the game `./bin/game`
5. Enjoy!

---

## Controls

1. `A` and `D` : move left and right
2. `Space` : jump
3. `E` : interact with objects

---

## Objective

1. **Play around and enjoy** the 8K graphic with the latest Unreal 5.2 engine!!!

---

## Future Works

_soon_

---

## What I Learn

1. Flow of using SDL2: **init** --> **create window** --> **create surface** --> **playing around** --> **free surface** --> **destroy window** --> **quit**
2. To load image, use SDL_LoadBMP and pass the BMP image file path
3. `SDL_Window`: hold the display graphics
4. `SDL_Surface`: a data/image that we want to render to the display/window
5. `SDL_BlitSurface`: copy image from one surface to another
6. `SDL_Texture`: same like surface, but more powerfull
7. `SDL_PollEvent`: pull out an event from event stact
8. **Rendering flow in SDL2** : `SDL_RenderClear` --> `SDL_RenderCopy` --> `SDL_RenderPresent`
9. To handle gravity : repeatdly add the y-velocity with the gravity constant

---

## References

1. https://lazyfoo.net/tutorials/SDL/index2.php
2. https://wiki.libsdl.org/SDL2/
3. https://www.parallelrealities.co.uk/tutorials

---

### Licesne

Open-source
