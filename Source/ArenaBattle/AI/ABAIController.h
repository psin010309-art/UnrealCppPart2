// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ABAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AABAIController();

	//AI실행함수
	void RunAI();

	//AI중지함수
	void StopAI();

protected:
	//컨트롤러가 폰에 빙의(소유)할 때 호출되는 함수
	//AI 실행시키기 위함(beginPlay는 보장할 수 없기에 더 안전한 방법)
	virtual void OnPossess(APawn* InPawn) override;

private:
	//블랙보드 애셋
	UPROPERTY(VisibleAnywhere, Category = AI)
	TObjectPtr<class UBlackboardData> BBAsset;

	//비헤이비어 애셋
	UPROPERTY(VisibleAnywhere, Category = AI)
	TObjectPtr<class UBehaviorTree> BTAsset;
};
