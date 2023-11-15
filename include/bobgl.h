#ifndef _BOBGL_H
#define _BOBGL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stddef.h>

///////////////////////////////////////////////////////////////

/* * * * * * * *
**             *
**  TYPEDEFS   *
**             *
** * * * * * * *
*/

typedef GLFWwindow BGL_Window;
typedef GLFWmonitor BGL_Monitor;

struct BGL_Winopt
{
    size_t width;
    size_t height;
    char* title;
    int resizable;
    int fullscreen;
};

///////////////////////////////////////////////////////////////

// default windows options struct
#ifndef BGL_DEFAULT_WINOPT
#define BGL_DEFAULT_WINOPT { 860, 640, "BobGL", 1, 0 }
#endif

#ifndef BGL_RECT_VERT
#define BGL_RECT_VERT {-1.0,1.0,1.0,1.0,1.0,-1.0,1.0,-1.0,-1.0,-1.0,-1.0,1.0}
#endif

///////////////////////////////////////////////////////////////

/* * * * * * * *
**             *
**  FUNCTIONS  *
**             *
** * * * * * * *
*/

void bgl_init(void (*on_load)(void));
void bgl_loop(void (*on_update)(void));
void bgl_exit(void (*on_exit)(void));

char* get_file_content(const char* file);
GLuint bgl_new_shader(GLenum shaderType, const char* file);
void bgl_def_keycall(GLFWwindow* window, int key, int scancode, int action, int mods);
BGL_Window* bgl_create_window(struct BGL_Winopt* opt);

///////////////////////////////////////////////////////////////

#endif
