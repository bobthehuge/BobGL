# BobGL

Simple GLFW and GLEW based Graphical Library

## Compile

1. create dir named 'lib'
2. make

## Get Started

1. create c file
2. include 'bobgl.h' ('log.h' contains debug macros)
3. define a main entry point where you can add you code:
    * `bgl_init(void (*on_load(void)))` -> init bgl context with default keycalls and calls `on_load()` if not `NULL`
    * `bgl_loop(void (*on_loop(void)))` -> start render loop and calls `on_loop()` each
        iteration if not `NULL`
    * `bgl_exit(void (*on_exit(void)))` -> calls `on_exit()` if not `NULL` then terminates context
4. HAVE FUN !
    :)
