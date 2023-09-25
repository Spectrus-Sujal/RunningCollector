// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicMenu.h"
#include "PlayerCharacter.h"
#include <Kismet/GameplayStatics.h>
#include "RunningCollectorGameMode.h"

void UDynamicMenu::NativeConstruct()
{
	Super::NativeConstruct();

	APlayerCharacter* Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if(Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerCharacterFound Menu"));
		Player->OnGameStateChangedDelegate.AddUniqueDynamic(this,
			&UDynamicMenu::PlayPauseGame);
	}

	ARunningCollectorGameMode* GameMode = Cast<ARunningCollectorGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if(GameMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game mode Found"));
		GameMode->OnGameEndedDelegate.AddUniqueDynamic(this,
			&UDynamicMenu::ShowEndScreen);
	}

}
