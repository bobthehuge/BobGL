# BobGL

Simple GLFW and GLEW based Graphical Library

## Get Started

1. create c file
2. include 'bobgl.h'
3. define following variables with desired value:
    * `int WINDOW_WIDTH`
    * `int WINDOW_HEIGHT`
    * `int RESIZABLE`
    * `int FULLSCREEN`
    * `char* WINDOW_TITLE`
4. define following methods:
    * `void bglOnLoad(void)`
    * `void bglOnUpdate(void)`
    * `void bglOnUnload(void)`
5. finally, define a main entry point where you can add you code:
    * `bglInit(void)` -> init bgl context and calls `bglOnLoad()`
    * `bglRunLopp(void)` -> start render loop and calls `bglOnUpdate()` each
        iteration
    * `bglTerminate(void)` -> calls `bglOnUnload()` then terminates context
6. HAVE FUN !
    :)
