// Copyright (C) Gaslight Games Ltd, 2019-2020


// EOS Basic Includes
#include "BasicPlayerController.h"

// Engine Includes
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineIdentityInterface.h"

// EOS Plugin Includes
#include "eos_auth.h"
#include "OnlineSubsystemEOS.h"


bool ABasicPlayerController::RequestLogin(FString Id, FString Token, FString Type )
{
	IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get( EOS_SUBSYSTEM );

	if( SubSystem != nullptr )
	{
		IOnlineIdentityPtr OnlineIdentity = SubSystem->GetIdentityInterface();

		if( OnlineIdentity != nullptr )
		{
			FOnlineAccountCredentials Credentials( Type, Id, Token );
			return OnlineIdentity->Login( 0, Credentials );
		}
	}

	return false;
}

bool ABasicPlayerController::RequestLogout()
{
	IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get( EOS_SUBSYSTEM );

	if( SubSystem != nullptr )
	{
		IOnlineIdentityPtr OnlineIdentity = SubSystem->GetIdentityInterface();

		if( OnlineIdentity != nullptr )
		{
			// Assume we are logging out local user num 0
			return OnlineIdentity->Logout(0);
		}
	}
	return false;
}


