// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ABItemData.h"
#include "ABWeaponItemData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABWeaponItemData : public UABItemData
{
	GENERATED_BODY()
	
public:
	//무기 매시 설정 가능하도록
	UPROPERTY(EditAnyWhere, Category = Weapon)
	//TObjectPtr<class USkeletalMesh> WeaponMesh;
	TSoftObjectPtr<class USkeletalMesh> WeaponMesh;
};
