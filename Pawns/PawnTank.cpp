// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"


APawnTank::APawnTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APawnTank::Fire);

	PlayerInputComponent->BindAxis("MoveForward", this,&APawnTank::CalculateMoveInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);

}

void APawnTank::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());

	if (PlayerControllerRef)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Ref Found!"));
	}
}

// called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate();
	Move();

	if (PlayerControllerRef)
	{
		
		FHitResult TraceHitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);
		FVector HitLocation = TraceHitResult.ImpactPoint;

		RotateTurret(HitLocation);

	}
}

void APawnTank::CalculateMoveInput(float Val)
{
	MoveDirection = FVector(Val * moveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalculateRotateInput(float Val)
{
	float RotateAmount = Val * rotateSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0.f, RotateAmount, 0.f);
	RotationDirection = FQuat(Rotation);

}

void APawnTank::Move()
{
	AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate()
{
	AddActorLocalRotation(RotationDirection, true);
}

void APawnTank::HandleDestruction()
{
	Super::HandleDestruction();

}