// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABCharacterControlData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABCharacterControlData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UABCharacterControlData();

	//폰에 설정할 회전 속성 -> 1바이트 차지
	UPROPERTY(EditAnywhere, Category = Pawn)
	uint32 bUseControllerRotationYaw : 1;

	//캐릭터 무브먼트 컴포넌트에 적용될 회전 관련 속성
	UPROPERTY(EditAnywhere, Category = CharacterMovement)
	uint32 bUseControllerDesiredRotation : 1;

	UPROPERTY(EditAnywhere, Category = CharacterMovement)
	uint32 bUseOrientToMovement : 1;

	UPROPERTY(EditAnywhere, Category = CharacterMovement)
	FRotator RotationRate;

	//사용할 입력 매핑 컨텍스트 애셋.
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Input)
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = SpringArm)
	float TargetArmLength;

	//스프링 암 관련 속성.
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = SpringArm)
	FRotator RelativeRotation;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = SpringArm)
	uint32 bDoCollisionTest : 1;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = SpringArm)
	uint32 bUsePawnControllerRotation : 1;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = SpringArm)
	uint32 bInheritPitch : 1;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = SpringArm)
	uint32 bInheritYaw : 1;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = SpringArm)
	uint32 bInheritRoll : 1;
};
