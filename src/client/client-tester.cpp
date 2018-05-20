#include "client-tester.h"

#include <iostream>

ClientTester::ClientTester(Configuration* config)
{
    this->client = new Client(config);
}

ClientTester::~ClientTester()
{
    delete this->client;
}

void ClientTester::TestCompleteFlow()
{
    client->Init("127.0.0.1");

    string username;
    cout << "ingrese username: ";
    getline(cin, username);

    LoginRequest* login_request = new LoginRequest();
    login_request->SetUsername(username);
    login_request->SetPassword("1234");
    login_request->SetTeam("team_a");
    login_request->SetServerIp("127.0.0.1");
    client->LogIn(login_request);

//    for (int i = 0; i < 10; i++)
//    {
//        int seconds = rand() % 5;
//        sleep(seconds);
//        this->client->SendEvent();
//    }

    cin.get();

    QuitRequest* quit_request = new QuitRequest("gperez");
    client->Quit(quit_request);


    cin.get();
    client->Close();

    delete login_request;
    delete quit_request;
}
