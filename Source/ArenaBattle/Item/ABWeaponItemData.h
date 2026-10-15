// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ABItemData.h"
#include <GameData/ABCharacterStat.h>
#include "ABWeaponItemData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABWeaponItemData : public UABItemData
{
	GENERATED_BODY()

public:
	UABWeaponItemData();
	
public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("ABItemData", GetFName());
	}

	//무기 매시 설정 가능하도록
	UPROPERTY(EditAnyWhere, Category = Weapon)
	//TObjectPtr<class USkeletalMesh> WeaponMesh;
	TSoftObjectPtr<class USkeletalMesh> WeaponMesh;

	//무기 아이템이 제공할 부가 스탯 데이터.
	UPROPERTY(EditAnyWhere, Category = Stat)
	FABCharacterStat ModifierStat;
};
