// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ABHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHpBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//UserWidget은 기본 생성자가 아니라
	//FObjectInitializer를 인자로 받는 생성자를 사용해야함. -> UserWidget으로 넘어가보면 파라미터가 있음.
	UABHpBarWidget(const FObjectInitializer& ObjectInitializer);

	//MaxHp를 설정할 수 있는 함수
	FORCEINLINE void SetMaxHp(float NewMaxHp) { MaxHp = NewMaxHp; }

	//HpBar에 게이지를 설정하기 위한 함수.
	//바인딩하고 구독
	void UpdatHpBar(float NewCurrentHp);

protected:
	//UMG가 초기화될 때 호출되는 함수.
	virtual void NativeConstruct() override;

protected:
	//Hp게이지를 보여주기 위한 프로그레스 바 참조 변수.
	UPROPERTY()
	TObjectPtr<class UProgressBar> HpProgressBar;

	//최대 체력 값.
	UPROPERTY()
	float MaxHp;
};
