#pragma once

#include <memory>
#include <string>

class GLFWwindow;

namespace glfw
{
    /*! Wrapper class for a GLFW window
    Methods are static because only a single window should exist
    at any given time
    */

    class Window
    {
    private:
        static GLFWwindow* m_window;
        Window() = default;
        static bool init();

    public:
        static void create(
            const int width,
            const int height,
            const std::string& title,
            const int glVersionMajor,
            const int glVersionMinor);
        static void destroy();
        static bool exitRequested();
        static void update();
        static auto getProcAddress();

        Window(Window const&) = delete;
        Window(Window const&&) = delete;
        void operator=(Window const&) = delete;

    };
}