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
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
	{
		Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	AMorushna* Morushna = Cast<AMorushna>(OtherActor);
		if(Morushna)
		{
			FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
			ItemMesh->AttachToComponent(Morushna->GetMesh(), TransformRules, FName("Hand_RSocket"));
		}
	}
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
	{
		Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	}
};

