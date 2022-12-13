// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_Item.h"

FPrimaryAssetId UACT_Item::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemType, GetFName());
}
