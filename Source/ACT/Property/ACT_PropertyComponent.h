// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../ACT_Type.h"
#include "ACT_PropertyComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class ACT_API UACT_PropertyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UACT_PropertyComponent();

	// define property of this component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	TMap<EACT_PropertyName, FACT_PropertyValue> Properties;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	FORCEINLINE FACT_PropertyValue &GetPropertyStructWithName(EACT_PropertyName Name) { return *Properties.Find(Name); }

	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetPropertyValueWithName(EACT_PropertyName Name) { return Properties.Find(Name)->Current; }

	// a interface for cpp programming to modify property value
	UFUNCTION()
	virtual void UpdatePropertyUI(EACT_PropertyName Name);

	// set property value in blueprint
	UFUNCTION(BlueprintImplementableEvent)
	void BP_UpdatePropertyUI(EACT_PropertyName Name);

	// Modify value
	UFUNCTION(BlueprintCallable)
	bool SetPropertyValue(EACT_PropertyName Name, float NewValue, bool bUpdateUI);

	// Modify value based on previous value. By: value change, can be negative
	UFUNCTION(BlueprintCallable)
	bool ModifyPropertyValue(EACT_PropertyName Name, float By, bool bUpdateUI);
};
