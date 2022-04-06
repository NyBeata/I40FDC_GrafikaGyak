#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>

#include "line.h"

int mouseX;
int mouseY;
#define NoLines 10

Line line_array[NoLines]; 

int main(int argc, char* argv[])
{
  int error_code;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_GLContext gl_context;
  int i;

  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "Lángos",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600,
    SDL_WINDOW_OPENGL);

  gl_context = SDL_GL_CreateContext(window);
  glClearColor(0, 0, 0, 1);
  glColor3f(1, 1, 1);
  glPointSize(5.0);
  glLineWidth(5.0);

  int current=-1;

  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:
      SDL_GetMouseState(&mouseX, &mouseY);
      printf("\nx: %d y: %d", mouseX, mouseY);
      if(current==-1){
        line_array[0].x1 = mouseX;
        line_array[0].y1 = mouseY;
      }else{
        line_array[current].x2 = mouseX;
        line_array[current].y2 = mouseY;
        line_array[current+1].x1 = mouseX;
        line_array[current+1].y1 = mouseY;
      } 
      current++;
      break;
      case SDL_KEYDOWN:
        case SDL_SCANCODE_Q:
        need_run = false;
        break;
      case SDL_QUIT:
        need_run = false;
        break;
      }
    }

   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(i=0; i<current; i++){
      DrawLine(line_array[i]);
    }

     SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}