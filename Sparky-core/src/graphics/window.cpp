#include "window.h"

namespace sparky::graphics {

    void windowResize(GLFWwindow *window, int width, int height) {
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0,0, width, height);
    }

    Window::Window(const char *title, int width, int height) {
        m_Title = title;
        m_Width = width;
        m_Height = height;

        if(!init()) {
            glfwTerminate();
        }
    }

    Window::~Window() {
        glfwTerminate();
    }

    bool Window::init() {
        /* Initialize the library */
        if (!glfwInit()) {
            std::cout << "Failed to initialize" << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);

        if (!m_Window) {
            std::cout << "Failed to create GLFW window!" << std::endl;
            return false;
        }

        glfwMakeContextCurrent(m_Window);
        glfwSetWindowSizeCallback(m_Window, windowResize);

        if (glewInit() != GLEW_OK) {
            std::cout << "Could not initialize GLEW!" << std::endl;
            return false;
        }

        std::cout <<  "OPENGL" << glGetString(GL_VERSION) << std::endl;

        return true;
    }

    void Window::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    bool Window::closed() const {
        return glfwWindowShouldClose(m_Window);
    }
}