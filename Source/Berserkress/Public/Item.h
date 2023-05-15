// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"


class USphereComponent;

UCLASS()
class BERSERKRESS_API AItem : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		float RunningTime;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
	
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)

	float TestFloat = 29.f;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
