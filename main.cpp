#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <iostream>

int initGLFW() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
    return 0;
}

int initWindow(GLFWwindow*& window) {
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

    return 0;
}

int main() {
    //im not sure if this is fully fine, but it works right now.
    //in case of anything, just switch out the init functions with the ifs inside.
    if (initGLFW() != 0) return -1;

    GLFWwindow* window = glfwCreateWindow(250, 250, "First OpenGL program", NULL, NULL);

    //same here
    initWindow(window);

    glfwSetWindowPos(window, 100, 100);
    glfwMakeContextCurrent(window);


    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // TL red
        glColor3f(1.0f, 0.0f, 0.0f);
        glRectf(-0.9f, 0.1f, -0.1f, 0.9f);

        // TR green
        glColor3f(0.0f, 1.0f, 0.0f);
        glRectf(0.1f, 0.1f, 0.9f, 0.9f);

        // BL blue
        glColor3f(0.0f, 0.0f, 1.0f);
        glRectf(-0.9f, -0.9f, -0.1f, -0.1f);

        // BR yellow
        glColor3f(1.0f, 1.0f, 0.0f);
        glRectf(0.1f, -0.9f, 0.9f, -0.1f);

        // M cyan
        glColor3f(0.0f, 0.9f, 0.9f);
        glRectf(-0.5f, -0.5f, 0.5f, 0.5f);




        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
