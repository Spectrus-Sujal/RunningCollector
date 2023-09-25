// Fill out your copyright notice in the Description page of Project Settings.


#include "RunningCollectorGameMode.h"
#include <Kismet/GameplayStatics.h>
#include "PlayerCharacter.h"

void ARunningCollectorGameMode::BeginPlay()
{
	Super::BeginPlay();

	CurrentTime = MaxTime;

	UGameplayStatics::SetGamePaused(GetWorld(), true);

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if(PlayerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerCharacterFound"));

		PlayerCharacter->OnGameStateChangedDelegate.AddUniqueDynamic(this,
			&ARunningCollectorGameMode::PauseGame);
	}

}

void ARunningCollectorGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime -= DeltaTime;

	if(CurrentTime <= 0)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		OnGameEndedDelegate.Broadcast();
	}
}

void ARunningCollectorGameMode::PauseGame(bool state)
{
	UGameplayStatics::SetGamePaused(GetWorld(), state);
}
