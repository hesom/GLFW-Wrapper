#include "inputevent.h"
#include "GLFW/glfw3.h"
#include "keymap.h"
#include <vector>
#include <algorithm>

namespace glfw
{
    // ReSharper disable once CppInconsistentNaming
    double InputEvent::m_mouseX_old = 0.0;
    // ReSharper disable once CppInconsistentNaming
    double InputEvent::m_mouseY_old = 0.0;
    std::vector<IKeyListener*> InputEvent::m_keyListeners;
    std::vector<IMouseListener*> InputEvent::m_mouseListeners;

    InputEvent::InputEvent() = default;

    void InputEvent::handleKeyPressedEvent(const int key, const int mods)
    {
        for (auto& listener : m_keyListeners) {
            listener->onKeyPressed(mapKey(key), mapMods(mods));
        }
    }

    void InputEvent::handleKeyReleasedEvent(const int key, const int mods)
    {
        for (auto& listener : m_keyListeners) {
            listener->onKeyReleased(mapKey(key), mapMods(mods));
        }
    }

    void InputEvent::handleMousePressedEvent(const int button, const int mods)
    {
        for (auto& listener : m_mouseListeners) {
            listener->onMousePressed(mapMouse(button), mapMods(mods));
        }
    }

    void InputEvent::handleMouseReleasedEvent(const int button, const int mods)
    {
        for (auto& listener : m_mouseListeners) {
            listener->onMouseReleased(mapMouse(button), mapMods(mods));
        }
    }

    void InputEvent::handleCursorEvent(const double xpos, const double ypos)
    {
        //calculates dinstance since last cursor movement in pixels
        const auto dx = m_mouseX_old - xpos;
        const auto dy = m_mouseY_old - ypos;
        m_mouseX_old = xpos;
        m_mouseY_old = ypos;
        for (auto& listener : m_mouseListeners) {
            listener->onMouseMoved(xpos, ypos, dx, dy);
        }
    }

    void InputEvent::handleScrollEvent(const double xoffset, const double yoffset)
    {
        for (auto& listener : m_mouseListeners) {
            listener->onMouseScroll(xoffset, yoffset);
        }
    }

    void InputEvent::attachMouseListener(IMouseListener* mouseListener)
    {
        m_mouseListeners.push_back(mouseListener);
    }

    void InputEvent::detachMouseListener(const IMouseListener* mouseListener)
    {
        m_mouseListeners.erase(
            std::remove(m_mouseListeners.begin(), m_mouseListeners.end(), mouseListener),
            m_mouseListeners.end());
    }

    void InputEvent::attachKeyListener(IKeyListener* keyListener)
    {
        m_keyListeners.push_back(keyListener);
    }

    void InputEvent::detachKeyListener(const IKeyListener* keyListener)
    {
        m_keyListeners.erase(
            std::remove(m_keyListeners.begin(), m_keyListeners.end(), keyListener),
            m_keyListeners.end());
    }

