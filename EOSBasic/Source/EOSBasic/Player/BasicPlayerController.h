// Copyright (C) Gaslight Games Ltd, 2019-2020

#pragma once

#include "CoreMinimal.h"
#include "eos_auth_types.h"
#include "eos_connect_types.h"
#include "GameFramework/PlayerController.h"
#include "BasicPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class EOSBASIC_API ABasicPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UFUNCTION( BlueprintCallable, Category = "EOS Basic")
	bool RequestLogin( FString Id, FString Token, FString Type );

	UFUNCTION( BlueprintCallable, Category = "EOS Basic")
	static bool RequestLogout( );

};
