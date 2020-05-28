#pragma once
#include <vector>
#include "keymap.h"

namespace glfw
{
    /*! Implement this interface to be able to subscribe to keyboard events.
    Each of these functions will only be called when the corresponding keyboard
    event occured. Make sure to call InputerManager::attachKeyListener to attach your
    listener
    */
    class IKeyListener
    {
    public:
        virtual ~IKeyListener() = default;

        virtual void onKeyPressed(Key key, std::vector<KeyMod> mods) = 0;
        virtual void onKeyReleased(Key key, std::vector<KeyMod> mods) = 0;
    };
}