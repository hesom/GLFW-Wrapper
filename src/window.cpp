#include "window.h"
#include "inputevent.h"

#include "glfw/glfw3.h"

namespace glfww
{
    GLFWwindow* Window::window;

    bool Window::init()
    {
        return glfwInit();
    }

    void Window::create(const int width, const int height, const std::string title, int glVersionMajor, int glVersionMinor)
    {
        init();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glVersionMajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glVersionMinor);

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(window);

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (action == GLFW_PRESS) {
                InputEvent::handleKeyPressedEvent(key, mods);
            }
            else if (action == GLFW_RELEASE) {
                InputEvent::handleKeyReleasedEvent(key, mods);
            }
        });
        glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
            if (action == GLFW_PRESS) {
                InputEvent::handleMousePressedEvent(button, mods);
            }
            else if (action == GLFW_RELEASE) {
                InputEvent::handleMouseReleasedEvent(button, mods);
            }
        });
        glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
            InputEvent::handleCursorEvent(xpos, ypos);
        });
        glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
            InputEvent::handleScrollEvent(xoffset, yoffset);
        });

    }

    void Window::destroy()
    {
        glfwDestroyWindow(window);
    }

    bool Window::exitRequested()
    {
        return glfwWindowShouldClose(window);
    }

    void Window::update()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}