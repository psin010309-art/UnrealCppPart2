// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHpBarWidget.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>
#include <Inteface/ABCharacterWidgetInterface.h>

UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	//최대 체력은 외부에서 설정이 되어야 함.
	//따라서 초기값은 오류의 의미를 가진 음수로 설정.
	MaxHp = -1.0f;
}

void UABHpBarWidget::UpdateStat(const FABCharacterStat& InBaseStat, const FABCharacterStat& InModifierStat)
{
	//최대 체력
	MaxHp = (InBaseStat + InModifierStat).MaxHp;

	//프로그래스바 설정.
	if (nullptr != HpProgressBar)
	{
		HpProgressBar->SetPercent(CurrentHp / MaxHp);
	}

	//텍스트 블록 값 설정
	if (nullptr != HpStatText)
	{
		HpStatText->SetText(FText::FromString(GetHpStatText()));
	}
}

FString UABHpBarWidget::GetHpStatText()
{
	//문자열 조합을 통해서 Hp스탯 TEXT로 반환.
	return FString::Printf(TEXT("%.0f / %.0f"), CurrentHp, MaxHp);
}

void UABHpBarWidget::UpdateHpBar(float NewCurrentHp)
{
	//현재 Hp값도 업데이트
	CurrentHp = NewCurrentHp;

	//검증.
	ensure(MaxHp > 0.0f);

	//프로그래스 바 위젯 참조 유효성 확인.
	if (HpProgressBar)
	{
		//최대 체력 대비 현재 체력의 게이지(퍼센트)결정.
		//퍼센트를 넘겨줘야 함.
		HpProgressBar->SetPercent(NewCurrentHp / MaxHp);
	}

	if (nullptr != HpStatText)
	{
		HpStatText->SetText(FText::FromString(GetHpStatText()));
	}
}

void UABHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//이 함수가 호출될 때는 UI(UMG)가 초기화됐다고 생각할 수 있음.

	//이름 값을 사용해 위젯 참조 가져오기.
	//UProgress타입이 아닌 UserWidget타입이었기 때문
	HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HpBar")));
	ensure(HpProgressBar);

	//이름 값을 사용해 위젯 참조 가져오기.
	HpStatText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TxtHpStat")));
	ensure(HpStatText);

	//인터페이스를 통해서 이 위젯의 함수에 Stat 컴포넌트의 델리게이트 등록 요청 및 초기 값 설정
	IABCharacterWidgetInterface* CharacterWidgetInterface 
		= Cast<IABCharacterWidgetInterface>(OwningActor);
	if (CharacterWidgetInterface)
	{
		CharacterWidgetInterface->SetupCharacterWidget(this);
	}
}
