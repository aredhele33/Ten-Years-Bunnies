/// \file    BunGameObjectBunny.hpp
/// \project TenYearsBunnies

#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include <BunGameObject.hpp>

class BunGameObjectBunny : public BunGameObject
{
private:
    static constexpr float s_StartPositionX = 32.0f;
    static constexpr float s_StartPositionY = 32.0f;
    static constexpr float s_StartVelocityX = 150.0f;
    static constexpr float s_StartVelocityY = 150.0f;
    static constexpr float s_Gravity        = 120.0f;

public:
    BunGameObjectBunny (BunApplication& application);
    ~BunGameObjectBunny() override;

    void HandleInput(const sf::Event& event) override;
    void Update     (float timeStep)         override;
    void Draw       (sf::RenderWindow& window, float timeStep, float interpolation) override;

private:
    sf::Sprite m_Sprite;
    float      m_PositionX;
    float      m_PositionY;
    float      m_VelocityX;
    float      m_VelocityY;
};
