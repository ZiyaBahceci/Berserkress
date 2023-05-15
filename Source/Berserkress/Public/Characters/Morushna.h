// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Morushna.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class BERSERKRESS_API AMorushna : public ACharacter
{
	GENERATED_BODY()

public:
	AMorushna();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;



protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputMappingContext* MorushnaContext;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* MovementAction;	

	void Move(const FInputActionValue& Value);
};
