// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <GameData/ABCharacterStat.h>
#include "ABCharacterStatWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABCharacterStatWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	//데이터가 업뎃되면 바인딩(Delegate 등록용)
	void UpdateStat(
		const FABCharacterStat& InBaseStat,
		const FABCharacterStat& InModifierStat);

private:
	//스탯 위젯이 가진 UI항목 중에서 Base스탯에 해당하는 텍스트 블록 모음
	UPROPERTY()
	TMap<FName, class UTextBlock*> BaseLookup;

	//스탯 위젯이 가진 UI항목 중에서 Modifier스탯에 해당하는 텍스트 블록 모음
	UPROPERTY()
	TMap<FName, class UTextBlock*> ModifierLookup;
};
