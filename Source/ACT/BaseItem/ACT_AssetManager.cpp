// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_AssetManager.h"

const FPrimaryAssetType UACT_AssetManager::SkillType = TEXT("SkillType");
const FPrimaryAssetType UACT_AssetManager::MotionType = TEXT("MotionType");
const FPrimaryAssetType UACT_AssetManager::ComboType = TEXT("ComboType");
const FPrimaryAssetType UACT_AssetManager::ComboClipType = TEXT("ComboClipType");

UACT_AssetManager& UACT_AssetManager::Get()
{
	// TODO: 在此处插入 return 语句
	UACT_AssetManager* Singleton = Cast<UACT_AssetManager>(GEngine->AssetManager);

	if (Singleton) {
		return *Singleton;
	}
	else {
		//UE_LOG(LogAssetManager, Fatal, TEXT("Cannot use AssetManager if no AssetManagerClassName is defined!"));
		return *NewObject<UACT_AssetManager>();
	}
}
