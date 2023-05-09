// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item_A.h"

// Sets default values
AItem_A::AItem_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

