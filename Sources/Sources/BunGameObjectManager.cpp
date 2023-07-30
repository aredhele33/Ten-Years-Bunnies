/// \file    BunGameObjectManager.cpp
/// \project TenYearsBunnies

#include <SFML/Graphics.hpp>

#include <BunApplication.hpp>
#include <BunGameObjectBunny.hpp>
#include <BunGameObjectManager.hpp>

BunGameObjectManager::BunGameObjectManager (BunApplication& application)
: BunGameObject                (application)
, m_TextCurrentFrameID         ("", *m_Application.GetFontDebug(), s_TextFontSize)
, m_TextCurrentFramePerSecond  ("", *m_Application.GetFontDebug(), s_TextFontSize)
, m_TextCurrentFrameTime       ("", *m_Application.GetFontDebug(), s_TextFontSize)
, m_TextWorldObjectCount       ("", *m_Application.GetFontDebug(), s_TextFontSize)
, m_TextWorldPendingObjectCount("", *m_Application.GetFontDebug(), s_TextFontSize)
{
    m_TextCurrentFrameID.setPosition(sf::Vector2f(
        s_CurrentFrameIDPositionX,
        s_CurrentFrameIDPositionY));

    m_TextCurrentFramePerSecond.setPosition(sf::Vector2f(
        s_CurrentFramePerSecondPositionX,
        s_CurrentFramePerSecondPositionY));

    m_TextCurrentFrameTime.setPosition(sf::Vector2f(
        s_CurrentFrameTimePositionX,
        s_CurrentFrameTimePositionY));

    m_TextWorldObjectCount.setPosition(sf::Vector2f(
            s_WorldObjectCountPositionX,
            s_WorldObjectCountPositionY));

    m_TextWorldPendingObjectCount.setPosition(sf::Vector2f(
            s_WorldPendingObjectCountPositionX,
            s_WorldPendingObjectCountPositionY));
}

BunGameObjectManager::~BunGameObjectManager()
{
    // None
}

void BunGameObjectManager::HandleInput(const sf::Event& event)
{
    if(event.type     == sf::Event::KeyPressed &&
       event.key.code == sf::Keyboard::A)
    {
        for(uint32_t i = 0; i < s_WorldObjectBatchCount; ++i)
        {
            m_Application.AddToWorld(new BunGameObjectBunny(m_Application));
        }
    }
}

void BunGameObjectManager::Update([[maybe_unused]] float timeStep)
{
    const uint32_t currentFrameID            = m_Application.GetCurrentFrameID();
    const uint32_t currentFramePerSecond     = m_Application.GetCurrentFramePerSecond();
    const float    currentFrameTime          = m_Application.GetCurrentFrameTime();
    const uint32_t currentObjectCount        = m_Application.GetWorldObjectCount();
    const uint32_t currentPendingObjectCount = m_Application.GetWorldObjectPendingCount();

    if (currentFramePerSecond >= 60)
    {
        m_TextCurrentFramePerSecond.setFillColor(sf::Color::Green);
    }
    else
    {
        m_TextCurrentFramePerSecond.setFillColor(sf::Color::Red);
    }

    m_TextCurrentFrameID.setString         (std::string("Current FID : ") + std::to_string(currentFrameID));
    m_TextCurrentFramePerSecond.setString  (std::string("Current FPS : ") + std::to_string(currentFramePerSecond));
    m_TextCurrentFrameTime.setString       (std::string("Current Frame time : ") + std::to_string(currentFrameTime) + " s");
    m_TextWorldObjectCount.setString       (std::string("World object count : ") + std::to_string(currentObjectCount));
    m_TextWorldPendingObjectCount.setString(std::string("World object count (pending) : ") + std::to_string(currentPendingObjectCount));
}

void BunGameObjectManager::Draw(sf::RenderWindow& window, [[maybe_unused]] float timeStep, [[maybe_unused]] float interpolation)
{
    window.draw(m_TextCurrentFrameID);
    window.draw(m_TextCurrentFramePerSecond);
    window.draw(m_TextCurrentFrameTime);
    window.draw(m_TextWorldObjectCount);
    window.draw(m_TextWorldPendingObjectCount);
}
