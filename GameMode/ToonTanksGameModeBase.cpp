// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"


AToonTanksGameModeBase::AToonTanksGameModeBase()
{

}
void AToonTanksGameModeBase::BeginPlay()
{
	Super::BeginPlay();


	HandleGameStart();

}

int32 AToonTanksGameModeBase::GetTargetTurretCount()
{
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
	return TurretActors.Num();
}

void AToonTanksGameModeBase::HandleGameStart()
{
	TargetTurrets = GetTargetTurretCount();

	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GameStart();
}

void AToonTanksGameModeBase::HandleGameOver(bool bPlayerWon)
{
	// See if the player has destroyed all the turrets, show win result.
	GameOver(bPlayerWon);
	// else if turret destroyed player, show lose result.
	
	// Call blueprint version GameOver(bool).

}

void AToonTanksGameModeBase::ActorDied(AActor* DeadActor)
{
	if(DeadActor == PlayerTank)
	{
		PlayerTank->HandleDestruction();
		HandleGameOver(false);
	}
	else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
		if (--TargetTurrets == 0)
		{
			HandleGameOver(true);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("A Pawn Died !"));
	// check what type of Actor died. If Turret, tally, If Player -> go to lose condition
}
