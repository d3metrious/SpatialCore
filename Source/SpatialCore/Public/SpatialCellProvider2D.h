#pragma once
#include "UObject/Interface.h"
#include "SpatialCell2D.h"
#include "SpatialCellProvider2D.generated.h"

UINTERFACE(Blueprintable)
class SPATIALCORE_API USpatialCellProvider2D : public UInterface
{
	GENERATED_BODY()
};

class SPATIALCORE_API ISpatialCellProvider2D
{
	GENERATED_BODY()

public:
	virtual bool WorldToSpatialCell(
		const FVector& WorldLocation,
		FSpatialCell2D& OutCell) const = 0;
};
