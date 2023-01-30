#ifndef _BOBGL_H
#define _BOBGL_H 1

#include <GL/glew.h>
#include <GLFW/glfw3.h>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern char* WINDOW_TITLE;
extern int RESIZABLE;
extern int FULLSCREEN;

extern void bglOnLoad(void);
extern void bglOnUpdate(void);
extern void bglOnUnload(void);

GLFWwindow* window;

void bglInit(void);
void bglRunLoop(void);
void bglTerminate(void);

#endif
