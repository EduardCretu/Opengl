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

float squareX = 0.0f;
float squareY = 0.0f;

int windowWidth = 250;
int windowHeight = 250;
int pressed = 0;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        // convert pixel coordinates → OpenGL coordinates
        squareX = (xpos / windowWidth) * 2.0f - 1.0f;
        squareY = -((ypos / windowHeight) * 2.0f - 1.0f);
        pressed = 1;
    }
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

    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while (!glfwWindowShouldClose(window)) {


        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.2f, 0.6f, 0.8f);

        float s = 0.1f;
        if(pressed == 1) {
            glRectf(squareX - s, squareY - s,
                    squareX + s, squareY + s);
        }


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
