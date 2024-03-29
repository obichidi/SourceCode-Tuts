// Fill out your copyright notice in the Description page of Project Settings.

#include "Collider.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ColliderPawnMovement.generated.h"
#include "GameFramework/MovementComponent.h"
#include "Camera/CameraComponent.h"




// Sets default values
ACollider::ACollider()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->InitSphereRadius(40.f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	
	if(MeshComponentAsset.Succeeded())
	
	{
		MeshComponent->SetStaticMesh(MeshComponentAsset.Object);
		MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
		MeshComponent->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));


	}
	    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	    SpringArm->SetupAttachment(GetRootComponent());
	    SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	    SpringArm->TargetArmLength = 400.f;
	    SpringArm->bEnableCameraLag = true;
	    SpringArm->CameraLagSpeed = 3.0f;



	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	MovementComponent = CreateDefaultSubobject<UColliderPawnMovement>(TEXT("MovementComponent"));
	
     MovementComponent->UpdatedComponent = RootComponent;





	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);

}

void ACollider::MoveForward(float input)
{
	FVector Forward = GetActorForwardVector();
	AddMovementInput(input * Forward);
}
void ACollider::MoveRight(float input)
{
	FVector Right = GetActorRightVector();
	AddMovementInput(input * Right);
}

UPawnMovementComponent* ACollider::GetMovementComponent() const
{
	return MovementComponent;
}