// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(blueprintable)
class NEWESTTUTTUT_API UMyObject : public UObject
{
	GENERATED_BODY()



public:

		UMyObject();

	UPROPERTY(BlueprintReadWrite, category = "MyVariables")
    float MyFloat;
	
	UFUNCTION(BlueprintCallable, category = "MyFunction")
	void MyFunction();
	
};
