// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
#include <Inteface/ABAnimationAttackInterface.h>

void UAnimNotify_AttackHitCheck::Notify(
	USkeletalMeshComponent* MeshComp,
	UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	//캐릭터에 접근해서 공격 판정 함수 호출.
	//직접 캐릭터에 접근하는 대신 인터페이슬르 통한 간접 접근.
	//->의존성을 줄이기 위해.
	if (MeshComp)
	{
		IABAnimationAttackInterface* AttackPawn
			= Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());
		if (AttackPawn)
		{
			AttackPawn->AttackHitCheck();
		}
	}
}
