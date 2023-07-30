/// \file    BunGameObjectManager.hpp
/// \project TenYearsBunnies

#pragma once

#include <SFML/Graphics/Text.hpp>

#include <BunGameObject.hpp>

class BunGameObjectManager : public BunGameObject
{
private:
    static constexpr uint32_t s_WorldObjectBatchCount            = 128;
    static constexpr uint32_t s_TextFontSize                     = 24;
    static constexpr float    s_TextDefaultPositionX             = 790.0f;
    static constexpr float    s_TextDefaultPositionY             = 10.0f;
    static constexpr float    s_CurrentFrameIDPositionX          = s_TextDefaultPositionX;
    static constexpr float    s_CurrentFrameIDPositionY          = s_TextDefaultPositionY;
    static constexpr float    s_CurrentFramePerSecondPositionX   = s_TextDefaultPositionX;
    static constexpr float    s_CurrentFramePerSecondPositionY   = s_TextDefaultPositionY + s_TextFontSize * 1.0f;
    static constexpr float    s_CurrentFrameTimePositionX        = s_TextDefaultPositionX;
    static constexpr float    s_CurrentFrameTimePositionY        = s_TextDefaultPositionY + s_TextFontSize * 2.0f;
    static constexpr float    s_WorldObjectCountPositionX        = s_TextDefaultPositionX;
    static constexpr float    s_WorldObjectCountPositionY        = s_TextDefaultPositionY + s_TextFontSize * 4.0f;
    static constexpr float    s_WorldPendingObjectCountPositionX = s_TextDefaultPositionX;
    static constexpr float    s_WorldPendingObjectCountPositionY = s_TextDefaultPositionY + s_TextFontSize * 5.0f;

public:
    BunGameObjectManager (BunApplication& application);
    ~BunGameObjectManager() override;

    void HandleInput(const sf::Event& event) override;
    void Update     (float timeStep)         override;
    void Draw       (sf::RenderWindow& window, float timeStep, float interpolation) override;

private:
    sf::Text m_TextCurrentFrameID;
    sf::Text m_TextCurrentFramePerSecond;
    sf::Text m_TextCurrentFrameTime;
    sf::Text m_TextWorldObjectCount;
    sf::Text m_TextWorldPendingObjectCount;
};
