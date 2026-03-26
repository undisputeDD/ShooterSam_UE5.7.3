// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterSamGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "ShooterSamCharacter.h"
#include "ShooterAI.h"

void AShooterSamGameMode::BeginPlay()
{
	Super::BeginPlay();

	AShooterSamCharacter* Player = Cast<AShooterSamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	TArray<AActor*> Enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), Enemies);
	for (int i = 0; i < Enemies.Num(); ++i)
	{
		AShooterAI* Enemy = Cast<AShooterAI>(Enemies[i]);
		if (Enemy)
		{
			Enemy->StartBehaviorTree(Player);
		}
	}
}

AShooterSamGameMode::AShooterSamGameMode()
{
	// stub
}
