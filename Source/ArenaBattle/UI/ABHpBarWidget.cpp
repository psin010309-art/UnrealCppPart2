// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHpBarWidget.h"
#include <Components/ProgressBar.h>

UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	//최대 체력은 외부에서 설정이 되어야 함.
	//따라서 초기값은 오류의 의미를 가진 음수로 설정.
	MaxHp = -1.0f;
}

void UABHpBarWidget::UpdatHpBar(float NewCurrentHp)
{
	//검증.
	ensure(MaxHp > 0.0f);

	//프로그래스 바 위젯 참조 유효성 확인.
	if (HpProgressBar)
	{
		//최대 체력 대비 현재 체력의 게이지(퍼센트)결정.
		//퍼센트를 넘겨줘야 함.
		HpProgressBar->SetPercent(NewCurrentHp / MaxHp);
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
}
