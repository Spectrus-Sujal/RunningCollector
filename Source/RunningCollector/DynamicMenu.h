// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DynamicMenu.generated.h"

/**
 * 
 */

UCLASS()
class RUNNINGCOLLECTOR_API UDynamicMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayPauseGame(bool paused);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ShowEndScreen();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ChangeMenuState();

};

