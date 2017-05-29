#pragma once

#include "GameComponent.h"

namespace MatMeshModLibrary
{
    class Camera;

    class DrawableGameComponent : public GameComponent
    {
        RTTI_DECLARATIONS(DrawableGameComponent, GameComponent)

    public:
        DrawableGameComponent();
        DrawableGameComponent(Game& game);
        DrawableGameComponent(Game& game, Camera& camera);
        virtual ~DrawableGameComponent();

		DrawableGameComponent(const DrawableGameComponent& rhs) = delete;
		DrawableGameComponent& operator=(const DrawableGameComponent& rhs) = delete;

        bool Visible() const;
        void SetVisible(bool visible);

        Camera* GetCamera();
        void SetCamera(Camera* camera);

        virtual void Draw(const GameTime& gameTime);

    protected:
        bool mVisible;
        Camera* mCamera;
    };
}