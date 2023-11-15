# BobGL

Simple GLFW and GLEW based Graphical Library

## Get Started

1. create c file
2. include 'bobgl.h'
3. define following variables with desired value (or macro define `BGL_DEFS`):
    * `int WINDOW_WIDTH`
    * `int WINDOW_HEIGHT`
    * `int RESIZABLE`
    * `int FULLSCREEN`
    * `char* WINDOW_TITLE`
4. define a main entry point where you can add you code:
    * `bgl_init(void (*on_load(void)))` -> init bgl context and calls `on_load()` if not `NULL`
    * `bgl_loop(void (*on_loop(void)))` -> start render loop and calls `on_loop()` each
        iteration if not `NULL`
    * `bgl_exit(void (*on_exit(void)))` -> calls `on_exit()` if not `NULL` then terminates context
5. HAVE FUN !
    :)
