// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	UPROPERTY(EditAnywhere)
		float PlatformSpeed = 10.f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget))
		FVector TargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int32 ActiveTriggers = 1;
};


