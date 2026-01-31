#pragma once
#include "CoreMinimal.h"
#include "SpatialCell2D.generated.h"

USTRUCT(BlueprintType)
struct SPATIALCORE_API FSpatialCell2D
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int32 X = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 Y = 0;

	FSpatialCell2D() = default;
	FSpatialCell2D(int32 InX, int32 InY) : X(InX), Y(InY) {}

	FORCEINLINE bool operator==(const FSpatialCell2D& Other) const
	{
		return X == Other.X && Y == Other.Y;
	}

	FORCEINLINE bool operator!=(const FSpatialCell2D& Other) const
	{
		return !(*this == Other);
	}
};
