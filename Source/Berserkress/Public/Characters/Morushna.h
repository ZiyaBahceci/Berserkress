// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Morushna.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class AItem;

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedTwoHanded UMETA(DisplayName = "Equipped Two Handed Weapon"),
	ECS_EquippedOneHanded UMETA(DisplayName = "Equipped One Handed Weapon")
};

UCLASS()
class BERSERKRESS_API AMorushna : public ACharacter
{
	GENERATED_BODY()

public:
	AMorushna();
	void Equip();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE void SetOverlappingItem(AItem* Item)
	{
		OverlappingItem	 = Item;
	}
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputMappingContext* MorushnaContext;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* MovementAction;	

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction*  LookAction;	

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction*  JumpAction;	

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction*  AttackAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction*  DodgeAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction*  EquipAction;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:
ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent*  CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly);
	AItem* OverlappingItem;

};
