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

}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMorushna* Morushna = Cast<AMorushna>(OtherActor);
	if(Morushna)
	{
		Morushna->SetOverlappingItem(this);
	}
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMorushna* Morushna = Cast<AMorushna>(OtherActor);
if(Morushna)
{
	Morushna->SetOverlappingItem(nullptr);
}
}


void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
