#include <stdio.h>
#include <stdlib.h>


#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "main.h"


void processInput(GLFWwindow *pWwindow);

int main() {

    

    if (!glfwInit()) puts("Failed to load");
    int number = 7;
    int number2 = 10;

    printf("%d", number);

    GLFWwindow* window;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1024, 600, "First Window", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, 1366, 768);

    glfwSetFramebufferSizeCallback(window, frame_resize_buffer);
    while(!glfwWindowShouldClose(window)){
        //Process key inputs
        processInput(window);

        //render commands
        glClearColor(.2f, .3f, .3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Poll events and swap buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *pWwindow) {
    if (glfwGetKey(pWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(pWwindow, 1);
}


void frame_resize_buffer(GLFWwindow *window, int width, int height) {
    puts("Resize called");
}
