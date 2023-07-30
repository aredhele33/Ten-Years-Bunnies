/// \file    BunGameObjectBunny.cpp
/// \project TenYearsBunnies

#include <SFML/Graphics.hpp>

#include <BunApplication.hpp>
#include <BunGameObjectBunny.hpp>
#include <BunGameObjectTerrain.hpp>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"

BunGameObjectBunny::BunGameObjectBunny (BunApplication& application)
: BunGameObject(application)
, m_Sprite      (*m_Application.GetTextureBunny())
, m_PositionX   (s_StartPositionX)
, m_PositionY   (s_StartPositionY)
, m_VelocityX   (s_StartVelocityX)
, m_VelocityY   (s_StartVelocityY)
{
    m_VelocityX += static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / s_StartVelocityX));
    m_VelocityY += static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / s_StartVelocityY));

    m_Sprite.setPosition(sf::Vector2f(m_PositionX, m_PositionY));
}

#pragma clang diagnostic pop

BunGameObjectBunny::~BunGameObjectBunny()
{
    // None
}

void BunGameObjectBunny::HandleInput(const sf::Event& event)
{
    // None
}

void BunGameObjectBunny::Update(float timeStep)
{
    if(m_PositionX < 0.0f || m_PositionX > (BunGameObjectTerrain::s_TileCountX - 1) * BunGameObjectTerrain::s_TileSize)
    {
        m_VelocityX *= -1.0f;
        m_PositionX += m_VelocityX * timeStep;
    }

    if(m_PositionY < 0.0f || m_PositionY > (BunGameObjectTerrain::s_TileCountY - 1) * BunGameObjectTerrain::s_TileSize)
    {
        m_VelocityY *= -1.0f;
        m_PositionY += m_VelocityY * timeStep;
    }

    m_VelocityY += s_Gravity   * timeStep;
    m_PositionX += m_VelocityX * timeStep;
    m_PositionY += m_VelocityY * timeStep;
}

void BunGameObjectBunny::Draw(sf::RenderWindow& window, float timeStep, float interpolation)
{
    m_Sprite.setPosition(
        m_PositionX + m_VelocityX * timeStep * interpolation,
        m_PositionY + m_VelocityY * timeStep * interpolation
    );

    window.draw(m_Sprite);
}
