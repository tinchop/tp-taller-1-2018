#ifndef PLAYERRECOVERBALLSTATE_H
#define PLAYERRECOVERBALLSTATE_H

#include "../../client/view/player-view.h"
#include "iplayer-state.h"
#include "../player.h"

class Player;
class PlayerRecoverBallState : public IPlayerState
{
    public:
        PlayerRecoverBallState(Player* player);
        virtual ~PlayerRecoverBallState();
        void MoveLeft(bool run);
        void MoveRight(bool run);
        void MoveUp(bool run);
        void MoveDown(bool run);
        void MoveUpToRight(bool run);
        void MoveUpToLeft(bool run);
        void MoveDownToRight(bool run);
        void MoveDownToLeft(bool run);
        void Kick();
        void RecoverBall();
        void PassBall();
        void CatchBall();
        void Play();
        bool IsKicking(){ return false; }
        bool IsRecoveringBall() { return true; }
    protected:
        Player* player;
    private:
        u_int timming;
        bool ContinueRecovering();
        u_int frames_per_event;
        u_int frames_count;
};

#endif // PLAYERRECOVERBALLSTATE_H
