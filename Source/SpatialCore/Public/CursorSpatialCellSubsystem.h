// Copyright 2023-2026 Jimi Demetriou All Rights Reserved. Jimi Games | jimid.io

#pragma once

#include "CoreMinimal.h"
#include "SpatialCell2D.h"
#include "SpatialCellProvider2D.h"
#include "Subsystems/WorldSubsystem.h"
#include "CursorSpatialCellSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpatialCellChanged, FSpatialCell2D, Cell);

/**
 * 
 */
UCLASS()
class SPATIALCORE_API UCursorSpatialCellSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnSpatialCellChanged OnCellChanged;

	UFUNCTION(BlueprintCallable, Category="Cursor|Spatial")
	void SetSpatialProvider(TScriptInterface<ISpatialCellProvider2D> InProvider)
	{
		SpatialProvider = InProvider;
	}

	// Called by PlayerController when cursor moves
	void UpdateCursorLocation(const FVector& WorldLocation);

private:
	TScriptInterface<ISpatialCellProvider2D> SpatialProvider;
	TOptional<FSpatialCell2D> LastCell;
};
