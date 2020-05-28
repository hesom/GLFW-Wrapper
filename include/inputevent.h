#pragma once
#include <vector>
#include "keylistener.h"
#include "mouselistener.h"
#include "keymap.h"

namespace glfw
{
    /*! The InputManager is a singleton class which dispatches the keyboard and mouse inputs gathered
    by the window to subscribed listener classes (aka observer design pattern)
    */
    class InputEvent
    {
    private:
        InputEvent();
        // ReSharper disable once CppInconsistentNaming
        static double m_mouseX_old;
        // ReSharper disable once CppInconsistentNaming
        static double m_mouseY_old;
        static std::vector<IKeyListener*> m_keyListeners;
        static std::vector<IMouseListener*> m_mouseListeners;
    public:

        InputEvent(InputEvent const&) = delete;
        void operator=(InputEvent const&) = delete;

        /*! Handles the single event after a key is pressed down.
        \param key the glfw key id
        \param mods the glfw mod keys pressed, encoded in a single int (shift, alt, etc)
        */
        static void handleKeyPressedEvent(const int key, const int mods);

        /*! Handles the single event after a key is released.
        \param key the glfw key id
        \param mods the glfw mod keys pressed, encoded in a single int (shift, alt, etc)
        */
        static void handleKeyReleasedEvent(const int key, const int mods);

        /*! Handles the single event after a key is pressed.
        \param button the glfw mouse button id
        \param mods the glfw mod keys pressed, encoded in a single int (shift, alt, etc)
        */
        static void handleMousePressedEvent(const int button, const int mods);

        /*! Handles the single event after a key is released.
        \param button the glfw key id
        \param mods the glfw mod keys pressed, encoded in a single int (shift, alt, etc)
        */
        static void handleMouseReleasedEvent(const int button, const int mods);

        /*! Handles the event after the mouse is released.
        \param xpos the x position of the mouse. 0 is top left of the window
        \param ypos the y position of the mouse. 0 is top left of the window
        */
        static void handleCursorEvent(const double xpos, const double ypos);

        /*! Handles the event after scrolling with the mouse wheel
        \param xoffset how far the mouse wheel was scrolled from left to right
        \param yoffset how far the mouse wheel was scrolled from top to bottom
        */
        static void handleScrollEvent(const double xoffset, const double yoffset);

        /*! Attaches a IMouseListener that gets notified each time a mouse event occurs
        \param mouseListener pointer to the IMouseListener to be attached
        */
        static void attachMouseListener(IMouseListener* mouseListener);

        /*! Detaches a IMouseListener to unsubscribed from event notifications
        \param mouseListener pointer to the IMouseListener to be detached
        */
        static void detachMouseListener(const IMouseListener* mouseListener);

        /*! Attaches a IKeyListener that gets notified each time a keyboard event occurs
        \param keyListener pointer to the IKeyListener to be attached
        */
        static void attachKeyListener(IKeyListener* keyListener);

        /*! Detaches a IKeyListener to unsubscribed from event notifications
        \param keyListener pointer to the IKeyListener to be detached
        */
        static void detachKeyListener(const IKeyListener* keyListener);

    private:
        /*! Maps glfw key enum values to a safer internal enum class format */
        static Key mapKey(int glfwKey);
        /*! Maps glfw mod enum values to a safer internal enum class format */
        static std::vector<KeyMod> mapMods(int glfwKey);
        /*! Maps glfw mouse button enum values to a safer internal enum class format */
        static MouseButton mapMouse(int glfwMouse);
    };
}