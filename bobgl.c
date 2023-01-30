#include <bobgl.h>

GLFWwindow* window;

GLFWwindow* WindowCreate()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, RESIZABLE);

    GLFWmonitor* monitor = FULLSCREEN ? glfwGetPrimaryMonitor() : NULL;
     
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, monitor, NULL);

    return window;
}

void bglInit(void)
{
    glfwInit();

    GLFWwindow* window = WindowCreate();
    glfwMakeContextCurrent(window);

    glewInit();

    bglOnLoad();
}

void bglRunLoop(void)
{
    while(!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
        bglOnUpdate();
    }
}

void bglTerminate(void)
{
    bglOnUnload();
    glfwTerminate();
}
