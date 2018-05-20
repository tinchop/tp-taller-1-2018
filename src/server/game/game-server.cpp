#include "game-server.h"

#include "../../shared/logger.h"


GameServer::GameServer(Configuration* initial_configuration)
{
    this->game_state = new GameState(initial_configuration);
    this->session_manager = new SessionManager(initial_configuration->GetCredentials(), initial_configuration->GetMaxPlayers());
}

GameServer::~GameServer()
{
    delete this->game_state;
    delete this->session_manager;
}

GameState* GameServer::GetGameState()
{
    return this->game_state;
}

void GameServer::DoLogin(ClientSocket* client, LoginRequest* login_request)
{
    User* authenticated_user = this->session_manager->Authenticate(client, login_request);
}

void GameServer::DoQuit(QuitRequest* quit_request)
{
    this->session_manager->RemoveSession(quit_request->GetUsername());
}
