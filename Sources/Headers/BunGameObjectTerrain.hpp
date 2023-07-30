/// \file    BunGameObjectTerrain.hpp
/// \project TenYearsBunnies

#pragma once

#include <cstdint>

#include <SFML/Graphics/Sprite.hpp>

#include <BunGameObject.hpp>

class BunGameObjectTerrain : public BunGameObject
{
public:
    static constexpr float    s_TileSize   = 32.0f;
    static constexpr uint32_t s_TileCountX = 24;
    static constexpr uint32_t s_TileCountY = 24;

public:
    BunGameObjectTerrain (BunApplication& application);
    ~BunGameObjectTerrain() override;

    void HandleInput(const sf::Event& event) override;
    void Update     (float timeStep)         override;
    void Draw       (sf::RenderWindow& window, float timeStep, float interpolation) override;

private:
    std::vector<sf::Sprite> m_Tiles;
};
