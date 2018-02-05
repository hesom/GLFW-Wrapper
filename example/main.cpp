#include "glfw-wrapper.h"
#include <iostream>

using namespace glfww;

class Listener : IKeyListener
{
public:
    Listener()
    {
        InputEvent::attachKeyListener(this);
    }

    void onKeyPressed(Key key, std::vector<KeyMod> mods)
    {
        if (key == Key::KEY_A) {
            std::cout << "A pressed!" << std::endl;
        }
    }
    void onKeyReleased(Key key, std::vector<KeyMod> mods)
    {
        if (key == Key::KEY_A) {
            std::cout << "A released!" << std::endl;
        }
    }
};

int main()
{
    Window::create(800, 600, "My Window", 3, 0);
    Listener listener;

    while (!Window::exitRequested()) {
        Window::update();
    }
}