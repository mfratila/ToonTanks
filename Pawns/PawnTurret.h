// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/Pawns/PawnBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "PawnTurret.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()


public:

	APawnTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction() override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	APawnTank* PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float fireRange = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float fireRate = 2.f;

	FTimerHandle FireRateTimerHandle;

	void CheckFireCondition();

	float ReturnDistanceToPlayer();
};
