#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

enum Shape {
    BOX,
    CONE,
    CUBE,
    CYLINDER,
    DODECAHEDRON,
    ICOSAHEDRON,
    OCTAHEDRON,
    SPHERE,
    TEAPOT,
    TETRAHEDRON,
    TORUS
};

Shape currentShape = BOX;

void drawBox(float lx, float ly, float lz) {
    glPushMatrix();
    glScalef(lx, ly, lz);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawCylinder(float radius, float height) {
    #ifdef FREEGLUT
    glutSolidCylinder(radius, height, 32, 8);
    #else
    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, radius, radius, height, 32, 8);
    gluDeleteQuadric(q);
    #endif
}

void drawScaledPlatonic(float s, void (*fn)()) {
    glPushMatrix();
    glScalef(s, s, s);
    fn();
    glPopMatrix();
}

void renderShape() {
    switch (currentShape) {
        case BOX:
            drawBox(1.8f, 1.0f, 0.8f);
            break;
        case CONE:
            glutSolidCone(1.0, 2.0, 32, 16);
            break;
        case CUBE:
            glutSolidCube(1.5);
            break;
        case CYLINDER:
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, -1.0f);
            drawCylinder(0.8f, 2.0f);
            glPopMatrix();
            break;
        case DODECAHEDRON:
            drawScaledPlatonic(0.8f, glutSolidDodecahedron);
            break;
        case ICOSAHEDRON:
            drawScaledPlatonic(1.0f, glutSolidIcosahedron);
            break;
        case OCTAHEDRON:
            drawScaledPlatonic(1.2f, glutSolidOctahedron);
            break;
        case SPHERE:
            glutSolidSphere(1.0, 32, 16);
            break;
        case TEAPOT:
            glutSolidTeapot(1.0);
            break;
        case TETRAHEDRON:
            drawScaledPlatonic(1.5f, glutSolidTetrahedron);
            break;
        case TORUS:
            glutSolidTorus(0.35, 0.9, 24, 48);
            break;
    }
}

void keyCallback(GLFWwindow* window, int key, int, int action, int) {
    if (action != GLFW_PRESS) return;

    switch (key) {
        case GLFW_KEY_1: currentShape = BOX; break;
        case GLFW_KEY_2: currentShape = CONE; break;
        case GLFW_KEY_3: currentShape = CUBE; break;
        case GLFW_KEY_4: currentShape = CYLINDER; break;
        case GLFW_KEY_5: currentShape = DODECAHEDRON; break;
        case GLFW_KEY_6: currentShape = ICOSAHEDRON; break;
        case GLFW_KEY_7: currentShape = OCTAHEDRON; break;
        case GLFW_KEY_8: currentShape = SPHERE; break;
        case GLFW_KEY_9: currentShape = TEAPOT; break;
        case GLFW_KEY_0: currentShape = TETRAHEDRON; break;
        case GLFW_KEY_T: currentShape = TORUS; break;
        case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

    GLFWwindow* window = glfwCreateWindow(900, 700, "OpenGL Shapes", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    glfwSwapInterval(1);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        int w, h;
        glfwGetFramebufferSize(window, &w, &h);
        float aspect = (h == 0) ? 1.0f : (float)w / (float)h;

        glViewport(0, 0, w, h);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, aspect, 0.1, 100.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);

        float t = (float)glfwGetTime();
        glRotatef(t * 30.0f, 1.0f, 1.0f, 0.0f);

        renderShape();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
