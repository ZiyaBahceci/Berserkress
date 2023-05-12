// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawn/Bird.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

ABird::ABird()
{
	PrimaryActorTick.bCanEverTick = true;
Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight((20.f));
	Capsule->SetCapsuleRadius(15.f);
SetRootComponent(Capsule);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(GetRootComponent());

	AutoPossessPlayer = EAutoReceiveInput::Player0;		
}

void ABird::BeginPlay()
{
	Super::BeginPlay();

	/*
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if(PlayerController)
	{
	UEnhancedInputLocalPlayerSubsystem*  Subsystem =ULocalPlayer::GetSubsystem<	UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if(Subsystem)
		{
				
		}
	}
	*/

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(BirdMappingContext, 0);
		}
	}
}

void ABird::Move(const FInputActionValue& Value)
{
	const bool CurrentValue = Value.Get<bool>();
	if(CurrentValue)
	{
		UE_LOG(LogTemp, Warning, TEXT("IA_Move triggered"));
	}
}


void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}	

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABird::Move);
	}
}

