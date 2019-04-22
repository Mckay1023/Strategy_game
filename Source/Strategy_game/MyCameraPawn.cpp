// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCameraPawn.h"
#include "Strategy_game.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"



// Sets default values
AMyCameraPawn::AMyCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Create Mesh
	MyCameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CameraMesh"));
	MyCameraMesh->SetupAttachment(RootComponent);
	MyCameraMesh->SetRelativeRotation(FRotator(0.0f,-70.0f,0.0f));
	//Create and initialize the SpringArm Component
	MyCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	MyCameraSpringArm->SetupAttachment(MyCameraMesh);
	//Sets the location of the component and the angle of the MyCameraSpringArm
	MyCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(0.0f, 0.0f, 0.0f));
	MyCameraSpringArm->TargetArmLength = 1500.f;
	MyCameraSpringArm->bEnableCameraLag = true;
	MyCameraSpringArm->CameraLagSpeed = 3.0f;

	//Create Camera Component
	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	MyCamera->SetupAttachment(MyCameraSpringArm, USpringArmComponent::SocketName);

	//Takes control of the default Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}



