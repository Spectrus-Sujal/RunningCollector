// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RunningCollectorGameMode.h"

using UEILPS = UEnhancedInputLocalPlayerSubsystem;
using UEIC = UEnhancedInputComponent;

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetSimulatePhysics(true);
	RootComponent = PlayerMesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(PlayerMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	const APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if(PlayerController)
	{
		const ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		UEILPS* SubSystem = ULocalPlayer::GetSubsystem<UEILPS>(LocalPlayer);

		if(SubSystem)
		{
			SubSystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEIC* EnhancedInputComponent = CastChecked<UEIC>(PlayerInputComponent);

	if(EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveActionLeftRight, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveRightLeft);
		EnhancedInputComponent->BindAction(MoveActionFrontBack, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveFrontBack);
		EnhancedInputComponent->BindAction(PlayPause, ETriggerEvent::Triggered, this, &APlayerCharacter::PauseGame);
	}

}

void APlayerCharacter::MoveRightLeft(const FInputActionValue& Value)
{
	const float MovementAxis = Value.Get<float>();

	if(!GamePaused)
	{
		const FVector PlayerForce = PlayerMesh->GetRightVector() * (MovementAxis * SideSpeed);
		PlayerMesh->AddForce(PlayerForce, NAME_None, true);
	}
}

void APlayerCharacter::MoveFrontBack(const FInputActionValue& Value)
{
	const float MovementAxis = Value.Get<float>();

	if(!GamePaused)
	{
		const FVector PlayerForce = PlayerMesh->GetForwardVector() * (MovementAxis * ForwardSpeed);
		PlayerMesh->AddForce(PlayerForce, NAME_None, true);
	}
}

void APlayerCharacter::PauseGame(const FInputActionValue& Value)
{
	GamePaused = !GamePaused;

	OnGameStateChangedDelegate.Broadcast(GamePaused);
}

void APlayerCharacter::UnPauseGame()
{
	GamePaused = false;

	OnGameStateChangedDelegate.Broadcast(GamePaused);
}

