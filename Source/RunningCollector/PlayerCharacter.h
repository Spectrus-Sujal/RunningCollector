// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

// Forward Declares
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class RUNNINGCOLLECTOR_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected: 

	// ENHANCED INPUT SYSTEM
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveActionLeftRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveActionFrontBack;

	void MoveRightLeft(const FInputActionValue& Value);

	void MoveFrontBack(const FInputActionValue& Value);

	// ASSET COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Setup)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Setup)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Setup)
	UCameraComponent* Camera;

	// MOVEMENT VARIABLES
	UPROPERTY(EditAnywhere, Category = "Movement")
	float ForwardSpeed = 1800.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float SideSpeed = 1800.0f;

	bool gamePaused = false;

};
