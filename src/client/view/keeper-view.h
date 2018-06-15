#ifndef KEEPERVIEW_H
#define KEEPERVIEW_H

#include "../../shared/model/keeper.h"
#include "../../shared/model/player.h"
#include "abstract-view.h"
#include "ishowable.h"
#include "sprites-provider.h"
#include "camera.h"

class KeeperView : public AbstractView, public IShowable
{
    public:
		KeeperView(Keeper* keeper);
        virtual ~KeeperView();
        void Render(int x_camera, int y_camera, int max_x, int max_y);
        Location* GetLocation();
        static constexpr float FRAMES_PER_EVENT = 0.3;
        static constexpr int RUN_FRAME_COUNT = 4;
        static constexpr int KICKING_FRAME_COUNT = 4;
        static constexpr int RECOVERING_FRAME_COUNT = 7;
    protected:
        void SetAnimation(Animation* animation);
    private:
        Keeper* keeper;
        int frame;
        static constexpr int RUN_ANIMATION_INDEX = 0;
        static constexpr int STILL_ANIMATION_INDEX = 1;
        static constexpr int KICKING_ANIMATION_INDEX = 2;
        static constexpr int RECOVERING_BALL_ANIMATION_INDEX = 3;
        static constexpr int SELECTOR_ANIMATION_INDEX = 4;
        static const int SPRITE_WIDTH = 64;
        static const int SPRITE_HEIGHT = 64;
        static const int SELECTOR_SPRITE_WIDTH = 64;
        static const int SELECTOR_SPRITE_HEIGHT = 64;
        double angle = 0;
        Location* previous_location;
        void GetKeeperAngle();
        SpriteSheet* selector_sheet;
        bool IsStill();
};

#endif // KEEPERVIEW_H
