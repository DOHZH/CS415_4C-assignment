// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ACT_Item.generated.h"

/**
 * 
 */
UCLASS(Abstract) //forbid instantiating
class ACT_API UACT_Item : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
	FPrimaryAssetType ItemType;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
