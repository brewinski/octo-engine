#include "src/graphics/window.h"

void printErrors(std::string s) {
    GLenum err;
    int i = 0;
    while((err = glGetError()) != GL_NO_ERROR)
    {
        std::cout << s << err << ", " << glewGetErrorString(err)  << std::endl;
        i++;
    }

    if (i == 0) {
        std::cout << s << " No Errors"  << std::endl;
    }
}

int main() {
    using namespace sparky;
    using namespace graphics;

    Window window("Sparky!" ,960, 540);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    while (!window.closed()) {
        printErrors("Start: ");
        window.clear();
        printErrors("Clear: ");
        glBegin(GL_TRIANGLES);
        printErrors("Begin: ");
        glVertex2f(-0.5f, -0.5f);
        printErrors("Vert 1: ");
        glVertex2f(0.0f, 0.5f);
        printErrors("Vert 2: ");
        glVertex2f(0.5f, -0.5f);
        printErrors("Vert 3: ");
        glEnd();
        printErrors("End: ");

        window.update();
        printErrors("Update: ");

    }

    return 0;
}
