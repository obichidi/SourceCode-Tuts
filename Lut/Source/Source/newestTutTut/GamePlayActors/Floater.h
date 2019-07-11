// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class NEWESTTUTTUT_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;

	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
		FVector InitialLocation;


	UPROPERTY( VisibleInstanceOnly,BlueprintReadWrite, Category ="Floater Variables ")
	FVector PlacedLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Floater Variables" )
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
		bool bShouldFloat;


	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Floater Variables")
		FVector WorldOrgin;

	UPROPERTY(BlueprintReadWrite,EditInstanceOnly, Category = "Floater Variables")
	FVector InitialForce;
	 
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Floater Variables")
	FVector InitialTorque;

	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Floater Variables")
	bool bInitializeFloaterLocation;

private:
	float RunningTime;

	
	UPROPERTY(EditAnywhere, Category = "FloaterVariables  |   Wave Parameters")
	float Amplitude;
	UPROPERTY(EditAnywhere, Category = "FloaterVariables  |   Wave Parameters")
	float TimeStretch;
	
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
