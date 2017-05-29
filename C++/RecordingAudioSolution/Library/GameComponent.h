#pragma once

#include "Common.h"

namespace MatMeshModLibrary
{
    class Game;
    class GameTime;

    class GameComponent : public RTTI
    {
        RTTI_DECLARATIONS(GameComponent, RTTI)

    public:
        GameComponent();
        GameComponent(Game& game);
        virtual ~GameComponent();

		GameComponent(const GameComponent& rhs) = delete;
		GameComponent& operator=(const GameComponent& rhs) = delete;

        Game* GetGame();
        void SetGame(Game& game);
        bool Enabled() const;
        void SetEnabled(bool enabled);

        virtual void Initialize();
        virtual void Update(const GameTime& gameTime);

    protected:
        Game* mGame;
        bool mEnabled;
    };
}
