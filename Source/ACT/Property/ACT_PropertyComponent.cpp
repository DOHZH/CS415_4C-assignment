// Fill out your copyright notice in the Description page of Project Settings.

#include "ACT_PropertyComponent.h"

// Sets default values for this component's properties
UACT_PropertyComponent::UACT_PropertyComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}

// Called when the game starts
void UACT_PropertyComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...
}

// Called every frame
void UACT_PropertyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    // ...
}

void UACT_PropertyComponent::UpdatePropertyUI(EACT_PropertyName Name)
{
    BP_UpdatePropertyUI(Name);
}

bool UACT_PropertyComponent::SetPropertyValue(EACT_PropertyName Name, float NewValue, bool bUpdateUI)
{
    if (Properties.Contains(Name))
    {
        FACT_PropertyValue CurrentValue = GetPropertyStructWithName(Name);
        CurrentValue.Current = FMath::Clamp(NewValue, CurrentValue.Min, CurrentValue.Max); // make the new value between min and max
        Properties.Add(Name, CurrentValue);                                                // because Name in map is uniqueness, so if you use Add with the name which has already existed, you will update Name
        if (bUpdateUI)
            UpdatePropertyUI(Name);
    }
    return false;
}

bool UACT_PropertyComponent::ModifyPropertyValue(EACT_PropertyName Name, float By, bool bUpdateUI)
{
    if (By != 0)
    {
        float OldValue = GetPropertyValueWithName(Name);
        return SetPropertyValue(Name, OldValue + By, bUpdateUI);
    }
    return true;
}
