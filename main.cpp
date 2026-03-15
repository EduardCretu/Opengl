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



    float x = -0.5f;      // starting position
    float speed = 0.01f;  // movement speed
    int direction = 1;    // 1 = right, -1 = left



    while (!glfwWindowShouldClose(window)) {

        x += speed * direction;

        if (x > 0.8f || x < -0.8f)
            direction *= -1;

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.2f, 0.6f, 0.8f);


        // Formula to move square diagonally
         glRectf( (-1*x) - 0.2f,   x - 0.2f,
                  (-1*x) + 0.2f,   x + 0.2f);

        // Move square horizontally
        // glRectf(x- 0.2f, -0.2f,
        //         x + 0.2f, 0.2f);



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
