// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseItem/ACT_Item.h"
#include "ACT_ComboClip.h"
#include "ACT_ComboTree.generated.h"

/**
 *
 */
UCLASS()
class ACT_API UACT_ComboTree : public UACT_Item
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UACT_ComboClip* FirstComboClip;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName ComboName = FName("");
};
