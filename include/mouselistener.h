#pragma once
#include <vector>
#include "keymap.h"

namespace glfw
{
    /*! Implement this interface to be able to subscribe to mouse events.
    Each of these functions will only be called when the corresponding mouse
    event occured. Make sure to call InputerManager::attachMouseListener to attach your
    listener
    */
    class IMouseListener
    {
    public:
        virtual ~IMouseListener() = default;
        virtual void onMousePressed(MouseButton button, std::vector<KeyMod> mods) = 0;
        virtual void onMouseReleased(MouseButton button, std::vector<KeyMod> mods) = 0;
        virtual void onMouseMoved(double xpos, double ypos, double dx, double dy) = 0;
        virtual void onMouseScroll(double xoffset, double yoffset) = 0;
    };
}