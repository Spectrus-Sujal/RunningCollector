// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InputActionValue.h"
#include "RunningCollectorGameMode.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;

UCLASS()
class RUNNINGCOLLECTOR_API ARunningCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* PauseButton;
	
};
