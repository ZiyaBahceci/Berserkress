// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Characters/Morushna.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class BERSERKRESS_API AWeapon : public AItem
{
	GENERATED_BODY()

protected:
	
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) override;

	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

public:
	void EquipWeapon(USceneComponent* InParent, FName InSocketName);
};

