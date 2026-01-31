# SpatialCore

**SpatialCore** is a lightweight Unreal Engine plugin that provides a **generic spatial abstraction layer** for cursor-driven gameplay systems.

It decouples *where the cursor is in the world* from *how that position is interpreted*, allowing projects and plugins to optionally resolve cursor positions into logical 2D “cells” (grids, tiles, etc.) **without hard dependencies**.

---

## Why SpatialCore Exists

Many gameplay systems need to answer:

> *“What logical space is the cursor currently over?”*

Examples:
- RTS selection & placement
- City-builder hover logic
- Tactical overlays
- UI context actions

Traditionally, this logic gets:
- Re-implemented per project, or
- Hard-wired into a grid or RTS system

SpatialCore solves this once, in a **project-agnostic** way.

---

## Core Concepts

### Cursor Provider
Any system that can provide a **cursor world position**  
(e.g. PlayerController, camera pawn, input system).

### Spatial Cell Provider
An optional system that can convert a world position into a **logical 2D cell**.

- Grid systems
- Tile maps
- Custom spatial layouts

Implemented via an interface:
```
ISpatialCellProvider2D
```

### Cursor Spatial Cell Subsystem
A **client-side World Subsystem** that:
- Receives cursor world locations
- Optionally resolves them via a spatial provider
- Emits `OnCellChanged` when the resolved cell changes

---

## What SpatialCore Does

- Tracks cursor world position (client-side)
- Optionally resolves that position into a logical cell
- Broadcasts cell changes via delegates
- Provides a stable API usable across multiple projects
- Works in C++ and Blueprints

---

## What SpatialCore Does *Not* Do

- Does **not** implement a grid
- Does **not** assume RTS gameplay
- Does **not** require a spatial provider to function
- Does **not** perform server-side gameplay logic

SpatialCore is intentionally minimal.

---

## Typical Integration Flow

1. PlayerController updates cursor world position
2. `UCursorSpatialCellSubsystem` receives the update
3. If a spatial provider is set:
   - World position → logical cell
4. If the cell changes:
   - `OnCellChanged` is broadcast
5. Gameplay / UI systems react

All steps are optional.

---

## Optional Grid Integration

SpatialCore does **not** depend on any grid plugin.

Grid systems (e.g. `WorldGrid`) may:
- Implement `ISpatialCellProvider2D`
- Register themselves with the subsystem at runtime

This keeps both plugins reusable and independent.

---

## Multiplayer Notes

- Designed for **client-only** spatial intent
- Safe for multiplayer projects
- Server logic should consume results explicitly if needed

---

## Intended Use Cases

- RTS & city-builder cursor interaction
- Placement previews
- Selection highlighting
- UI hover logic
- Shared spatial behavior across multiple games

---

## Design Goals

- No hard dependencies
- No gameplay assumptions
- Minimal surface area
- Long-term reuse across projects
