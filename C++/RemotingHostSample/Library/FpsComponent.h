#pragma once

#include "DrawableGameComponent.h"

namespace DirectX
{
    class SpriteBatch;
    class SpriteFont;
}

namespace Library
{
    class FpsComponent : public DrawableGameComponent
    {
        RTTI_DECLARATIONS(FpsComponent, DrawableGameComponent)

    public:
        FpsComponent(Game& game);

		FpsComponent() = delete;
		FpsComponent(const FpsComponent& rhs) = delete;
		FpsComponent& operator=(const FpsComponent& rhs) = delete;

        XMFLOAT2& TextPosition();
        int FrameRate() const;

        virtual void Initialize() override;
        virtual void Update(const GameTime& gameTime) override;
        virtual void Draw(const GameTime& gameTime) override;

    private:        
     //   std::unique_ptr<SpriteBatch> mSpriteBatch;
	//	std::unique_ptr<SpriteFont> mSpriteFont;
        XMFLOAT2 mTextPosition;

        int mFrameCount;
        int mFrameRate;
        double mLastTotalElapsedTime;
    };
}