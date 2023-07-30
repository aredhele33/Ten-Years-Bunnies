/// \file    GameObject.hpp
/// \project TenYearsBunnies

#pragma once

namespace sf
{
    class Event;
    class RenderWindow;
}

class BunApplication;
class BunGameObject
{
public: // Public interface
             BunGameObject(BunApplication& application) : m_Application(application) {};
    virtual ~BunGameObject() {};

    virtual void HandleInput(const sf::Event& event) = 0;
    virtual void Update     (float timeStep)         = 0;
    virtual void Draw       (sf::RenderWindow& window, float timeStep, float interpolation) = 0;

protected:
    BunApplication& m_Application;
};
