// Copyright©2021 vAhirwar Technology.All rights reserved.


#include "vPlayerController.h"


void AvPlayerController::SetPlayerEnabledState(bool SetPlayerEnabled) 
{

    if(SetPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
    }else
    {
        GetPawn()->DisableInput(this);
    };
    bShowMouseCursor =SetPlayerEnabled;
       

};

