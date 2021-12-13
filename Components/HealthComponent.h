// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class AToonTanksGameModeBase;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()


private:

	UPROPERTY(EditAnywhere)
	float defaultHealth = 100.f;
	float Health = 0.f;

	AToonTanksGameModeBase* GameModeRef;

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor,
		            float Damage,
		            const class UDamageType* DamageType,
		            class AController* InstigatedBy,
		            AActor* DamageCauser);
		
};
