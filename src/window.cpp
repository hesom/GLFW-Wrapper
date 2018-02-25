#include "window.h"
#include "inputevent.h"

#include "GLFW/glfw3.h"

namespace glfww
{
    GLFWwindow* Window::m_window;

    bool Window::init()
    {
        return glfwInit();
    }

    void Window::create(const int width, const int height, const std::string& title, const int glVersionMajor, const int glVersionMinor)
    {
        init();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glVersionMajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glVersionMinor);

        m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_window);

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (action == GLFW_PRESS) {
                InputEvent::handleKeyPressedEvent(key, mods);
            }
            else if (action == GLFW_RELEASE) {
                InputEvent::handleKeyReleasedEvent(key, mods);
            }
        });
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
            if (action == GLFW_PRESS) {
                InputEvent::handleMousePressedEvent(button, mods);
            }
            else if (action == GLFW_RELEASE) {
                InputEvent::handleMouseReleasedEvent(button, mods);
            }
        });
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
            InputEvent::handleCursorEvent(xpos, ypos);
        });
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
            InputEvent::handleScrollEvent(xoffset, yoffset);
        });

    }

    void Window::destroy()
    {
        glfwDestroyWindow(m_window);
    }

    bool Window::exitRequested()
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::update()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

}