// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	void PauseGame(bool state);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxTime = 5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CurrentTime = 60;


	// Delegate signature
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameEndedSignature);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FOnGameEndedSignature OnGameEndedDelegate;
	
};