    Key InputEvent::mapKey(const int glfwKey)
    {
        switch (glfwKey) {
        case GLFW_KEY_0:
            return Key::KEY_0;
        case GLFW_KEY_1:
            return Key::KEY_1;
        case GLFW_KEY_2:
            return Key::KEY_2;
        case GLFW_KEY_3:
            return Key::KEY_3;
        case GLFW_KEY_4:
            return Key::KEY_4;
        case GLFW_KEY_5:
            return Key::KEY_5;
        case GLFW_KEY_6:
            return Key::KEY_6;
        case GLFW_KEY_7:
            return Key::KEY_7;
        case GLFW_KEY_8:
            return Key::KEY_8;
        case GLFW_KEY_9:
            return Key::KEY_9;
        case GLFW_KEY_A:
            return Key::KEY_A;
        case GLFW_KEY_B:
            return Key::KEY_B;
        case GLFW_KEY_C:
            return Key::KEY_C;
        case GLFW_KEY_D:
            return Key::KEY_D;
        case GLFW_KEY_E:
            return Key::KEY_E;
        case GLFW_KEY_F:
            return Key::KEY_F;
        case GLFW_KEY_G:
            return Key::KEY_G;
        case GLFW_KEY_H:
            return Key::KEY_H;
        case GLFW_KEY_I:
            return Key::KEY_I;
        case GLFW_KEY_J:
            return Key::KEY_J;
        case GLFW_KEY_K:
            return Key::KEY_K;
        case GLFW_KEY_L:
            return Key::KEY_L;
        case GLFW_KEY_M:
            return Key::KEY_M;
        case GLFW_KEY_N:
            return Key::KEY_N;
        case GLFW_KEY_O:
            return Key::KEY_O;
        case GLFW_KEY_P:
            return Key::KEY_P;
        case GLFW_KEY_Q:
            return Key::KEY_Q;
        case GLFW_KEY_R:
            return Key::KEY_R;
        case GLFW_KEY_S:
            return Key::KEY_S;
        case GLFW_KEY_T:
            return Key::KEY_T;
        case GLFW_KEY_U:
            return Key::KEY_U;
        case GLFW_KEY_V:
            return Key::KEY_V;
        case GLFW_KEY_W:
            return Key::KEY_W;
        case GLFW_KEY_X:
            return Key::KEY_X;
        case GLFW_KEY_Y:
            return Key::KEY_Y;
        case GLFW_KEY_Z:
            return Key::KEY_Z;
        case GLFW_KEY_ENTER:
            return Key::KEY_RETURN;
        case GLFW_KEY_SPACE:
            return Key::KEY_SPACE;
        case GLFW_KEY_BACKSPACE:
            return Key::KEY_BACKSPACE;
        case GLFW_KEY_ESCAPE:
            return Key::KEY_ESC;
        case GLFW_KEY_INSERT:
            return Key::KEY_INSERT;
        case GLFW_KEY_F1:
            return Key::KEY_F1;
        case GLFW_KEY_F2:
            return Key::KEY_F2;
        case GLFW_KEY_F3:
            return Key::KEY_F3;
        case GLFW_KEY_F4:
            return Key::KEY_F4;
        case GLFW_KEY_F5:
            return Key::KEY_F5;
        case GLFW_KEY_F6:
            return Key::KEY_F6;
        case GLFW_KEY_F7:
            return Key::KEY_F7;
        case GLFW_KEY_F8:
            return Key::KEY_F8;
        case GLFW_KEY_F9:
            return Key::KEY_F9;
        case GLFW_KEY_F10:
            return Key::KEY_F10;
        case GLFW_KEY_F11:
            return Key::KEY_F11;
        case GLFW_KEY_F12:
            return Key::KEY_F12;
        case GLFW_KEY_TAB:
            return Key::KEY_TAB;
        case GLFW_KEY_CAPS_LOCK:
            return Key::KEY_CAPSLOCK;
        case GLFW_KEY_PRINT_SCREEN:
            return Key::KEY_PRINT;
        case GLFW_KEY_UP:
            return Key::KEY_UP;
        case GLFW_KEY_DOWN:
            return Key::KEY_DOWN;
        case GLFW_KEY_LEFT:
            return Key::KEY_LEFT;
        case GLFW_KEY_RIGHT:
            return Key::KEY_RIGHT;
        case GLFW_KEY_SCROLL_LOCK:
            return Key::KEY_SCROLL;
        case GLFW_KEY_DELETE:
            return Key::KEY_REMOVE;
        case GLFW_KEY_PAUSE:
            return Key::KEY_PAUSE;
        default:
            return Key::ERROR;
        }
    }

    MouseButton InputEvent::mapMouse(const int glfwMouse)
    {
        switch (glfwMouse) {
        case GLFW_MOUSE_BUTTON_1:
            return MouseButton::MOUSE_1;
        case GLFW_MOUSE_BUTTON_2:
            return MouseButton::MOUSE_2;
        case GLFW_MOUSE_BUTTON_3:
            return MouseButton::MOUSE_3;
        case GLFW_MOUSE_BUTTON_4:
            return MouseButton::MOUSE_4;
        case GLFW_MOUSE_BUTTON_5:
            return MouseButton::MOUSE_5;
        case GLFW_MOUSE_BUTTON_6:
            return MouseButton::MOUSE_6;
        case GLFW_MOUSE_BUTTON_7:
            return MouseButton::MOUSE_7;
        case GLFW_MOUSE_BUTTON_8:
            return MouseButton::MOUSE_8;
        default:
            return MouseButton::ERROR;
        }
    }

    std::vector<KeyMod> InputEvent::mapMods(const int glfwKey)
    {
        std::vector<KeyMod> mods;
        if (glfwKey & GLFW_MOD_SHIFT) {
            mods.push_back(KeyMod::MOD_SHIFT);
        }
        if (glfwKey & GLFW_MOD_CONTROL) {
            mods.push_back(KeyMod::MOD_CTRL);
        }
        if (glfwKey & GLFW_MOD_ALT) {
            mods.push_back(KeyMod::MOD_ALT);
        }
        if (glfwKey & GLFW_MOD_SUPER) {
            mods.push_back(KeyMod::MOD_WIN);
        }
        if (glfwKey & GLFW_MOD_CAPS_LOCK) {
            mods.push_back(KeyMod::MOD_CAPS);
        }
        if (glfwKey & GLFW_MOD_NUM_LOCK) {
            mods.push_back(KeyMod::MOD_NUM);
        }

        return mods;
    }
}