// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "ACT_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class ACT_API UACT_AssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static const FPrimaryAssetType SkillType;
	static const FPrimaryAssetType MotionType;
	static const FPrimaryAssetType ComboType;
	static const FPrimaryAssetType ComboClipType;
	static UACT_AssetManager& Get();


};
