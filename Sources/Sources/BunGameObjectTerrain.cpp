/// \file    BunGameObjectTerrain.cpp
/// \project TenYearsBunnies

#include <SFML/Graphics.hpp>

#include <BunApplication.hpp>
#include <BunGameObjectTerrain.hpp>

BunGameObjectTerrain::BunGameObjectTerrain (BunApplication& application)
: BunGameObject(application)
, m_Tiles      ()
{
    m_Tiles.reserve(s_TileCountX * s_TileCountY);
    for(uint32_t i = 0; i < s_TileCountY; ++i)
    {
        for(uint32_t j = 0; j < s_TileCountX; ++j)
        {
            sf::Sprite& sprite = m_Tiles.emplace_back(*m_Application.GetTextureTerrain());
            sprite.setPosition(sf::Vector2f(s_TileSize * j, s_TileSize * i));
        }
    }
}

BunGameObjectTerrain::~BunGameObjectTerrain()
{
    // None
}

void BunGameObjectTerrain::HandleInput([[maybe_unused]] const sf::Event& event)
{
    // None
}

void BunGameObjectTerrain::Update([[maybe_unused]] float timeStep)
{
    // None
}

void BunGameObjectTerrain::Draw(sf::RenderWindow& window, [[maybe_unused]] float timeStep, [[maybe_unused]] float interpolation)
{
    for(const sf::Sprite& tile : m_Tiles)
    {
        window.draw(tile);
    }
}
