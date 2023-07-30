/// \file    BunApplication.hpp
/// \project TenYearsBunnies

#pragma once

#include <cstdint>
#include <cstdlib>
#include <vector>

namespace sf
{
    class Font;
    class RenderWindow;
    class Texture;
}

class BunGameObject;
class BunApplication
{
private:
    static constexpr uint32_t    s_FixedStepCount    = 60;
    static constexpr uint32_t    s_WindowWidth       = 1280;
    static constexpr uint32_t    s_WindowHeight      = 768;
    static constexpr const char* s_WindowName        = "Ten Years Bunnies";
    static constexpr const char* s_TextureGroundPath = "../../Resources/Texture/ground.png";
    static constexpr const char* s_TextureBunnyPath  = "../../Resources/Texture/bunny.png";
    static constexpr const char* s_FontDebugPath     = "../../Resources/Font/RL.ttf";

public: // Minimalist public interface
    int Run(int argc, char** argv);

    void AddToWorld     (BunGameObject* object);
    void RemoveFromWorld(BunGameObject* object);

    [[nodiscard]] sf::Texture* GetTextureTerrain() const;
    [[nodiscard]] sf::Texture* GetTextureBunny  () const;
    [[nodiscard]] sf::Font*    GetFontDebug     () const;

    [[nodiscard]] uint32_t     GetWorldObjectCount       () const;
    [[nodiscard]] uint32_t     GetWorldObjectPendingCount() const;
    [[nodiscard]] uint32_t     GetCurrentFrameID         () const;
    [[nodiscard]] uint32_t     GetCurrentFramePerSecond  () const;
    [[nodiscard]] float        GetCurrentFrameTime       () const;

private: // Application life cycle
    int Initialize();
    int GameLoop  ();
    int Shutdown  ();

private: // Game loop management
    void ManageObjects();
    void HandleInput  ();
    void UpdateObjects(float timeStep);
    void Render       (float timeStep, float interpolation);

private: // SFML objects
    sf::RenderWindow* m_RenderWindow   { nullptr };
    sf::Texture*      m_TextureTerrain { nullptr };
    sf::Texture*      m_TextureBunny   { nullptr };
    sf::Font*         m_FontDebug      { nullptr };

private: // Application objects
    std::vector<BunGameObject*> m_World;
    std::vector<BunGameObject*> m_WorldAddCommands;

    uint32_t m_CurrentFrameID        { 0 };
    uint32_t m_CurrentFramePerSecond { 0 };
    float    m_CurrentFrameTime      { 0 };
};
