// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

void ARifle::PullTrigger() 
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("Muzzle"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("Muzzle"));

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return;
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) return;

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	FVector End = Location + Rotation.Vector() * MaxRange;
	FHitResult Hit;

	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECC_GameTraceChannel1);
	if (bSuccess) {
		FVector ShotDirection = -Rotation.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
	}
}


// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

