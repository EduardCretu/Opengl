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

float posX = 0.0f;
float posY = 0.0f;
float dirX = 0.0f;
float dirY = 0.0f;


// Technically the proper way to do it according to the study guide.
// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
//     if (action == GLFW_PRESS || action == GLFW_REPEAT) {
//
//         if (key == GLFW_KEY_W) {
//             dirY = 0.01f;
//             dirX = 0.0f;
//         }
//         else if (key == GLFW_KEY_S) {
//             dirY = -0.01f;
//             dirX = 0.0f;
//         }
//         else if (key == GLFW_KEY_D) {
//             dirY = 0.0f;
//             dirX = 0.01f;
//         }
//         else if (key == GLFW_KEY_A) {
//             dirY = 0.0f;
//             dirX = -0.01f;
//         }
//     }
//     if (action == GLFW_RELEASE) {
//         dirX = 0.0f;
//         dirY = 0.0f;
//     }
// }


int main() {
    //im not sure if this is fully fine, but it works right now.
    //in case of anything, just switch out the init functions with the ifs inside.
    if (initGLFW() != 0) return -1;

    GLFWwindow* window = glfwCreateWindow(720, 720, "Moving Square", NULL, NULL);

    //same here
    initWindow(window);

    glfwSetWindowPos(window, 100, 100);
    glfwMakeContextCurrent(window);



    while (!glfwWindowShouldClose(window)) {

        dirX = 0.0f;
        dirY = 0.0f;

        // Taking key inputs, check GLFW docs
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
             dirY = 1.0f;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            dirY = -1.0f;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            dirX = 1.0f;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            dirX = -1.0f;
        }
        float speed = 0.01f;

        posX += dirX * speed;
        posY += dirY * speed;


        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.2f, 0.6f, 0.8f);

        glRectf(
            posX - 0.1f, posY - 0.1f,
            posX + 0.1f, posY + 0.1f
        );

        // Traditional use of 'callback'. It's a bit Janky..
        //glfwSetKeyCallback(window,key_callback);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
