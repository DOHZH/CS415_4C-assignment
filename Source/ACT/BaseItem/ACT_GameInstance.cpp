// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_GameInstance.h"
#include "ACT_AssetManager.h"

void UACT_GameInstance::Init()
{
	Super::Init();
	AutoLoadDataAssets();
}

void UACT_GameInstance::AutoLoadDataAssets()
{
	UACT_AssetManager& Manager = UACT_AssetManager::Get();
	for (auto& Type : AutoLoadTypes) {
		FPrimaryAssetType CurrentType = Type;
		TArray<FPrimaryAssetId> AssetIds;
		if (Manager.GetPrimaryAssetIdList(CurrentType, AssetIds)) {
			Manager.LoadPrimaryAssets(AssetIds, TArray<FName>(), FStreamableDelegate(), 0);//last para is priority, the bigger num presents lower priority
		}
	}

}
