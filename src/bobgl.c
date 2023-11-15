#include <bobgl.h>
#include <log.h>
#include <stdlib.h>
#include <string.h>

char* get_file_content(const char* file)
{
    FILE *fp;
    long size = 0;
    char* cont;
    
    /* Read File to get size */
    fp = fopen(file, "rb");
    if (fp == NULL) {
        return "";
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp)+1;
    fclose(fp);

    /* Read File for Content */
    cont = calloc(size, 1);
    fp = fopen(file, "r");

    if (fread(cont, 1, size-1, fp))
    {
        if (ferror(fp))
        {
            WARN("Can't read file '%s'", file);
        }
    }

    fclose(fp);

    return cont;
}

GLuint bgl_new_shader(GLenum shaderType, const char* file)
{
    const char* shaderSource = get_file_content(file);
    GLuint shader = glCreateShader(shaderType);

    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    char buffer[512];
    glGetShaderInfoLog(shader, 512, NULL, buffer);

    if (status != GL_TRUE)
    {
        WARNX("file '%s' compilation failed with:\n%s", file, buffer);
    }

    return shader;
}

void bgl_def_keycall(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    (void) scancode;
    (void) action;
    (void) mods;

    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_ESCAPE)
        {
            exit(0);
        }
        if (key == GLFW_KEY_Q)
        {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }
}

BGL_Window* bgl_create_window(struct BGL_Winopt* opt)
{
    struct BGL_Winopt def = BGL_DEFAULT_WINOPT;

    if (opt == NULL)
    {
        opt = &def;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, opt->resizable);

    BGL_Monitor* monitor = opt->fullscreen ? glfwGetPrimaryMonitor() : NULL;

    return glfwCreateWindow(opt->width, opt->height, opt->title, monitor, NULL);
}

void bgl_init(void (*on_load)(void))
{
    glfwInit();

    BGL_Window* win = bgl_create_window(NULL);
    glfwMakeContextCurrent(win);

    glewInit();

    glfwSetKeyCallback(win, bgl_def_keycall);

    if (on_load != NULL)
    {
        (*on_load)();
    }
}

void bgl_loop(void (*on_update)(void))
{
    BGL_Window* window = glfwGetCurrentContext();

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (on_update != NULL)
        {
            (*on_update)();
        }
    }

}

void bgl_exit(void (*on_exit)(void))
{
    if (on_exit != NULL)
    {
        (*on_exit)();
    }

    glfwTerminate();
}
