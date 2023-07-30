/// \file    BunApplication.cpp
/// \project TenYearsBunnies

#include <iostream>

#include <SFML/Graphics.hpp>

#include <BunApplication.hpp>
#include <BunGameObjectManager.hpp>
#include <BunGameObjectTerrain.hpp>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"

int BunApplication::Run([[maybe_unused]] int argc, [[maybe_unused]]char** argv)
{
    const int initializeReturnCode = Initialize();
    if(initializeReturnCode)
    {
        std::cerr << "[Bun] Failed to initialize the application properly. Aborting." << std::endl;
        return initializeReturnCode;
    }

    const int gameLoopReturnCode = GameLoop();
    if(gameLoopReturnCode)
    {
        std::cerr << "[Bun] Failed to run the game loop properly. Aborting." << std::endl;
        return gameLoopReturnCode;
    }

    const int shutdownReturnCode = Shutdown();
    if(shutdownReturnCode)
    {
        std::cerr << "[Bun] Failed to exit the application properly. Aborting." << std::endl;
        return shutdownReturnCode;
    }

    return EXIT_SUCCESS;
}

void BunApplication::AddToWorld(BunGameObject* object)
{
    m_WorldAddCommands.push_back(object);
}

void BunApplication::RemoveFromWorld([[maybe_unused]] BunGameObject* object)
{
    // Not implemented
}

sf::Texture* BunApplication::GetTextureTerrain() const
{
    return m_TextureTerrain;
}

sf::Texture* BunApplication::GetTextureBunny() const
{
    return m_TextureBunny;
}

sf::Font* BunApplication::GetFontDebug() const
{
    return m_FontDebug;
}

uint32_t BunApplication::GetWorldObjectCount() const
{
    return static_cast<uint32_t>(m_World.size());
}

uint32_t BunApplication::GetWorldObjectPendingCount() const
{
    return static_cast<uint32_t>(m_WorldAddCommands.size());
}

uint32_t BunApplication::GetCurrentFrameID() const
{
    return m_CurrentFrameID;
}

uint32_t BunApplication::GetCurrentFramePerSecond() const
{
    return m_CurrentFramePerSecond;
}

float BunApplication::GetCurrentFrameTime() const
{
    return m_CurrentFrameTime;
}

int BunApplication::Initialize()
{
    m_RenderWindow = new sf::RenderWindow(sf::VideoMode(s_WindowWidth, s_WindowHeight), s_WindowName);
    m_RenderWindow->setVerticalSyncEnabled(true);

    m_TextureTerrain = new sf::Texture();
    if(!m_TextureTerrain->loadFromFile(s_TextureGroundPath))
    {
        std::cerr << "[Bun] Failed to load texture from path : " << s_TextureGroundPath << std::endl;
        return EXIT_FAILURE;
    }

    m_TextureBunny = new sf::Texture();
    if(!m_TextureBunny->loadFromFile(s_TextureBunnyPath))
    {
        std::cerr << "[Bun] Failed to load texture from path : " << s_TextureBunnyPath << std::endl;
        return EXIT_FAILURE;
    }

    m_FontDebug = new sf::Font();
    if(!m_FontDebug->loadFromFile(s_FontDebugPath))
    {
        std::cerr << "[Bun] Failed to load font from path : " << s_FontDebugPath << std::endl;
        return EXIT_FAILURE;
    }

    m_CurrentFrameID        = 0;
    m_CurrentFramePerSecond = 0;
    m_CurrentFrameTime      = 0.0f;
    
    AddToWorld(new BunGameObjectManager(*this));
    AddToWorld(new BunGameObjectTerrain(*this));

    return EXIT_SUCCESS;
}

int BunApplication::GameLoop()
{
    if(!m_RenderWindow)
    {
        std::cerr << "[Bun] Failed to enter the game loop with a nullptr window." << std::endl;
        return EXIT_FAILURE;
    }

    uint32_t previousFrameID = m_CurrentFrameID;

    sf::Clock clockFPS;
    sf::Clock clock;
    sf::Time previous = clock.getElapsedTime();
    sf::Time lag;

    // Fixed time step game loop.
    // We will update the game logic 60 times per second.
    // But we will render the game as much as we can to get 
    // smooth motion on 60Hz+ monitors. If the game is slow,
    // The logic update loop will catch up and we will start
    // losing frames to keep a consistent simulation.
    const sf::Time timeStep(sf::seconds(1.f / s_FixedStepCount));
    while (m_RenderWindow->isOpen())
    {
        const sf::Time current = clock.getElapsedTime();
        const sf::Time elapsed = current - previous;
        previous = current;
        lag     += elapsed;

        m_CurrentFrameTime = elapsed.asSeconds();
        while(lag.asMicroseconds() >= timeStep.asMicroseconds())
        {
            ManageObjects();
            HandleInput  ();
            UpdateObjects(timeStep.asSeconds());

            lag -= timeStep;
        }

        Render(timeStep.asSeconds(), lag / timeStep);

        m_CurrentFrameID++;
        if (clockFPS.getElapsedTime() >= sf::seconds(1.f))
        {
            m_CurrentFramePerSecond = m_CurrentFrameID - previousFrameID;
            previousFrameID         = m_CurrentFrameID;

            clockFPS.restart();
        }
    }

    return EXIT_SUCCESS;
}

int BunApplication::Shutdown()
{
    for(BunGameObject* object : m_WorldAddCommands)
    {
        delete object;
    }

    for(BunGameObject* object : m_World)
    {
        delete object;
    }

    m_WorldAddCommands.clear();
    m_World.clear();

    delete m_RenderWindow;
    delete m_TextureTerrain;
    delete m_TextureBunny;
    delete m_FontDebug;

    m_RenderWindow   = nullptr;
    m_TextureTerrain = nullptr;
    m_TextureBunny   = nullptr;
    m_FontDebug      = nullptr;

    return EXIT_SUCCESS;
}

void BunApplication::ManageObjects()
{
    for(BunGameObject* object : m_WorldAddCommands)
    {
        m_World.push_back(object);
    }

    m_WorldAddCommands.clear();
}

void BunApplication::HandleInput()
{
    sf::Event event {};
    while (m_RenderWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_RenderWindow->close();
        }

        for(BunGameObject* object : m_World)
        {
            object->HandleInput(event);
        }
    }
}

void BunApplication::UpdateObjects(float timeStep)
{
    for(BunGameObject* object : m_World)
    {
        object->Update(timeStep);
    }
}

void BunApplication::Render(float timeStep, float interpolation)
{
    m_RenderWindow->clear(sf::Color::Black);

    for(BunGameObject* object : m_World)
    {
        object->Draw(*m_RenderWindow, timeStep, interpolation);
    }

    m_RenderWindow->display();
}

#pragma clang diagnostic pop
