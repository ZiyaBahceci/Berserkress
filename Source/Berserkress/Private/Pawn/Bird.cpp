// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawn/Bird.h"
#include "Components/CapsuleComponent.h"


ABird::ABird()
{
	PrimaryActorTick.bCanEverTick = true;
Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight((20.f));
	Capsule->SetCapsuleRadius(15.f);
SetRootComponent(Capsule);

}

void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

