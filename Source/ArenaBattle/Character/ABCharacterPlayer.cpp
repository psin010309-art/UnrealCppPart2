// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterPlayer.h"
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework//CharacterMovementComponent.h>
#include <Camera/CameraComponent.h>

AABCharacterPlayer::AABCharacterPlayer()
{
	//회전 속성 결정.
	bUseControllerRotationYaw = false;   //z축
	bUseControllerRotationPitch = false; // y축
	bUseControllerRotationRoll = false;  //x축
	//컴포넌트 구성 및 생성
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(
		TEXT("SpringArm")
	);

	//계층 설정
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 600.0f;

	//컨트롤러 회전을 사용하도록 설정(기본 값은 폰의 횐 속성 사용)
	SpringArm->bUsePawnControlRotation = true;

	//카메라 컴포넌트 생성
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//무브먼트 컴포넌트 설정
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 800.0f;

	//매시 컴포넌트 설정
	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0.0f, 0.0f, -88.0f),
		FRotator(0.0f, -90.0f, 0.0f) //P,Y,R -> Y,Z,X
	);

	//메시 애셋 지정.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>CharacterMesh(
		TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple.SKM_Manny_Simple")
	);

	if (CharacterMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(CharacterMesh.Object);
	}
	
	//애님 블루프린트 클래스 검색 및 설정
	static ConstructorHelpers::FClassFinder<UAnimInstance> CharacterAnim(
		TEXT("/Game/Characters/Mannequins/Anims/Unarmed/ABP_Unarmed.ABP_Unarmed_C")
	);

	if (CharacterAnim.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(CharacterAnim.Class);
	}
}

void AABCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
}
