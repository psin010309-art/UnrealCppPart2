// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStat/ABCharacterStatComponent.h"

// Sets default values for this component's properties
UABCharacterStatComponent::UABCharacterStatComponent()
{
	MaxHp = 200.0f;
	//현재 Hp
	SetHp(MaxHp);
}


// Called when the game starts
void UABCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	SetHp(MaxHp);
	
}

float UABCharacterStatComponent::ApplyDamage(float InDamage)
{
	//기존 Hp 저장.
	//기존 Hp와 변경된 Hp간의 차이가 있으면 델리게이트에 반영하기 위함.
	const float PrevHp = CurrentHp;
	//음수 방지
	const float ActualDamage = FMath::Clamp<float>(InDamage, 0, InDamage);
	
	//대미지를 적용한 새 HP 계산
	SetHp(PrevHp - ActualDamage);

	//Hp가 모두 소멸(0이 되었는지)
	if (CurrentHp <= KINDA_SMALL_NUMBER)
	{
		//델리게이트 발행
		OnHpZero.Broadcast();
	}


	return ActualDamage;
}

void UABCharacterStatComponent::SetHp(float NewHp)
{
	//현재 체력 업데이트
	CurrentHp = FMath::Clamp<float>(NewHp, 0.0f, MaxHp);

	//체력 변경 델리게이트 발행
	OnHpChanged.Broadcast(CurrentHp);
}

