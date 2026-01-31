// Copyright 2023-2026 Jimi Demetriou All Rights Reserved. Jimi Games | jimid.io


#include "CursorSpatialCellSubsystem.h"

void UCursorSpatialCellSubsystem::UpdateCursorLocation(const FVector& WorldLocation)
{
	if (!SpatialProvider)
		return;

	FSpatialCell2D Cell;
	if (SpatialProvider->WorldToSpatialCell(WorldLocation, Cell))
	{
		if (!LastCell.IsSet() || LastCell.GetValue() != Cell)
		{
			LastCell = Cell;
			OnCellChanged.Broadcast(Cell);
		}
	}
}
