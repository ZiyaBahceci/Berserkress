// Fill out your copyright notice in the Description page of Project Settings.

//UNUSED CLASS
#include "Characters/MorushnaAnimInstance.h"
#include "Characters/Morushna.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UMorushnaAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Morushna = Cast<AMorushna>(TryGetPawnOwner());
if (Morushna)
{
	MorushnaMovement = Morushna->GetCharacterMovement();
} 

}

void UMorushnaAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if(MorushnaMovement)
	{   
		GroundSpeed = UKismetMathLibrary::VSizeXY(MorushnaMovement->Velocity);
		IsFalling = MorushnaMovement->IsFalling();
	}
}
