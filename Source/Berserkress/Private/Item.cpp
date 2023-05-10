// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "DrawDebugHelpers.h"
#include "Berserkress/Berserkress.h"

#define THIRTY 30

// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlayCalled!")); 
	
	UWorld* World = GetWorld();

	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	
	DRAW_SPHERE(Location);
	DRAW_LINE(Location, Location + Forward * 2000.f);
	SetActorLocation(FVector(-620.f, 0, 250.f));	
	SetActorRotation(FRotator(90.f, 45.f, 22.f));

	Location = GetActorLocation();
	Forward = GetActorForwardVector();
	DRAW_SPHERE(Location);
	DRAW_LINE(Location, Location + Forward * 2000.f);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);	

	if (GEngine)
	{
		FString Name = GetName();	 
		FString Message = FString::Printf(TEXT("DeltaTime = %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 25.f, FColor::Cyan, Message);
	}

}
