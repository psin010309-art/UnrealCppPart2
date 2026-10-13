// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/ABAIController.h"
#include <AI/ABAI.h>

#include <BehaviorTree/BlackboardData.h>
#include <BehaviorTree/BehaviorTree.h>
#include <BehaviorTree/BlackboardComponent.h>

AABAIController::AABAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBAssetRef(
		TEXT("/Game/ArenaBattle/AI/BB_ABCharacter.BB_ABCharacter")
	);

	if (BBAssetRef.Succeeded())
	{
		BBAsset = BBAssetRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTAssetRef(
		TEXT("/Game/ArenaBattle/AI/BT_ABCharacter.BT_ABCharacter")
	);

	if (BTAssetRef.Succeeded())
	{
		BTAsset = BTAssetRef.Object;
	}
}

void AABAIController::RunAI()
{
	//블랙보드 컴포넌트 가져오기.
	//Get을 통해 Raw포인터로 자동변환.
	UBlackboardComponent* BlackboardPtr =  Blackboard.Get();

	//사용할 블랙보드 지정
	if (UseBlackboard(BBAsset, BlackboardPtr))
	{
		//NPC 폰이 생성된 위치를 블랙보드에 기록
		Blackboard->SetValueAsVector(BBKEY_HOMEPOS, GetPawn()->GetActorLocation());

		//행동트리 실행.
		bool RunResult = RunBehaviorTree(BTAsset);

		//실행 성공여부 확인
		ensureAlways(RunResult);
	}
}

void AABAIController::StopAI()
{
	//실행 중인 행동트리 컴포넌트 가져오기.
	UBehaviorTreeComponent* BTComponent 
		= Cast<UBehaviorTreeComponent>(BrainComponent);

	if (BTComponent)
	{
		//BT 실행 중지.
		BTComponent->StopTree();
	}
}

void AABAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//AI실행
	RunAI();
}
