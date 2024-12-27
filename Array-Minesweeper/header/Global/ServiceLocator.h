#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Time/TimeService.h"

namespace Global
{
    using namespace Sound;
    using namespace Event;
    using namespace Time;

    class ServiceLocator
    {
    private:
        EventService* event_service;
        Graphics::GraphicService* graphic_service;
        SoundService* sound_service;
        UI::UIService* ui_service;
        Gameplay::GameplayService* gameplay_service;
        TimeService* time_service;
        Gameplay::Board::BoardService* board_service;


        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        SoundService* getSoundService();
        UI::UIService* getUIService();
        Gameplay::Board::BoardService* getBoardService();
        Gameplay::GameplayService* getGameplayService();
        TimeService* getTimeService();
        void deleteServiceLocator();
    };
}