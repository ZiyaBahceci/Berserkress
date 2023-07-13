// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MorushnaAnimInstance.generated.h"

/**
 * UNUSED
 */
UCLASS()
class BERSERKRESS_API UMorushnaAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override; 

	UPROPERTY(BlueprintReadOnly)
	class AMorushna* Morushna;

	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* MorushnaMovement;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool IsFalling;
	
};
