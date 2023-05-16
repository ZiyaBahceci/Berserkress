// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "Characters/Morushna.h"

#define THIRTY 30



// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AItem::BeginPlay()
{

	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
	/*
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
	*/
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
const FString OtherActorName = OtherActor->GetName();	
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
	}
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = FString("Ending overlap w/ : " + OtherActor->GetName());	
AMorushna* MorushnaCharacter = Cast<AMorushna>;(OtherActor);	

}



void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	//UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);	

//	SetActorRotation(GetActorRotation() + FRotator(0, 1, 0));
/*	
	if (GEngine)
	{
		FString Name = GetName();	 
		FString Message = FString::Printf(TEXT("DeltaTime = %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 25.f, FColor::Cyan, Message);
	}
*/	
	
}
