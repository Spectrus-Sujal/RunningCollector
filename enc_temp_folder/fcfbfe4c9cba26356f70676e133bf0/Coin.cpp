// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "PlayerCharacter.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	CoinMesh->SetGenerateOverlapEvents(true);
	RootComponent = CoinMesh;
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();

	if (CoinMesh)
	{
		CoinMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnBeginOverlap);
		
		UE_LOG(LogTemp, Warning, TEXT("%b"), CoinMesh->OnComponentBeginOverlap.IsBound());
	}
}

void ACoin::OnBeginOverlap(UPrimitiveComponent* hitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
						   int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Done Overlap"));
	APlayerCharacter* player = Cast<APlayerCharacter>(OtherActor);

	if(player) 
	{
		player->Score += ScoreValue;

		Destroy();
	}
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
